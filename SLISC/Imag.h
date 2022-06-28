// pure imaginary scalar type and arithmetics

#pragma once
#include "global.h"

namespace slisc {

class Fimag
{
protected:
    Float m_s;
public:
    Fimag() {};
    explicit Fimag(const Float &val);
    operator Fcomp() const;
    Float real() const;
    Float imag() const;
    void imag(Float_I val);
};

typedef const Fimag &Fimag_I;
typedef Fimag &Fimag_O, &Fimag_IO;

inline Fimag::Fimag(const Float &val): m_s(val) {}

inline Fimag::operator Fcomp() const
{
    return Fcomp(0, m_s);
}

inline Float Fimag::real() const
{
    return 0;
}

inline Float Fimag::imag() const
{
    return m_s;
}

inline void Fimag::imag(Float_I val)
{
    m_s = val;
}

// arithmetic

// real(), imag()
inline Float real(Fimag_I val)
{
    return 0;
}

inline Float imag(Fimag_I val)
{
    return val.imag();
}

inline Float abs(Fimag_I val)
{
    return val.imag();
}

class Imag
{
protected:
    Doub m_s;
public:
    Imag() {};
    explicit Imag(const Doub &val);
    operator Comp() const;
    Doub real() const;
    Doub imag() const;
    void imag(Doub_I val);
};

typedef const Imag &Imag_I;
typedef Imag &Imag_O, &Imag_IO;

inline Imag::Imag(const Doub &val): m_s(val) {}

inline Imag::operator Comp() const
{
    return Comp(0, m_s);
}

inline Doub Imag::real() const
{
    return 0;
}

inline Doub Imag::imag() const
{
    return m_s;
}

inline void Imag::imag(Doub_I val)
{
    m_s = val;
}

// arithmetic

// real(), imag()
inline Doub real(Imag_I val)
{
    return 0;
}

inline Doub imag(Imag_I val)
{
    return val.imag();
}

inline Doub abs(Imag_I val)
{
    return val.imag();
}

class Limag
{
protected:
    Ldoub m_s;
public:
    Limag() {};
    explicit Limag(const Ldoub &val);
    operator Lcomp() const;
    Ldoub real() const;
    Ldoub imag() const;
    void imag(Ldoub_I val);
};

typedef const Limag &Limag_I;
typedef Limag &Limag_O, &Limag_IO;

inline Limag::Limag(const Ldoub &val): m_s(val) {}

inline Limag::operator Lcomp() const
{
    return Lcomp(0, m_s);
}

inline Ldoub Limag::real() const
{
    return 0;
}

inline Ldoub Limag::imag() const
{
    return m_s;
}

inline void Limag::imag(Ldoub_I val)
{
    m_s = val;
}

// arithmetic

// real(), imag()
inline Ldoub real(Limag_I val)
{
    return 0;
}

inline Ldoub imag(Limag_I val)
{
    return val.imag();
}

inline Ldoub abs(Limag_I val)
{
    return val.imag();
}


// imaginary unit
const Imag I(1);

// imag +-*/ imag
inline Fimag operator+(Fimag_I z1, Fimag_I z2)
{ return Fimag(imag(z1) + imag(z2)); }

inline Fimag operator-(Fimag_I z1, Fimag_I z2)
{ return Fimag(imag(z1) - imag(z2)); }

inline Float operator*(Fimag_I z1, Fimag_I z2)
{ return -imag(z1) * imag(z2); }

inline Float operator/(Fimag_I z1, Fimag_I z2)
{ return imag(z1) / imag(z2); }

inline Imag operator+(Fimag_I z1, Imag_I z2)
{ return Imag(imag(z1) + imag(z2)); }

inline Imag operator-(Fimag_I z1, Imag_I z2)
{ return Imag(imag(z1) - imag(z2)); }

inline Doub operator*(Fimag_I z1, Imag_I z2)
{ return -imag(z1) * imag(z2); }

inline Doub operator/(Fimag_I z1, Imag_I z2)
{ return imag(z1) / imag(z2); }

inline Limag operator+(Fimag_I z1, Limag_I z2)
{ return Limag(imag(z1) + imag(z2)); }

inline Limag operator-(Fimag_I z1, Limag_I z2)
{ return Limag(imag(z1) - imag(z2)); }

inline Ldoub operator*(Fimag_I z1, Limag_I z2)
{ return -imag(z1) * imag(z2); }

inline Ldoub operator/(Fimag_I z1, Limag_I z2)
{ return imag(z1) / imag(z2); }

inline Imag operator+(Imag_I z1, Fimag_I z2)
{ return Imag(imag(z1) + imag(z2)); }

inline Imag operator-(Imag_I z1, Fimag_I z2)
{ return Imag(imag(z1) - imag(z2)); }

inline Doub operator*(Imag_I z1, Fimag_I z2)
{ return -imag(z1) * imag(z2); }

inline Doub operator/(Imag_I z1, Fimag_I z2)
{ return imag(z1) / imag(z2); }

inline Imag operator+(Imag_I z1, Imag_I z2)
{ return Imag(imag(z1) + imag(z2)); }

inline Imag operator-(Imag_I z1, Imag_I z2)
{ return Imag(imag(z1) - imag(z2)); }

inline Doub operator*(Imag_I z1, Imag_I z2)
{ return -imag(z1) * imag(z2); }

inline Doub operator/(Imag_I z1, Imag_I z2)
{ return imag(z1) / imag(z2); }

inline Limag operator+(Imag_I z1, Limag_I z2)
{ return Limag(imag(z1) + imag(z2)); }

inline Limag operator-(Imag_I z1, Limag_I z2)
{ return Limag(imag(z1) - imag(z2)); }

inline Ldoub operator*(Imag_I z1, Limag_I z2)
{ return -imag(z1) * imag(z2); }

inline Ldoub operator/(Imag_I z1, Limag_I z2)
{ return imag(z1) / imag(z2); }

inline Limag operator+(Limag_I z1, Fimag_I z2)
{ return Limag(imag(z1) + imag(z2)); }

inline Limag operator-(Limag_I z1, Fimag_I z2)
{ return Limag(imag(z1) - imag(z2)); }

inline Ldoub operator*(Limag_I z1, Fimag_I z2)
{ return -imag(z1) * imag(z2); }

inline Ldoub operator/(Limag_I z1, Fimag_I z2)
{ return imag(z1) / imag(z2); }

inline Limag operator+(Limag_I z1, Imag_I z2)
{ return Limag(imag(z1) + imag(z2)); }

inline Limag operator-(Limag_I z1, Imag_I z2)
{ return Limag(imag(z1) - imag(z2)); }

inline Ldoub operator*(Limag_I z1, Imag_I z2)
{ return -imag(z1) * imag(z2); }

inline Ldoub operator/(Limag_I z1, Imag_I z2)
{ return imag(z1) / imag(z2); }

inline Limag operator+(Limag_I z1, Limag_I z2)
{ return Limag(imag(z1) + imag(z2)); }

inline Limag operator-(Limag_I z1, Limag_I z2)
{ return Limag(imag(z1) - imag(z2)); }

inline Ldoub operator*(Limag_I z1, Limag_I z2)
{ return -imag(z1) * imag(z2); }

inline Ldoub operator/(Limag_I z1, Limag_I z2)
{ return imag(z1) / imag(z2); }


// TODO: use template
inline Comp operator+(Doub_I x, Imag_I y)
{
    return Comp(x, imag(y));
}

inline Comp operator+(Imag_I x, Doub_I y)
{
    return Comp(y, imag(x));
}

inline Comp operator+(Imag_I z1, Comp_I z2)
{
    return Comp(real(z2), imag(z1)+imag(z2));
}

inline Comp operator+(Comp_I z1, Imag_I z2)
{
    return z2 + z1;
}

// operator-
inline Imag operator-(Imag_I z)
{
    return Imag(-z.imag());
}

inline Comp operator-(Doub_I x, Imag_I z)
{
    return Comp(x, -z.imag());
}

inline Comp operator-(Imag_I z, Doub_I x)
{
    return Comp(-x, z.imag());
}

inline Comp operator-(Comp_I z1, Imag_I z2)
{
    return Comp(z1.real(), z1.imag() - z2.imag());
}

inline Comp operator-(Imag_I z1, Comp_I z2)
{
    return Comp(-z2.real(), z1.imag() - z2.imag());
}

// operator*
inline Imag operator*(Imag_I z, Doub_I x)
{
    return Imag(z.imag()*x);
}

inline Imag operator*(Doub_I x, Imag_I z)
{
    return Imag(z.imag()*x);
}

inline Comp operator*(Imag_I z1, Comp_I z2)
{
    return Comp(-z1.imag()*z2.imag(), z1.imag()*z2.real());
}

inline Comp operator*(Comp_I z1, Imag_I z2)
{
    return Comp(-z2.imag()*z1.imag(), z2.imag()*z1.real());
}

// operator/
inline Imag operator/(Imag_I z, Doub_I x)
{
    return Imag(z.imag() / x);
}

inline Imag operator/(Doub_I x, Imag_I z)
{
    return Imag(-x / z.imag());
}

inline Comp operator/(Comp_I z1, Imag_I z2)
{
    return Comp(z1.imag() / z2.imag(), -z1.real() / z2.imag());
}

// operator+=
inline void operator+=(Comp_IO z1, Imag_I z2)
{
    z1 = z1 + z2;
}

// operator-=
inline void operator-=(Comp_IO z1, Imag_I z2)
{
    z1 = z1 - z2;
}

// operator*=
inline void operator*=(Comp_IO z1, Imag_I z2)
{
    z1 = z1 * z2;
}

// operator/=
inline void operator/=(Comp_IO z1, Imag_I z2)
{
    z1 = z1 / z2;
}

// operator<<
inline std::ostream &operator<<(std::ostream &out, Imag_I num)
{
    out << num.imag() << 'i';
    return out;
}

} // namespace slisc
