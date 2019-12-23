#pragma once
#include "arithmetic.h"
#include "slice_arith.h"
#include "Cband.h"

namespace slisc {

// conversion between full matrix and band diagonal matrix
// Nup and Nlow are the number of upper diagonals and lower diagonals
// ref: cBLAS gbmv() routine
// https://software.intel.com/en-us/node/834918#DAEC7CD0-620A-4696-9612-C295F8211646

// slice the non-zero band
inline DcmatDoub band(CbandDoub_IO a)
{
	return DcmatDoub(&a.cmat()[a.idiag() - a.nup()], a.nup() + a.nlow() + 1, a.n2(), a.lda());
}

inline DcmatDoub_c band(CbandDoub_I a)
{
	return DcmatDoub_c(&a.cmat()[a.idiag() - a.nup()], a.nup() + a.nlow() + 1, a.n2(), a.lda());
}

inline DcmatComp band(CbandComp_IO a)
{
	return DcmatComp(&a.cmat()[a.idiag() - a.nup()], a.nup() + a.nlow() + 1, a.n2(), a.lda());
}

inline DcmatComp_c band(CbandComp_I a)
{
	return DcmatComp_c(&a.cmat()[a.idiag() - a.nup()], a.nup() + a.nlow() + 1, a.n2(), a.lda());
}


inline void copy(CbandDoub_O a, Doub_I s)
{
	copy(band(a), s);
}

inline void copy(CbandComp_O a, Comp_I s)
{
	copy(band(a), s);
}


inline void copy(CbandDoub_O a, CbandDoub_I b)
{
#ifdef SLS_CHECK_SHAPE
	if (a.idiag() < b.nup() || a.lda() - a.idiag() - 1 < b.nlow())
		SLS_ERR("wrong shape!");
#endif
	a.reshape(b.n1(), b.nup(), b.nlow());
	copy(band(a), band(b));
}

inline void copy(CbandComp_O a, CbandComp_I b)
{
#ifdef SLS_CHECK_SHAPE
	if (a.idiag() < b.nup() || a.lda() - a.idiag() - 1 < b.nlow())
		SLS_ERR("wrong shape!");
#endif
	a.reshape(b.n1(), b.nup(), b.nlow());
	copy(band(a), band(b));
}


inline void copy(CbandDoub_O b, CmatDoub_I a)
{
#ifdef SLS_CHECK_SHAPE
	if (!shape_cmp(a, b))
		SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n1(), N2 = a.n2();
    for (Long j = 0; j < N2; ++j) {
		SvecDoub sli_b = slice1(b.cmat(), j);
		SvecDoub_c sli_a = slice1(a, j);
        Long k = b.idiag() - j;
		Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        for (Long i = i_beg; i < i_end; ++i)
            sli_b[k + i] = sli_a[i];
    }
}

inline void copy(CmatDoub_O a, CbandDoub_I b)
{
#ifdef SLS_CHECK_SHAPE
	if (!shape_cmp(a, b))
		SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n1(), N2 = a.n2();
    for (Long j = 0; j < N2; ++j) {
        Long k = b.idiag() - j;
		Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
		SvecDoub sli_a = slice1(a, j);
		SvecDoub_c sli_b = slice1(b.cmat(), j);
		for (Long i = 0; i < i_beg; ++i)
			sli_a[i] = 0;
        for (Long i = i_beg; i < i_end; i++)
            sli_a[i] = sli_b[k + i];
		for (Long i = i_end; i < N1; ++i)
			sli_a[i] = 0;
    }
}

inline void copy(CbandComp_O b, CmatComp_I a)
{
#ifdef SLS_CHECK_SHAPE
	if (!shape_cmp(a, b))
		SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n1(), N2 = a.n2();
    for (Long j = 0; j < N2; ++j) {
		SvecComp sli_b = slice1(b.cmat(), j);
		SvecComp_c sli_a = slice1(a, j);
        Long k = b.idiag() - j;
		Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        for (Long i = i_beg; i < i_end; ++i)
            sli_b[k + i] = sli_a[i];
    }
}

inline void copy(CmatComp_O a, CbandComp_I b)
{
#ifdef SLS_CHECK_SHAPE
	if (!shape_cmp(a, b))
		SLS_ERR("wrong shape!");
#endif
    Long N1 = a.n1(), N2 = a.n2();
    for (Long j = 0; j < N2; ++j) {
        Long k = b.idiag() - j;
		Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
		SvecComp sli_a = slice1(a, j);
		SvecComp_c sli_b = slice1(b.cmat(), j);
		for (Long i = 0; i < i_beg; ++i)
			sli_a[i] = 0;
        for (Long i = i_beg; i < i_end; i++)
            sli_a[i] = sli_b[k + i];
		for (Long i = i_end; i < N1; ++i)
			sli_a[i] = 0;
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
inline void mul(VecDoub_O y, CbandDoub_I a, VecDoub_I x)
{
    Doub alpha = 1, beta = 0;
    Long incx = 1, incy = 1;
    cblas_dgbmv(CblasColMajor, CblasNoTrans, a.n1(), a.n2(), a.nlow(), a.nup(),
        alpha, a.ptr() + a.idiag() - a.nup(), a.lda(), x.ptr(), incx, beta, y.ptr(), incy);
}

inline void mul(VecComp_O y, CbandComp_I a, VecComp_I x)
{
    Comp alpha(1, 0), beta(0, 0);
    Long incx = 1, incy = 1;
    cblas_zgbmv(CblasColMajor, CblasNoTrans, a.n1(), a.n2(), a.nlow(), a.nup(),
        &alpha, a.ptr() + a.idiag() - a.nup(), a.lda(), x.ptr(), incx, &beta, y.ptr(), incy);
}

} // namespace slisc
