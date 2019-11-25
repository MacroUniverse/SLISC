// matrix-vector multiplication using cBLAS
inline void mul_gen(VecFloat_O &y, CmatFloat_I a, VecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
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

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

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
inline void mul_gen(VecComp_O &y, CmatComp_I a, VecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
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

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
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
inline void mul_gen(SvecFloat_O &y, CmatFloat_I a, VecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
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

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecDoub_O &y, CmatDoub_I a, VecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
inline void mul_gen(SvecComp_O &y, CmatComp_I a, VecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
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

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, CmatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
inline void mul_gen(DvecFloat_O &y, CmatFloat_I a, VecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecDoub_O &y, CmatDoub_I a, VecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
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
inline void mul_gen(DvecComp_O &y, CmatComp_I a, VecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, CmatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
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
inline void mul_gen(VecFloat_O &y, CmatFloat_I a, SvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
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

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecDoub_O &y, CmatDoub_I a, SvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
inline void mul_gen(VecComp_O &y, CmatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
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

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, CmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
inline void mul_gen(SvecFloat_O &y, CmatFloat_I a, SvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
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

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecDoub_O &y, CmatDoub_I a, SvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
inline void mul_gen(SvecComp_O &y, CmatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
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

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, CmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
inline void mul_gen(DvecFloat_O &y, CmatFloat_I a, SvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecDoub_O &y, CmatDoub_I a, SvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
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
inline void mul_gen(DvecComp_O &y, CmatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, CmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
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
inline void mul_gen(VecFloat_O &y, CmatFloat_I a, DvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecDoub_O &y, CmatDoub_I a, DvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, CmatComp_I a, DvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, CmatDoub_I a, DvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
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

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecFloat_O &y, CmatFloat_I a, DvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecDoub_O &y, CmatDoub_I a, DvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, CmatComp_I a, DvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, CmatDoub_I a, DvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
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

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecFloat_O &y, CmatFloat_I a, DvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecDoub_O &y, CmatDoub_I a, DvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, CmatComp_I a, DvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, CmatDoub_I a, DvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
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

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecFloat_O &y, ScmatFloat_I a, VecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
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

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecDoub_O &y, ScmatDoub_I a, VecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
inline void mul_gen(VecComp_O &y, ScmatComp_I a, VecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
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

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, ScmatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
inline void mul_gen(SvecFloat_O &y, ScmatFloat_I a, VecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
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

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecDoub_O &y, ScmatDoub_I a, VecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
inline void mul_gen(SvecComp_O &y, ScmatComp_I a, VecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
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

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, ScmatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
inline void mul_gen(DvecFloat_O &y, ScmatFloat_I a, VecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecDoub_O &y, ScmatDoub_I a, VecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
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
inline void mul_gen(DvecComp_O &y, ScmatComp_I a, VecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, ScmatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
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
inline void mul_gen(VecFloat_O &y, ScmatFloat_I a, SvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
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

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecDoub_O &y, ScmatDoub_I a, SvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
inline void mul_gen(VecComp_O &y, ScmatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
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

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, ScmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
inline void mul_gen(SvecFloat_O &y, ScmatFloat_I a, SvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
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

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecDoub_O &y, ScmatDoub_I a, SvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
inline void mul_gen(SvecComp_O &y, ScmatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
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

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, ScmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
inline void mul_gen(DvecFloat_O &y, ScmatFloat_I a, SvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecDoub_O &y, ScmatDoub_I a, SvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
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
inline void mul_gen(DvecComp_O &y, ScmatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, ScmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
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
inline void mul_gen(VecFloat_O &y, ScmatFloat_I a, DvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecDoub_O &y, ScmatDoub_I a, DvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, ScmatComp_I a, DvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, ScmatDoub_I a, DvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
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

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecFloat_O &y, ScmatFloat_I a, DvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecDoub_O &y, ScmatDoub_I a, DvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, ScmatComp_I a, DvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, ScmatDoub_I a, DvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
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

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecFloat_O &y, ScmatFloat_I a, DvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecDoub_O &y, ScmatDoub_I a, DvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, ScmatComp_I a, DvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, ScmatDoub_I a, DvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
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

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecFloat_O &y, DcmatFloat_I a, VecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecDoub_O &y, DcmatDoub_I a, VecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, DcmatComp_I a, VecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, DcmatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
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
inline void mul_gen(SvecFloat_O &y, DcmatFloat_I a, VecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecDoub_O &y, DcmatDoub_I a, VecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, DcmatComp_I a, VecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, DcmatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
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
inline void mul_gen(DvecFloat_O &y, DcmatFloat_I a, VecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecDoub_O &y, DcmatDoub_I a, VecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, DcmatComp_I a, VecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, DcmatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.lda();
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
inline void mul_gen(VecFloat_O &y, DcmatFloat_I a, SvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecDoub_O &y, DcmatDoub_I a, SvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, DcmatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, DcmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
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
inline void mul_gen(SvecFloat_O &y, DcmatFloat_I a, SvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecDoub_O &y, DcmatDoub_I a, SvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, DcmatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, DcmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
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
inline void mul_gen(DvecFloat_O &y, DcmatFloat_I a, SvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecDoub_O &y, DcmatDoub_I a, SvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, DcmatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.lda();
    incx = 1;
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, DcmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.lda();
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
inline void mul_gen(VecFloat_O &y, DcmatFloat_I a, DvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecDoub_O &y, DcmatDoub_I a, DvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, DcmatComp_I a, DvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, DcmatDoub_I a, DvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
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

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecFloat_O &y, DcmatFloat_I a, DvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecDoub_O &y, DcmatDoub_I a, DvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, DcmatComp_I a, DvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.lda();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasColMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, DcmatDoub_I a, DvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
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

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecFloat_O &y, DcmatFloat_I a, DvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
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

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecDoub_O &y, DcmatDoub_I a, DvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
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

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, DcmatComp_I a, DvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
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

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
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

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecFloat_O &y, MatFloat_I a, VecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
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
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecDoub_O &y, MatDoub_I a, VecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, MatComp_I a, VecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
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
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, MatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
	CBLAS_LAYOUT layout = CblasRowMajor;

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
inline void mul_gen(SvecFloat_O &y, MatFloat_I a, VecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
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
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecDoub_O &y, MatDoub_I a, VecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, MatComp_I a, VecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
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
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, MatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
	CBLAS_LAYOUT layout = CblasRowMajor;

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
inline void mul_gen(DvecFloat_O &y, MatFloat_I a, VecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecDoub_O &y, MatDoub_I a, VecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, MatComp_I a, VecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, MatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasRowMajor;

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
inline void mul_gen(VecFloat_O &y, MatFloat_I a, SvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
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
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecDoub_O &y, MatDoub_I a, SvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, MatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
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
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, MatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
	CBLAS_LAYOUT layout = CblasRowMajor;

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
inline void mul_gen(SvecFloat_O &y, MatFloat_I a, SvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
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
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecDoub_O &y, MatDoub_I a, SvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, MatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
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
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, MatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
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
	CBLAS_LAYOUT layout = CblasRowMajor;

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
inline void mul_gen(DvecFloat_O &y, MatFloat_I a, SvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecDoub_O &y, MatDoub_I a, SvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, MatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, MatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = 1;
	CBLAS_LAYOUT layout = CblasRowMajor;

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
inline void mul_gen(VecFloat_O &y, MatFloat_I a, DvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecDoub_O &y, MatDoub_I a, DvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, MatComp_I a, DvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(VecComp_O &y, MatDoub_I a, DvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasRowMajor;

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
inline void mul_gen(SvecFloat_O &y, MatFloat_I a, DvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecDoub_O &y, MatDoub_I a, DvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, MatComp_I a, DvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(SvecComp_O &y, MatDoub_I a, DvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasRowMajor;

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
inline void mul_gen(DvecFloat_O &y, MatFloat_I a, DvecFloat_I x, Float_I alpha = 1, Float_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecDoub_O &y, MatDoub_I a, DvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
		lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, MatComp_I a, DvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasRowMajor;

	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

// matrix-vector multiplication using cBLAS
inline void mul_gen(DvecComp_O &y, MatDoub_I a, DvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy = y.step();
    lda = a.n1();
    incx = x.step();
	CBLAS_LAYOUT layout = CblasRowMajor;

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

