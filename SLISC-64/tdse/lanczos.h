// lanczos algorithm to propagate wave function by exp(-iH dt)
// for error estimation of using Nk-1 basis (not Nk basis!) see 4.51 of Johannes Feist's thesis: prod(beta)/(Nk-1)!*dt^(Nk-1)

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
template <class Treal>
inline Long exp_Hdt_v_lanc_Nwsp(Long_I N, Long_I Nk) {
	return sizeof(Treal)*((2*N+Nk)*(Nk+1)+Nk)+4*(SLS_WSP_ALIGN-1);
}

template <class Treal>
inline Long exp_miHdt_v_lanc_Nwsp(Long_I N, Long_I Nk) {
	return sizeof(Treal)*((2*N+Nk)*(Nk+1)+3*Nk)+5*(SLS_WSP_ALIGN-1);
}

// calculate y = exp(H*dt) * x or y = exp(-i*H*dt) * x
// ref: https://wuli.wiki/online/Lanc.html
// x, y can be the same object
// mul_fun(y, x) performs y = H*x, where H is a hermitian matrix
// to save time, only beta inside the tridiag matrix is calculated, return error estimation as the product of (Nkrylov-1) beta. Which is actually the error if only (Nkrylov-1) bases are used.
// exp_Hdt_v_lanc_par() is the parallel version, but will not call `mul_fun` in parallel region
// when `err_max` is positive, iteration will be terminated if `error < err_max` and a smaller Nk will be used
template <class Tmul>
inline Doub exp_Hdt_v_lanc(Long_O Nk_used, SvbaseComp_O y, Tmul &mul_fun, SvbaseComp_I x, Doub_I dt, Long_I Nkrylov, WorkSpace &wsp, Doub_I err_max=0)
{
	Long N = x.size(), Nk = Nkrylov, Nk_min = 6;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N) SLS_ERR("Nk > N !");
#endif
    // error estimation if only Nk-1 basis is used
	auto alpha = wsp.SvecDoub(Nk); // alpha[i] = <v_i|H|v_i> // eq_Lanc_31
	auto beta = wsp.SvecDoub(Nk); // beta[0] is actually beta_1 in eq_Lanc_2 (the first beta in tridiag matrix), last elem is only used as workspace.
	auto eigV = wsp.ScmatDoub(Nk, Nk); // eigen vectors
	auto vc = wsp.SvecComp(N); // temp vec
	auto bases = wsp.ScmatComp(N, Nk); // orthonormal Krylov bases eq_Lanc_7

	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	Doub norm_x = norm(x);
	if (norm_x == 0) {
		if (y.p() == x.p()) copy(y, 0);
		Nk_used = 0;
		return 0;
	}
	times(v0, x, 1/norm_x);

	mul_fun(vc, v0);
	alpha[0] = dot_real(v0, vc);
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[0] = norm(v1);
	if (beta[0] == 0) { // H*x is an exact eigen state of x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times(y, x, exp(eigval*dt)); // y[i] = exp(eigval[i]*dt)*x[i]
        Nk_used = 1;
		return 0;
	}
	Doub err = dt*beta[0];
	v1 /= beta[0];
	mul_fun(vc, v1);
	alpha[1] = dot_real(v1, vc);

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2, j3 = j+3;
		mul_fun(v2, v1);
		Doub a = alpha[j1], b = beta[j];
		for (Long i = 0; i < N; ++i)
			v2[i] -= a * v1[i] + b * v0[i];
		beta[j1] = norm(v2);
#ifndef NDEBUG
		if (beta[j1] == 0)
			SLS_ERR("exp_Hdt_v_lanc(): H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		v2 /= beta[j1];
		mul_fun(vc, v2);
		alpha[j2] = dot_real(v2, vc);
		Doub fact = (dt*beta[j1]/j2);
		err *= fact;
		if (j3 >= Nk_min && err < err_max) {
		    Nk = j3;
		    alpha.set(alpha.p(), Nk); beta.set(beta.p(), Nk);
		    eigV.set(eigV.p(), Nk, Nk);
		    break;
		}
		v0.next(); v1.next(); v2.next();
	}

	lapack_int info =
		LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p(), eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));

	for (Long i = 0; i < Nk; ++i)
		alpha[i] = exp(alpha[i] * dt) * eigV[i*Nk] * norm_x;
	// alpha, beta are just work spaces now
	mul_gen(beta, eigV, alpha);
	mul(y, bases, beta);
    Nk_used = Nk;
	return abs(err);
}

template <class Tmul>
inline Doub exp_Hdt_v_lanc_par(Long_O Nk_used, SvbaseComp_O y, Tmul &mul_fun, SvbaseComp_I x, Doub_I dt, Long_I Nkrylov, WorkSpace &wsp, Doub_I err_max=0)
{
	Long N = x.size(), Nk = Nkrylov, Nk_min = 6;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N) SLS_ERR("Nk > N !");
#endif
    // error estimation if only Nk-1 basis is used
	auto alpha = wsp.SvecDoub(Nk); // alpha[i] = <v_i|H|v_i> // eq_Lanc_31
	auto beta = wsp.SvecDoub(Nk); // beta[0] is actually beta_1 in eq_Lanc_2 (the first beta in tridiag matrix), last elem is only used as workspace.
	auto eigV = wsp.ScmatDoub(Nk, Nk); // eigen vectors
	auto vc = wsp.SvecComp(N); // temp vec
	auto bases = wsp.ScmatComp(N, Nk); // orthonormal Krylov bases eq_Lanc_7

	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	Doub norm_x = norm_par(x);
	if (norm_x == 0) {
		if (y.p() == x.p()) copy(y, 0);
		Nk_used = 0;
		return 0;
	}
	times_par(v0, x, 1/norm_x);

	mul_fun(vc, v0);
	alpha[0] = dot_real_par(v0, vc);
#pragma omp parallel for
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[0] = norm_par(v1);
	if (beta[0] == 0) { // H*x is an exact eigen state of x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times_par(y, x, exp(eigval*dt)); // y[i] = exp(eigval[i]*dt)*x[i]
        Nk_used = 1;
		return 0;
	}
	Doub err = dt*beta[0];
	times_eq_par(v1, 1./beta[0]);
	mul_fun(vc, v1);
	alpha[1] = dot_real_par(v1, vc);

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2, j3 = j+3;
		mul_fun(v2, v1);
		Doub a = alpha[j1], b = beta[j];
#pragma omp parallel for
		for (Long i = 0; i < N; ++i)
			v2[i] -= a * v1[i] + b * v0[i];
		beta[j1] = norm_par(v2);
#ifndef NDEBUG
		if (beta[j1] == 0)
			SLS_ERR("exp_Hdt_v_lanc(): H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		times_eq_par(v2, 1./beta[j1]);
		mul_fun(vc, v2);
		alpha[j2] = dot_real_par(v2, vc);
		Doub fact = (dt*beta[j1]/j2);
		err *= fact;
		if (j3 >= Nk_min && err < err_max) {
		    Nk = j3;
		    alpha.set(alpha.p(), Nk); beta.set(beta.p(), Nk);
		    eigV.set(eigV.p(), Nk, Nk);
		    break;
		}
		v0.next(); v1.next(); v2.next();
	}

	lapack_int info =
		LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p(), eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));

	for (Long i = 0; i < Nk; ++i)
		alpha[i] = exp(alpha[i] * dt) * eigV[i*Nk] * norm_x;
	// alpha, beta are just work spaces now
	mul_gen(beta, eigV, alpha);
	mul(y, bases, beta);
    Nk_used = Nk;
	return abs(err);
}


template <class Tmul>
inline Doub exp_Hdt_v_lanc(Long_O Nk_used, DvecComp_O y, Tmul &mul_fun, DvecComp_I x, Doub_I dt, Long_I Nkrylov, WorkSpace &wsp, Doub_I err_max=0)
{
	Long N = x.size(), Nk = Nkrylov, Nk_min = 6;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N) SLS_ERR("Nk > N !");
#endif
    // error estimation if only Nk-1 basis is used
	auto alpha = wsp.SvecDoub(Nk); // alpha[i] = <v_i|H|v_i> // eq_Lanc_31
	auto beta = wsp.SvecDoub(Nk); // beta[0] is actually beta_1 in eq_Lanc_2 (the first beta in tridiag matrix), last elem is only used as workspace.
	auto eigV = wsp.ScmatDoub(Nk, Nk); // eigen vectors
	auto vc = wsp.SvecComp(N); // temp vec
	auto bases = wsp.ScmatComp(N, Nk); // orthonormal Krylov bases eq_Lanc_7

	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	Doub norm_x = norm(x);
	if (norm_x == 0) {
		if (y.p() == x.p()) copy(y, 0);
		Nk_used = 0;
		return 0;
	}
	times(v0, x, 1/norm_x);

	mul_fun(vc, v0);
	alpha[0] = dot_real(v0, vc);
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[0] = norm(v1);
	if (beta[0] == 0) { // H*x is an exact eigen state of x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times(y, x, exp(eigval*dt)); // y[i] = exp(eigval[i]*dt)*x[i]
        Nk_used = 1;
		return 0;
	}
	Doub err = dt*beta[0];
	v1 /= beta[0];
	mul_fun(vc, v1);
	alpha[1] = dot_real(v1, vc);

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2, j3 = j+3;
		mul_fun(v2, v1);
		Doub a = alpha[j1], b = beta[j];
		for (Long i = 0; i < N; ++i)
			v2[i] -= a * v1[i] + b * v0[i];
		beta[j1] = norm(v2);
#ifndef NDEBUG
		if (beta[j1] == 0)
			SLS_ERR("exp_Hdt_v_lanc(): H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		v2 /= beta[j1];
		mul_fun(vc, v2);
		alpha[j2] = dot_real(v2, vc);
		Doub fact = (dt*beta[j1]/j2);
		err *= fact;
		if (j3 >= Nk_min && err < err_max) {
		    Nk = j3;
		    alpha.set(alpha.p(), Nk); beta.set(beta.p(), Nk);
		    eigV.set(eigV.p(), Nk, Nk);
		    break;
		}
		v0.next(); v1.next(); v2.next();
	}

	lapack_int info =
		LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p(), eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));

	for (Long i = 0; i < Nk; ++i)
		alpha[i] = exp(alpha[i] * dt) * eigV[i*Nk] * norm_x;
	// alpha, beta are just work spaces now
	mul_gen(beta, eigV, alpha);
	mul(y, bases, beta);
    Nk_used = Nk;
	return abs(err);
}

template <class Tmul>
inline Doub exp_Hdt_v_lanc_par(Long_O Nk_used, DvecComp_O y, Tmul &mul_fun, DvecComp_I x, Doub_I dt, Long_I Nkrylov, WorkSpace &wsp, Doub_I err_max=0)
{
	Long N = x.size(), Nk = Nkrylov, Nk_min = 6;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N) SLS_ERR("Nk > N !");
#endif
    // error estimation if only Nk-1 basis is used
	auto alpha = wsp.SvecDoub(Nk); // alpha[i] = <v_i|H|v_i> // eq_Lanc_31
	auto beta = wsp.SvecDoub(Nk); // beta[0] is actually beta_1 in eq_Lanc_2 (the first beta in tridiag matrix), last elem is only used as workspace.
	auto eigV = wsp.ScmatDoub(Nk, Nk); // eigen vectors
	auto vc = wsp.SvecComp(N); // temp vec
	auto bases = wsp.ScmatComp(N, Nk); // orthonormal Krylov bases eq_Lanc_7

	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	Doub norm_x = norm_par(x);
	if (norm_x == 0) {
		if (y.p() == x.p()) copy(y, 0);
		Nk_used = 0;
		return 0;
	}
	times_par(v0, x, 1/norm_x);

	mul_fun(vc, v0);
	alpha[0] = dot_real_par(v0, vc);
#pragma omp parallel for
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[0] = norm_par(v1);
	if (beta[0] == 0) { // H*x is an exact eigen state of x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times_par(y, x, exp(eigval*dt)); // y[i] = exp(eigval[i]*dt)*x[i]
        Nk_used = 1;
		return 0;
	}
	Doub err = dt*beta[0];
	times_eq_par(v1, 1./beta[0]);
	mul_fun(vc, v1);
	alpha[1] = dot_real_par(v1, vc);

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2, j3 = j+3;
		mul_fun(v2, v1);
		Doub a = alpha[j1], b = beta[j];
#pragma omp parallel for
		for (Long i = 0; i < N; ++i)
			v2[i] -= a * v1[i] + b * v0[i];
		beta[j1] = norm_par(v2);
#ifndef NDEBUG
		if (beta[j1] == 0)
			SLS_ERR("exp_Hdt_v_lanc(): H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		times_eq_par(v2, 1./beta[j1]);
		mul_fun(vc, v2);
		alpha[j2] = dot_real_par(v2, vc);
		Doub fact = (dt*beta[j1]/j2);
		err *= fact;
		if (j3 >= Nk_min && err < err_max) {
		    Nk = j3;
		    alpha.set(alpha.p(), Nk); beta.set(beta.p(), Nk);
		    eigV.set(eigV.p(), Nk, Nk);
		    break;
		}
		v0.next(); v1.next(); v2.next();
	}

	lapack_int info =
		LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p(), eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));

	for (Long i = 0; i < Nk; ++i)
		alpha[i] = exp(alpha[i] * dt) * eigV[i*Nk] * norm_x;
	// alpha, beta are just work spaces now
	mul_gen(beta, eigV, alpha);
	mul(y, bases, beta);
    Nk_used = Nk;
	return abs(err);
}


template <class Tmul>
inline Doub exp_miHdt_v_lanc(Long_O Nk_used, SvbaseComp_O y, Tmul &mul_fun, SvbaseComp_I x, Doub_I dt, Long_I Nkrylov, WorkSpace &wsp, Doub_I err_max=0)
{
	Long N = x.size(), Nk = Nkrylov, Nk_min = 6;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N) SLS_ERR("Nk > N !");
#endif
    // error estimation if only Nk-1 basis is used
	auto alpha = wsp.SvecDoub(Nk); // alpha[i] = <v_i|H|v_i> // eq_Lanc_31
	auto beta = wsp.SvecDoub(Nk); // beta[0] is actually beta_1 in eq_Lanc_2 (the first beta in tridiag matrix), last elem is only used as workspace.
	auto eigV = wsp.ScmatDoub(Nk, Nk); // eigen vectors
	auto vc = wsp.SvecComp(N); // temp vec
	auto vc1 = wsp.SvecComp(Nk); // temp vec
	auto bases = wsp.ScmatComp(N, Nk); // orthonormal Krylov bases eq_Lanc_7

	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	Doub norm_x = norm(x);
	if (norm_x == 0) {
		if (y.p() == x.p()) copy(y, 0);
		Nk_used = 0;
		return 0;
	}
	times(v0, x, 1/norm_x);

	mul_fun(vc, v0);
	alpha[0] = dot_real(v0, vc);
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[0] = norm(v1);
	if (beta[0] == 0) { // H*x is an exact eigen state of x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times(y, x, exp(Comp(0, -eigval*dt))); // y[i] = exp(-i*eigval[i]*dt)*x[i]
        Nk_used = 1;
		return 0;
	}
	Doub err = dt*beta[0];
	v1 /= beta[0];
	mul_fun(vc, v1);
	alpha[1] = dot_real(v1, vc);

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2, j3 = j+3;
		mul_fun(v2, v1);
		Doub a = alpha[j1], b = beta[j];
		for (Long i = 0; i < N; ++i)
			v2[i] -= a * v1[i] + b * v0[i];
		beta[j1] = norm(v2);
#ifndef NDEBUG
		if (beta[j1] == 0)
			SLS_ERR("exp_miHdt_v_lanc(): H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		v2 /= beta[j1];
		mul_fun(vc, v2);
		alpha[j2] = dot_real(v2, vc);
		Doub fact = (dt*beta[j1]/j2);
		err *= fact;
		if (j3 >= Nk_min && err < err_max) {
		    Nk = j3;
		    alpha.set(alpha.p(), Nk); beta.set(beta.p(), Nk);
		    vc1.set(vc1.p(), Nk);
		    eigV.set(eigV.p(), Nk, Nk);
		    break;
		}
		v0.next(); v1.next(); v2.next();
	}

	lapack_int info =
		LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p(), eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));

	SvecComp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
		vc2[i] = exp(Comp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * norm_x;
	// alpha, beta are just work spaces now
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
    Nk_used = Nk;
	return abs(err);
}

template <class Tmul>
inline Doub exp_miHdt_v_lanc_par(Long_O Nk_used, SvbaseComp_O y, Tmul &mul_fun, SvbaseComp_I x, Doub_I dt, Long_I Nkrylov, WorkSpace &wsp, Doub_I err_max=0)
{
	Long N = x.size(), Nk = Nkrylov, Nk_min = 6;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N) SLS_ERR("Nk > N !");
#endif
    // error estimation if only Nk-1 basis is used
	auto alpha = wsp.SvecDoub(Nk); // alpha[i] = <v_i|H|v_i> // eq_Lanc_31
	auto beta = wsp.SvecDoub(Nk); // beta[0] is actually beta_1 in eq_Lanc_2 (the first beta in tridiag matrix), last elem is only used as workspace.
	auto eigV = wsp.ScmatDoub(Nk, Nk); // eigen vectors
	auto vc = wsp.SvecComp(N); // temp vec
	auto vc1 = wsp.SvecComp(Nk); // temp vec
	auto bases = wsp.ScmatComp(N, Nk); // orthonormal Krylov bases eq_Lanc_7

	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	Doub norm_x = norm_par(x);
	if (norm_x == 0) {
		if (y.p() == x.p()) copy(y, 0);
		Nk_used = 0;
		return 0;
	}
	times_par(v0, x, 1/norm_x);

	mul_fun(vc, v0);
	alpha[0] = dot_real_par(v0, vc);
#pragma omp parallel for
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[0] = norm_par(v1);
	if (beta[0] == 0) { // H*x is an exact eigen state of x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times_par(y, x, exp(Comp(0, -eigval*dt))); // y[i] = exp(-i*eigval[i]*dt)*x[i]
        Nk_used = 1;
		return 0;
	}
	Doub err = dt*beta[0];
	times_eq_par(v1, 1./beta[0]);
	mul_fun(vc, v1);
	alpha[1] = dot_real_par(v1, vc);

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2, j3 = j+3;
		mul_fun(v2, v1);
		Doub a = alpha[j1], b = beta[j];
#pragma omp parallel for
		for (Long i = 0; i < N; ++i)
			v2[i] -= a * v1[i] + b * v0[i];
		beta[j1] = norm_par(v2);
#ifndef NDEBUG
		if (beta[j1] == 0)
			SLS_ERR("exp_miHdt_v_lanc(): H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		times_eq_par(v2, 1./beta[j1]);
		mul_fun(vc, v2);
		alpha[j2] = dot_real_par(v2, vc);
		Doub fact = (dt*beta[j1]/j2);
		err *= fact;
		if (j3 >= Nk_min && err < err_max) {
		    Nk = j3;
		    alpha.set(alpha.p(), Nk); beta.set(beta.p(), Nk);
		    vc1.set(vc1.p(), Nk);
		    eigV.set(eigV.p(), Nk, Nk);
		    break;
		}
		v0.next(); v1.next(); v2.next();
	}

	lapack_int info =
		LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p(), eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));

	SvecComp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
		vc2[i] = exp(Comp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * norm_x;
	// alpha, beta are just work spaces now
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
    Nk_used = Nk;
	return abs(err);
}


template <class Tmul>
inline Doub exp_miHdt_v_lanc(Long_O Nk_used, DvecComp_O y, Tmul &mul_fun, DvecComp_I x, Doub_I dt, Long_I Nkrylov, WorkSpace &wsp, Doub_I err_max=0)
{
	Long N = x.size(), Nk = Nkrylov, Nk_min = 6;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N) SLS_ERR("Nk > N !");
#endif
    // error estimation if only Nk-1 basis is used
	auto alpha = wsp.SvecDoub(Nk); // alpha[i] = <v_i|H|v_i> // eq_Lanc_31
	auto beta = wsp.SvecDoub(Nk); // beta[0] is actually beta_1 in eq_Lanc_2 (the first beta in tridiag matrix), last elem is only used as workspace.
	auto eigV = wsp.ScmatDoub(Nk, Nk); // eigen vectors
	auto vc = wsp.SvecComp(N); // temp vec
	auto vc1 = wsp.SvecComp(Nk); // temp vec
	auto bases = wsp.ScmatComp(N, Nk); // orthonormal Krylov bases eq_Lanc_7

	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	Doub norm_x = norm(x);
	if (norm_x == 0) {
		if (y.p() == x.p()) copy(y, 0);
		Nk_used = 0;
		return 0;
	}
	times(v0, x, 1/norm_x);

	mul_fun(vc, v0);
	alpha[0] = dot_real(v0, vc);
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[0] = norm(v1);
	if (beta[0] == 0) { // H*x is an exact eigen state of x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times(y, x, exp(Comp(0, -eigval*dt))); // y[i] = exp(-i*eigval[i]*dt)*x[i]
        Nk_used = 1;
		return 0;
	}
	Doub err = dt*beta[0];
	v1 /= beta[0];
	mul_fun(vc, v1);
	alpha[1] = dot_real(v1, vc);

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2, j3 = j+3;
		mul_fun(v2, v1);
		Doub a = alpha[j1], b = beta[j];
		for (Long i = 0; i < N; ++i)
			v2[i] -= a * v1[i] + b * v0[i];
		beta[j1] = norm(v2);
#ifndef NDEBUG
		if (beta[j1] == 0)
			SLS_ERR("exp_miHdt_v_lanc(): H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		v2 /= beta[j1];
		mul_fun(vc, v2);
		alpha[j2] = dot_real(v2, vc);
		Doub fact = (dt*beta[j1]/j2);
		err *= fact;
		if (j3 >= Nk_min && err < err_max) {
		    Nk = j3;
		    alpha.set(alpha.p(), Nk); beta.set(beta.p(), Nk);
		    vc1.set(vc1.p(), Nk);
		    eigV.set(eigV.p(), Nk, Nk);
		    break;
		}
		v0.next(); v1.next(); v2.next();
	}

	lapack_int info =
		LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p(), eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));

	SvecComp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
		vc2[i] = exp(Comp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * norm_x;
	// alpha, beta are just work spaces now
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
    Nk_used = Nk;
	return abs(err);
}

template <class Tmul>
inline Doub exp_miHdt_v_lanc_par(Long_O Nk_used, DvecComp_O y, Tmul &mul_fun, DvecComp_I x, Doub_I dt, Long_I Nkrylov, WorkSpace &wsp, Doub_I err_max=0)
{
	Long N = x.size(), Nk = Nkrylov, Nk_min = 6;
#ifdef SLS_CHECK_SHAPES
	if (Nk > N) SLS_ERR("Nk > N !");
#endif
    // error estimation if only Nk-1 basis is used
	auto alpha = wsp.SvecDoub(Nk); // alpha[i] = <v_i|H|v_i> // eq_Lanc_31
	auto beta = wsp.SvecDoub(Nk); // beta[0] is actually beta_1 in eq_Lanc_2 (the first beta in tridiag matrix), last elem is only used as workspace.
	auto eigV = wsp.ScmatDoub(Nk, Nk); // eigen vectors
	auto vc = wsp.SvecComp(N); // temp vec
	auto vc1 = wsp.SvecComp(Nk); // temp vec
	auto bases = wsp.ScmatComp(N, Nk); // orthonormal Krylov bases eq_Lanc_7

	SvecComp v0 = cut0(bases, 0), v1 = cut0(bases, 1), v2 = cut0(bases, 2);
	Doub norm_x = norm_par(x);
	if (norm_x == 0) {
		if (y.p() == x.p()) copy(y, 0);
		Nk_used = 0;
		return 0;
	}
	times_par(v0, x, 1/norm_x);

	mul_fun(vc, v0);
	alpha[0] = dot_real_par(v0, vc);
#pragma omp parallel for
	for (Long i = 0; i < N; ++i)
		v1[i] = vc[i] - alpha[0] * v0[i];
	beta[0] = norm_par(v1);
	if (beta[0] == 0) { // H*x is an exact eigen state of x
		Long ind;
		max_abs(ind, vc);
		Doub eigval = real(vc[ind] / v0[ind]);
		times_par(y, x, exp(Comp(0, -eigval*dt))); // y[i] = exp(-i*eigval[i]*dt)*x[i]
        Nk_used = 1;
		return 0;
	}
	Doub err = dt*beta[0];
	times_eq_par(v1, 1./beta[0]);
	mul_fun(vc, v1);
	alpha[1] = dot_real_par(v1, vc);

	for (Long j = 0; j < Nk-2; ++j) {
		Long j1 = j+1, j2 = j+2, j3 = j+3;
		mul_fun(v2, v1);
		Doub a = alpha[j1], b = beta[j];
#pragma omp parallel for
		for (Long i = 0; i < N; ++i)
			v2[i] -= a * v1[i] + b * v0[i];
		beta[j1] = norm_par(v2);
#ifndef NDEBUG
		if (beta[j1] == 0)
			SLS_ERR("exp_miHdt_v_lanc(): H^" + num2str(j2) + "*x is linearly dependent!");
#endif
		times_eq_par(v2, 1./beta[j1]);
		mul_fun(vc, v2);
		alpha[j2] = dot_real_par(v2, vc);
		Doub fact = (dt*beta[j1]/j2);
		err *= fact;
		if (j3 >= Nk_min && err < err_max) {
		    Nk = j3;
		    alpha.set(alpha.p(), Nk); beta.set(beta.p(), Nk);
		    vc1.set(vc1.p(), Nk);
		    eigV.set(eigV.p(), Nk, Nk);
		    break;
		}
		v0.next(); v1.next(); v2.next();
	}

	lapack_int info =
		LAPACKE_dstev(LAPACK_COL_MAJOR, 'V', Nk, alpha.p(), beta.p(), eigV.p(), Nk);
	// alpha is now eigen values
	if (info != 0) SLS_ERR("something wrong with LAPACKE_dstev: return = " + num2str(info));

	SvecComp vc2 = cut(vc, 0, Nk);
	for (Long i = 0; i < Nk; ++i)
		vc2[i] = exp(Comp(0,-1) * (alpha[i] * dt)) * eigV[i*Nk] * norm_x;
	// alpha, beta are just work spaces now
	mul_gen(vc1, eigV, vc2);
	mul_gen(y, bases, vc1);
    Nk_used = Nk;
	return abs(err);
}



} // namespace slisc

#endif
