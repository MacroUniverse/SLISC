// declare quad functions before <complex>, to prevent errors
#pragma once

namespace std {

inline ostream& operator<<(ostream& os, const __float128 &x);
inline istream& operator>>(istream& is, __float128 &x);

// === C++ function overloading ===

// real = fun(real)
#define SLS_QMATH_DEC_RFUNR2(name, name0) inline __float128 name(const __float128 &x);

#define SLS_QMATH_DEC_RFUNR(name) SLS_QMATH_DEC_RFUNR2(name, name##q)

// real = fun(real, real)
#define SLS_QMATH_DEC_RFUNRR2(name, name0) inline __float128 name(const __float128 &x, const __float128 &y);

#define SLS_QMATH_DEC_RFUNRR(name) SLS_QMATH_DEC_RFUNRR2(name, name##q)

#define SLS_QMATH_DEC_RFUNC(name) SLS_QMATH_DEC_RFUNC2(name, c##name##q)

#define SLS_QMATH_DEC_CFUNC(name) SLS_QMATH_DEC_CFUNC2(name, c##name##q)

// ref: quadmath.h
SLS_QMATH_DEC_RFUNR2(abs, fabsq)
SLS_QMATH_DEC_RFUNR(acos)
SLS_QMATH_DEC_RFUNR(acosh)
SLS_QMATH_DEC_RFUNR(asin)
SLS_QMATH_DEC_RFUNR(asinh)
SLS_QMATH_DEC_RFUNR(atan)
SLS_QMATH_DEC_RFUNR(atanh)
SLS_QMATH_DEC_RFUNRR(atan2)
SLS_QMATH_DEC_RFUNR(cbrt)
SLS_QMATH_DEC_RFUNR(ceil)
SLS_QMATH_DEC_RFUNRR(copysign)
SLS_QMATH_DEC_RFUNR(cos)
SLS_QMATH_DEC_RFUNR(cosh)
SLS_QMATH_DEC_RFUNR(erf)
SLS_QMATH_DEC_RFUNR(exp)
// SLS_QMATH_DEC_RFUNR(exp2) // not supported in earlier g++
SLS_QMATH_DEC_RFUNR(expm1)
SLS_QMATH_DEC_RFUNR(fabs)
SLS_QMATH_DEC_RFUNRR(fdim)
SLS_QMATH_DEC_RFUNR(floor)
// fma
SLS_QMATH_DEC_RFUNR(isinf)
SLS_QMATH_DEC_RFUNR(isnan)
SLS_QMATH_DEC_RFUNR(j0)
SLS_QMATH_DEC_RFUNR(j1)
SLS_QMATH_DEC_RFUNR(lgamma)
// not defined in older version of GCC
// SLS_QMATH_DEC_RFUNR(logb)
SLS_QMATH_DEC_RFUNR(log)
SLS_QMATH_DEC_RFUNR(log10)
SLS_QMATH_DEC_RFUNR(log2)
SLS_QMATH_DEC_RFUNR(log1p)
SLS_QMATH_DEC_RFUNRR(nextafter)
SLS_QMATH_DEC_RFUNRR(pow)
SLS_QMATH_DEC_RFUNRR(remainder)
SLS_QMATH_DEC_RFUNR(rint)
SLS_QMATH_DEC_RFUNR(round)
SLS_QMATH_DEC_RFUNR(sinh)
SLS_QMATH_DEC_RFUNR(sin)
SLS_QMATH_DEC_RFUNR(sqrt)
SLS_QMATH_DEC_RFUNR(tan)
SLS_QMATH_DEC_RFUNR(tanh)
SLS_QMATH_DEC_RFUNR(tgamma)
SLS_QMATH_DEC_RFUNR(trunc)
SLS_QMATH_DEC_RFUNR(y0)
SLS_QMATH_DEC_RFUNR(y1)
// yn

} // namespace std
