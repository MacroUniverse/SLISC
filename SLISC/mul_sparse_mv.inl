void mul(VecDoub_O y, McooDoub_I a, VecDoub_I x)
{
#ifdef SLS_CHECK_SHAPE
    if (a.n2() != x.size() || a.n1() != y.size())
		SLS_ERR("illegal shape!");
#endif
	mul_v_coo_v(y.ptr(), x.ptr(), a.ptr(), a.row_ptr(), a.col_ptr(), a.n1(), a.nnz());
}

void mul(VecComp_O y, McooComp_I a, VecComp_I x)
{
#ifdef SLS_CHECK_SHAPE
    if (a.n2() != x.size() || a.n1() != y.size())
		SLS_ERR("illegal shape!");
#endif
	mul_v_coo_v(y.ptr(), x.ptr(), a.ptr(), a.row_ptr(), a.col_ptr(), a.n1(), a.nnz());
}

