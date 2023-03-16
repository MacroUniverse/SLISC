// solve eigen problem
#pragma once
#include "../arith/copy.h"

namespace slisc {
#ifdef SLS_USE_LAPACKE
// only upper triangle is needed
// eigen value in ascending order
inline void eig_sym(SvecDoub_O eigVal, ScmatDoub_O eigVec, CmatDoub_I A)
{
#ifdef SLS_CHECK_SHAPES
	if (A.n0() != A.n1() || !shape_cmp(eigVec, A)
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

inline void eig_sym(SvecDoub_O eigVal, ScmatDoub_O eigVec, ScmatDoub_I A)
{
#ifdef SLS_CHECK_SHAPES
	if (A.n0() != A.n1() || !shape_cmp(eigVec, A)
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

inline void eig_sym(VecDoub_O eigVal, CmatDoub_O eigVec, CmatDoub_I A)
{
#ifdef SLS_CHECK_SHAPES
	if (A.n0() != A.n1() || !shape_cmp(eigVec, A)
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
	if (A.n0() != A.n1() || !shape_cmp(eigVec, A)
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
inline void eig_sym(SvecQdoub_O eigVal, ScmatQdoub_O eigVec, CmatQdoub_I A, VecQdoub_IO wsp_qd)
{
	Long N = A.n1();
#ifdef SLS_CHECK_SHAPES
	if (A.n0() != A.n1() || !shape_cmp(eigVec, A)
	    || eigVal.size() != eigVec.n0())
	    SLS_ERR("wrong shape!");
	if (wsp_qd.size() != 3*N) // this is gessed, Rsyev will show have error is not enough.
		SLS_ERR("wrong shape!");
#endif

	copy(eigVec, A);
	Long ret;
	// Rsyev(const char *jobz, const char *uplo, mplapackint const n, _Float128 *a, mplapackint const lda, _Float128 *w, _Float128 *work, mplapackint const lwork, mplapackint &info);
	mplapackint ret0;
	Rsyev("V", "U", N, eigVec.p(), N, eigVal.p(), wsp_qd.p(), wsp_qd.size(), ret0);
	ret = ret0;
	if (ret != 0)
	    SLS_ERR("failed!");
}

inline void eig_sym(SvecQdoub_O eigVal, ScmatQdoub_O eigVec, ScmatQdoub_I A, VecQdoub_IO wsp_qd)
{
	Long N = A.n1();
#ifdef SLS_CHECK_SHAPES
	if (A.n0() != A.n1() || !shape_cmp(eigVec, A)
	    || eigVal.size() != eigVec.n0())
	    SLS_ERR("wrong shape!");
	if (wsp_qd.size() != 3*N) // this is gessed, Rsyev will show have error is not enough.
		SLS_ERR("wrong shape!");
#endif

	copy(eigVec, A);
	Long ret;
	// Rsyev(const char *jobz, const char *uplo, mplapackint const n, _Float128 *a, mplapackint const lda, _Float128 *w, _Float128 *work, mplapackint const lwork, mplapackint &info);
	mplapackint ret0;
	Rsyev("V", "U", N, eigVec.p(), N, eigVal.p(), wsp_qd.p(), wsp_qd.size(), ret0);
	ret = ret0;
	if (ret != 0)
	    SLS_ERR("failed!");
}

inline void eig_sym(VecQdoub_O eigVal, CmatQdoub_O eigVec, CmatQdoub_I A, VecQdoub_IO wsp_qd)
{
	Long N = A.n1();
#ifdef SLS_CHECK_SHAPES
	if (A.n0() != A.n1() || !shape_cmp(eigVec, A)
	    || eigVal.size() != eigVec.n0())
	    SLS_ERR("wrong shape!");
	if (wsp_qd.size() != 3*N) // this is gessed, Rsyev will show have error is not enough.
		SLS_ERR("wrong shape!");
#endif

	copy(eigVec, A);
	Long ret;
	// Rsyev(const char *jobz, const char *uplo, mplapackint const n, _Float128 *a, mplapackint const lda, _Float128 *w, _Float128 *work, mplapackint const lwork, mplapackint &info);
	mplapackint ret0;
	Rsyev("V", "U", N, eigVec.p(), N, eigVal.p(), wsp_qd.p(), wsp_qd.size(), ret0);
	ret = ret0;
	if (ret != 0)
	    SLS_ERR("failed!");
}

#endif
} // namespace slisc
