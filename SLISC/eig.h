// solve eigen problem
#pragma once
#include "arithmetic.h"

namespace slisc {

// only upper triangle is needed
// eigen value in ascending order
#include "eig_sym.inl"

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

} // namespace slisc
