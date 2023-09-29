// lanczos algorithm to propagate wave function by exp(-iH dt)
// for error estimation, see 4.51 of Johannes Feist's thesis: prod(beta) * (dt^Nk / Nk!)
// however, (dt^Nk / Nk!) is extremely small and omitted.

#pragma once
#include "../global.h"
#ifdef SLS_USE_LAPACKE
#include "../dense/cut.h"
#include "../sparse/sparse_arith.h"
#include "../sparse/band_arith.h"
#include "../lin/mul.h"
#include "../dense/WorkSpace.h"

namespace slisc {

// bytes of workspace required
inline Long exp_Hdt_v_lanc_Comp_Nwsp(Long_I N, Long_I Nk) {
	return sizeof(Doub)*((2*N+Nk)*(Nk+1)+Nk)+4*(SLS_WSP_ALIGN-1);
}

// calculate y = exp(H*dt) * x
// x, y can be the same object
// mul_fun(y, x) performs y = H*x, where H is a hermitian matrix
// return error
// required workspace: sizeof(Doub)*((2*N+Nk)*(Nk+1)+Nk)+4*align
template <class Tmul>
inline Doub exp_Hdt_v_lanc(VecComp_O y, Tmul &mul_fun, VecComp_I x, Doub_I dt, Long_I Nkrylov, WorkSpace &wsp)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N) SLS_ERR("Nk > N !");
#endif
	auto alpha = wsp.SvecDoub(Nk); // alpha[i] = <v_i|H|v_i>
	auto beta = wsp.SvecDoub(Nk); // beta[i] = norm(bar v_i)
	auto eigV = wsp.ScmatDoub(Nk, Nk); // eigen vectors
	auto vc = wsp.SvecComp(N); // temp vec
	auto bases = wsp.ScmatComp(N, Nk); // Krylov bases

	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	if (beta[0] == 0) {
		if (y.p() == x.p()) copy(y, 0);
		return 0;
	}
	times(v0, x, 1/beta[0]); 

	mul_fun(vc, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	if (beta[1] == 0) { // H*x is an exact eigen state of x
		// do y = exp(eigval*dt)*x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times(y, x, exp(eigval*dt));
	}
	v1 /= beta[1];
	mul_fun(vc, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2;
		mul_fun(v2, v1);
		Doub a = alpha[j1], b = beta[j1];
		for (Long i = 0; i < N; ++i)
			v2[i] -= a * v1[i] + b * v0[i];
		beta[j2] = norm(v2);
#ifndef NDEBUG
		if (beta[j2] == 0)
			SLS_ERR("exp_Hdt_v_lanc(): input H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		v2 /= beta[j2];
		mul_fun(vc, v2);
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

// required workspace: sizeof(Qdoub)*((2*N+Nk)*(Nk+1)+Nk)+4*align
template <class Tmul>
inline Qdoub exp_Hdt_v_lanc(VecQcomp_O y, Tmul &mul_fun, VecQcomp_I x, Qdoub_I dt, Long_I Nkrylov, WorkSpace &wsp)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N) SLS_ERR("Nk > N !");
#endif
	auto alpha = wsp.SvecQdoub(Nk); // alpha[i] = <v_i|H|v_i>
	auto beta = wsp.SvecQdoub(Nk); // beta[i] = norm(bar v_i)
	auto eigV = wsp.ScmatQdoub(Nk, Nk); // eigen vectors
	auto vc = wsp.SvecQcomp(N); // temp vec
	auto bases = wsp.ScmatQcomp(N, Nk); // Krylov bases

	SvecQcomp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	if (beta[0] == 0) {
		if (y.p() == x.p()) copy(y, 0);
		return 0;
	}
	times(v0, x, 1/beta[0]); 

	mul_fun(vc, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	if (beta[1] == 0) { // H*x is an exact eigen state of x
		// do y = exp(eigval*dt)*x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times(y, x, exp(eigval*dt));
	}
	v1 /= beta[1];
	mul_fun(vc, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2;
		mul_fun(v2, v1);
		Qdoub a = alpha[j1], b = beta[j1];
		for (Long i = 0; i < N; ++i)
			v2[i] -= a * v1[i] + b * v0[i];
		beta[j2] = norm(v2);
#ifndef NDEBUG
		if (beta[j2] == 0)
			SLS_ERR("exp_Hdt_v_lanc(): input H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		v2 /= beta[j2];
		mul_fun(vc, v2);
		alpha[j2] = real(dot(v2, vc));
		v0.next(); v1.next(); v2.next();
	}
	Qdoub err = prod(beta);

#ifdef SLS_USE_MPLAPACK
	mplapackint info;
	Rstev("V", Nk, alpha.p(), beta.p()+1, eigV.p(), Nk, wsp.pQdoub(Nk), info);
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

// required workspace: sizeof(Doub)*((2*N+Nk)*(Nk+1)+Nk)+4*align
template <class Tmul>
inline Doub exp_Hdt_v_lanc(SvecComp_O y, Tmul &mul_fun, SvecComp_I x, Doub_I dt, Long_I Nkrylov, WorkSpace &wsp)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N) SLS_ERR("Nk > N !");
#endif
	auto alpha = wsp.SvecDoub(Nk); // alpha[i] = <v_i|H|v_i>
	auto beta = wsp.SvecDoub(Nk); // beta[i] = norm(bar v_i)
	auto eigV = wsp.ScmatDoub(Nk, Nk); // eigen vectors
	auto vc = wsp.SvecComp(N); // temp vec
	auto bases = wsp.ScmatComp(N, Nk); // Krylov bases

	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	if (beta[0] == 0) {
		if (y.p() == x.p()) copy(y, 0);
		return 0;
	}
	times(v0, x, 1/beta[0]); 

	mul_fun(vc, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	if (beta[1] == 0) { // H*x is an exact eigen state of x
		// do y = exp(eigval*dt)*x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times(y, x, exp(eigval*dt));
	}
	v1 /= beta[1];
	mul_fun(vc, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2;
		mul_fun(v2, v1);
		Doub a = alpha[j1], b = beta[j1];
		for (Long i = 0; i < N; ++i)
			v2[i] -= a * v1[i] + b * v0[i];
		beta[j2] = norm(v2);
#ifndef NDEBUG
		if (beta[j2] == 0)
			SLS_ERR("exp_Hdt_v_lanc(): input H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		v2 /= beta[j2];
		mul_fun(vc, v2);
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

// required workspace: sizeof(Qdoub)*((2*N+Nk)*(Nk+1)+Nk)+4*align
template <class Tmul>
inline Qdoub exp_Hdt_v_lanc(SvecQcomp_O y, Tmul &mul_fun, SvecQcomp_I x, Qdoub_I dt, Long_I Nkrylov, WorkSpace &wsp)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N) SLS_ERR("Nk > N !");
#endif
	auto alpha = wsp.SvecQdoub(Nk); // alpha[i] = <v_i|H|v_i>
	auto beta = wsp.SvecQdoub(Nk); // beta[i] = norm(bar v_i)
	auto eigV = wsp.ScmatQdoub(Nk, Nk); // eigen vectors
	auto vc = wsp.SvecQcomp(N); // temp vec
	auto bases = wsp.ScmatQcomp(N, Nk); // Krylov bases

	SvecQcomp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	if (beta[0] == 0) {
		if (y.p() == x.p()) copy(y, 0);
		return 0;
	}
	times(v0, x, 1/beta[0]); 

	mul_fun(vc, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	if (beta[1] == 0) { // H*x is an exact eigen state of x
		// do y = exp(eigval*dt)*x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times(y, x, exp(eigval*dt));
	}
	v1 /= beta[1];
	mul_fun(vc, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2;
		mul_fun(v2, v1);
		Qdoub a = alpha[j1], b = beta[j1];
		for (Long i = 0; i < N; ++i)
			v2[i] -= a * v1[i] + b * v0[i];
		beta[j2] = norm(v2);
#ifndef NDEBUG
		if (beta[j2] == 0)
			SLS_ERR("exp_Hdt_v_lanc(): input H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		v2 /= beta[j2];
		mul_fun(vc, v2);
		alpha[j2] = real(dot(v2, vc));
		v0.next(); v1.next(); v2.next();
	}
	Qdoub err = prod(beta);

#ifdef SLS_USE_MPLAPACK
	mplapackint info;
	Rstev("V", Nk, alpha.p(), beta.p()+1, eigV.p(), Nk, wsp.pQdoub(Nk), info);
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

// required workspace: sizeof(Doub)*((2*N+Nk)*(Nk+1)+Nk)+4*align
template <class Tmul>
inline Doub exp_Hdt_v_lanc(DvecComp_O y, Tmul &mul_fun, DvecComp_I x, Doub_I dt, Long_I Nkrylov, WorkSpace &wsp)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N) SLS_ERR("Nk > N !");
#endif
	auto alpha = wsp.SvecDoub(Nk); // alpha[i] = <v_i|H|v_i>
	auto beta = wsp.SvecDoub(Nk); // beta[i] = norm(bar v_i)
	auto eigV = wsp.ScmatDoub(Nk, Nk); // eigen vectors
	auto vc = wsp.SvecComp(N); // temp vec
	auto bases = wsp.ScmatComp(N, Nk); // Krylov bases

	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	if (beta[0] == 0) {
		if (y.p() == x.p()) copy(y, 0);
		return 0;
	}
	times(v0, x, 1/beta[0]); 

	mul_fun(vc, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	if (beta[1] == 0) { // H*x is an exact eigen state of x
		// do y = exp(eigval*dt)*x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times(y, x, exp(eigval*dt));
	}
	v1 /= beta[1];
	mul_fun(vc, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2;
		mul_fun(v2, v1);
		Doub a = alpha[j1], b = beta[j1];
		for (Long i = 0; i < N; ++i)
			v2[i] -= a * v1[i] + b * v0[i];
		beta[j2] = norm(v2);
#ifndef NDEBUG
		if (beta[j2] == 0)
			SLS_ERR("exp_Hdt_v_lanc(): input H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		v2 /= beta[j2];
		mul_fun(vc, v2);
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

// required workspace: sizeof(Qdoub)*((2*N+Nk)*(Nk+1)+Nk)+4*align
template <class Tmul>
inline Qdoub exp_Hdt_v_lanc(DvecQcomp_O y, Tmul &mul_fun, DvecQcomp_I x, Qdoub_I dt, Long_I Nkrylov, WorkSpace &wsp)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N) SLS_ERR("Nk > N !");
#endif
	auto alpha = wsp.SvecQdoub(Nk); // alpha[i] = <v_i|H|v_i>
	auto beta = wsp.SvecQdoub(Nk); // beta[i] = norm(bar v_i)
	auto eigV = wsp.ScmatQdoub(Nk, Nk); // eigen vectors
	auto vc = wsp.SvecQcomp(N); // temp vec
	auto bases = wsp.ScmatQcomp(N, Nk); // Krylov bases

	SvecQcomp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	if (beta[0] == 0) {
		if (y.p() == x.p()) copy(y, 0);
		return 0;
	}
	times(v0, x, 1/beta[0]); 

	mul_fun(vc, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	if (beta[1] == 0) { // H*x is an exact eigen state of x
		// do y = exp(eigval*dt)*x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times(y, x, exp(eigval*dt));
	}
	v1 /= beta[1];
	mul_fun(vc, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2;
		mul_fun(v2, v1);
		Qdoub a = alpha[j1], b = beta[j1];
		for (Long i = 0; i < N; ++i)
			v2[i] -= a * v1[i] + b * v0[i];
		beta[j2] = norm(v2);
#ifndef NDEBUG
		if (beta[j2] == 0)
			SLS_ERR("exp_Hdt_v_lanc(): input H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		v2 /= beta[j2];
		mul_fun(vc, v2);
		alpha[j2] = real(dot(v2, vc));
		v0.next(); v1.next(); v2.next();
	}
	Qdoub err = prod(beta);

#ifdef SLS_USE_MPLAPACK
	mplapackint info;
	Rstev("V", Nk, alpha.p(), beta.p()+1, eigV.p(), Nk, wsp.pQdoub(Nk), info);
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


// bytes of workspace required
inline Long exp_miHdt_v_lanc_Comp_Nwsp(Long_I N, Long_I Nk) {
	return sizeof(Doub)*((2*N+Nk)*(Nk+1)+3*Nk)+5*(SLS_WSP_ALIGN-1);
}

// calculate y = exp(-i*H*dt) * x
// x, y can be the same object
// mul_fun(y, x) performs y = H*x, where H is a hermitian matrix
// return error
// required workspace: sizeof(Doub)*((2*N+Nk)*(Nk+1)+3*Nk)+5*align
template <class Tmul>
inline Doub exp_miHdt_v_lanc(DvecComp_IO y, Tmul &mul_fun, DvecComp_I x, Doub_I dt, Long_I Nkrylov, WorkSpace &wsp)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N)
		SLS_ERR("Nk > N !");
#endif

	auto alpha = wsp.SvecDoub(Nk); // alpha[i] = <v_i|H|v_i> // eq_Lanc_31
	auto beta = wsp.SvecDoub(Nk); // beta[i] = norm(bar v_i) // eq_Lanc_13
	auto eigV = wsp.ScmatDoub(Nk, Nk); // eigen vectors
	
	auto vc = wsp.SvecComp(N); // temp vec
	auto vc1 = wsp.SvecComp(Nk); // temp vec
	auto bases = wsp.ScmatComp(N, Nk); // orthonormal Krylov bases eq_Lanc_7
	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	if (beta[0] == 0) {
		if (y.p() == x.p()) copy(y, 0);
		return 0;
	}
	times(v0, x, 1/beta[0]);
	mul_fun(vc, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	if (beta[1] == 0) { // H*x is an exact eigen state of x
		// do y = exp(-i*eigval*dt)*x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times(y, x, exp(Comp(0, -eigval*dt)));
	}
	v1 /= beta[1];
	mul_fun(vc, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2;
		mul_fun(v2, v1);
		Doub a = alpha[j1], b = beta[j1];
		for (Long i = 0; i < N; ++i)
		v2[i] -= a * v1[i] + b * v0[i];
		beta[j2] = norm(v2);
#ifndef NDEBUG
		if (beta[j2] == 0)
			SLS_ERR("exp_miHdt_v_lanc(): H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		v2 /= beta[j2];
		mul_fun(vc, v2);
		alpha[j2] = real(dot(v2, vc));
		v0.next(); v1.next(); v2.next();
	}
	Doub err = prod(beta);
	lapack_int info =
	LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p()+1, eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0)
		SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));
	SvecComp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
		vc2[i] = exp(Comp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * beta[0];
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
	return err;
}

// required workspace: sizeof(Qdoub)*((2*N+Nk)*(Nk+1)+3*Nk)+5*align
template <class Tmul>
inline Qdoub exp_miHdt_v_lanc(DvecQcomp_IO y, Tmul &mul_fun, DvecQcomp_I x, Qdoub_I dt, Long_I Nkrylov, WorkSpace &wsp)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N)
		SLS_ERR("Nk > N !");
#endif

	auto alpha = wsp.SvecQdoub(Nk); // alpha[i] = <v_i|H|v_i> // eq_Lanc_31
	auto beta = wsp.SvecQdoub(Nk); // beta[i] = norm(bar v_i) // eq_Lanc_13
	auto eigV = wsp.ScmatQdoub(Nk, Nk); // eigen vectors
	
	auto vc = wsp.SvecQcomp(N); // temp vec
	auto vc1 = wsp.SvecQcomp(Nk); // temp vec
	auto bases = wsp.ScmatQcomp(N, Nk); // orthonormal Krylov bases eq_Lanc_7
	SvecQcomp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	if (beta[0] == 0) {
		if (y.p() == x.p()) copy(y, 0);
		return 0;
	}
	times(v0, x, 1/beta[0]);
	mul_fun(vc, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	if (beta[1] == 0) { // H*x is an exact eigen state of x
		// do y = exp(-i*eigval*dt)*x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times(y, x, exp(Comp(0, -eigval*dt)));
	}
	v1 /= beta[1];
	mul_fun(vc, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2;
		mul_fun(v2, v1);
		Qdoub a = alpha[j1], b = beta[j1];
		for (Long i = 0; i < N; ++i)
		v2[i] -= a * v1[i] + b * v0[i];
		beta[j2] = norm(v2);
#ifndef NDEBUG
		if (beta[j2] == 0)
			SLS_ERR("exp_miHdt_v_lanc(): H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		v2 /= beta[j2];
		mul_fun(vc, v2);
		alpha[j2] = real(dot(v2, vc));
		v0.next(); v1.next(); v2.next();
	}
	Qdoub err = prod(beta);
#ifdef SLS_USE_MPLAPACK
	mplapackint info;
	// alpha is now eigen values
	Rstev("V", Nk, alpha.p(), beta.p()+1, eigV.p(), Nk, wsp.pQdoub(Nk), info);
	if (info != 0)
		SLS_ERR("something wrong with Rstev: return = " + num2str((Long)info));
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

// required workspace: sizeof(Doub)*((2*N+Nk)*(Nk+1)+3*Nk)+5*align
template <class Tmul>
inline Doub exp_miHdt_v_lanc(VecComp_IO y, Tmul &mul_fun, VecComp_I x, Doub_I dt, Long_I Nkrylov, WorkSpace &wsp)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N)
		SLS_ERR("Nk > N !");
#endif

	auto alpha = wsp.SvecDoub(Nk); // alpha[i] = <v_i|H|v_i> // eq_Lanc_31
	auto beta = wsp.SvecDoub(Nk); // beta[i] = norm(bar v_i) // eq_Lanc_13
	auto eigV = wsp.ScmatDoub(Nk, Nk); // eigen vectors
	
	auto vc = wsp.SvecComp(N); // temp vec
	auto vc1 = wsp.SvecComp(Nk); // temp vec
	auto bases = wsp.ScmatComp(N, Nk); // orthonormal Krylov bases eq_Lanc_7
	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	if (beta[0] == 0) {
		if (y.p() == x.p()) copy(y, 0);
		return 0;
	}
	times(v0, x, 1/beta[0]);
	mul_fun(vc, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	if (beta[1] == 0) { // H*x is an exact eigen state of x
		// do y = exp(-i*eigval*dt)*x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times(y, x, exp(Comp(0, -eigval*dt)));
	}
	v1 /= beta[1];
	mul_fun(vc, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2;
		mul_fun(v2, v1);
		Doub a = alpha[j1], b = beta[j1];
		for (Long i = 0; i < N; ++i)
		v2[i] -= a * v1[i] + b * v0[i];
		beta[j2] = norm(v2);
#ifndef NDEBUG
		if (beta[j2] == 0)
			SLS_ERR("exp_miHdt_v_lanc(): H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		v2 /= beta[j2];
		mul_fun(vc, v2);
		alpha[j2] = real(dot(v2, vc));
		v0.next(); v1.next(); v2.next();
	}
	Doub err = prod(beta);
	lapack_int info =
	LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p()+1, eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0)
		SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));
	SvecComp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
		vc2[i] = exp(Comp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * beta[0];
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
	return err;
}

// required workspace: sizeof(Qdoub)*((2*N+Nk)*(Nk+1)+3*Nk)+5*align
template <class Tmul>
inline Qdoub exp_miHdt_v_lanc(VecQcomp_IO y, Tmul &mul_fun, VecQcomp_I x, Qdoub_I dt, Long_I Nkrylov, WorkSpace &wsp)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N)
		SLS_ERR("Nk > N !");
#endif

	auto alpha = wsp.SvecQdoub(Nk); // alpha[i] = <v_i|H|v_i> // eq_Lanc_31
	auto beta = wsp.SvecQdoub(Nk); // beta[i] = norm(bar v_i) // eq_Lanc_13
	auto eigV = wsp.ScmatQdoub(Nk, Nk); // eigen vectors
	
	auto vc = wsp.SvecQcomp(N); // temp vec
	auto vc1 = wsp.SvecQcomp(Nk); // temp vec
	auto bases = wsp.ScmatQcomp(N, Nk); // orthonormal Krylov bases eq_Lanc_7
	SvecQcomp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	if (beta[0] == 0) {
		if (y.p() == x.p()) copy(y, 0);
		return 0;
	}
	times(v0, x, 1/beta[0]);
	mul_fun(vc, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	if (beta[1] == 0) { // H*x is an exact eigen state of x
		// do y = exp(-i*eigval*dt)*x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times(y, x, exp(Comp(0, -eigval*dt)));
	}
	v1 /= beta[1];
	mul_fun(vc, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2;
		mul_fun(v2, v1);
		Qdoub a = alpha[j1], b = beta[j1];
		for (Long i = 0; i < N; ++i)
		v2[i] -= a * v1[i] + b * v0[i];
		beta[j2] = norm(v2);
#ifndef NDEBUG
		if (beta[j2] == 0)
			SLS_ERR("exp_miHdt_v_lanc(): H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		v2 /= beta[j2];
		mul_fun(vc, v2);
		alpha[j2] = real(dot(v2, vc));
		v0.next(); v1.next(); v2.next();
	}
	Qdoub err = prod(beta);
#ifdef SLS_USE_MPLAPACK
	mplapackint info;
	// alpha is now eigen values
	Rstev("V", Nk, alpha.p(), beta.p()+1, eigV.p(), Nk, wsp.pQdoub(Nk), info);
	if (info != 0)
		SLS_ERR("something wrong with Rstev: return = " + num2str((Long)info));
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

// required workspace: sizeof(Doub)*((2*N+Nk)*(Nk+1)+3*Nk)+5*align
template <class Tmul>
inline Doub exp_miHdt_v_lanc(SvecComp_IO y, Tmul &mul_fun, SvecComp_I x, Doub_I dt, Long_I Nkrylov, WorkSpace &wsp)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N)
		SLS_ERR("Nk > N !");
#endif

	auto alpha = wsp.SvecDoub(Nk); // alpha[i] = <v_i|H|v_i> // eq_Lanc_31
	auto beta = wsp.SvecDoub(Nk); // beta[i] = norm(bar v_i) // eq_Lanc_13
	auto eigV = wsp.ScmatDoub(Nk, Nk); // eigen vectors
	
	auto vc = wsp.SvecComp(N); // temp vec
	auto vc1 = wsp.SvecComp(Nk); // temp vec
	auto bases = wsp.ScmatComp(N, Nk); // orthonormal Krylov bases eq_Lanc_7
	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	if (beta[0] == 0) {
		if (y.p() == x.p()) copy(y, 0);
		return 0;
	}
	times(v0, x, 1/beta[0]);
	mul_fun(vc, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	if (beta[1] == 0) { // H*x is an exact eigen state of x
		// do y = exp(-i*eigval*dt)*x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times(y, x, exp(Comp(0, -eigval*dt)));
	}
	v1 /= beta[1];
	mul_fun(vc, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2;
		mul_fun(v2, v1);
		Doub a = alpha[j1], b = beta[j1];
		for (Long i = 0; i < N; ++i)
		v2[i] -= a * v1[i] + b * v0[i];
		beta[j2] = norm(v2);
#ifndef NDEBUG
		if (beta[j2] == 0)
			SLS_ERR("exp_miHdt_v_lanc(): H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		v2 /= beta[j2];
		mul_fun(vc, v2);
		alpha[j2] = real(dot(v2, vc));
		v0.next(); v1.next(); v2.next();
	}
	Doub err = prod(beta);
	lapack_int info =
	LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p()+1, eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0)
		SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));
	SvecComp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
		vc2[i] = exp(Comp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * beta[0];
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
	return err;
}

// required workspace: sizeof(Qdoub)*((2*N+Nk)*(Nk+1)+3*Nk)+5*align
template <class Tmul>
inline Qdoub exp_miHdt_v_lanc(SvecQcomp_IO y, Tmul &mul_fun, SvecQcomp_I x, Qdoub_I dt, Long_I Nkrylov, WorkSpace &wsp)
{
	Long N = x.size(), Nk = Nkrylov;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N)
		SLS_ERR("Nk > N !");
#endif

	auto alpha = wsp.SvecQdoub(Nk); // alpha[i] = <v_i|H|v_i> // eq_Lanc_31
	auto beta = wsp.SvecQdoub(Nk); // beta[i] = norm(bar v_i) // eq_Lanc_13
	auto eigV = wsp.ScmatQdoub(Nk, Nk); // eigen vectors
	
	auto vc = wsp.SvecQcomp(N); // temp vec
	auto vc1 = wsp.SvecQcomp(Nk); // temp vec
	auto bases = wsp.ScmatQcomp(N, Nk); // orthonormal Krylov bases eq_Lanc_7
	SvecQcomp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	beta[0] = norm(x);
	if (beta[0] == 0) {
		if (y.p() == x.p()) copy(y, 0);
		return 0;
	}
	times(v0, x, 1/beta[0]);
	mul_fun(vc, v0);
	alpha[0] = real(dot(v0, vc));
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[1] = norm(v1);
	if (beta[1] == 0) { // H*x is an exact eigen state of x
		// do y = exp(-i*eigval*dt)*x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times(y, x, exp(Comp(0, -eigval*dt)));
	}
	v1 /= beta[1];
	mul_fun(vc, v1);
	alpha[1] = real(dot(v1, vc));

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2;
		mul_fun(v2, v1);
		Qdoub a = alpha[j1], b = beta[j1];
		for (Long i = 0; i < N; ++i)
		v2[i] -= a * v1[i] + b * v0[i];
		beta[j2] = norm(v2);
#ifndef NDEBUG
		if (beta[j2] == 0)
			SLS_ERR("exp_miHdt_v_lanc(): H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		v2 /= beta[j2];
		mul_fun(vc, v2);
		alpha[j2] = real(dot(v2, vc));
		v0.next(); v1.next(); v2.next();
	}
	Qdoub err = prod(beta);
#ifdef SLS_USE_MPLAPACK
	mplapackint info;
	// alpha is now eigen values
	Rstev("V", Nk, alpha.p(), beta.p()+1, eigV.p(), Nk, wsp.pQdoub(Nk), info);
	if (info != 0)
		SLS_ERR("something wrong with Rstev: return = " + num2str((Long)info));
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
