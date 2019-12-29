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


// matrix-vector multiplication for band matrix
#ifdef SLS_USE_CBLAS
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
#endif

} // namespace slisc
