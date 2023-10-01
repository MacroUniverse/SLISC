// solve eigen problem
#pragma once
#include "../arith/copy.h"

namespace slisc {
#ifdef SLS_USE_LAPACKE
// only upper triangle is needed
// eigen value in ascending order
inline void eig_sym(SvecDoub_O eigVal, ScmatDoub_O eigVec, ScmatDoub_I A)
{
#ifdef SLS_CHECK_SHAPES
	if (A.n0() != A.n1() || !shape_cmp2(eigVec, A)
		|| eigVal.size() != eigVec.n0())
		SLS_ERR("wrong shape!");
#endif
	copy(eigVec, A);
	Long N = A.n1();
	Long ret;
	ret = LAPACKE_dsyev(LAPACK_COL_MAJOR, 'V', 'U', N, eigVec.p(), N, eigVal.p());
	if (ret != 0)
		SLS_ERR("failed!");
}


// only upper triangle is needed
// eigen value in ascending order
inline void eig_her(VecDoub_O eigVal, CmatComp_O eigVec, CmatComp_I A)
{
#ifdef SLS_CHECK_BOUNDS
	if (A.n0() != A.n1() || !shape_cmp2(eigVec, A)
		|| eigVal.size() != eigVec.n0())
		SLS_ERR("wrong shape!");
#endif
	copy(eigVec, A);
	Long N = A.n1();
	eigVal.resize(N);
	Long ret = LAPACKE_zheev(LAPACK_COL_MAJOR, 'V', 'U', N,
		(double _Complex*)eigVec.p(), N, eigVal.p());
	if (ret != 0)
		SLS_ERR("failed!");
}
#endif

#ifdef SLS_USE_MPLAPACK
// same as eig_sym(), for quad precision, needs workspace

#endif
} // namespace slisc
