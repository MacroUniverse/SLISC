// matrix-vector multiplication using cBLAS
inline void mul_gen(VecDoub_O &y, CmatDoub_I a, VecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, CmatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	// do real part
	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, (Doub*)x.ptr(), 2*incx, beta, (Doub*)y.ptr(), 2*incy);
	// do imag part
	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, (Doub*)x.ptr()+1, 2*incx, beta, (Doub*)y.ptr()+1, 2*incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, DcmatDoub_I a, DvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.lda();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	// do real part
	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, (Doub*)x.ptr(), 2*incx, beta, (Doub*)y.ptr(), 2*incy);
	// do imag part
	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, (Doub*)x.ptr()+1, 2*incx, beta, (Doub*)y.ptr()+1, 2*incy);
#else
    mul(y, a, x);
#endif
}

