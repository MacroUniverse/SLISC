// matrix-vector multiplication using cBLAS
//% [Ty, Ta, Tx] = varargin{1:3};
//% Tsy = contain_type(Ty); Tsa = contain_type(Ta); Tsx = contain_type(Tx);
inline void mul_gen(@Ty@_O &y, @Ta@_I a, @Tx@_I x)
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
//% if is_Doub(Tsy) && is_Doub(Tsx)
        cblas_dgemv(CblasColMajor, CblasNoTrans, N1, N2, 1, (Doub *)a.ptr(),
            lda, (Doub *)x.ptr(), incx, 0, (Doub *)y.ptr(), incy);
//% elseif (is_Comp(Tsy) && is_Comp(Tsx))
        Comp alpha(1), beta(0);
        cblas_zgemv(CblasColMajor, CblasNoTrans, N1, N2, &alpha, (Comp *)a.ptr(),
            lda, (Comp *)x.ptr(), incx, &beta, (Comp *)y.ptr(), incy);
//% elseif is_Comp(Ts) && is_Doub(Ts1)
        // do real part
        cblas_dgemv(CblasColMajor, CblasNoTrans, N1, N2, 1, (Doub*)a.ptr(),
            lda, (Doub*)x.ptr(), 2*incx, 0, (Doub*)y.ptr(), 2*incy);
        // do imag part
        cblas_dgemv(CblasColMajor, CblasNoTrans, N1, N2, 1, (Doub*)a.ptr(),
            lda, (Doub*)x.ptr() + 1, 2*incx, 0, (Doub*)y.ptr() + 1, 2*incy);
//% end
#else
    mul(y, a, x);
#endif
}
