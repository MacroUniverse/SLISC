// partly translated from anglib.f90
// as directly as possible! all vars values unchanged.

// anglib.f90: angular momentum coupling coefficients in Fortran 90
// Copyright (C) 1998  Paul Stevenson

#pragma once
#include "cut.h"
#include "arithmetic.h"
#include "disp.h"

namespace slisc {

// calculate y = exp(-i*H*dt) * x
// H is a hermitian matrix
// return error
inline Doub expv_lanc(VecComp_O y, CmatDoub_I H, VecComp_IO x, Doub_I dt, Long_I Nkrylov)
{
    Long N = x.size(), Nk = Nkrylov;
    if (Nk > N)
        SLS_ERR("Nk > N !");
    CmatComp bases(N, Nk); // Krylov bases
    CmatDoub eig_vec(Nk, Nk); // eigen vectors
    VecDoub alpha(Nk), beta(Nk);

    // alpha = <v|H|v>
    VecComp tmp(N);
    VecDoub tmp1(Nk);
    SvecComp v0 = cut1(bases, 0), v1 = cut1(bases, 1), v2 = cut1(bases, 2);
    beta[0] = norm(x);
    times(v0, x, 1/beta[0]); 

    mul_gen(tmp, H, v0);
    alpha[0] = real(dot(v0, tmp));
    for (Long i = 0; i < N; ++i)
        v1[i] = tmp[i] - alpha[0] * v0[i];
    beta[1] = norm(v1);
    v1 /= beta[1];
    mul_gen(tmp, H, v1);
    alpha[1] = real(dot(v1, tmp));

    for (Long j = 0; j < Nk-2; ++j) {
        Long j1 = j+1, j2 = j+2;
        v0 = cut1(bases, j);
        v1 = cut1(bases, j+1);
        v2 = cut1(bases, j+2);
        mul_gen(v2, H, v1); // ???
        Doub a = alpha[j1], b = beta[j1];
        for (Long i = 0; i < N; ++i)
            v2[i] -= a * v1[i] + b * v0[i];
        beta[j2] = norm(v2);
        v2 /= beta[j2];
        mul_gen(tmp, H, v2);
        alpha[j2] = real(dot(v2, tmp));
    }
    Doub err = prod(beta) * pow(dt, N) / factorial(N);

    lapack_int info =
    LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p()+1, eig_vec.p(), Nk);
    if (info != 0)
        SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));
    // alpha is now eigen value vector
    for (Long i = 0; i < Nk; ++i)
        tmp1[i] = exp(alpha[i] * dt) * eig_vec[i*Nk] * beta[0];
    VecDoub yk(Nk);
    mul_gen(yk, eig_vec, tmp1);
    mul(y, bases, yk);

    // cout << "orthogonality of bases" << endl;
    // CmatComp t(Nk, N), prod(Nk, Nk); her(t, bases);
    // mul(prod, t, bases);
    // disp(prod);

    // cout << "orthogonality of eigen_v" << endl;
    // CmatDoub uni(Nk, Nk), tr(Nk, Nk);
    // trans(tr, eig_vec);
    // mul(uni, tr, eig_vec);
    // disp(uni);

    return err;
}

} // namespace slisc
