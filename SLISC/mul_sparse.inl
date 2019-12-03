void mul(CmatDoub_O c, CmatDoub_I a, DiagDoub_I b)
{
#ifdef SLS_CHECK_SHAPE
    if (a.n2() != b.n1())
		SLS_ERR("illegal shape!");
    if (c.n1() != a.n1() || c.n2() != b.n2())
        SLS_ERR("illegal shape!");
#endif
    mul_cmat_cmat_diag(c.ptr(), a.ptr(), a.n1(), a.n2(), b.ptr());
}

void mul(CmatComp_O c, CmatComp_I a, DiagDoub_I b)
{
#ifdef SLS_CHECK_SHAPE
    if (a.n2() != b.n1())
		SLS_ERR("illegal shape!");
    if (c.n1() != a.n1() || c.n2() != b.n2())
        SLS_ERR("illegal shape!");
#endif
    mul_cmat_cmat_diag(c.ptr(), a.ptr(), a.n1(), a.n2(), b.ptr());
}

void mul(CmatComp_O c, CmatComp_I a, DiagComp_I b)
{
#ifdef SLS_CHECK_SHAPE
    if (a.n2() != b.n1())
		SLS_ERR("illegal shape!");
    if (c.n1() != a.n1() || c.n2() != b.n2())
        SLS_ERR("illegal shape!");
#endif
    mul_cmat_cmat_diag(c.ptr(), a.ptr(), a.n1(), a.n2(), b.ptr());
}

void mul(CmatDoub_O c, DiagDoub_I a, CmatDoub_I b)
{
#ifdef SLS_CHECK_SHAPE
    if (a.n2() != b.n1())
		SLS_ERR("illegal shape!");
    if (c.n1() != a.n1() || c.n2() != b.n2())
        SLS_ERR("illegal shape!");
#endif
	mul_cmat_diag_cmat(c.ptr(), a.ptr(), b.ptr(), b.n1(), b.n2());
}

void mul(CmatComp_O c, DiagComp_I a, CmatComp_I b)
{
#ifdef SLS_CHECK_SHAPE
    if (a.n2() != b.n1())
		SLS_ERR("illegal shape!");
    if (c.n1() != a.n1() || c.n2() != b.n2())
        SLS_ERR("illegal shape!");
#endif
	mul_cmat_diag_cmat(c.ptr(), a.ptr(), b.ptr(), b.n1(), b.n2());
}

void mul(CmatComp_O c, DiagDoub_I a, CmatComp_I b)
{
#ifdef SLS_CHECK_SHAPE
    if (a.n2() != b.n1())
		SLS_ERR("illegal shape!");
    if (c.n1() != a.n1() || c.n2() != b.n2())
        SLS_ERR("illegal shape!");
#endif
	mul_cmat_diag_cmat(c.ptr(), a.ptr(), b.ptr(), b.n1(), b.n2());
}

