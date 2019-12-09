#pragma once
#include "compare.h"

namespace slisc {
#ifdef SLS_USE_LAPACKE
inline void inv_mat(CmatDoub_IO A)
{
#ifdef SLS_CHECK_SHAPE
    if (A.n1() != A.n2())
        SLS_ERR("wrong shape!");
#endif
    Int N = (Int)A.n1();
    VecInt ipiv(N);
    LAPACKE_dgetrf(LAPACK_COL_MAJOR, N, N, A.ptr(), N, ipiv.ptr());
    LAPACKE_dgetri(LAPACK_COL_MAJOR, N, A.ptr(), N, ipiv.ptr());
}
#endif

#ifdef SLS_USE_LAPACKE
inline void inv_mat(ScmatDoub_IO A)
{
#ifdef SLS_CHECK_SHAPE
    if (A.n1() != A.n2())
        SLS_ERR("wrong shape!");
#endif
    Int N = (Int)A.n1();
    VecInt ipiv(N);
    LAPACKE_dgetrf(LAPACK_COL_MAJOR, N, N, A.ptr(), N, ipiv.ptr());
    LAPACKE_dgetri(LAPACK_COL_MAJOR, N, A.ptr(), N, ipiv.ptr());
}
#endif

} // namespace slisc
