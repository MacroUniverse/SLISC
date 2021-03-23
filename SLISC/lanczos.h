// partly translated from anglib.f90
// as directly as possible! all vars values unchanged.

// anglib.f90: angular momentum coupling coefficients in Fortran 90
// Copyright (C) 1998  Paul Stevenson

#pragma once
#include "cut.h"
#include "arithmetic.h"

namespace slisc {

// calculate y = exp(-i*H*dt) * x
// H is a hermitian matrix
// return error
inline Doub expv(VecComp_O y, CmatDoub_I H, VecComp_IO x, Doub_I dt, Long_I Nkrylov)
{
    Long N = x.size();
    if (Nkrylov > N)
        SLS_ERR("Nkrylov > N !");
    CmatComp bases(N, Nkrylov); // Krylov bases
    CmatDoub eig_vec(Nkrylov, Nkrylov); // eigen vectors
    VecDoub alpha(Nkrylov), beta(Nkrylov);

    // alpha = <v|H|v>
    VecComp tmp(N);
    SvecComp v0 = cut1(bases, 0), v1 = cut1(bases, 1), v2 = cut1(bases, 2);
    times(v0, x, 1/norm(x)); beta[0] = 1;

    mul_gen(tmp, H, v0);
    alpha[0] = real(dot(v0, tmp));
    for (Long i = 0; i < N; ++i)
        v1[i] = tmp[i] - alpha[0] * v0[i];
    beta[1] = norm(v1);
    v1 /= beta[1];
    mul_gen(tmp, H, v1);
    alpha[1] = real(dot(v1, tmp));

    for (Long j = 0; j < Nkrylov-2; ++j) {
        Long j1 = j+1, j2 = j+2;
        v0 = cut1(bases, j);
        v1 = cut1(bases, j+1);
        v2 = cut1(bases, j+2);
        mul_gen(v2, H, v1);
        Doub a = alpha[j1], b = beta[j1];
        for (Long i = 0; i < N; ++i)
            v2[i] -= a * v1[i] + b * v0[i];
        v2 /= (beta[j2] = norm(v2));
        mul_gen(tmp, H, v2);
        alpha[j2] = real(dot(v2, tmp));
    }
    Doub err = prod(beta) * pow(dt, N) / factorial(N);
    disp(alpha);
    disp(beta);

    lapack_int info =
    LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nkrylov, alpha.ptr(), beta.ptr()+1, eig_vec.ptr(), Nkrylov);
    if (info != 0)
        SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));
    // alpha is now eigen value vector
    for (Long i = 0; i < Nkrylov; ++i)
        tmp[i] = eig_vec[i*Nkrylov] * exp(Comp(0,-1)*alpha[i]*dt);
    VecComp yk(Nkrylov);
    mul_gen(yk, eig_vec, cut(tmp, 0, Nkrylov));
    disp(yk);
    mul_gen(y, bases, yk);

    return err;
}

} // namespace slisc
