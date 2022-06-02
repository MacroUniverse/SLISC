#pragma once
#include "complex_arith.h"
#include "Imag.h"

namespace slisc {

constexpr Char sign(Char_I s)
{ return s > 0 ? 1 : (s < 0 ? -1 : 0); }

constexpr Int sign(Int_I s)
{ return s > 0 ? 1 : (s < 0 ? -1 : 0); }

constexpr Llong sign(Llong_I s)
{ return s > 0LL ? 1LL : (s < 0LL ? -1LL : 0LL); }

constexpr Float sign(Float_I s)
{ return s > 0.F ? 1.F : (s < 0.F ? -1.F : 0.F); }

constexpr Doub sign(Doub_I s)
{ return s > 0. ? 1. : (s < 0. ? -1. : 0.); }

constexpr Ldoub sign(Ldoub_I s)
{ return s > 0.L ? 1.L : (s < 0.L ? -1.L : 0.L); }

constexpr Qdoub sign(Qdoub_I s)
{ return s > 0.Q ? 1.Q : (s < 0.Q ? -1.Q : 0.Q); }


inline Char sign(Char_I a, Char_I b)
{ return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a); }

inline Int sign(Int_I a, Int_I b)
{ return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a); }

inline Llong sign(Llong_I a, Llong_I b)
{ return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a); }

inline Float sign(Float_I a, Float_I b)
{ return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a); }

inline Doub sign(Doub_I a, Doub_I b)
{ return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a); }

inline Ldoub sign(Ldoub_I a, Ldoub_I b)
{ return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a); }

inline Qdoub sign(Qdoub_I a, Qdoub_I b)
{ return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a); }


inline Bool isodd(Char_I n) { return n & 1; }

inline Bool isodd(Int_I n) { return n & 1; }

inline Bool isodd(Uint_I n) { return n & 1; }

inline Bool isodd(Llong_I n) { return n & 1; }

inline Bool isodd(Ullong_I n) { return n & 1; }


inline Bool ispow2(Char_I n) { return (n&(n-1)) == 0; }

inline Bool ispow2(Int_I n) { return (n&(n-1)) == 0; }

inline Bool ispow2(Llong_I n) { return (n&(n-1)) == 0; }


inline Int to_num(Char_I x) { return (Int)x; }

inline Int to_num(Int_I x) { return x; }

inline Llong to_num(Llong_I x) { return x; }

inline Doub to_num(Doub_I x) { return x; }

inline Ldoub to_num(Ldoub_I x) { return x; }

inline Qdoub to_num(Qdoub_I x) { return x; }

inline Comp to_num(Comp_I x) { return x; }

inline Lcomp to_num(Lcomp_I x) { return x; }

inline Qcomp to_num(Qcomp_I x) { return x; }


// modulus
// mod operation satisfies "s = div(s,d)*d + mod(s,d)"
// however, "div" can have different truncation:
// 1. c++11 operator "/" truncates towards 0, so "s = (s/d)*d + s%d"
// 2. "mod()" truncates towards negative direction
// 3. "mod_eu()" always return positive modulus
// when both numbers are positive, all cases returns the same result
// see https://en.wikipedia.org/wiki/Modulo_operation
inline Int mod(Int_I i, Int_I n) { return i % n; }

inline Int mod_fl(Int_I i, Int_I n) { return (i % n + n) % n; }

inline Int mod_eu(Int_I i, Int_I n)
{
    Int ret = i % n;
    return ret < 0 ? ret + abs(n) : ret;
}

inline Llong mod(Llong_I i, Int_I n) { return i % n; }

inline Llong mod_fl(Llong_I i, Int_I n) { return (i % n + n) % n; }

inline Llong mod_eu(Llong_I i, Int_I n)
{
    Llong ret = i % n;
    return ret < 0 ? ret + abs(n) : ret;
}

inline Llong mod(Int_I i, Llong_I n) { return i % n; }

inline Llong mod_fl(Int_I i, Llong_I n) { return (i % n + n) % n; }

inline Llong mod_eu(Int_I i, Llong_I n)
{
    Llong ret = i % n;
    return ret < 0 ? ret + abs(n) : ret;
}

inline Llong mod(Llong_I i, Llong_I n) { return i % n; }

inline Llong mod_fl(Llong_I i, Llong_I n) { return (i % n + n) % n; }

inline Llong mod_eu(Llong_I i, Llong_I n)
{
    Llong ret = i % n;
    return ret < 0 ? ret + abs(n) : ret;
}

inline Float mod(Float_I s, Float_I d)
{ return s - round(s/d) * d; }

// floating point version of "%", s = n * d + return
inline Float mod(Long_O n, Float_I s, Float_I d)
{
    n = round(s/d);
    return s - n * d;
}

inline Float mod_fl(Float_I s, Float_I d)
{ return s - floor(s/d) * d; }

// s = n * d + return
inline Float mod_fl(Long_O n, Float_I s, Float_I d)
{
    n = floor(s/d);
    return s - n * d;
}

inline Float mod_eu(Float_I s, Float_I d)
{
    Long n = s/d;
    Float r = s - n*d;
    return r < 0 ? r + abs(d) : r;
}

// s = n * d + return
inline Float mod_eu(Long_O n, Float_I s, Float_I d)
{
    n = s/d;
    Float r = s - n*d;
    if (r < 0) {
        r += abs(d);
        n -= sign(d);
    }
    return r;
}

inline Doub mod(Doub_I s, Doub_I d)
{ return s - round(s/d) * d; }

// floating point version of "%", s = n * d + return
inline Doub mod(Long_O n, Doub_I s, Doub_I d)
{
    n = round(s/d);
    return s - n * d;
}

inline Doub mod_fl(Doub_I s, Doub_I d)
{ return s - floor(s/d) * d; }

// s = n * d + return
inline Doub mod_fl(Long_O n, Doub_I s, Doub_I d)
{
    n = floor(s/d);
    return s - n * d;
}

inline Doub mod_eu(Doub_I s, Doub_I d)
{
    Long n = s/d;
    Doub r = s - n*d;
    return r < 0 ? r + abs(d) : r;
}

// s = n * d + return
inline Doub mod_eu(Long_O n, Doub_I s, Doub_I d)
{
    n = s/d;
    Doub r = s - n*d;
    if (r < 0) {
        r += abs(d);
        n -= sign(d);
    }
    return r;
}


inline Char sqr(Char_I a) { return a * a; }

inline Int sqr(Int_I a) { return a * a; }

inline Llong sqr(Llong_I a) { return a * a; }

inline Doub sqr(Doub_I a) { return a * a; }

inline Comp sqr(Comp_I a) { return a * a; }


inline Int abs2(Int_I a) { return a * a; }

inline Doub abs2(Doub_I a) { return a * a; }

inline Doub abs2(Comp_I &a) { return sqr(real(a)) + sqr(imag(a)); }


inline Doub factorial(Int_I n) {
    if (n > 170)
        SLS_ERR("n too large!");
    Doub ret = 1;
    for (Int i = 2; i <= n; ++i)
        ret *= i;
    return ret;
}

#ifdef SLS_USE_QUAD_MATH
inline Qdoub factorialq(Int_I n) {
    if (n > 1754)
        SLS_ERR("n too large!");
    Qdoub ret = 1;
    for (Int i = 2; i <= n; ++i)
        ret *= i;
    return ret;
}
#endif

inline Doub sinc(Doub_I x) { return x == 0. ? 1. : sin(x) / x; }


} // namespace slisc
