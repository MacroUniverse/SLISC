// functions of square matrix
#pragma once
#include "../sparse/sparse_arith.h"
#include "../lin/eig.h"
#include "../lin/mul.h"
#ifdef SLS_USE_LAPACKE
namespace slisc {

// out = exp(a*s) for symmetric matrix
inline void exp_mat_sym(CmatDoub_O out, CmatDoub_I a, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || !shape_cmp2(out, a))
		SLS_ERR("not a square matrix!");
#endif
	Long N = a.n0();
	thread_local static VecDoub eigVal(N);
	thread_local static CmatDoub eigVec(N, N);
	eig_sym(eigVal, eigVec, a);
	eigVal *= s;
for (Long i = 0; i < N; ++i)
		eigVal[i] = exp(eigVal[i]);
	CmatDoub temp(N, N);
	mul(temp, eigVec, diag(eigVal));
	trans(eigVec);
	// TODO: using cBLAS multiplication can save the transpose
	mul_gen(out, temp, eigVec);
}

inline void exp_mat_sym(CmatComp_O out, CmatDoub_I a, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || !shape_cmp2(out, a))
		SLS_ERR("not a square matrix!");
#endif
	Long N = a.n0();
	thread_local static VecDoub eigVal(N);
	thread_local static VecComp eigValComp(N);
	thread_local static CmatDoub eigVec(N, N);
	eig_sym(eigVal, eigVec, a);
	times(eigValComp, eigVal, s);
	for (Long i = 0; i < N; ++i)
		eigValComp[i] = exp(eigValComp[i]);
	thread_local static CmatComp temp(N, N);
	mul(temp, eigVec, diag(eigValComp));
	trans(eigVec);
	// TODO: using cBLAS multiplication can save the transpose
	mul_gen(out, temp, eigVec);
}

// calculate u = exp(As)v by n-th order taylor expansion
// mul_fun(u) implements u = Au
// algorithm (e.g. n = 4):
// exp(As)v ~ v + (As)v + (As)^2 v/2! + (As)^3 v/3! + (As)^4 v/4!
// = v + (As/1)(v + (As/2)(v + (As/3)(v + (As/4)v)
template <class Tmul, class Tv, class Ts>
inline void exp_taylor(Tv &u, Tmul mul_eq_fun, const Ts &s, int n, const Tv &v)
{
	u = v;
	while (n > 0) {
		u *= s/n;
		mul_eq_fun(u);
		u += v;
		--n;
	}
}

} // namespace slisc
#endif
