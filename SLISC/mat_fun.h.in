// functions of square matrix
#pragma once
#include "arithmetic.h"
#include "sparse_arith.h"
#include "eig.h"
#ifdef SLS_USE_LAPACKE
namespace slisc {

// out = exp(a*s) for symmetric matrix
void exp_mat_sym(CmatDoub_O out, CmatDoub_I a, Doub_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (a.n1() != a.n2() || !shape_cmp(out, a))
        SLS_ERR("not a square matrix!");
#endif
    Long N = a.n1();
    VecDoub eigVal(N);
    CmatDoub eigVec(N, N);
    eig_sym(eigVal, eigVec, a);
    eigVal *= s;
    exp(eigVal, eigVal);
    CmatDoub temp(N, N);
    mul(temp, eigVec, diag(eigVal));
    trans(eigVec);
    // TODO: using cBLAS multiplication can save the transpose
    mul_gen(out, temp, eigVec);
}

void exp_mat_sym(CmatComp_O out, CmatDoub_I a, Comp_I s)
{
#ifdef SLS_CHECK_SHAPES
    if (a.n1() != a.n2() || !shape_cmp(out, a))
        SLS_ERR("not a square matrix!");
#endif
    Long N = a.n1();
    VecDoub eigVal(N);
    VecComp eigValComp(N);
    CmatDoub eigVec(N, N);
    eig_sym(eigVal, eigVec, a);
    times(eigValComp, eigVal, s);
    exp(eigValComp, eigValComp);
    CmatComp temp(N, N);
    mul(temp, eigVec, diag(eigValComp));
    trans(eigVec);
    // TODO: using cBLAS multiplication can save the transpose
    mul_gen(out, temp, eigVec);
}

} // namespace slisc
#endif
