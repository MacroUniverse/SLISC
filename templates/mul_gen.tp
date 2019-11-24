// matrix-vector multiplication using cBLAS
//% [Ty, Ta, Tx] = varargin{1:3};
//% Tsy = contain_type(Ty); Tsa = contain_type(Ta); Tsx = contain_type(Tx);
inline void mul_gen(@Ty@_O &y, @Ta@_I a, @Tx@_I x, @Tsx@_I alpha = 1, @Tsx@_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
//% if is_dense_vec(Ty)
    incy =  1;
//% else
    incy = y.step();
//% end
//% if is_dense_mat(Ta)
    lda = a.n1(a);
//% else
    lda = a.lda(a);
//% end
//% if is_dense_vec(Tx)
    incx = 1;
//% else
    incx = x.step();
//% end
//% if is_cmajor(Ta)
	CBLAS_LAYOUT layout = CblasColMajor;
//% else
	CBLAS_LAYOUT layout = CblasRowMajor;
//% end

//% if is_Float(Tsy) && is_Float(Tsa) && is_Float(Tsx)
	cblas_sgemv(layout, CblasNoTrans, N1, N2, alpha a.ptr(),
		lda, x.ptr(), incx, beta y.ptr(), incy);
//% elseif is_Doub(Tsy) && is_Doub(Tsa) && is_Doub(Tsx)
	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha a.ptr(),
		lda, x.ptr(), incx, beta y.ptr(), incy);
//% elseif is_Comp(Tsy) && is_Comp(Tsa) && is_Comp(Tsx)
	Comp alpha(1), beta(0);
	cblas_zgemv(layout, CblasNoTrans, N1, N2, &alpha, a.ptr(),
		lda, x.ptr(), incx, &beta, y.ptr(), incy);
//% elseif is_Comp(Tsy) && is_Doub(Tsa) && is_Comp(Tsx)
	// do real part
	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha a.ptr(),
		lda, x.ptr(), 2*incx, beta y.ptr(), 2*incy);
	// do imag part
	cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha a.ptr(),
		lda, x.ptr() + alpha 2*incx, beta y.ptr() + alpha 2*incy);
//% else
//%     error('not implemented!');
//% end
#else
    mul(y, a, x);
#endif
}
