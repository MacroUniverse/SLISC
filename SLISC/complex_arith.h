// complex related functions
#pragma once
#include "global.h"

namespace slisc {
inline constexpr Bool operator==(Float_I s1, Comp_I s2)
{
    return real(s2) == s1 && imag(s2) == 0;
}

inline constexpr Bool operator!=(Float_I s1, Comp_I s2)
{
    return !(s1 == s2);
}

inline constexpr Bool operator==(Fcomp_I s1, Comp_I s2)
{
    return real(s1) == real(s2) && imag(s1) == imag(s2);
}

inline constexpr Bool operator!=(Fcomp_I s1, Comp_I s2)
{
    return !(s1 == s2);
}

inline constexpr Bool operator==(Comp_I s1, Int_I s2)
{
    return real(s1) == s2 && imag(s1) == 0;
}

inline constexpr Bool operator!=(Comp_I s1, Int_I s2)
{
    return !(s1 == s2);
}

inline constexpr Bool operator==(Int_I s1, Comp_I s2)
{
    return real(s2) == s1 && imag(s2) == 0;
}

inline constexpr Bool operator!=(Int_I s1, Comp_I s2)
{
    return !(s1 == s2);
}

inline constexpr Bool operator==(Lcomp_I s1, Comp_I s2)
{
    return real(s1) == real(s2) && imag(s1) == imag(s2);
}

inline constexpr Bool operator!=(Lcomp_I s1, Comp_I s2)
{
    return !(s1 == s2);
}


inline void operator+=(Comp_O z, Float_I x)
{
    z += (Comp)x;
}

inline void operator-=(Comp_O z, Float_I x)
{
    z -= (Comp)x;
}

inline void operator*=(Comp_O z, Float_I x)
{
    z *= (Comp)x;
}

inline void operator/=(Comp_O z, Float_I x)
{
    z /= (Comp)x;
}


inline const Comp operator+(Float_I s1, Comp_I s2)
{
    return Comp(s1 + real(s2), imag(s2));
}

inline const Comp operator-(Float_I s1, Comp_I s2)
{
    return Comp(s1 - real(s2), -imag(s2));
}

inline const Comp operator*(Float_I s1, Comp_I s2)
{
    return Comp(s1*real(s2), s1*imag(s2));
}

inline const Comp operator/(Float_I s1, Comp_I s2)
{
    return (Doub)s1 / s2;
}

inline const Comp operator+(Comp_I s1, Int_I s2)
{
    return Comp(real(s1) + s2, imag(s1));
}

inline const Comp operator-(Comp_I s1, Int_I s2)
{
    return Comp(real(s1) - s2, imag(s1));
}

inline const Comp operator*(Comp_I s1, Int_I s2)
{
    return Comp(real(s1)*s2, imag(s1)*s2);
}

inline const Comp operator/(Comp_I s1, Int_I s2)
{
    return s1 / (Doub)s2;
}

inline const Comp operator+(Int_I s1, Comp_I s2)
{
    return Comp(s1 + real(s2), imag(s2));
}

inline const Comp operator-(Int_I s1, Comp_I s2)
{
    return Comp(s1 - real(s2), -imag(s2));
}

inline const Comp operator*(Int_I s1, Comp_I s2)
{
    return Comp(s1*real(s2), s1*imag(s2));
}

inline const Comp operator/(Int_I s1, Comp_I s2)
{
    return (Doub)s1 / s2;
}

inline const Comp operator+(Llong_I s1, Comp_I s2)
{
    return Comp(s1 + real(s2), imag(s2));
}

inline const Comp operator-(Llong_I s1, Comp_I s2)
{
    return Comp(s1 - real(s2), -imag(s2));
}

inline const Comp operator*(Llong_I s1, Comp_I s2)
{
    return Comp(s1*real(s2), s1*imag(s2));
}

inline const Comp operator/(Llong_I s1, Comp_I s2)
{
    return (Doub)s1 / s2;
}

inline const Comp operator+(Comp_I s1, Llong_I s2)
{
    return Comp(real(s1) + s2, imag(s1));
}

inline const Comp operator-(Comp_I s1, Llong_I s2)
{
    return Comp(real(s1) - s2, imag(s1));
}

inline const Comp operator*(Comp_I s1, Llong_I s2)
{
    return Comp(real(s1)*s2, imag(s1)*s2);
}

inline const Comp operator/(Comp_I s1, Llong_I s2)
{
    return s1 / (Doub)s2;
}

inline const Comp operator+(Comp_I s1, Char_I s2)
{
    return Comp(real(s1) + s2, imag(s1));
}

inline const Comp operator-(Comp_I s1, Char_I s2)
{
    return Comp(real(s1) - s2, imag(s1));
}

inline const Comp operator*(Comp_I s1, Char_I s2)
{
    return Comp(real(s1)*s2, imag(s1)*s2);
}

inline const Comp operator/(Comp_I s1, Char_I s2)
{
    return s1 / (Doub)s2;
}

inline const Comp operator+(Comp_I s1, Float_I s2)
{
    return Comp(real(s1) + s2, imag(s1));
}

inline const Comp operator-(Comp_I s1, Float_I s2)
{
    return Comp(real(s1) - s2, imag(s1));
}

inline const Comp operator*(Comp_I s1, Float_I s2)
{
    return Comp(real(s1)*s2, imag(s1)*s2);
}

inline const Comp operator/(Comp_I s1, Float_I s2)
{
    return s1 / (Doub)s2;
}

inline const Comp operator+(Doub_I s1, Fcomp_I s2)
{
    return Comp(s1 + real(s2), imag(s2));
}

inline const Comp operator-(Doub_I s1, Fcomp_I s2)
{
    return Comp(s1 - real(s2), -imag(s2));
}

inline const Comp operator*(Doub_I s1, Fcomp_I s2)
{
    return Comp(s1*real(s2), s1*imag(s2));
}

inline const Comp operator/(Doub_I s1, Fcomp_I s2)
{
    return s1 / (Comp)s2;
}

inline const Comp operator+(Fcomp_I s1, Comp_I s2)
{
    return (Comp)s1 + s2;
}

inline const Comp operator-(Fcomp_I s1, Comp_I s2)
{
    return (Comp)s1 - s2;
}

inline const Comp operator*(Fcomp_I s1, Comp_I s2)
{
    return (Comp)s1 * s2;
}

inline const Comp operator/(Fcomp_I s1, Comp_I s2)
{
    return (Comp)s1 / s2;
}

} // namespace slisc
