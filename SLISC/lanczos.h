// partly translated from anglib.f90
// as directly as possible! all vars values unchanged.

// anglib.f90: angular momentum coupling coefficients in Fortran 90
// Copyright (C) 1998  Paul Stevenson

#pragma once
#include "cut.h"
#include "arithmetic.h"
#include "disp.h"

namespace slisc {

// calculate y = exp(H*dt) * x
// H is a hermitian matrix
// return error
inline Doub expHdt_v_lanc(VecComp_O y, CmatDoub_I H, VecComp_IO x, Doub_I dt, Long_I Nkrylov, VecDoub_IO wsp_d, VecComp_IO wsp_c)
{
    Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
    if (Nk > N)
        SLS_ERR("Nk > N !");
    if (wsp_d.size() < Nk*Nk + 2*Nk)
        SLS_ERR("wsp_d too short!");
    if (wsp_c.size() < N*Nk + N)
        SLS_ERR("wsp_c too short!");
#endif

    Doub *pd = wsp_d.p();
    SvecDoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
    SvecDoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
    ScmatDoub eigV(pd, Nk, Nk); pd += eigV.size(); // eigen vectors
    
    Comp *pc = wsp_c.p();
    SvecComp vc(pc, N); pc += vc.size(); // temp vec
    ScmatComp bases(pc, N, Nk); pc += bases.size(); // Krylov bases
    
    SvecComp v0 = cut1(bases, 0), v1 = cut1(bases, 1), v2 = cut1(bases, 2);
    beta[0] = norm(x);
    times(v0, x, 1/beta[0]); 

    mul_gen(vc, H, v0);
    alpha[0] = real(dot(v0, vc));
    for (Long i = 0; i < N; ++i)
        v1[i] = vc[i] - alpha[0] * v0[i];
    beta[1] = norm(v1);
    v1 /= beta[1];
    mul_gen(vc, H, v1);
    alpha[1] = real(dot(v1, vc));

    for (Long j = 0; j < Nk-2; ++j) {
        Long j1 = j+1, j2 = j+2;
        mul_gen(v2, H, v1); // ???
        Doub a = alpha[j1], b = beta[j1];
        for (Long i = 0; i < N; ++i)
            v2[i] -= a * v1[i] + b * v0[i];
        beta[j2] = norm(v2);
        v2 /= beta[j2];
        mul_gen(vc, H, v2);
        alpha[j2] = real(dot(v2, vc));
        v0.next(); v1.next(); v2.next();
    }
    Doub err = prod(beta) * pow(dt, N) / factorial(N);

    lapack_int info =
    LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p()+1, eigV.p(), Nk);
    // alpha is now eigen values
    if (info != 0)
        SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));
    
    for (Long i = 0; i < Nk; ++i)
        alpha[i] = exp(alpha[i] * dt) * eigV[i*Nk] * beta[0];
    // alpha, beta are just work spaces now
    mul_gen(beta, eigV, alpha);
    mul(y, bases, beta);

    return err;
}

// calculate y = exp(-i*H*dt) * x
// H is a hermitian matrix
// return error
inline Doub exp_miHdt_v_lanc(VecComp_O y, CmatDoub_I H, VecComp_IO x, Doub_I dt, Long_I Nkrylov, VecDoub_IO wsp_d, VecComp_IO wsp_c)
{
    Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
    if (Nk > N)
        SLS_ERR("Nk > N !");
    if (wsp_d.size() < Nk*Nk + 2*Nk)
        SLS_ERR("wsp_d too short!");
    if (wsp_c.size() < N*Nk + N)
        SLS_ERR("wsp_c too short!");
#endif

    Doub *pd = wsp_d.p();
    SvecDoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
    SvecDoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
    ScmatDoub eigV(pd, Nk, Nk); pd += eigV.size(); // eigen vectors
    
    Comp *pc = wsp_c.p();
    SvecComp vc(pc, N); pc += vc.size(); // temp vec
    SvecComp vc1(pc, Nk); pc += vc1.size(); // temp vec
    ScmatComp bases(pc, N, Nk); pc += bases.size(); // Krylov bases
    
    SvecComp v0 = cut1(bases, 0), v1 = cut1(bases, 1), v2 = cut1(bases, 2);
    beta[0] = norm(x);
    times(v0, x, 1/beta[0]); 

    mul_gen(vc, H, v0);
    alpha[0] = real(dot(v0, vc));
    for (Long i = 0; i < N; ++i)
        v1[i] = vc[i] - alpha[0] * v0[i];
    beta[1] = norm(v1);
    v1 /= beta[1];
    mul_gen(vc, H, v1);
    alpha[1] = real(dot(v1, vc));

    for (Long j = 0; j < Nk-2; ++j) {
        Long j1 = j+1, j2 = j+2;
        mul_gen(v2, H, v1); // ???
        Doub a = alpha[j1], b = beta[j1];
        for (Long i = 0; i < N; ++i)
            v2[i] -= a * v1[i] + b * v0[i];
        beta[j2] = norm(v2);
        v2 /= beta[j2];
        mul_gen(vc, H, v2);
        alpha[j2] = real(dot(v2, vc));
        v0.next(); v1.next(); v2.next();
    }
    Doub err = prod(beta) * pow(dt, N) / factorial(N);

    lapack_int info =
    LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p()+1, eigV.p(), Nk);
    // alpha is now eigen values
    if (info != 0)
        SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));
    
    SvecComp vc2 = cut(vc, 0, Nk);
    for (Long i = 0; i < Nk; ++i)
        vc2[i] = exp(Comp(0,-1) * (alpha[i] * dt)) * conj(eigV[i*Nk]) * beta[0];
    mul_gen(vc1, eigV, vc2);
    mul(y, bases, vc1);

    return err;
}

} // namespace slisc
