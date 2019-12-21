#pragma once
#include "arithmetic.h"
#include "Cband.h"

namespace slisc {

// conversion between full matrix and band diagonal matrix
// Nup and Nlow are the number of upper diagonals and lower diagonals
// ref: cBLAS gbmv() routine
// https://software.intel.com/en-us/node/834918#DAEC7CD0-620A-4696-9612-C295F8211646

void copy(CbandDoub_O b, CmatDoub_I a)
{
#ifdef SLS_CHECK_SHAPE
	if (!shape_cmp(a, b))
		SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n1(), N2 = a.n2();
	CmatDoub &c = b.cmat();
    for (Long j = 0; j < N2; j++) {
        Long k = b.nup() - j;
        for (Long i = max(Long(0), j - b.nup()); i < min(N1, j + b.nlow() + 1); i++) {
            c(k + i, j) = a(i, j);
        }
    }
}

void copy(CmatDoub_O a, CbandDoub_O b)
{
#ifdef SLS_CHECK_SHAPE
	if (!shape_cmp(a, b))
		SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n1(), N2 = a.n2();
	CmatDoub &c = b.cmat();
    for (Long j = 0; j < N2; j++) {
        Long k = b.nup() - j;
        for (Long i = max(Long(0), j - b.nup()); i < min(N1, j + b.nlow() + 1); i++) {
            a(i, j) = c(k + i, j);
        }
    }
}

void copy(CbandComp_O b, CmatComp_I a)
{
#ifdef SLS_CHECK_SHAPE
	if (!shape_cmp(a, b))
		SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n1(), N2 = a.n2();
	CmatComp &c = b.cmat();
    for (Long j = 0; j < N2; j++) {
        Long k = b.nup() - j;
        for (Long i = max(Long(0), j - b.nup()); i < min(N1, j + b.nlow() + 1); i++) {
            c(k + i, j) = a(i, j);
        }
    }
}

void copy(CmatComp_O a, CbandComp_O b)
{
#ifdef SLS_CHECK_SHAPE
	if (!shape_cmp(a, b))
		SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n1(), N2 = a.n2();
	CmatComp &c = b.cmat();
    for (Long j = 0; j < N2; j++) {
        Long k = b.nup() - j;
        for (Long i = max(Long(0), j - b.nup()); i < min(N1, j + b.nlow() + 1); i++) {
            a(i, j) = c(k + i, j);
        }
    }
}


// void mat2band(Matrix<T> &b, const Matrix<T> &a, Long_I Nup, Long_I Nlow)
// {
//     Long N1 = a.n1(), N2 = a.n2();
//     for (Long i = 0; i < N1; i++) {
//         Long k = Nlow - i;
//         for (Long j = max(Long(0), i - Nlow); j < MIN(N2, i + Nup + 1); j++) {
//             b(i, k + j) = a(i, j);
//         }
//     }
// }

// template <class T, SLS_IF0(is_scalar<T>())>
// void band2mat(Matrix<T> &a, const Matrix<T> &b, Long_I Nup, Long_I Nlow)
// {
//     Long N1 = a.n1(), N2 = a.n2();
//     for (Long i = 0; i < N1; i++) {
//         Long k = Nlow - i;
//         for (Long j = max(Long(0), i - Nlow); j < MIN(N2, i + Nup + 1); j++) {
//             a(i, j) = b(i, k + j);
//         }
//     }
// }

// matrix-vector multiplication for band matrix

// matrix-vector multiplication for band matrix
void mul(VecDoub_O y, CbandDoub_I a, VecDoub_I x)
{
    Doub alpha = 1, beta = 0;
    Long lda = a.nlow() + a.nup() + 1;
    Long incx = 1, incy = 1;
    cblas_dgbmv(CblasColMajor, CblasNoTrans, a.n1(), a.n2(), a.nlow(), a.nup(),
        alpha, a.ptr(), lda, x.ptr(), incx, beta, y.ptr(), incy);
}

void mul(VecComp_O y, CbandComp_I a, VecComp_I x)
{
    Comp alpha(1, 0), beta(0, 0);
    Long lda = a.nlow() + a.nup() + 1;
    Long incx = 1, incy = 1;
    cblas_zgbmv(CblasColMajor, CblasNoTrans, a.n1(), a.n2(), a.nlow(), a.nup(),
        &alpha, a.ptr(), lda, x.ptr(), incx, &beta, y.ptr(), incy);
}

} // namespace slisc
