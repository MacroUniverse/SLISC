inline void mul(CmatDoub_O y, CmatDoub_I a, DiagDoub_I x)
{
#ifdef SLS_CHECK_SHAPE
    if (a.n2() != x.n1())
		SLS_ERR("illegal shape!");
    if (y.n1() != a.n1() || y.n2() != x.n2())
        SLS_ERR("illegal shape!");
#endif
    mul_cmat_cmat_diag(y.ptr(), a.ptr(), a.n1(), a.n2(), x.ptr());
}

inline void mul(CmatComp_O y, CmatComp_I a, DiagDoub_I x)
{
#ifdef SLS_CHECK_SHAPE
    if (a.n2() != x.n1())
		SLS_ERR("illegal shape!");
    if (y.n1() != a.n1() || y.n2() != x.n2())
        SLS_ERR("illegal shape!");
#endif
    mul_cmat_cmat_diag(y.ptr(), a.ptr(), a.n1(), a.n2(), x.ptr());
}

inline void mul(CmatComp_O y, CmatComp_I a, DiagComp_I x)
{
#ifdef SLS_CHECK_SHAPE
    if (a.n2() != x.n1())
		SLS_ERR("illegal shape!");
    if (y.n1() != a.n1() || y.n2() != x.n2())
        SLS_ERR("illegal shape!");
#endif
    mul_cmat_cmat_diag(y.ptr(), a.ptr(), a.n1(), a.n2(), x.ptr());
}

inline void mul(CmatDoub_O y, DiagDoub_I a, CmatDoub_I x)
{
#ifdef SLS_CHECK_SHAPE
    if (a.n2() != x.n1())
		SLS_ERR("illegal shape!");
    if (y.n1() != a.n1() || y.n2() != x.n2())
        SLS_ERR("illegal shape!");
#endif
	mul_cmat_diag_cmat(y.ptr(), a.ptr(), x.ptr(), x.n1(), x.n2());
}

inline void mul(CmatComp_O y, DiagComp_I a, CmatComp_I x)
{
#ifdef SLS_CHECK_SHAPE
    if (a.n2() != x.n1())
		SLS_ERR("illegal shape!");
    if (y.n1() != a.n1() || y.n2() != x.n2())
        SLS_ERR("illegal shape!");
#endif
	mul_cmat_diag_cmat(y.ptr(), a.ptr(), x.ptr(), x.n1(), x.n2());
}

inline void mul(CmatComp_O y, DiagDoub_I a, CmatComp_I x)
{
#ifdef SLS_CHECK_SHAPE
    if (a.n2() != x.n1())
		SLS_ERR("illegal shape!");
    if (y.n1() != a.n1() || y.n2() != x.n2())
        SLS_ERR("illegal shape!");
#endif
	mul_cmat_diag_cmat(y.ptr(), a.ptr(), x.ptr(), x.n1(), x.n2());
}

