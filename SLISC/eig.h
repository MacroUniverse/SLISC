// solve eigen problem
#pragma once
#include "arithmetic.h"

namespace slisc {
#ifdef SLS_USE_LAPACKE
// only upper triangle is needed
// eigen value in ascending order
inline void eig_sym(VecDoub_O eigVal, CmatDoub_O eigVec, CmatDoub_I A)
{
#ifdef SLS_CHECK_BOUNDS
    if (A.n1() != A.n2() || !shape_cmp(eigVec, A)
        || eigVal.size() != eigVec.n1())
        SLS_ERR("wrong shape!");
#endif
    copy(eigVec, A);
    Int N = (Int)A.n2();
    Int ret;
    ret = LAPACKE_dsyev(LAPACK_COL_MAJOR, 'V', 'U', N, eigVec.ptr(), N, eigVal.ptr());
    if (ret != 0)
        SLS_ERR("failed!");
}

inline void eig_sym(SvecDoub_O eigVal, ScmatDoub_O eigVec, CmatDoub_I A)
{
#ifdef SLS_CHECK_BOUNDS
    if (A.n1() != A.n2() || !shape_cmp(eigVec, A)
        || eigVal.size() != eigVec.n1())
        SLS_ERR("wrong shape!");
#endif
    copy(eigVec, A);
    Int N = (Int)A.n2();
    Int ret;
    ret = LAPACKE_dsyev(LAPACK_COL_MAJOR, 'V', 'U', N, eigVec.ptr(), N, eigVal.ptr());
    if (ret != 0)
        SLS_ERR("failed!");
}

inline void eig_sym(SvecDoub_O eigVal, ScmatDoub_O eigVec, ScmatDoub_I A)
{
#ifdef SLS_CHECK_BOUNDS
    if (A.n1() != A.n2() || !shape_cmp(eigVec, A)
        || eigVal.size() != eigVec.n1())
        SLS_ERR("wrong shape!");
#endif
    copy(eigVec, A);
    Int N = (Int)A.n2();
    Int ret;
    ret = LAPACKE_dsyev(LAPACK_COL_MAJOR, 'V', 'U', N, eigVec.ptr(), N, eigVal.ptr());
    if (ret != 0)
        SLS_ERR("failed!");
}


// only upper triangle is needed
// eigen value in ascending order
inline void eig_her(VecDoub_O eigVal, CmatComp_O eigVec, CmatComp_I A)
{
#ifdef SLS_CHECK_BOUNDS
    if (A.n1() != A.n2() || !shape_cmp(eigVec, A)
        || eigVal.size() != eigVec.n1())
        SLS_ERR("wrong shape!");
#endif
    copy(eigVec, A);
    Int N = (Int)A.n2();
    eigVal.resize(N);
    Int ret = LAPACKE_zheev(LAPACK_COL_MAJOR, 'V', 'U', N,
        (double _Complex*)eigVec.ptr(), N, eigVal.ptr());
    if (ret != 0)
        SLS_ERR("failed!");
}
#endif
} // namespace slisc
