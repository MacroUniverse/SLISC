inline void mul_sym(VecDoub_O &y, CmatDoub_I a, VecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1() || x.size() != y.size())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_dsymv(layout, CblasUpper, N1, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_sym(VecComp_O &y, CmatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1() || x.size() != y.size())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	// do real part
	cblas_dsymv(layout, CblasUpper, N1, alpha, a.ptr(),
		lda, (Doub*)x.ptr(), 2*incx, beta, (Doub*)y.ptr(), 2*incy);
	// do imag part
	cblas_dsymv(layout, CblasUpper, N1, alpha, a.ptr(),
		lda, (Doub*)x.ptr()+1, 2*incx, beta, (Doub*)y.ptr()+1, 2*incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_sym(SvecComp_O &y, DcmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1() || x.size() != y.size())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	// do real part
	cblas_dsymv(layout, CblasUpper, N1, alpha, a.ptr(),
		lda, (Doub*)x.ptr(), 2*incx, beta, (Doub*)y.ptr(), 2*incy);
	// do imag part
	cblas_dsymv(layout, CblasUpper, N1, alpha, a.ptr(),
		lda, (Doub*)x.ptr()+1, 2*incx, beta, (Doub*)y.ptr()+1, 2*incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_sym(DvecComp_O &y, DcmatDoub_I a, DvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1() || x.size() != y.size())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), lda, incx, incy;
    incy = y.step();
    lda = a.lda();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	// do real part
	cblas_dsymv(layout, CblasUpper, N1, alpha, a.ptr(),
		lda, (Doub*)x.ptr(), 2*incx, beta, (Doub*)y.ptr(), 2*incy);
	// do imag part
	cblas_dsymv(layout, CblasUpper, N1, alpha, a.ptr(),
		lda, (Doub*)x.ptr()+1, 2*incx, beta, (Doub*)y.ptr()+1, 2*incy);
#else
    mul(y, a, x);
#endif
}

