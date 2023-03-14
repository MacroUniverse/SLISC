// lanczos algorithm to propagate wave function by exp(-iH dt)
// for error estimation, see 4.51 of Johannes Feist's thesis: prod(beta) * (dt^Nk / Nk!)
// however, (dt^Nk / Nk!) is extremely small and omitted.

#pragma once
#include "../global.h"
#ifdef SLS_USE_LAPACKE
#include "../dense/cut.h"
#include "../sparse/sparse_arith.h"
#include "../sparse/band_arith.h"
#include "../str/disp.h"

namespace slisc {

// calculate y = exp(H*dt) * x
// x, y can be the same object
// H is a hermitian matrix
// return error
// calculate v = exp(-i*H*dt) * v
// H is a hermitian matrix
// return error
inline Doub exp_Hdt_v_lanc(VecComp_O y, CmatDoub_I H, VecComp_I x, Doub_I dt, Long_I Nkrylov, SvecDoub_IO wsp_d, SvecComp_IO wsp_c)
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
	ScmatDoub eigV(pd, Nk, Nk); // eigen vectors
	
	Comp *pc = wsp_c.p();
	SvecComp vc(pc, N); pc += vc.size(); // temp vec
	ScmatComp bases(pc, N, Nk); // Krylov bases
	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
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
	    mul_gen(v2, H, v1);
	    Doub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	        v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul_gen(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Doub err = prod(beta);

	lapack_int info =
	LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p()+1, eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));
	
	for (Long i = 0; i < Nk; ++i)
	    alpha[i] = exp(alpha[i] * dt) * eigV[i*Nk] * beta[0];
	// alpha, beta are just work spaces now
	mul_gen(beta, eigV, alpha);
	mul(y, bases, beta);

	return err;
}

inline Qdoub exp_Hdt_v_lanc(VecQcomp_O y, CmatQdoub_I H, VecQcomp_I x, Qdoub_I dt, Long_I Nkrylov, SvecQdoub_IO wsp_d, SvecQcomp_IO wsp_c)
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

	Qdoub *pd = wsp_d.p();
	SvecQdoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
	SvecQdoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
	ScmatQdoub eigV(pd, Nk, Nk); // eigen vectors
	
	Qcomp *pc = wsp_c.p();
	SvecQcomp vc(pc, N); pc += vc.size(); // temp vec
	ScmatQcomp bases(pc, N, Nk); // Krylov bases
	SvecQcomp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
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
	    mul_gen(v2, H, v1);
	    Qdoub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	        v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul_gen(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Qdoub err = prod(beta);

#ifdef SLS_USE_MPLAPACK
	SLS_WARN("not optimized!");
	VecQdoub wsp(Nk);
	mplapackint info;
	Rstev("V", Nk, alpha.p(), beta.p()+1, eigV.p(), Nk, wsp.p(), info);
	if (info != 0) SLS_ERR("something wrong with Rstev: return = " + num2str((Long)info));
#else
	SLS_ERR("MPLAPACK is turned off!");
#endif
	
	for (Long i = 0; i < Nk; ++i)
	    alpha[i] = exp(alpha[i] * dt) * eigV[i*Nk] * beta[0];
	// alpha, beta are just work spaces now
	mul_gen(beta, eigV, alpha);
	mul(y, bases, beta);

	return err;
}

inline Doub exp_Hdt_v_lanc(VecComp_O y, CmatDoub_I H, VecComp_I x, Doub_I dt, Long_I Nkrylov, VecDoub_IO wsp_d, VecComp_IO wsp_c)
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
	ScmatDoub eigV(pd, Nk, Nk); // eigen vectors
	
	Comp *pc = wsp_c.p();
	SvecComp vc(pc, N); pc += vc.size(); // temp vec
	ScmatComp bases(pc, N, Nk); // Krylov bases
	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
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
	    mul_gen(v2, H, v1);
	    Doub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	        v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul_gen(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Doub err = prod(beta);

	lapack_int info =
	LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p()+1, eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));
	
	for (Long i = 0; i < Nk; ++i)
	    alpha[i] = exp(alpha[i] * dt) * eigV[i*Nk] * beta[0];
	// alpha, beta are just work spaces now
	mul_gen(beta, eigV, alpha);
	mul(y, bases, beta);

	return err;
}

inline Qdoub exp_Hdt_v_lanc(VecQcomp_O y, CmatQdoub_I H, VecQcomp_I x, Qdoub_I dt, Long_I Nkrylov, VecQdoub_IO wsp_d, VecQcomp_IO wsp_c)
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

	Qdoub *pd = wsp_d.p();
	SvecQdoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
	SvecQdoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
	ScmatQdoub eigV(pd, Nk, Nk); // eigen vectors
	
	Qcomp *pc = wsp_c.p();
	SvecQcomp vc(pc, N); pc += vc.size(); // temp vec
	ScmatQcomp bases(pc, N, Nk); // Krylov bases
	SvecQcomp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
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
	    mul_gen(v2, H, v1);
	    Qdoub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	        v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul_gen(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Qdoub err = prod(beta);

#ifdef SLS_USE_MPLAPACK
	SLS_WARN("not optimized!");
	VecQdoub wsp(Nk);
	mplapackint info;
	Rstev("V", Nk, alpha.p(), beta.p()+1, eigV.p(), Nk, wsp.p(), info);
	if (info != 0) SLS_ERR("something wrong with Rstev: return = " + num2str((Long)info));
#else
	SLS_ERR("MPLAPACK is turned off!");
#endif
	
	for (Long i = 0; i < Nk; ++i)
	    alpha[i] = exp(alpha[i] * dt) * eigV[i*Nk] * beta[0];
	// alpha, beta are just work spaces now
	mul_gen(beta, eigV, alpha);
	mul(y, bases, beta);

	return err;
}

inline Doub exp_Hdt_v_lanc(SvecComp_O y, CmobdDoub_I H, SvecComp_I x, Doub_I dt, Long_I Nkrylov, SvecDoub_IO wsp_d, SvecComp_IO wsp_c)
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
	ScmatDoub eigV(pd, Nk, Nk); // eigen vectors
	
	Comp *pc = wsp_c.p();
	SvecComp vc(pc, N); pc += vc.size(); // temp vec
	ScmatComp bases(pc, N, Nk); // Krylov bases
	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	times(v0, x, 1/beta[0]); 

	mul(vc, H, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
	    v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	v1 /= beta[1];
	mul(vc, H, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
	    Long j1 = j+1, j2 = j+2;
	    mul(v2, H, v1);
	    Doub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	        v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Doub err = prod(beta);

	lapack_int info =
	LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p()+1, eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));
	
	for (Long i = 0; i < Nk; ++i)
	    alpha[i] = exp(alpha[i] * dt) * eigV[i*Nk] * beta[0];
	// alpha, beta are just work spaces now
	mul_gen(beta, eigV, alpha);
	mul(y, bases, beta);

	return err;
}

inline Qdoub exp_Hdt_v_lanc(SvecQcomp_O y, CmobdQdoub_I H, SvecQcomp_I x, Qdoub_I dt, Long_I Nkrylov, SvecQdoub_IO wsp_d, SvecQcomp_IO wsp_c)
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

	Qdoub *pd = wsp_d.p();
	SvecQdoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
	SvecQdoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
	ScmatQdoub eigV(pd, Nk, Nk); // eigen vectors
	
	Qcomp *pc = wsp_c.p();
	SvecQcomp vc(pc, N); pc += vc.size(); // temp vec
	ScmatQcomp bases(pc, N, Nk); // Krylov bases
	SvecQcomp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	times(v0, x, 1/beta[0]); 

	mul(vc, H, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
	    v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	v1 /= beta[1];
	mul(vc, H, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
	    Long j1 = j+1, j2 = j+2;
	    mul(v2, H, v1);
	    Qdoub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	        v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Qdoub err = prod(beta);

#ifdef SLS_USE_MPLAPACK
	SLS_WARN("not optimized!");
	VecQdoub wsp(Nk);
	mplapackint info;
	Rstev("V", Nk, alpha.p(), beta.p()+1, eigV.p(), Nk, wsp.p(), info);
	if (info != 0) SLS_ERR("something wrong with Rstev: return = " + num2str((Long)info));
#else
	SLS_ERR("MPLAPACK is turned off!");
#endif
	
	for (Long i = 0; i < Nk; ++i)
	    alpha[i] = exp(alpha[i] * dt) * eigV[i*Nk] * beta[0];
	// alpha, beta are just work spaces now
	mul_gen(beta, eigV, alpha);
	mul(y, bases, beta);

	return err;
}

inline Doub exp_Hdt_v_lanc(DvecComp_O y, McooDoub_I H, DvecComp_I x, Doub_I dt, Long_I Nkrylov, SvecDoub_IO wsp_d, SvecComp_IO wsp_c)
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
	ScmatDoub eigV(pd, Nk, Nk); // eigen vectors
	
	Comp *pc = wsp_c.p();
	SvecComp vc(pc, N); pc += vc.size(); // temp vec
	ScmatComp bases(pc, N, Nk); // Krylov bases
	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	times(v0, x, 1/beta[0]); 

	mul(vc, H, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
	    v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	v1 /= beta[1];
	mul(vc, H, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
	    Long j1 = j+1, j2 = j+2;
	    mul(v2, H, v1);
	    Doub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	        v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Doub err = prod(beta);

	lapack_int info =
	LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p()+1, eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));
	
	for (Long i = 0; i < Nk; ++i)
	    alpha[i] = exp(alpha[i] * dt) * eigV[i*Nk] * beta[0];
	// alpha, beta are just work spaces now
	mul_gen(beta, eigV, alpha);
	mul(y, bases, beta);

	return err;
}

inline Qdoub exp_Hdt_v_lanc(DvecQcomp_O y, McooQdoub_I H, DvecQcomp_I x, Qdoub_I dt, Long_I Nkrylov, SvecQdoub_IO wsp_d, SvecQcomp_IO wsp_c)
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

	Qdoub *pd = wsp_d.p();
	SvecQdoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
	SvecQdoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
	ScmatQdoub eigV(pd, Nk, Nk); // eigen vectors
	
	Qcomp *pc = wsp_c.p();
	SvecQcomp vc(pc, N); pc += vc.size(); // temp vec
	ScmatQcomp bases(pc, N, Nk); // Krylov bases
	SvecQcomp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	times(v0, x, 1/beta[0]); 

	mul(vc, H, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
	    v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	v1 /= beta[1];
	mul(vc, H, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
	    Long j1 = j+1, j2 = j+2;
	    mul(v2, H, v1);
	    Qdoub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	        v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Qdoub err = prod(beta);

#ifdef SLS_USE_MPLAPACK
	SLS_WARN("not optimized!");
	VecQdoub wsp(Nk);
	mplapackint info;
	Rstev("V", Nk, alpha.p(), beta.p()+1, eigV.p(), Nk, wsp.p(), info);
	if (info != 0) SLS_ERR("something wrong with Rstev: return = " + num2str((Long)info));
#else
	SLS_ERR("MPLAPACK is turned off!");
#endif
	
	for (Long i = 0; i < Nk; ++i)
	    alpha[i] = exp(alpha[i] * dt) * eigV[i*Nk] * beta[0];
	// alpha, beta are just work spaces now
	mul_gen(beta, eigV, alpha);
	mul(y, bases, beta);

	return err;
}

inline Doub exp_Hdt_v_lanc(DvecComp_O y, CmobdDoub_I H, DvecComp_I x, Doub_I dt, Long_I Nkrylov, SvecDoub_IO wsp_d, SvecComp_IO wsp_c)
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
	ScmatDoub eigV(pd, Nk, Nk); // eigen vectors
	
	Comp *pc = wsp_c.p();
	SvecComp vc(pc, N); pc += vc.size(); // temp vec
	ScmatComp bases(pc, N, Nk); // Krylov bases
	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	times(v0, x, 1/beta[0]); 

	mul(vc, H, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
	    v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	v1 /= beta[1];
	mul(vc, H, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
	    Long j1 = j+1, j2 = j+2;
	    mul(v2, H, v1);
	    Doub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	        v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Doub err = prod(beta);

	lapack_int info =
	LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p()+1, eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));
	
	for (Long i = 0; i < Nk; ++i)
	    alpha[i] = exp(alpha[i] * dt) * eigV[i*Nk] * beta[0];
	// alpha, beta are just work spaces now
	mul_gen(beta, eigV, alpha);
	mul(y, bases, beta);

	return err;
}

inline Qdoub exp_Hdt_v_lanc(DvecQcomp_O y, CmobdQdoub_I H, DvecQcomp_I x, Qdoub_I dt, Long_I Nkrylov, SvecQdoub_IO wsp_d, SvecQcomp_IO wsp_c)
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

	Qdoub *pd = wsp_d.p();
	SvecQdoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
	SvecQdoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
	ScmatQdoub eigV(pd, Nk, Nk); // eigen vectors
	
	Qcomp *pc = wsp_c.p();
	SvecQcomp vc(pc, N); pc += vc.size(); // temp vec
	ScmatQcomp bases(pc, N, Nk); // Krylov bases
	SvecQcomp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	times(v0, x, 1/beta[0]); 

	mul(vc, H, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
	    v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	v1 /= beta[1];
	mul(vc, H, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
	    Long j1 = j+1, j2 = j+2;
	    mul(v2, H, v1);
	    Qdoub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	        v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Qdoub err = prod(beta);

#ifdef SLS_USE_MPLAPACK
	SLS_WARN("not optimized!");
	VecQdoub wsp(Nk);
	mplapackint info;
	Rstev("V", Nk, alpha.p(), beta.p()+1, eigV.p(), Nk, wsp.p(), info);
	if (info != 0) SLS_ERR("something wrong with Rstev: return = " + num2str((Long)info));
#else
	SLS_ERR("MPLAPACK is turned off!");
#endif
	
	for (Long i = 0; i < Nk; ++i)
	    alpha[i] = exp(alpha[i] * dt) * eigV[i*Nk] * beta[0];
	// alpha, beta are just work spaces now
	mul_gen(beta, eigV, alpha);
	mul(y, bases, beta);

	return err;
}


// calculate y = exp(-i*H*dt) * x
// x, y can be the same object
// H is a hermitian matrix
// return error
inline Doub exp_miHdt_v_lanc(DvecComp_IO y, CbandDoub_I H, DvecComp_I x, Doub_I dt, Long_I Nkrylov, SvecDoub_IO wsp_d, SvecComp_IO wsp_c)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N)
	    SLS_ERR("Nk > N !");
	if (wsp_d.size() < Nk*Nk + 2*Nk)
	    SLS_ERR("wsp_d too short!");
	if (wsp_c.size() < N*Nk + N + Nk)
	    SLS_ERR("wsp_c too short!");
#endif

	Doub *pd = wsp_d.p();
	SvecDoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
	SvecDoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
	ScmatDoub eigV(pd, Nk, Nk); // eigen vectors
	
	Comp *pc = wsp_c.p();
	SvecComp vc(pc, N); pc += vc.size(); // temp vec
	SvecComp vc1(pc, Nk); pc += vc1.size(); // temp vec
	ScmatComp bases(pc, N, Nk); // Krylov bases
	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	times(v0, x, 1/beta[0]);
	mul(vc, H, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
	    v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	v1 /= beta[1];
	mul(vc, H, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
	    Long j1 = j+1, j2 = j+2;
	    mul(v2, H, v1);
	    Doub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	    v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Doub err = prod(beta);
	lapack_int info =
	LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p()+1, eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));
	SvecComp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
	    vc2[i] = exp(Comp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * beta[0];
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
	return err;
}

inline Qdoub exp_miHdt_v_lanc(DvecQcomp_IO y, CbandQdoub_I H, DvecQcomp_I x, Qdoub_I dt, Long_I Nkrylov, SvecQdoub_IO wsp_d, SvecQcomp_IO wsp_c)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N)
	    SLS_ERR("Nk > N !");
	if (wsp_d.size() < Nk*Nk + 2*Nk)
	    SLS_ERR("wsp_d too short!");
	if (wsp_c.size() < N*Nk + N + Nk)
	    SLS_ERR("wsp_c too short!");
#endif

	Qdoub *pd = wsp_d.p();
	SvecQdoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
	SvecQdoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
	ScmatQdoub eigV(pd, Nk, Nk); // eigen vectors
	
	Qcomp *pc = wsp_c.p();
	SvecQcomp vc(pc, N); pc += vc.size(); // temp vec
	SvecQcomp vc1(pc, Nk); pc += vc1.size(); // temp vec
	ScmatQcomp bases(pc, N, Nk); // Krylov bases
	SvecQcomp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	times(v0, x, 1/beta[0]);
	mul(vc, H, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
	    v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	v1 /= beta[1];
	mul(vc, H, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
	    Long j1 = j+1, j2 = j+2;
	    mul(v2, H, v1);
	    Qdoub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	    v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Qdoub err = prod(beta);
#ifdef SLS_USE_MPLAPACK
	SLS_WARN("not optimized!");
	VecQdoub wsp(Nk);
	mplapackint info;
	// alpha is now eigen values
	Rstev("V", Nk, alpha.p(), beta.p()+1, eigV.p(), Nk, wsp.p(), info);
	if (info != 0) SLS_ERR("something wrong with Rstev: return = " + num2str((Long)info));
#else
	SLS_ERR("MPLAPACK is turned off!");
#endif
	SvecQcomp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
	    vc2[i] = exp(Qcomp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * beta[0];
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
	return err;
}

inline Doub exp_miHdt_v_lanc(DvecComp_IO y, CmatDoub_I H, DvecComp_I x, Doub_I dt, Long_I Nkrylov, VecDoub_IO wsp_d, VecComp_IO wsp_c)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N)
	    SLS_ERR("Nk > N !");
	if (wsp_d.size() < Nk*Nk + 2*Nk)
	    SLS_ERR("wsp_d too short!");
	if (wsp_c.size() < N*Nk + N + Nk)
	    SLS_ERR("wsp_c too short!");
#endif

	Doub *pd = wsp_d.p();
	SvecDoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
	SvecDoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
	ScmatDoub eigV(pd, Nk, Nk); // eigen vectors
	
	Comp *pc = wsp_c.p();
	SvecComp vc(pc, N); pc += vc.size(); // temp vec
	SvecComp vc1(pc, Nk); pc += vc1.size(); // temp vec
	ScmatComp bases(pc, N, Nk); // Krylov bases
	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
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
	    mul_gen(v2, H, v1);
	    Doub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	    v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul_gen(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Doub err = prod(beta);
	lapack_int info =
	LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p()+1, eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));
	SvecComp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
	    vc2[i] = exp(Comp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * beta[0];
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
	return err;
}

inline Qdoub exp_miHdt_v_lanc(DvecQcomp_IO y, CmatQdoub_I H, DvecQcomp_I x, Qdoub_I dt, Long_I Nkrylov, VecQdoub_IO wsp_d, VecQcomp_IO wsp_c)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N)
	    SLS_ERR("Nk > N !");
	if (wsp_d.size() < Nk*Nk + 2*Nk)
	    SLS_ERR("wsp_d too short!");
	if (wsp_c.size() < N*Nk + N + Nk)
	    SLS_ERR("wsp_c too short!");
#endif

	Qdoub *pd = wsp_d.p();
	SvecQdoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
	SvecQdoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
	ScmatQdoub eigV(pd, Nk, Nk); // eigen vectors
	
	Qcomp *pc = wsp_c.p();
	SvecQcomp vc(pc, N); pc += vc.size(); // temp vec
	SvecQcomp vc1(pc, Nk); pc += vc1.size(); // temp vec
	ScmatQcomp bases(pc, N, Nk); // Krylov bases
	SvecQcomp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
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
	    mul_gen(v2, H, v1);
	    Qdoub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	    v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul_gen(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Qdoub err = prod(beta);
#ifdef SLS_USE_MPLAPACK
	SLS_WARN("not optimized!");
	VecQdoub wsp(Nk);
	mplapackint info;
	// alpha is now eigen values
	Rstev("V", Nk, alpha.p(), beta.p()+1, eigV.p(), Nk, wsp.p(), info);
	if (info != 0) SLS_ERR("something wrong with Rstev: return = " + num2str((Long)info));
#else
	SLS_ERR("MPLAPACK is turned off!");
#endif
	SvecQcomp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
	    vc2[i] = exp(Qcomp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * beta[0];
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
	return err;
}

inline Doub exp_miHdt_v_lanc(VecComp_IO y, CmatDoub_I H, VecComp_I x, Doub_I dt, Long_I Nkrylov, VecDoub_IO wsp_d, VecComp_IO wsp_c)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N)
	    SLS_ERR("Nk > N !");
	if (wsp_d.size() < Nk*Nk + 2*Nk)
	    SLS_ERR("wsp_d too short!");
	if (wsp_c.size() < N*Nk + N + Nk)
	    SLS_ERR("wsp_c too short!");
#endif

	Doub *pd = wsp_d.p();
	SvecDoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
	SvecDoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
	ScmatDoub eigV(pd, Nk, Nk); // eigen vectors
	
	Comp *pc = wsp_c.p();
	SvecComp vc(pc, N); pc += vc.size(); // temp vec
	SvecComp vc1(pc, Nk); pc += vc1.size(); // temp vec
	ScmatComp bases(pc, N, Nk); // Krylov bases
	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
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
	    mul_gen(v2, H, v1);
	    Doub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	    v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul_gen(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Doub err = prod(beta);
	lapack_int info =
	LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p()+1, eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));
	SvecComp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
	    vc2[i] = exp(Comp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * beta[0];
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
	return err;
}

inline Qdoub exp_miHdt_v_lanc(VecQcomp_IO y, CmatQdoub_I H, VecQcomp_I x, Qdoub_I dt, Long_I Nkrylov, VecQdoub_IO wsp_d, VecQcomp_IO wsp_c)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N)
	    SLS_ERR("Nk > N !");
	if (wsp_d.size() < Nk*Nk + 2*Nk)
	    SLS_ERR("wsp_d too short!");
	if (wsp_c.size() < N*Nk + N + Nk)
	    SLS_ERR("wsp_c too short!");
#endif

	Qdoub *pd = wsp_d.p();
	SvecQdoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
	SvecQdoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
	ScmatQdoub eigV(pd, Nk, Nk); // eigen vectors
	
	Qcomp *pc = wsp_c.p();
	SvecQcomp vc(pc, N); pc += vc.size(); // temp vec
	SvecQcomp vc1(pc, Nk); pc += vc1.size(); // temp vec
	ScmatQcomp bases(pc, N, Nk); // Krylov bases
	SvecQcomp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
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
	    mul_gen(v2, H, v1);
	    Qdoub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	    v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul_gen(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Qdoub err = prod(beta);
#ifdef SLS_USE_MPLAPACK
	SLS_WARN("not optimized!");
	VecQdoub wsp(Nk);
	mplapackint info;
	// alpha is now eigen values
	Rstev("V", Nk, alpha.p(), beta.p()+1, eigV.p(), Nk, wsp.p(), info);
	if (info != 0) SLS_ERR("something wrong with Rstev: return = " + num2str((Long)info));
#else
	SLS_ERR("MPLAPACK is turned off!");
#endif
	SvecQcomp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
	    vc2[i] = exp(Qcomp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * beta[0];
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
	return err;
}

inline Doub exp_miHdt_v_lanc(DvecComp_IO y, McooDoub_I H, DvecComp_I x, Doub_I dt, Long_I Nkrylov, SvecDoub_IO wsp_d, SvecComp_IO wsp_c)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N)
	    SLS_ERR("Nk > N !");
	if (wsp_d.size() < Nk*Nk + 2*Nk)
	    SLS_ERR("wsp_d too short!");
	if (wsp_c.size() < N*Nk + N + Nk)
	    SLS_ERR("wsp_c too short!");
#endif

	Doub *pd = wsp_d.p();
	SvecDoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
	SvecDoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
	ScmatDoub eigV(pd, Nk, Nk); // eigen vectors
	
	Comp *pc = wsp_c.p();
	SvecComp vc(pc, N); pc += vc.size(); // temp vec
	SvecComp vc1(pc, Nk); pc += vc1.size(); // temp vec
	ScmatComp bases(pc, N, Nk); // Krylov bases
	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	times(v0, x, 1/beta[0]);
	mul(vc, H, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
	    v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	v1 /= beta[1];
	mul(vc, H, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
	    Long j1 = j+1, j2 = j+2;
	    mul(v2, H, v1);
	    Doub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	    v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Doub err = prod(beta);
	lapack_int info =
	LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p()+1, eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));
	SvecComp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
	    vc2[i] = exp(Comp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * beta[0];
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
	return err;
}

inline Qdoub exp_miHdt_v_lanc(DvecQcomp_IO y, McooQdoub_I H, DvecQcomp_I x, Qdoub_I dt, Long_I Nkrylov, SvecQdoub_IO wsp_d, SvecQcomp_IO wsp_c)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N)
	    SLS_ERR("Nk > N !");
	if (wsp_d.size() < Nk*Nk + 2*Nk)
	    SLS_ERR("wsp_d too short!");
	if (wsp_c.size() < N*Nk + N + Nk)
	    SLS_ERR("wsp_c too short!");
#endif

	Qdoub *pd = wsp_d.p();
	SvecQdoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
	SvecQdoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
	ScmatQdoub eigV(pd, Nk, Nk); // eigen vectors
	
	Qcomp *pc = wsp_c.p();
	SvecQcomp vc(pc, N); pc += vc.size(); // temp vec
	SvecQcomp vc1(pc, Nk); pc += vc1.size(); // temp vec
	ScmatQcomp bases(pc, N, Nk); // Krylov bases
	SvecQcomp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	times(v0, x, 1/beta[0]);
	mul(vc, H, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
	    v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	v1 /= beta[1];
	mul(vc, H, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
	    Long j1 = j+1, j2 = j+2;
	    mul(v2, H, v1);
	    Qdoub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	    v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Qdoub err = prod(beta);
#ifdef SLS_USE_MPLAPACK
	SLS_WARN("not optimized!");
	VecQdoub wsp(Nk);
	mplapackint info;
	// alpha is now eigen values
	Rstev("V", Nk, alpha.p(), beta.p()+1, eigV.p(), Nk, wsp.p(), info);
	if (info != 0) SLS_ERR("something wrong with Rstev: return = " + num2str((Long)info));
#else
	SLS_ERR("MPLAPACK is turned off!");
#endif
	SvecQcomp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
	    vc2[i] = exp(Qcomp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * beta[0];
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
	return err;
}

inline Doub exp_miHdt_v_lanc(SvecComp_IO y, CmobdDoub_I H, SvecComp_I x, Doub_I dt, Long_I Nkrylov, SvecDoub_IO wsp_d, SvecComp_IO wsp_c)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N)
	    SLS_ERR("Nk > N !");
	if (wsp_d.size() < Nk*Nk + 2*Nk)
	    SLS_ERR("wsp_d too short!");
	if (wsp_c.size() < N*Nk + N + Nk)
	    SLS_ERR("wsp_c too short!");
#endif

	Doub *pd = wsp_d.p();
	SvecDoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
	SvecDoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
	ScmatDoub eigV(pd, Nk, Nk); // eigen vectors
	
	Comp *pc = wsp_c.p();
	SvecComp vc(pc, N); pc += vc.size(); // temp vec
	SvecComp vc1(pc, Nk); pc += vc1.size(); // temp vec
	ScmatComp bases(pc, N, Nk); // Krylov bases
	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	times(v0, x, 1/beta[0]);
	mul(vc, H, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
	    v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	v1 /= beta[1];
	mul(vc, H, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
	    Long j1 = j+1, j2 = j+2;
	    mul(v2, H, v1);
	    Doub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	    v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Doub err = prod(beta);
	lapack_int info =
	LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p()+1, eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));
	SvecComp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
	    vc2[i] = exp(Comp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * beta[0];
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
	return err;
}

inline Qdoub exp_miHdt_v_lanc(SvecQcomp_IO y, CmobdQdoub_I H, SvecQcomp_I x, Qdoub_I dt, Long_I Nkrylov, SvecQdoub_IO wsp_d, SvecQcomp_IO wsp_c)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N)
	    SLS_ERR("Nk > N !");
	if (wsp_d.size() < Nk*Nk + 2*Nk)
	    SLS_ERR("wsp_d too short!");
	if (wsp_c.size() < N*Nk + N + Nk)
	    SLS_ERR("wsp_c too short!");
#endif

	Qdoub *pd = wsp_d.p();
	SvecQdoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
	SvecQdoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
	ScmatQdoub eigV(pd, Nk, Nk); // eigen vectors
	
	Qcomp *pc = wsp_c.p();
	SvecQcomp vc(pc, N); pc += vc.size(); // temp vec
	SvecQcomp vc1(pc, Nk); pc += vc1.size(); // temp vec
	ScmatQcomp bases(pc, N, Nk); // Krylov bases
	SvecQcomp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	times(v0, x, 1/beta[0]);
	mul(vc, H, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
	    v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	v1 /= beta[1];
	mul(vc, H, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
	    Long j1 = j+1, j2 = j+2;
	    mul(v2, H, v1);
	    Qdoub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	    v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Qdoub err = prod(beta);
#ifdef SLS_USE_MPLAPACK
	SLS_WARN("not optimized!");
	VecQdoub wsp(Nk);
	mplapackint info;
	// alpha is now eigen values
	Rstev("V", Nk, alpha.p(), beta.p()+1, eigV.p(), Nk, wsp.p(), info);
	if (info != 0) SLS_ERR("something wrong with Rstev: return = " + num2str((Long)info));
#else
	SLS_ERR("MPLAPACK is turned off!");
#endif
	SvecQcomp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
	    vc2[i] = exp(Qcomp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * beta[0];
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
	return err;
}

inline Doub exp_miHdt_v_lanc(DvecComp_IO y, CmobdDoub_I H, DvecComp_I x, Doub_I dt, Long_I Nkrylov, SvecDoub_IO wsp_d, SvecComp_IO wsp_c)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N)
	    SLS_ERR("Nk > N !");
	if (wsp_d.size() < Nk*Nk + 2*Nk)
	    SLS_ERR("wsp_d too short!");
	if (wsp_c.size() < N*Nk + N + Nk)
	    SLS_ERR("wsp_c too short!");
#endif

	Doub *pd = wsp_d.p();
	SvecDoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
	SvecDoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
	ScmatDoub eigV(pd, Nk, Nk); // eigen vectors
	
	Comp *pc = wsp_c.p();
	SvecComp vc(pc, N); pc += vc.size(); // temp vec
	SvecComp vc1(pc, Nk); pc += vc1.size(); // temp vec
	ScmatComp bases(pc, N, Nk); // Krylov bases
	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	times(v0, x, 1/beta[0]);
	mul(vc, H, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
	    v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	v1 /= beta[1];
	mul(vc, H, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
	    Long j1 = j+1, j2 = j+2;
	    mul(v2, H, v1);
	    Doub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	    v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Doub err = prod(beta);
	lapack_int info =
	LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p()+1, eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));
	SvecComp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
	    vc2[i] = exp(Comp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * beta[0];
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
	return err;
}

inline Qdoub exp_miHdt_v_lanc(DvecQcomp_IO y, CmobdQdoub_I H, DvecQcomp_I x, Qdoub_I dt, Long_I Nkrylov, SvecQdoub_IO wsp_d, SvecQcomp_IO wsp_c)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N)
	    SLS_ERR("Nk > N !");
	if (wsp_d.size() < Nk*Nk + 2*Nk)
	    SLS_ERR("wsp_d too short!");
	if (wsp_c.size() < N*Nk + N + Nk)
	    SLS_ERR("wsp_c too short!");
#endif

	Qdoub *pd = wsp_d.p();
	SvecQdoub alpha(pd, Nk); pd += alpha.size(); // alpha[i] = <v_i|H|v_i>
	SvecQdoub beta(pd, Nk); pd += beta.size(); // beta[i] = norm(bar v_i)
	ScmatQdoub eigV(pd, Nk, Nk); // eigen vectors
	
	Qcomp *pc = wsp_c.p();
	SvecQcomp vc(pc, N); pc += vc.size(); // temp vec
	SvecQcomp vc1(pc, Nk); pc += vc1.size(); // temp vec
	ScmatQcomp bases(pc, N, Nk); // Krylov bases
	SvecQcomp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	times(v0, x, 1/beta[0]);
	mul(vc, H, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
	    v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	v1 /= beta[1];
	mul(vc, H, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
	    Long j1 = j+1, j2 = j+2;
	    mul(v2, H, v1);
	    Qdoub a = alpha[j1], b = beta[j1];
	    for (Long i = 0; i < N; ++i)
	    v2[i] -= a * v1[i] + b * v0[i];
	    beta[j2] = norm(v2);
	    v2 /= beta[j2];
	    mul(vc, H, v2);
	    alpha[j2] = real(dot(v2, vc));
	    v0.next(); v1.next(); v2.next();
	}
	Qdoub err = prod(beta);
#ifdef SLS_USE_MPLAPACK
	SLS_WARN("not optimized!");
	VecQdoub wsp(Nk);
	mplapackint info;
	// alpha is now eigen values
	Rstev("V", Nk, alpha.p(), beta.p()+1, eigV.p(), Nk, wsp.p(), info);
	if (info != 0) SLS_ERR("something wrong with Rstev: return = " + num2str((Long)info));
#else
	SLS_ERR("MPLAPACK is turned off!");
#endif
	SvecQcomp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
	    vc2[i] = exp(Qcomp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * beta[0];
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
	return err;
}


} // namespace slisc

#endif
