#pragma once
#include "complex_arith.h"
#include "Imag.h"

namespace slisc {

inline Bool isodd(Char_I n)
{
    return n & 1;
}

inline Bool isodd(Int_I n)
{
    return n & 1;
}

inline Bool isodd(Llong_I n)
{
    return n & 1;
}


inline Bool ispow2(Char_I n)
{
    return (n&(n-1)) == 0;
}

inline Bool ispow2(Int_I n)
{
    return (n&(n-1)) == 0;
}

inline Bool ispow2(Llong_I n)
{
    return (n&(n-1)) == 0;
}


inline Int to_num(Char_I x) { return (Int)x; }

inline const Int to_num(Int_I x) { return x; }

inline const Llong to_num(Llong_I x) { return x; }

inline const Doub to_num(Doub_I x) { return x; }

inline const Comp to_num(Comp_I x) { return x; }


inline Int mod(Int_I i, Int_I n)
{
    return (i % n + n) % n;
}

inline Llong mod(Llong_I i, Llong_I n)
{
    return (i % n + n) % n;
}

inline Llong mod(Llong_I i, Int_I n)
{
    return (i % n + n) % n;
}

// s = n * d + return
inline Doub mod(Long_O n, Doub_I s, Doub_I d)
{
    n = floor(s/d);
    return s - n * d;
}

inline Doub mod(Doub_I s, Doub_I d)
{
    return s - floor(s/d) * d;
}


inline Char sqr(Char_I a) { return a * a; }

inline Int sqr(Int_I a) { return a * a; }

inline Llong sqr(Llong_I a) { return a * a; }

inline Doub sqr(Doub_I a) { return a * a; }

inline Comp sqr(Comp_I a) { return a * a; }


inline Int abs2(Int_I a)
{
    return a * a;
}

inline Doub abs2(Doub_I a)
{
    return a * a;
}

inline Doub abs2(Comp_I &a)
{
    return sqr(real(a)) + sqr(imag(a));
}


inline Doub factorial_imp(Doub_I n) {
    if (n == 0. || n == 1.)
        return 1.;
    else
        return n * factorial_imp(n - 1.);
}

inline Doub factorial(Int_I n) {
    if (n > 170)
        SLS_ERR("n too large!");
    return factorial_imp(n);
}

inline Float sinc(Float_I x) { return x == 0.f ? 1.f : sin(x) / x; }

inline Doub sinc(Doub_I x) { return x == 0. ? 1. : sin(x) / x; }

} // namespace slisc
