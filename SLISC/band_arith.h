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


// detect band width of dense matrix
// a(i,j) < tol is considered 0
inline void nband(Long_O Nup, Long_O Nlow, CmatDoub_I a, Doub_I tol = 0)
{
    Bool found = false;
    // check upper diagonals
    for (Long k = a.n2() - 1; k > 0 && !found; --k) {
        Long i = 0;
        for (Long j = k; j < a.n2() && !found; ++j) {
            if (i > a.n1()) break;
            if (abs(a(i, j)) > tol)  {
                Nup = k; found = true;
            }
            ++i;
        }
    }
    
    // check lower diagonals
    found = false;
	for (Long k = a.n1() - 1; k > 0  && !found; --k) {
        Long j = 0;
        for (Long i = k; i < a.n1() && !found; ++i) {
            if (j > a.n2()) break;
            if (abs(a(i, j)) > tol) {
                Nlow = k; found = true;
            }
            ++j;
        }
	}
}

inline void nband(Long_O Nup, Long_O Nlow, CmatComp_I a, Doub_I tol = 0)
{
    Bool found = false;
    // check upper diagonals
    for (Long k = a.n2() - 1; k > 0 && !found; --k) {
        Long i = 0;
        for (Long j = k; j < a.n2() && !found; ++j) {
            if (i > a.n1()) break;
            if (abs(a(i, j)) > tol)  {
                Nup = k; found = true;
            }
            ++i;
        }
    }
    
    // check lower diagonals
    found = false;
	for (Long k = a.n1() - 1; k > 0  && !found; --k) {
        Long j = 0;
        for (Long i = k; i < a.n1() && !found; ++i) {
            if (j > a.n2()) break;
            if (abs(a(i, j)) > tol) {
                Nlow = k; found = true;
            }
            ++j;
        }
	}
}

inline void nband(Long_O Nup, Long_O Nlow, ScmatDoub_I a, Doub_I tol = 0)
{
    Bool found = false;
    // check upper diagonals
    for (Long k = a.n2() - 1; k > 0 && !found; --k) {
        Long i = 0;
        for (Long j = k; j < a.n2() && !found; ++j) {
            if (i > a.n1()) break;
            if (abs(a(i, j)) > tol)  {
                Nup = k; found = true;
            }
            ++i;
        }
    }
    
    // check lower diagonals
    found = false;
	for (Long k = a.n1() - 1; k > 0  && !found; --k) {
        Long j = 0;
        for (Long i = k; i < a.n1() && !found; ++i) {
            if (j > a.n2()) break;
            if (abs(a(i, j)) > tol) {
                Nlow = k; found = true;
            }
            ++j;
        }
	}
}

inline void nband(Long_O Nup, Long_O Nlow, ScmatComp_I a, Doub_I tol = 0)
{
    Bool found = false;
    // check upper diagonals
    for (Long k = a.n2() - 1; k > 0 && !found; --k) {
        Long i = 0;
        for (Long j = k; j < a.n2() && !found; ++j) {
            if (i > a.n1()) break;
            if (abs(a(i, j)) > tol)  {
                Nup = k; found = true;
            }
            ++i;
        }
    }
    
    // check lower diagonals
    found = false;
	for (Long k = a.n1() - 1; k > 0  && !found; --k) {
        Long j = 0;
        for (Long i = k; i < a.n1() && !found; ++i) {
            if (j > a.n2()) break;
            if (abs(a(i, j)) > tol) {
                Nlow = k; found = true;
            }
            ++j;
        }
	}
}


// matrix-vector multiplication for band matrix
#ifdef SLS_USE_CBLAS
inline void mul(VecDoub_O y, CbandDoub_I a, VecDoub_I x)
{
    Long incx = 1;
    Long incy = 1;
	Doub alpha = 1, beta = 0;
    cblas_dgbmv(CblasColMajor, CblasNoTrans, a.n1(), a.n2(), a.nlow(), a.nup(),
        alpha, a.ptr() + a.idiag() - a.nup(), a.lda(), x.ptr(), incx, beta, y.ptr(), incy);
}

inline void mul(VecComp_O y, CbandComp_I a, VecComp_I x)
{
    Long incx = 1;
    Long incy = 1;
	Comp alpha(1, 0), beta(0, 0);
    cblas_zgbmv(CblasColMajor, CblasNoTrans, a.n1(), a.n2(), a.nlow(), a.nup(),
        &alpha, a.ptr() + a.idiag() - a.nup(), a.lda(), x.ptr(), incx, &beta, y.ptr(), incy);
}

inline void mul(VecComp_O y, CbandComp_I a, SvecComp_I x)
{
    Long incx = 1;
    Long incy = 1;
	Comp alpha(1, 0), beta(0, 0);
    cblas_zgbmv(CblasColMajor, CblasNoTrans, a.n1(), a.n2(), a.nlow(), a.nup(),
        &alpha, a.ptr() + a.idiag() - a.nup(), a.lda(), x.ptr(), incx, &beta, y.ptr(), incy);
}

#endif

} // namespace slisc
