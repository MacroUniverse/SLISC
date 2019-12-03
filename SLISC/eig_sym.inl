void eig_sym(VecDoub_O eigVal, CmatDoub_O eigVec, CmatDoub_I A)
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

