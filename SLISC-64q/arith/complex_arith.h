// complex related functions

#pragma once
#include "../global.h"

namespace slisc {
inline bool operator==(Char_I s1, Fcomp_I s2) { return real(s2) == s1 && imag(s2) == 0; }
inline bool operator!=(Char_I s1, Fcomp_I s2) { return !(s1 == s2); }

inline bool operator==(Char_I s1, Comp_I s2) { return real(s2) == s1 && imag(s2) == 0; }
inline bool operator!=(Char_I s1, Comp_I s2) { return !(s1 == s2); }

inline bool operator==(Char_I s1, Lcomp_I s2) { return real(s2) == s1 && imag(s2) == 0; }
inline bool operator!=(Char_I s1, Lcomp_I s2) { return !(s1 == s2); }

inline bool operator==(Char_I s1, Qcomp_I s2) { return real(s2) == s1 && imag(s2) == 0; }
inline bool operator!=(Char_I s1, Qcomp_I s2) { return !(s1 == s2); }

inline bool operator==(Int_I s1, Fcomp_I s2) { return real(s2) == s1 && imag(s2) == 0; }
inline bool operator!=(Int_I s1, Fcomp_I s2) { return !(s1 == s2); }

inline bool operator==(Int_I s1, Comp_I s2) { return real(s2) == s1 && imag(s2) == 0; }
inline bool operator!=(Int_I s1, Comp_I s2) { return !(s1 == s2); }

inline bool operator==(Int_I s1, Lcomp_I s2) { return real(s2) == s1 && imag(s2) == 0; }
inline bool operator!=(Int_I s1, Lcomp_I s2) { return !(s1 == s2); }

inline bool operator==(Int_I s1, Qcomp_I s2) { return real(s2) == s1 && imag(s2) == 0; }
inline bool operator!=(Int_I s1, Qcomp_I s2) { return !(s1 == s2); }

inline bool operator==(Float_I s1, Comp_I s2) { return real(s2) == s1 && imag(s2) == 0; }
inline bool operator!=(Float_I s1, Comp_I s2) { return !(s1 == s2); }

inline bool operator==(Float_I s1, Lcomp_I s2) { return real(s2) == s1 && imag(s2) == 0; }
inline bool operator!=(Float_I s1, Lcomp_I s2) { return !(s1 == s2); }

inline bool operator==(Float_I s1, Qcomp_I s2) { return real(s2) == s1 && imag(s2) == 0; }
inline bool operator!=(Float_I s1, Qcomp_I s2) { return !(s1 == s2); }

inline bool operator==(Doub_I s1, Fcomp_I s2) { return real(s2) == s1 && imag(s2) == 0; }
inline bool operator!=(Doub_I s1, Fcomp_I s2) { return !(s1 == s2); }

inline bool operator==(Doub_I s1, Lcomp_I s2) { return real(s2) == s1 && imag(s2) == 0; }
inline bool operator!=(Doub_I s1, Lcomp_I s2) { return !(s1 == s2); }

inline bool operator==(Ldoub_I s1, Fcomp_I s2) { return real(s2) == s1 && imag(s2) == 0; }
inline bool operator!=(Ldoub_I s1, Fcomp_I s2) { return !(s1 == s2); }

inline bool operator==(Ldoub_I s1, Comp_I s2) { return real(s2) == s1 && imag(s2) == 0; }
inline bool operator!=(Ldoub_I s1, Comp_I s2) { return !(s1 == s2); }

inline bool operator==(Ldoub_I s1, Qcomp_I s2) { return real(s2) == s1 && imag(s2) == 0; }
inline bool operator!=(Ldoub_I s1, Qcomp_I s2) { return !(s1 == s2); }

inline bool operator==(Fcomp_I s1, Char_I s2) { return real(s1) == s2 && imag(s1) == 0; }
inline bool operator!=(Fcomp_I s1, Char_I s2) { return !(s1 == s2); }

inline bool operator==(Comp_I s1, Char_I s2) { return real(s1) == s2 && imag(s1) == 0; }
inline bool operator!=(Comp_I s1, Char_I s2) { return !(s1 == s2); }

inline bool operator==(Qcomp_I s1, Char_I s2) { return real(s1) == s2 && imag(s1) == 0; }
inline bool operator!=(Qcomp_I s1, Char_I s2) { return !(s1 == s2); }

inline bool operator==(Lcomp_I s1, Char_I s2) { return real(s1) == s2 && imag(s1) == 0; }
inline bool operator!=(Lcomp_I s1, Char_I s2) { return !(s1 == s2); }

inline bool operator==(Fcomp_I s1, Int_I s2) { return real(s1) == s2 && imag(s1) == 0; }
inline bool operator!=(Fcomp_I s1, Int_I s2) { return !(s1 == s2); }

inline bool operator==(Comp_I s1, Int_I s2) { return real(s1) == s2 && imag(s1) == 0; }
inline bool operator!=(Comp_I s1, Int_I s2) { return !(s1 == s2); }

inline bool operator==(Lcomp_I s1, Int_I s2) { return real(s1) == s2 && imag(s1) == 0; }
inline bool operator!=(Lcomp_I s1, Int_I s2) { return !(s1 == s2); }

inline bool operator==(Qcomp_I s1, Int_I s2) { return real(s1) == s2 && imag(s1) == 0; }
inline bool operator!=(Qcomp_I s1, Int_I s2) { return !(s1 == s2); }

inline bool operator==(Comp_I s1, Float_I s2) { return real(s1) == s2 && imag(s1) == 0; }
inline bool operator!=(Comp_I s1, Float_I s2) { return !(s1 == s2); }

inline bool operator==(Lcomp_I s1, Float_I s2) { return real(s1) == s2 && imag(s1) == 0; }
inline bool operator!=(Lcomp_I s1, Float_I s2) { return !(s1 == s2); }

inline bool operator==(Qcomp_I s1, Float_I s2) { return real(s1) == s2 && imag(s1) == 0; }
inline bool operator!=(Qcomp_I s1, Float_I s2) { return !(s1 == s2); }

inline bool operator==(Fcomp_I s1, Doub_I s2) { return real(s1) == s2 && imag(s1) == 0; }
inline bool operator!=(Fcomp_I s1, Doub_I s2) { return !(s1 == s2); }

inline bool operator==(Lcomp_I s1, Doub_I s2) { return real(s1) == s2 && imag(s1) == 0; }
inline bool operator!=(Lcomp_I s1, Doub_I s2) { return !(s1 == s2); }

inline bool operator==(Fcomp_I s1, Ldoub_I s2) { return real(s1) == s2 && imag(s1) == 0; }
inline bool operator!=(Fcomp_I s1, Ldoub_I s2) { return !(s1 == s2); }

inline bool operator==(Comp_I s1, Ldoub_I s2) { return real(s1) == s2 && imag(s1) == 0; }
inline bool operator!=(Comp_I s1, Ldoub_I s2) { return !(s1 == s2); }

inline bool operator==(Qcomp_I s1, Ldoub_I s2) { return real(s1) == s2 && imag(s1) == 0; }
inline bool operator!=(Qcomp_I s1, Ldoub_I s2) { return !(s1 == s2); }

inline bool operator==(Fcomp_I s1, Comp_I s2) { return real(s1) == real(s2) && imag(s1) == imag(s2); }
inline bool operator!=(Fcomp_I s1, Comp_I s2) { return !(s1 == s2); }

inline bool operator==(Fcomp_I s1, Lcomp_I s2) { return real(s1) == real(s2) && imag(s1) == imag(s2); }
inline bool operator!=(Fcomp_I s1, Lcomp_I s2) { return !(s1 == s2); }

inline bool operator==(Fcomp_I s1, Qcomp_I s2) { return real(s1) == real(s2) && imag(s1) == imag(s2); }
inline bool operator!=(Fcomp_I s1, Qcomp_I s2) { return !(s1 == s2); }

inline bool operator==(Comp_I s1, Fcomp_I s2) { return real(s1) == real(s2) && imag(s1) == imag(s2); }
inline bool operator!=(Comp_I s1, Fcomp_I s2) { return !(s1 == s2); }

inline bool operator==(Comp_I s1, Lcomp_I s2) { return real(s1) == real(s2) && imag(s1) == imag(s2); }
inline bool operator!=(Comp_I s1, Lcomp_I s2) { return !(s1 == s2); }

inline bool operator==(Comp_I s1, Qcomp_I s2) { return real(s1) == real(s2) && imag(s1) == imag(s2); }
inline bool operator!=(Comp_I s1, Qcomp_I s2) { return !(s1 == s2); }

inline bool operator==(Lcomp_I s1, Fcomp_I s2) { return real(s1) == real(s2) && imag(s1) == imag(s2); }
inline bool operator!=(Lcomp_I s1, Fcomp_I s2) { return !(s1 == s2); }

inline bool operator==(Lcomp_I s1, Comp_I s2) { return real(s1) == real(s2) && imag(s1) == imag(s2); }
inline bool operator!=(Lcomp_I s1, Comp_I s2) { return !(s1 == s2); }

inline bool operator==(Lcomp_I s1, Qcomp_I s2) { return real(s1) == real(s2) && imag(s1) == imag(s2); }
inline bool operator!=(Lcomp_I s1, Qcomp_I s2) { return !(s1 == s2); }


// reference to real/imaginary part
inline Float &real_r(Fcomp &c) { return *((Float*)&c); }
inline Float &imag_r(Fcomp &c) { return *((Float*)&c + 1); }

inline Float *real_p(Fcomp &c) { return (Float*)&c; }
inline const Float *real_p(const Fcomp &c) { return (const Float*)&c; }
inline Float *imag_p(Fcomp &c) { return (Float*)&c + 1; }
inline const Float *imag_p(const Fcomp &c) { return (const Float*)&c + 1; }

inline Doub &real_r(Comp &c) { return *((Doub*)&c); }
inline Doub &imag_r(Comp &c) { return *((Doub*)&c + 1); }

inline Doub *real_p(Comp &c) { return (Doub*)&c; }
inline const Doub *real_p(const Comp &c) { return (const Doub*)&c; }
inline Doub *imag_p(Comp &c) { return (Doub*)&c + 1; }
inline const Doub *imag_p(const Comp &c) { return (const Doub*)&c + 1; }

inline Ldoub &real_r(Lcomp &c) { return *((Ldoub*)&c); }
inline Ldoub &imag_r(Lcomp &c) { return *((Ldoub*)&c + 1); }

inline Ldoub *real_p(Lcomp &c) { return (Ldoub*)&c; }
inline const Ldoub *real_p(const Lcomp &c) { return (const Ldoub*)&c; }
inline Ldoub *imag_p(Lcomp &c) { return (Ldoub*)&c + 1; }
inline const Ldoub *imag_p(const Lcomp &c) { return (const Ldoub*)&c + 1; }

inline Qdoub &real_r(Qcomp &c) { return *((Qdoub*)&c); }
inline Qdoub &imag_r(Qcomp &c) { return *((Qdoub*)&c + 1); }

inline Qdoub *real_p(Qcomp &c) { return (Qdoub*)&c; }
inline const Qdoub *real_p(const Qcomp &c) { return (const Qdoub*)&c; }
inline Qdoub *imag_p(Qcomp &c) { return (Qdoub*)&c + 1; }
inline const Qdoub *imag_p(const Qcomp &c) { return (const Qdoub*)&c + 1; }


inline void operator+=(Comp_O z, Float_I x) { z += (Doub)x; }
inline void operator-=(Comp_O z, Float_I x) { z -= (Doub)x; }
inline void operator*=(Comp_O z, Float_I x) { z *= (Doub)x; }
inline void operator/=(Comp_O z, Float_I x) { z /= (Doub)x; }

inline void operator+=(Lcomp_O z, Float_I x) { z += (Ldoub)x; }
inline void operator-=(Lcomp_O z, Float_I x) { z -= (Ldoub)x; }
inline void operator*=(Lcomp_O z, Float_I x) { z *= (Ldoub)x; }
inline void operator/=(Lcomp_O z, Float_I x) { z /= (Ldoub)x; }

inline void operator+=(Lcomp_O z, Doub_I x) { z += (Ldoub)x; }
inline void operator-=(Lcomp_O z, Doub_I x) { z -= (Ldoub)x; }
inline void operator*=(Lcomp_O z, Doub_I x) { z *= (Ldoub)x; }
inline void operator/=(Lcomp_O z, Doub_I x) { z /= (Ldoub)x; }

inline void operator+=(Comp_O z, Fcomp_I x) { z += (Comp)x; }
inline void operator-=(Comp_O z, Fcomp_I x) { z -= (Comp)x; }
inline void operator*=(Comp_O z, Fcomp_I x) { z *= (Comp)x; }
inline void operator/=(Comp_O z, Fcomp_I x) { z /= (Comp)x; }

inline void operator+=(Lcomp_O z, Fcomp_I x) { z += (Lcomp)x; }
inline void operator-=(Lcomp_O z, Fcomp_I x) { z -= (Lcomp)x; }
inline void operator*=(Lcomp_O z, Fcomp_I x) { z *= (Lcomp)x; }
inline void operator/=(Lcomp_O z, Fcomp_I x) { z /= (Lcomp)x; }

inline void operator+=(Lcomp_O z, Comp_I x) { z += (Lcomp)x; }
inline void operator-=(Lcomp_O z, Comp_I x) { z -= (Lcomp)x; }
inline void operator*=(Lcomp_O z, Comp_I x) { z *= (Lcomp)x; }
inline void operator/=(Lcomp_O z, Comp_I x) { z /= (Lcomp)x; }


inline Fcomp operator+(Char_I s1, Fcomp_I s2) { return Fcomp(s1 + real(s2), imag(s2)); }

inline Fcomp operator-(Char_I s1, Fcomp_I s2) { return Fcomp(s1 - real(s2), -imag(s2)); }

inline Fcomp operator*(Char_I s1, Fcomp_I s2) { return Fcomp(s1*real(s2), s1*imag(s2)); }

inline Fcomp operator/(Char_I s1, Fcomp_I s2) { return (Float)s1 / s2; }

inline Comp operator+(Char_I s1, Comp_I s2) { return Comp(s1 + real(s2), imag(s2)); }

inline Comp operator-(Char_I s1, Comp_I s2) { return Comp(s1 - real(s2), -imag(s2)); }

inline Comp operator*(Char_I s1, Comp_I s2) { return Comp(s1*real(s2), s1*imag(s2)); }

inline Comp operator/(Char_I s1, Comp_I s2) { return (Doub)s1 / s2; }

inline Lcomp operator+(Char_I s1, Lcomp_I s2) { return Lcomp(s1 + real(s2), imag(s2)); }

inline Lcomp operator-(Char_I s1, Lcomp_I s2) { return Lcomp(s1 - real(s2), -imag(s2)); }

inline Lcomp operator*(Char_I s1, Lcomp_I s2) { return Lcomp(s1*real(s2), s1*imag(s2)); }

inline Lcomp operator/(Char_I s1, Lcomp_I s2) { return (Ldoub)s1 / s2; }

inline Fcomp operator+(Int_I s1, Fcomp_I s2) { return Fcomp(s1 + real(s2), imag(s2)); }

inline Fcomp operator-(Int_I s1, Fcomp_I s2) { return Fcomp(s1 - real(s2), -imag(s2)); }

inline Fcomp operator*(Int_I s1, Fcomp_I s2) { return Fcomp(s1*real(s2), s1*imag(s2)); }

inline Fcomp operator/(Int_I s1, Fcomp_I s2) { return (Float)s1 / s2; }

inline Comp operator+(Int_I s1, Comp_I s2) { return Comp(s1 + real(s2), imag(s2)); }

inline Comp operator-(Int_I s1, Comp_I s2) { return Comp(s1 - real(s2), -imag(s2)); }

inline Comp operator*(Int_I s1, Comp_I s2) { return Comp(s1*real(s2), s1*imag(s2)); }

inline Comp operator/(Int_I s1, Comp_I s2) { return (Doub)s1 / s2; }

inline Lcomp operator+(Int_I s1, Lcomp_I s2) { return Lcomp(s1 + real(s2), imag(s2)); }

inline Lcomp operator-(Int_I s1, Lcomp_I s2) { return Lcomp(s1 - real(s2), -imag(s2)); }

inline Lcomp operator*(Int_I s1, Lcomp_I s2) { return Lcomp(s1*real(s2), s1*imag(s2)); }

inline Lcomp operator/(Int_I s1, Lcomp_I s2) { return (Ldoub)s1 / s2; }

inline Qcomp operator+(Int_I s1, Qcomp_I s2) { return Qcomp(s1 + real(s2), imag(s2)); }

inline Qcomp operator-(Int_I s1, Qcomp_I s2) { return Qcomp(s1 - real(s2), -imag(s2)); }

inline Qcomp operator*(Int_I s1, Qcomp_I s2) { return Qcomp(s1*real(s2), s1*imag(s2)); }

inline Qcomp operator/(Int_I s1, Qcomp_I s2) { return (Qdoub)s1 / s2; }

inline Fcomp operator+(Llong_I s1, Fcomp_I s2) { return Fcomp(s1 + real(s2), imag(s2)); }

inline Fcomp operator-(Llong_I s1, Fcomp_I s2) { return Fcomp(s1 - real(s2), -imag(s2)); }

inline Fcomp operator*(Llong_I s1, Fcomp_I s2) { return Fcomp(s1*real(s2), s1*imag(s2)); }

inline Fcomp operator/(Llong_I s1, Fcomp_I s2) { return (Float)s1 / s2; }

inline Comp operator+(Llong_I s1, Comp_I s2) { return Comp(s1 + real(s2), imag(s2)); }

inline Comp operator-(Llong_I s1, Comp_I s2) { return Comp(s1 - real(s2), -imag(s2)); }

inline Comp operator*(Llong_I s1, Comp_I s2) { return Comp(s1*real(s2), s1*imag(s2)); }

inline Comp operator/(Llong_I s1, Comp_I s2) { return (Doub)s1 / s2; }

inline Lcomp operator+(Llong_I s1, Lcomp_I s2) { return Lcomp(s1 + real(s2), imag(s2)); }

inline Lcomp operator-(Llong_I s1, Lcomp_I s2) { return Lcomp(s1 - real(s2), -imag(s2)); }

inline Lcomp operator*(Llong_I s1, Lcomp_I s2) { return Lcomp(s1*real(s2), s1*imag(s2)); }

inline Lcomp operator/(Llong_I s1, Lcomp_I s2) { return (Ldoub)s1 / s2; }

inline Qcomp operator+(Llong_I s1, Qcomp_I s2) { return Qcomp(s1 + real(s2), imag(s2)); }

inline Qcomp operator-(Llong_I s1, Qcomp_I s2) { return Qcomp(s1 - real(s2), -imag(s2)); }

inline Qcomp operator*(Llong_I s1, Qcomp_I s2) { return Qcomp(s1*real(s2), s1*imag(s2)); }

inline Qcomp operator/(Llong_I s1, Qcomp_I s2) { return (Qdoub)s1 / s2; }

inline Comp operator+(Float_I s1, Comp_I s2) { return Comp(s1 + real(s2), imag(s2)); }

inline Comp operator-(Float_I s1, Comp_I s2) { return Comp(s1 - real(s2), -imag(s2)); }

inline Comp operator*(Float_I s1, Comp_I s2) { return Comp(s1*real(s2), s1*imag(s2)); }

inline Comp operator/(Float_I s1, Comp_I s2) { return (Doub)s1 / s2; }

inline Lcomp operator+(Float_I s1, Lcomp_I s2) { return Lcomp(s1 + real(s2), imag(s2)); }

inline Lcomp operator-(Float_I s1, Lcomp_I s2) { return Lcomp(s1 - real(s2), -imag(s2)); }

inline Lcomp operator*(Float_I s1, Lcomp_I s2) { return Lcomp(s1*real(s2), s1*imag(s2)); }

inline Lcomp operator/(Float_I s1, Lcomp_I s2) { return (Ldoub)s1 / s2; }

inline Comp operator+(Doub_I s1, Fcomp_I s2) { return Comp(s1 + real(s2), imag(s2)); }

inline Comp operator-(Doub_I s1, Fcomp_I s2) { return Comp(s1 - real(s2), -imag(s2)); }

inline Comp operator*(Doub_I s1, Fcomp_I s2) { return Comp(s1*real(s2), s1*imag(s2)); }

inline Comp operator/(Doub_I s1, Fcomp_I s2) { return s1 / (Comp)s2; }

inline Lcomp operator+(Doub_I s1, Lcomp_I s2) { return Lcomp(s1 + real(s2), imag(s2)); }

inline Lcomp operator-(Doub_I s1, Lcomp_I s2) { return Lcomp(s1 - real(s2), -imag(s2)); }

inline Lcomp operator*(Doub_I s1, Lcomp_I s2) { return Lcomp(s1*real(s2), s1*imag(s2)); }

inline Lcomp operator/(Doub_I s1, Lcomp_I s2) { return (Ldoub)s1 / s2; }

inline Lcomp operator+(Ldoub_I s1, Fcomp_I s2) { return Lcomp(s1 + real(s2), imag(s2)); }

inline Lcomp operator-(Ldoub_I s1, Fcomp_I s2) { return Lcomp(s1 - real(s2), -imag(s2)); }

inline Lcomp operator*(Ldoub_I s1, Fcomp_I s2) { return Lcomp(s1*real(s2), s1*imag(s2)); }

inline Lcomp operator/(Ldoub_I s1, Fcomp_I s2) { return s1 / (Lcomp)s2; }

inline Lcomp operator+(Ldoub_I s1, Comp_I s2) { return Lcomp(s1 + real(s2), imag(s2)); }

inline Lcomp operator-(Ldoub_I s1, Comp_I s2) { return Lcomp(s1 - real(s2), -imag(s2)); }

inline Lcomp operator*(Ldoub_I s1, Comp_I s2) { return Lcomp(s1*real(s2), s1*imag(s2)); }

inline Lcomp operator/(Ldoub_I s1, Comp_I s2) { return s1 / (Lcomp)s2; }

inline Fcomp operator+(Fcomp_I s1, Char_I s2) { return Fcomp(real(s1) + s2, imag(s1)); }

inline Fcomp operator-(Fcomp_I s1, Char_I s2) { return Fcomp(real(s1) - s2, imag(s1)); }

inline Fcomp operator*(Fcomp_I s1, Char_I s2) { return Fcomp(real(s1)*s2, imag(s1)*s2); }

inline Fcomp operator/(Fcomp_I s1, Char_I s2) { return s1 / (Float)s2; }

inline Comp operator+(Comp_I s1, Char_I s2) { return Comp(real(s1) + s2, imag(s1)); }

inline Comp operator-(Comp_I s1, Char_I s2) { return Comp(real(s1) - s2, imag(s1)); }

inline Comp operator*(Comp_I s1, Char_I s2) { return Comp(real(s1)*s2, imag(s1)*s2); }

inline Comp operator/(Comp_I s1, Char_I s2) { return s1 / (Doub)s2; }

inline Lcomp operator+(Lcomp_I s1, Char_I s2) { return Lcomp(real(s1) + s2, imag(s1)); }

inline Lcomp operator-(Lcomp_I s1, Char_I s2) { return Lcomp(real(s1) - s2, imag(s1)); }

inline Lcomp operator*(Lcomp_I s1, Char_I s2) { return Lcomp(real(s1)*s2, imag(s1)*s2); }

inline Lcomp operator/(Lcomp_I s1, Char_I s2) { return s1 / (Ldoub)s2; }

inline Fcomp operator+(Fcomp_I s1, Int_I s2) { return Fcomp(real(s1) + s2, imag(s1)); }

inline Fcomp operator-(Fcomp_I s1, Int_I s2) { return Fcomp(real(s1) - s2, imag(s1)); }

inline Fcomp operator*(Fcomp_I s1, Int_I s2) { return Fcomp(real(s1)*s2, imag(s1)*s2); }

inline Fcomp operator/(Fcomp_I s1, Int_I s2) { return s1 / (Float)s2; }

inline Comp operator+(Comp_I s1, Int_I s2) { return Comp(real(s1) + s2, imag(s1)); }

inline Comp operator-(Comp_I s1, Int_I s2) { return Comp(real(s1) - s2, imag(s1)); }

inline Comp operator*(Comp_I s1, Int_I s2) { return Comp(real(s1)*s2, imag(s1)*s2); }

inline Comp operator/(Comp_I s1, Int_I s2) { return s1 / (Doub)s2; }

inline Lcomp operator+(Lcomp_I s1, Int_I s2) { return Lcomp(real(s1) + s2, imag(s1)); }

inline Lcomp operator-(Lcomp_I s1, Int_I s2) { return Lcomp(real(s1) - s2, imag(s1)); }

inline Lcomp operator*(Lcomp_I s1, Int_I s2) { return Lcomp(real(s1)*s2, imag(s1)*s2); }

inline Lcomp operator/(Lcomp_I s1, Int_I s2) { return s1 / (Ldoub)s2; }

inline Qcomp operator+(Qcomp_I s1, Int_I s2) { return Qcomp(real(s1) + s2, imag(s1)); }

inline Qcomp operator-(Qcomp_I s1, Int_I s2) { return Qcomp(real(s1) - s2, imag(s1)); }

inline Qcomp operator*(Qcomp_I s1, Int_I s2) { return Qcomp(real(s1)*s2, imag(s1)*s2); }

inline Qcomp operator/(Qcomp_I s1, Int_I s2) { return s1 / (Qdoub)s2; }

inline Fcomp operator+(Fcomp_I s1, Llong_I s2) { return Fcomp(real(s1) + s2, imag(s1)); }

inline Fcomp operator-(Fcomp_I s1, Llong_I s2) { return Fcomp(real(s1) - s2, imag(s1)); }

inline Fcomp operator*(Fcomp_I s1, Llong_I s2) { return Fcomp(real(s1)*s2, imag(s1)*s2); }

inline Fcomp operator/(Fcomp_I s1, Llong_I s2) { return s1 / (Float)s2; }

inline Comp operator+(Comp_I s1, Llong_I s2) { return Comp(real(s1) + s2, imag(s1)); }

inline Comp operator-(Comp_I s1, Llong_I s2) { return Comp(real(s1) - s2, imag(s1)); }

inline Comp operator*(Comp_I s1, Llong_I s2) { return Comp(real(s1)*s2, imag(s1)*s2); }

inline Comp operator/(Comp_I s1, Llong_I s2) { return s1 / (Doub)s2; }

inline Lcomp operator+(Lcomp_I s1, Llong_I s2) { return Lcomp(real(s1) + s2, imag(s1)); }

inline Lcomp operator-(Lcomp_I s1, Llong_I s2) { return Lcomp(real(s1) - s2, imag(s1)); }

inline Lcomp operator*(Lcomp_I s1, Llong_I s2) { return Lcomp(real(s1)*s2, imag(s1)*s2); }

inline Lcomp operator/(Lcomp_I s1, Llong_I s2) { return s1 / (Ldoub)s2; }

inline Qcomp operator+(Qcomp_I s1, Llong_I s2) { return Qcomp(real(s1) + s2, imag(s1)); }

inline Qcomp operator-(Qcomp_I s1, Llong_I s2) { return Qcomp(real(s1) - s2, imag(s1)); }

inline Qcomp operator*(Qcomp_I s1, Llong_I s2) { return Qcomp(real(s1)*s2, imag(s1)*s2); }

inline Qcomp operator/(Qcomp_I s1, Llong_I s2) { return s1 / (Qdoub)s2; }

inline Comp operator+(Comp_I s1, Float_I s2) { return Comp(real(s1) + s2, imag(s1)); }

inline Comp operator-(Comp_I s1, Float_I s2) { return Comp(real(s1) - s2, imag(s1)); }

inline Comp operator*(Comp_I s1, Float_I s2) { return Comp(real(s1)*s2, imag(s1)*s2); }

inline Comp operator/(Comp_I s1, Float_I s2) { return s1 / (Doub)s2; }

inline Lcomp operator+(Lcomp_I s1, Float_I s2) { return Lcomp(real(s1) + s2, imag(s1)); }

inline Lcomp operator-(Lcomp_I s1, Float_I s2) { return Lcomp(real(s1) - s2, imag(s1)); }

inline Lcomp operator*(Lcomp_I s1, Float_I s2) { return Lcomp(real(s1)*s2, imag(s1)*s2); }

inline Lcomp operator/(Lcomp_I s1, Float_I s2) { return s1 / (Ldoub)s2; }

inline Comp operator+(Fcomp_I s1, Doub_I s2) { return Comp(real(s1) + s2, imag(s1)); }

inline Comp operator-(Fcomp_I s1, Doub_I s2) { return Comp(real(s1) - s2, imag(s1)); }

inline Comp operator*(Fcomp_I s1, Doub_I s2) { return Comp(real(s1)*s2, imag(s1)*s2); }

inline Comp operator/(Fcomp_I s1, Doub_I s2) { return (Comp)s1 / s2; }

inline Lcomp operator+(Lcomp_I s1, Doub_I s2) { return Lcomp(real(s1) + s2, imag(s1)); }

inline Lcomp operator-(Lcomp_I s1, Doub_I s2) { return Lcomp(real(s1) - s2, imag(s1)); }

inline Lcomp operator*(Lcomp_I s1, Doub_I s2) { return Lcomp(real(s1)*s2, imag(s1)*s2); }

inline Lcomp operator/(Lcomp_I s1, Doub_I s2) { return s1 / (Ldoub)s2; }

inline Lcomp operator+(Fcomp_I s1, Ldoub_I s2) { return Lcomp(real(s1) + s2, imag(s1)); }

inline Lcomp operator-(Fcomp_I s1, Ldoub_I s2) { return Lcomp(real(s1) - s2, imag(s1)); }

inline Lcomp operator*(Fcomp_I s1, Ldoub_I s2) { return Lcomp(real(s1)*s2, imag(s1)*s2); }

inline Lcomp operator/(Fcomp_I s1, Ldoub_I s2) { return (Lcomp)s1 / s2; }

inline Lcomp operator+(Comp_I s1, Ldoub_I s2) { return Lcomp(real(s1) + s2, imag(s1)); }

inline Lcomp operator-(Comp_I s1, Ldoub_I s2) { return Lcomp(real(s1) - s2, imag(s1)); }

inline Lcomp operator*(Comp_I s1, Ldoub_I s2) { return Lcomp(real(s1)*s2, imag(s1)*s2); }

inline Lcomp operator/(Comp_I s1, Ldoub_I s2) { return (Lcomp)s1 / s2; }

inline Comp operator+(Fcomp_I s1, Comp_I s2) { return (Comp)s1 + s2; }

inline Comp operator-(Fcomp_I s1, Comp_I s2) { return (Comp)s1 - s2; }

inline Comp operator*(Fcomp_I s1, Comp_I s2) { return (Comp)s1 * s2; }

inline Comp operator/(Fcomp_I s1, Comp_I s2) { return (Comp)s1 / s2; }

inline Lcomp operator+(Fcomp_I s1, Lcomp_I s2) { return (Lcomp)s1 + s2; }

inline Lcomp operator-(Fcomp_I s1, Lcomp_I s2) { return (Lcomp)s1 - s2; }

inline Lcomp operator*(Fcomp_I s1, Lcomp_I s2) { return (Lcomp)s1 * s2; }

inline Lcomp operator/(Fcomp_I s1, Lcomp_I s2) { return (Lcomp)s1 / s2; }

inline Comp operator+(Comp_I s1, Fcomp_I s2) { return s1 + (Comp)s2; }

inline Comp operator-(Comp_I s1, Fcomp_I s2) { return s1 - (Comp)s2; }

inline Comp operator*(Comp_I s1, Fcomp_I s2) { return s1 * (Comp)s2; }

inline Comp operator/(Comp_I s1, Fcomp_I s2) { return s1 / (Comp)s2; }

inline Lcomp operator+(Comp_I s1, Lcomp_I s2) { return (Lcomp)s1 + s2; }

inline Lcomp operator-(Comp_I s1, Lcomp_I s2) { return (Lcomp)s1 - s2; }

inline Lcomp operator*(Comp_I s1, Lcomp_I s2) { return (Lcomp)s1 * s2; }

inline Lcomp operator/(Comp_I s1, Lcomp_I s2) { return (Lcomp)s1 / s2; }

inline Lcomp operator+(Lcomp_I s1, Fcomp_I s2) { return s1 + (Lcomp)s2; }

inline Lcomp operator-(Lcomp_I s1, Fcomp_I s2) { return s1 - (Lcomp)s2; }

inline Lcomp operator*(Lcomp_I s1, Fcomp_I s2) { return s1 * (Lcomp)s2; }

inline Lcomp operator/(Lcomp_I s1, Fcomp_I s2) { return s1 / (Lcomp)s2; }

inline Lcomp operator+(Lcomp_I s1, Comp_I s2) { return s1 + (Lcomp)s2; }

inline Lcomp operator-(Lcomp_I s1, Comp_I s2) { return s1 - (Lcomp)s2; }

inline Lcomp operator*(Lcomp_I s1, Comp_I s2) { return s1 * (Lcomp)s2; }

inline Lcomp operator/(Lcomp_I s1, Comp_I s2) { return s1 / (Lcomp)s2; }

} // namespace slisc
