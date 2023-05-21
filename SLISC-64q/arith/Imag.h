// pure imaginary scalar type and arithmetics
// this might not be necessary due to compiler optimization, need benchmark

#pragma once
#include "../global.h"

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

inline Fimag::operator Fcomp() const { return Fcomp(0, m_s); }

inline Float Fimag::real() const { return 0; }

inline Float Fimag::imag() const { return m_s; }

inline void Fimag::imag(Float_I val) { m_s = val; }

inline Float real(Fimag_I val) { return 0; }

inline Float imag(Fimag_I val) { return val.imag(); }

inline Float abs(Fimag_I val) { return val.imag(); }

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

inline Imag::operator Comp() const { return Comp(0, m_s); }

inline Doub Imag::real() const { return 0; }

inline Doub Imag::imag() const { return m_s; }

inline void Imag::imag(Doub_I val) { m_s = val; }

inline Doub real(Imag_I val) { return 0; }

inline Doub imag(Imag_I val) { return val.imag(); }

inline Doub abs(Imag_I val) { return val.imag(); }

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

inline Limag::operator Lcomp() const { return Lcomp(0, m_s); }

inline Ldoub Limag::real() const { return 0; }

inline Ldoub Limag::imag() const { return m_s; }

inline void Limag::imag(Ldoub_I val) { m_s = val; }

inline Ldoub real(Limag_I val) { return 0; }

inline Ldoub imag(Limag_I val) { return val.imag(); }

inline Ldoub abs(Limag_I val) { return val.imag(); }

class Qimag
{
protected:
	Qdoub m_s;
public:
	Qimag() {};
	explicit Qimag(const Qdoub &val);
	operator Qcomp() const;
	Qdoub real() const;
	Qdoub imag() const;
	void imag(Qdoub_I val);
};

typedef const Qimag &Qimag_I;
typedef Qimag &Qimag_O, &Qimag_IO;

inline Qimag::Qimag(const Qdoub &val): m_s(val) {}

inline Qimag::operator Qcomp() const { return Qcomp(0, m_s); }

inline Qdoub Qimag::real() const { return 0; }

inline Qdoub Qimag::imag() const { return m_s; }

inline void Qimag::imag(Qdoub_I val) { m_s = val; }

inline Qdoub real(Qimag_I val) { return 0; }

inline Qdoub imag(Qimag_I val) { return val.imag(); }

inline Qdoub abs(Qimag_I val) { return val.imag(); }


const Imag I(1);
#ifdef SLS_USE_QUAD_MATH
const Qimag Iq(1.Q);
#endif

// imag +-*/ imag
inline Fimag  operator+(Fimag_I z1, Fimag_I z2) { return Fimag(imag(z1) + imag(z2)); }
inline Fimag operator-(Fimag_I z1, Fimag_I z2) { return Fimag(imag(z1) - imag(z2)); }
inline Float  operator*(Fimag_I z1, Fimag_I z2) { return -imag(z1) * imag(z2); }
inline Float  operator/(Fimag_I z1, Fimag_I z2) { return imag(z1) / imag(z2); }
inline bool operator==(Fimag_I z1, Fimag_I z2) { return imag(z1) == imag(z2); }
inline bool operator!=(Fimag_I z1, Fimag_I z2) { return !(z1 == z2); }

inline Fcomp operator+(Float_I x1, Fimag_I z2) { return Fcomp(x1, imag(z2)); }
inline Fcomp operator-(Float_I x1, Fimag_I z2) { return Fcomp(x1, -imag(z2)); }
inline Fimag operator*(Float_I x1, Fimag_I z2) { return Fimag(x1 * imag(z2)); }
inline Fimag operator/(Float_I x1, Fimag_I z2) { return Fimag(-x1 / imag(z2)); }
inline bool operator==(Float_I x1, Fimag_I z2) { return x1 == 0 && imag(z2) == 0; }
inline bool operator!=(Float_I x1, Fimag_I z2) { return !(x1 == z2); }

inline Fcomp operator+(Fimag_I z1, Float_I x2) { return Fcomp(x2, imag(z1)); }
inline Fcomp operator-(Fimag_I z1, Float_I x2) { return Fcomp(-x2, imag(z1)); }
inline Fimag operator*(Fimag_I z1, Float_I x2) { return Fimag(x2 * imag(z1)); }
inline Fimag operator/(Fimag_I z1, Float_I x2) { return Fimag(imag(z1) / x2); }
inline bool operator==(Fimag_I z1, Float_I x2) { return imag(z1) == 0 && x2 == 0; }
inline bool operator!=(Fimag_I z1, Float_I x2) { return !(z1 == x2); }

inline Fcomp operator+(Fcomp_I z1, Fimag_I z2) { return Fcomp(real(z1), imag(z1) + imag(z2)); }
inline Fcomp operator-(Fcomp_I z1, Fimag_I z2) { return Fcomp(real(z1), imag(z1) - imag(z2)); }
inline Fcomp operator*(Fcomp_I z1, Fimag_I z2) { return Fcomp(-imag(z1)*imag(z2), real(z1)*imag(z2)); }
inline Fcomp operator/(Fcomp_I z1, Fimag_I z2) { return Fcomp(imag(z1)/imag(z2), -real(z1)/imag(z2)); }
inline bool operator==(Fcomp_I z1, Fimag_I z2) { return real(z1) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Fcomp_I z1, Fimag_I z2) { return !(z1 == z2); }

inline Fcomp operator+(Fimag_I z1, Fcomp_I z2) { return Fcomp(real(z2), imag(z2) + imag(z1)); }
inline Fcomp operator-(Fimag_I z1, Fcomp_I z2) { return Fcomp(-real(z2), imag(z1) - imag(z2)); }
inline Fcomp operator*(Fimag_I z1, Fcomp_I z2) { return Fcomp(-imag(z2)*imag(z1), real(z2)*imag(z1)); }
inline Fcomp operator/(Fimag_I z1, Fcomp_I z2) {
	const Float &x2 = real(z2), &y2 = imag(z2);
	return Fcomp(y2, x2) * Float(imag(z1) / (x2*x2 + y2*y2));
}
inline bool operator==(Fimag_I z1, Fcomp_I z2) { return real(z2) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Fimag_I z1, Fcomp_I z2) { return !(z1 == z2); }

inline Imag  operator+(Fimag_I z1, Imag_I z2) { return Imag(imag(z1) + imag(z2)); }
inline Imag operator-(Fimag_I z1, Imag_I z2) { return Imag(imag(z1) - imag(z2)); }
inline Doub  operator*(Fimag_I z1, Imag_I z2) { return -imag(z1) * imag(z2); }
inline Doub  operator/(Fimag_I z1, Imag_I z2) { return imag(z1) / imag(z2); }
inline bool operator==(Fimag_I z1, Imag_I z2) { return imag(z1) == imag(z2); }
inline bool operator!=(Fimag_I z1, Imag_I z2) { return !(z1 == z2); }

inline Comp operator+(Float_I x1, Imag_I z2) { return Comp(x1, imag(z2)); }
inline Comp operator-(Float_I x1, Imag_I z2) { return Comp(x1, -imag(z2)); }
inline Imag operator*(Float_I x1, Imag_I z2) { return Imag(x1 * imag(z2)); }
inline Imag operator/(Float_I x1, Imag_I z2) { return Imag(-x1 / imag(z2)); }
inline bool operator==(Float_I x1, Imag_I z2) { return x1 == 0 && imag(z2) == 0; }
inline bool operator!=(Float_I x1, Imag_I z2) { return !(x1 == z2); }

inline Comp operator+(Fimag_I z1, Doub_I x2) { return Comp(x2, imag(z1)); }
inline Comp operator-(Fimag_I z1, Doub_I x2) { return Comp(-x2, imag(z1)); }
inline Imag operator*(Fimag_I z1, Doub_I x2) { return Imag(x2 * imag(z1)); }
inline Imag operator/(Fimag_I z1, Doub_I x2) { return Imag(imag(z1) / x2); }
inline bool operator==(Fimag_I z1, Doub_I x2) { return imag(z1) == 0 && x2 == 0; }
inline bool operator!=(Fimag_I z1, Doub_I x2) { return !(z1 == x2); }

inline Comp operator+(Fcomp_I z1, Imag_I z2) { return Comp(real(z1), imag(z1) + imag(z2)); }
inline Comp operator-(Fcomp_I z1, Imag_I z2) { return Comp(real(z1), imag(z1) - imag(z2)); }
inline Comp operator*(Fcomp_I z1, Imag_I z2) { return Comp(-imag(z1)*imag(z2), real(z1)*imag(z2)); }
inline Comp operator/(Fcomp_I z1, Imag_I z2) { return Comp(imag(z1)/imag(z2), -real(z1)/imag(z2)); }
inline bool operator==(Fcomp_I z1, Imag_I z2) { return real(z1) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Fcomp_I z1, Imag_I z2) { return !(z1 == z2); }

inline Comp operator+(Fimag_I z1, Comp_I z2) { return Comp(real(z2), imag(z2) + imag(z1)); }
inline Comp operator-(Fimag_I z1, Comp_I z2) { return Comp(-real(z2), imag(z1) - imag(z2)); }
inline Comp operator*(Fimag_I z1, Comp_I z2) { return Comp(-imag(z2)*imag(z1), real(z2)*imag(z1)); }
inline Comp operator/(Fimag_I z1, Comp_I z2) {
	const Doub &x2 = real(z2), &y2 = imag(z2);
	return Comp(y2, x2) * Doub(imag(z1) / (x2*x2 + y2*y2));
}
inline bool operator==(Fimag_I z1, Comp_I z2) { return real(z2) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Fimag_I z1, Comp_I z2) { return !(z1 == z2); }

inline Limag  operator+(Fimag_I z1, Limag_I z2) { return Limag(imag(z1) + imag(z2)); }
inline Limag operator-(Fimag_I z1, Limag_I z2) { return Limag(imag(z1) - imag(z2)); }
inline Ldoub  operator*(Fimag_I z1, Limag_I z2) { return -imag(z1) * imag(z2); }
inline Ldoub  operator/(Fimag_I z1, Limag_I z2) { return imag(z1) / imag(z2); }
inline bool operator==(Fimag_I z1, Limag_I z2) { return imag(z1) == imag(z2); }
inline bool operator!=(Fimag_I z1, Limag_I z2) { return !(z1 == z2); }

inline Lcomp operator+(Float_I x1, Limag_I z2) { return Lcomp(x1, imag(z2)); }
inline Lcomp operator-(Float_I x1, Limag_I z2) { return Lcomp(x1, -imag(z2)); }
inline Limag operator*(Float_I x1, Limag_I z2) { return Limag(x1 * imag(z2)); }
inline Limag operator/(Float_I x1, Limag_I z2) { return Limag(-x1 / imag(z2)); }
inline bool operator==(Float_I x1, Limag_I z2) { return x1 == 0 && imag(z2) == 0; }
inline bool operator!=(Float_I x1, Limag_I z2) { return !(x1 == z2); }

inline Lcomp operator+(Fimag_I z1, Ldoub_I x2) { return Lcomp(x2, imag(z1)); }
inline Lcomp operator-(Fimag_I z1, Ldoub_I x2) { return Lcomp(-x2, imag(z1)); }
inline Limag operator*(Fimag_I z1, Ldoub_I x2) { return Limag(x2 * imag(z1)); }
inline Limag operator/(Fimag_I z1, Ldoub_I x2) { return Limag(imag(z1) / x2); }
inline bool operator==(Fimag_I z1, Ldoub_I x2) { return imag(z1) == 0 && x2 == 0; }
inline bool operator!=(Fimag_I z1, Ldoub_I x2) { return !(z1 == x2); }

inline Lcomp operator+(Fcomp_I z1, Limag_I z2) { return Lcomp(real(z1), imag(z1) + imag(z2)); }
inline Lcomp operator-(Fcomp_I z1, Limag_I z2) { return Lcomp(real(z1), imag(z1) - imag(z2)); }
inline Lcomp operator*(Fcomp_I z1, Limag_I z2) { return Lcomp(-imag(z1)*imag(z2), real(z1)*imag(z2)); }
inline Lcomp operator/(Fcomp_I z1, Limag_I z2) { return Lcomp(imag(z1)/imag(z2), -real(z1)/imag(z2)); }
inline bool operator==(Fcomp_I z1, Limag_I z2) { return real(z1) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Fcomp_I z1, Limag_I z2) { return !(z1 == z2); }

inline Lcomp operator+(Fimag_I z1, Lcomp_I z2) { return Lcomp(real(z2), imag(z2) + imag(z1)); }
inline Lcomp operator-(Fimag_I z1, Lcomp_I z2) { return Lcomp(-real(z2), imag(z1) - imag(z2)); }
inline Lcomp operator*(Fimag_I z1, Lcomp_I z2) { return Lcomp(-imag(z2)*imag(z1), real(z2)*imag(z1)); }
inline Lcomp operator/(Fimag_I z1, Lcomp_I z2) {
	const Ldoub &x2 = real(z2), &y2 = imag(z2);
	return Lcomp(y2, x2) * Ldoub(imag(z1) / (x2*x2 + y2*y2));
}
inline bool operator==(Fimag_I z1, Lcomp_I z2) { return real(z2) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Fimag_I z1, Lcomp_I z2) { return !(z1 == z2); }

inline Imag  operator+(Imag_I z1, Fimag_I z2) { return Imag(imag(z1) + imag(z2)); }
inline Imag operator-(Imag_I z1, Fimag_I z2) { return Imag(imag(z1) - imag(z2)); }
inline Doub  operator*(Imag_I z1, Fimag_I z2) { return -imag(z1) * imag(z2); }
inline Doub  operator/(Imag_I z1, Fimag_I z2) { return imag(z1) / imag(z2); }
inline bool operator==(Imag_I z1, Fimag_I z2) { return imag(z1) == imag(z2); }
inline bool operator!=(Imag_I z1, Fimag_I z2) { return !(z1 == z2); }

inline Comp operator+(Doub_I x1, Fimag_I z2) { return Comp(x1, imag(z2)); }
inline Comp operator-(Doub_I x1, Fimag_I z2) { return Comp(x1, -imag(z2)); }
inline Imag operator*(Doub_I x1, Fimag_I z2) { return Imag(x1 * imag(z2)); }
inline Imag operator/(Doub_I x1, Fimag_I z2) { return Imag(-x1 / imag(z2)); }
inline bool operator==(Doub_I x1, Fimag_I z2) { return x1 == 0 && imag(z2) == 0; }
inline bool operator!=(Doub_I x1, Fimag_I z2) { return !(x1 == z2); }

inline Comp operator+(Imag_I z1, Float_I x2) { return Comp(x2, imag(z1)); }
inline Comp operator-(Imag_I z1, Float_I x2) { return Comp(-x2, imag(z1)); }
inline Imag operator*(Imag_I z1, Float_I x2) { return Imag(x2 * imag(z1)); }
inline Imag operator/(Imag_I z1, Float_I x2) { return Imag(imag(z1) / x2); }
inline bool operator==(Imag_I z1, Float_I x2) { return imag(z1) == 0 && x2 == 0; }
inline bool operator!=(Imag_I z1, Float_I x2) { return !(z1 == x2); }

inline Comp operator+(Comp_I z1, Fimag_I z2) { return Comp(real(z1), imag(z1) + imag(z2)); }
inline Comp operator-(Comp_I z1, Fimag_I z2) { return Comp(real(z1), imag(z1) - imag(z2)); }
inline Comp operator*(Comp_I z1, Fimag_I z2) { return Comp(-imag(z1)*imag(z2), real(z1)*imag(z2)); }
inline Comp operator/(Comp_I z1, Fimag_I z2) { return Comp(imag(z1)/imag(z2), -real(z1)/imag(z2)); }
inline bool operator==(Comp_I z1, Fimag_I z2) { return real(z1) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Comp_I z1, Fimag_I z2) { return !(z1 == z2); }

inline Comp operator+(Imag_I z1, Fcomp_I z2) { return Comp(real(z2), imag(z2) + imag(z1)); }
inline Comp operator-(Imag_I z1, Fcomp_I z2) { return Comp(-real(z2), imag(z1) - imag(z2)); }
inline Comp operator*(Imag_I z1, Fcomp_I z2) { return Comp(-imag(z2)*imag(z1), real(z2)*imag(z1)); }
inline Comp operator/(Imag_I z1, Fcomp_I z2) {
	const Float &x2 = real(z2), &y2 = imag(z2);
	return Comp(y2, x2) * Doub(imag(z1) / (x2*x2 + y2*y2));
}
inline bool operator==(Imag_I z1, Fcomp_I z2) { return real(z2) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Imag_I z1, Fcomp_I z2) { return !(z1 == z2); }

inline Imag  operator+(Imag_I z1, Imag_I z2) { return Imag(imag(z1) + imag(z2)); }
inline Imag operator-(Imag_I z1, Imag_I z2) { return Imag(imag(z1) - imag(z2)); }
inline Doub  operator*(Imag_I z1, Imag_I z2) { return -imag(z1) * imag(z2); }
inline Doub  operator/(Imag_I z1, Imag_I z2) { return imag(z1) / imag(z2); }
inline bool operator==(Imag_I z1, Imag_I z2) { return imag(z1) == imag(z2); }
inline bool operator!=(Imag_I z1, Imag_I z2) { return !(z1 == z2); }

inline Comp operator+(Doub_I x1, Imag_I z2) { return Comp(x1, imag(z2)); }
inline Comp operator-(Doub_I x1, Imag_I z2) { return Comp(x1, -imag(z2)); }
inline Imag operator*(Doub_I x1, Imag_I z2) { return Imag(x1 * imag(z2)); }
inline Imag operator/(Doub_I x1, Imag_I z2) { return Imag(-x1 / imag(z2)); }
inline bool operator==(Doub_I x1, Imag_I z2) { return x1 == 0 && imag(z2) == 0; }
inline bool operator!=(Doub_I x1, Imag_I z2) { return !(x1 == z2); }

inline Comp operator+(Imag_I z1, Doub_I x2) { return Comp(x2, imag(z1)); }
inline Comp operator-(Imag_I z1, Doub_I x2) { return Comp(-x2, imag(z1)); }
inline Imag operator*(Imag_I z1, Doub_I x2) { return Imag(x2 * imag(z1)); }
inline Imag operator/(Imag_I z1, Doub_I x2) { return Imag(imag(z1) / x2); }
inline bool operator==(Imag_I z1, Doub_I x2) { return imag(z1) == 0 && x2 == 0; }
inline bool operator!=(Imag_I z1, Doub_I x2) { return !(z1 == x2); }

inline Comp operator+(Comp_I z1, Imag_I z2) { return Comp(real(z1), imag(z1) + imag(z2)); }
inline Comp operator-(Comp_I z1, Imag_I z2) { return Comp(real(z1), imag(z1) - imag(z2)); }
inline Comp operator*(Comp_I z1, Imag_I z2) { return Comp(-imag(z1)*imag(z2), real(z1)*imag(z2)); }
inline Comp operator/(Comp_I z1, Imag_I z2) { return Comp(imag(z1)/imag(z2), -real(z1)/imag(z2)); }
inline bool operator==(Comp_I z1, Imag_I z2) { return real(z1) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Comp_I z1, Imag_I z2) { return !(z1 == z2); }

inline Comp operator+(Imag_I z1, Comp_I z2) { return Comp(real(z2), imag(z2) + imag(z1)); }
inline Comp operator-(Imag_I z1, Comp_I z2) { return Comp(-real(z2), imag(z1) - imag(z2)); }
inline Comp operator*(Imag_I z1, Comp_I z2) { return Comp(-imag(z2)*imag(z1), real(z2)*imag(z1)); }
inline Comp operator/(Imag_I z1, Comp_I z2) {
	const Doub &x2 = real(z2), &y2 = imag(z2);
	return Comp(y2, x2) * Doub(imag(z1) / (x2*x2 + y2*y2));
}
inline bool operator==(Imag_I z1, Comp_I z2) { return real(z2) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Imag_I z1, Comp_I z2) { return !(z1 == z2); }

inline Limag  operator+(Imag_I z1, Limag_I z2) { return Limag(imag(z1) + imag(z2)); }
inline Limag operator-(Imag_I z1, Limag_I z2) { return Limag(imag(z1) - imag(z2)); }
inline Ldoub  operator*(Imag_I z1, Limag_I z2) { return -imag(z1) * imag(z2); }
inline Ldoub  operator/(Imag_I z1, Limag_I z2) { return imag(z1) / imag(z2); }
inline bool operator==(Imag_I z1, Limag_I z2) { return imag(z1) == imag(z2); }
inline bool operator!=(Imag_I z1, Limag_I z2) { return !(z1 == z2); }

inline Lcomp operator+(Doub_I x1, Limag_I z2) { return Lcomp(x1, imag(z2)); }
inline Lcomp operator-(Doub_I x1, Limag_I z2) { return Lcomp(x1, -imag(z2)); }
inline Limag operator*(Doub_I x1, Limag_I z2) { return Limag(x1 * imag(z2)); }
inline Limag operator/(Doub_I x1, Limag_I z2) { return Limag(-x1 / imag(z2)); }
inline bool operator==(Doub_I x1, Limag_I z2) { return x1 == 0 && imag(z2) == 0; }
inline bool operator!=(Doub_I x1, Limag_I z2) { return !(x1 == z2); }

inline Lcomp operator+(Imag_I z1, Ldoub_I x2) { return Lcomp(x2, imag(z1)); }
inline Lcomp operator-(Imag_I z1, Ldoub_I x2) { return Lcomp(-x2, imag(z1)); }
inline Limag operator*(Imag_I z1, Ldoub_I x2) { return Limag(x2 * imag(z1)); }
inline Limag operator/(Imag_I z1, Ldoub_I x2) { return Limag(imag(z1) / x2); }
inline bool operator==(Imag_I z1, Ldoub_I x2) { return imag(z1) == 0 && x2 == 0; }
inline bool operator!=(Imag_I z1, Ldoub_I x2) { return !(z1 == x2); }

inline Lcomp operator+(Comp_I z1, Limag_I z2) { return Lcomp(real(z1), imag(z1) + imag(z2)); }
inline Lcomp operator-(Comp_I z1, Limag_I z2) { return Lcomp(real(z1), imag(z1) - imag(z2)); }
inline Lcomp operator*(Comp_I z1, Limag_I z2) { return Lcomp(-imag(z1)*imag(z2), real(z1)*imag(z2)); }
inline Lcomp operator/(Comp_I z1, Limag_I z2) { return Lcomp(imag(z1)/imag(z2), -real(z1)/imag(z2)); }
inline bool operator==(Comp_I z1, Limag_I z2) { return real(z1) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Comp_I z1, Limag_I z2) { return !(z1 == z2); }

inline Lcomp operator+(Imag_I z1, Lcomp_I z2) { return Lcomp(real(z2), imag(z2) + imag(z1)); }
inline Lcomp operator-(Imag_I z1, Lcomp_I z2) { return Lcomp(-real(z2), imag(z1) - imag(z2)); }
inline Lcomp operator*(Imag_I z1, Lcomp_I z2) { return Lcomp(-imag(z2)*imag(z1), real(z2)*imag(z1)); }
inline Lcomp operator/(Imag_I z1, Lcomp_I z2) {
	const Ldoub &x2 = real(z2), &y2 = imag(z2);
	return Lcomp(y2, x2) * Ldoub(imag(z1) / (x2*x2 + y2*y2));
}
inline bool operator==(Imag_I z1, Lcomp_I z2) { return real(z2) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Imag_I z1, Lcomp_I z2) { return !(z1 == z2); }

inline Limag  operator+(Limag_I z1, Fimag_I z2) { return Limag(imag(z1) + imag(z2)); }
inline Limag operator-(Limag_I z1, Fimag_I z2) { return Limag(imag(z1) - imag(z2)); }
inline Ldoub  operator*(Limag_I z1, Fimag_I z2) { return -imag(z1) * imag(z2); }
inline Ldoub  operator/(Limag_I z1, Fimag_I z2) { return imag(z1) / imag(z2); }
inline bool operator==(Limag_I z1, Fimag_I z2) { return imag(z1) == imag(z2); }
inline bool operator!=(Limag_I z1, Fimag_I z2) { return !(z1 == z2); }

inline Lcomp operator+(Ldoub_I x1, Fimag_I z2) { return Lcomp(x1, imag(z2)); }
inline Lcomp operator-(Ldoub_I x1, Fimag_I z2) { return Lcomp(x1, -imag(z2)); }
inline Limag operator*(Ldoub_I x1, Fimag_I z2) { return Limag(x1 * imag(z2)); }
inline Limag operator/(Ldoub_I x1, Fimag_I z2) { return Limag(-x1 / imag(z2)); }
inline bool operator==(Ldoub_I x1, Fimag_I z2) { return x1 == 0 && imag(z2) == 0; }
inline bool operator!=(Ldoub_I x1, Fimag_I z2) { return !(x1 == z2); }

inline Lcomp operator+(Limag_I z1, Float_I x2) { return Lcomp(x2, imag(z1)); }
inline Lcomp operator-(Limag_I z1, Float_I x2) { return Lcomp(-x2, imag(z1)); }
inline Limag operator*(Limag_I z1, Float_I x2) { return Limag(x2 * imag(z1)); }
inline Limag operator/(Limag_I z1, Float_I x2) { return Limag(imag(z1) / x2); }
inline bool operator==(Limag_I z1, Float_I x2) { return imag(z1) == 0 && x2 == 0; }
inline bool operator!=(Limag_I z1, Float_I x2) { return !(z1 == x2); }

inline Lcomp operator+(Lcomp_I z1, Fimag_I z2) { return Lcomp(real(z1), imag(z1) + imag(z2)); }
inline Lcomp operator-(Lcomp_I z1, Fimag_I z2) { return Lcomp(real(z1), imag(z1) - imag(z2)); }
inline Lcomp operator*(Lcomp_I z1, Fimag_I z2) { return Lcomp(-imag(z1)*imag(z2), real(z1)*imag(z2)); }
inline Lcomp operator/(Lcomp_I z1, Fimag_I z2) { return Lcomp(imag(z1)/imag(z2), -real(z1)/imag(z2)); }
inline bool operator==(Lcomp_I z1, Fimag_I z2) { return real(z1) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Lcomp_I z1, Fimag_I z2) { return !(z1 == z2); }

inline Lcomp operator+(Limag_I z1, Fcomp_I z2) { return Lcomp(real(z2), imag(z2) + imag(z1)); }
inline Lcomp operator-(Limag_I z1, Fcomp_I z2) { return Lcomp(-real(z2), imag(z1) - imag(z2)); }
inline Lcomp operator*(Limag_I z1, Fcomp_I z2) { return Lcomp(-imag(z2)*imag(z1), real(z2)*imag(z1)); }
inline Lcomp operator/(Limag_I z1, Fcomp_I z2) {
	const Float &x2 = real(z2), &y2 = imag(z2);
	return Lcomp(y2, x2) * Ldoub(imag(z1) / (x2*x2 + y2*y2));
}
inline bool operator==(Limag_I z1, Fcomp_I z2) { return real(z2) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Limag_I z1, Fcomp_I z2) { return !(z1 == z2); }

inline Limag  operator+(Limag_I z1, Imag_I z2) { return Limag(imag(z1) + imag(z2)); }
inline Limag operator-(Limag_I z1, Imag_I z2) { return Limag(imag(z1) - imag(z2)); }
inline Ldoub  operator*(Limag_I z1, Imag_I z2) { return -imag(z1) * imag(z2); }
inline Ldoub  operator/(Limag_I z1, Imag_I z2) { return imag(z1) / imag(z2); }
inline bool operator==(Limag_I z1, Imag_I z2) { return imag(z1) == imag(z2); }
inline bool operator!=(Limag_I z1, Imag_I z2) { return !(z1 == z2); }

inline Lcomp operator+(Ldoub_I x1, Imag_I z2) { return Lcomp(x1, imag(z2)); }
inline Lcomp operator-(Ldoub_I x1, Imag_I z2) { return Lcomp(x1, -imag(z2)); }
inline Limag operator*(Ldoub_I x1, Imag_I z2) { return Limag(x1 * imag(z2)); }
inline Limag operator/(Ldoub_I x1, Imag_I z2) { return Limag(-x1 / imag(z2)); }
inline bool operator==(Ldoub_I x1, Imag_I z2) { return x1 == 0 && imag(z2) == 0; }
inline bool operator!=(Ldoub_I x1, Imag_I z2) { return !(x1 == z2); }

inline Lcomp operator+(Limag_I z1, Doub_I x2) { return Lcomp(x2, imag(z1)); }
inline Lcomp operator-(Limag_I z1, Doub_I x2) { return Lcomp(-x2, imag(z1)); }
inline Limag operator*(Limag_I z1, Doub_I x2) { return Limag(x2 * imag(z1)); }
inline Limag operator/(Limag_I z1, Doub_I x2) { return Limag(imag(z1) / x2); }
inline bool operator==(Limag_I z1, Doub_I x2) { return imag(z1) == 0 && x2 == 0; }
inline bool operator!=(Limag_I z1, Doub_I x2) { return !(z1 == x2); }

inline Lcomp operator+(Lcomp_I z1, Imag_I z2) { return Lcomp(real(z1), imag(z1) + imag(z2)); }
inline Lcomp operator-(Lcomp_I z1, Imag_I z2) { return Lcomp(real(z1), imag(z1) - imag(z2)); }
inline Lcomp operator*(Lcomp_I z1, Imag_I z2) { return Lcomp(-imag(z1)*imag(z2), real(z1)*imag(z2)); }
inline Lcomp operator/(Lcomp_I z1, Imag_I z2) { return Lcomp(imag(z1)/imag(z2), -real(z1)/imag(z2)); }
inline bool operator==(Lcomp_I z1, Imag_I z2) { return real(z1) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Lcomp_I z1, Imag_I z2) { return !(z1 == z2); }

inline Lcomp operator+(Limag_I z1, Comp_I z2) { return Lcomp(real(z2), imag(z2) + imag(z1)); }
inline Lcomp operator-(Limag_I z1, Comp_I z2) { return Lcomp(-real(z2), imag(z1) - imag(z2)); }
inline Lcomp operator*(Limag_I z1, Comp_I z2) { return Lcomp(-imag(z2)*imag(z1), real(z2)*imag(z1)); }
inline Lcomp operator/(Limag_I z1, Comp_I z2) {
	const Doub &x2 = real(z2), &y2 = imag(z2);
	return Lcomp(y2, x2) * Ldoub(imag(z1) / (x2*x2 + y2*y2));
}
inline bool operator==(Limag_I z1, Comp_I z2) { return real(z2) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Limag_I z1, Comp_I z2) { return !(z1 == z2); }

inline Limag  operator+(Limag_I z1, Limag_I z2) { return Limag(imag(z1) + imag(z2)); }
inline Limag operator-(Limag_I z1, Limag_I z2) { return Limag(imag(z1) - imag(z2)); }
inline Ldoub  operator*(Limag_I z1, Limag_I z2) { return -imag(z1) * imag(z2); }
inline Ldoub  operator/(Limag_I z1, Limag_I z2) { return imag(z1) / imag(z2); }
inline bool operator==(Limag_I z1, Limag_I z2) { return imag(z1) == imag(z2); }
inline bool operator!=(Limag_I z1, Limag_I z2) { return !(z1 == z2); }

inline Lcomp operator+(Ldoub_I x1, Limag_I z2) { return Lcomp(x1, imag(z2)); }
inline Lcomp operator-(Ldoub_I x1, Limag_I z2) { return Lcomp(x1, -imag(z2)); }
inline Limag operator*(Ldoub_I x1, Limag_I z2) { return Limag(x1 * imag(z2)); }
inline Limag operator/(Ldoub_I x1, Limag_I z2) { return Limag(-x1 / imag(z2)); }
inline bool operator==(Ldoub_I x1, Limag_I z2) { return x1 == 0 && imag(z2) == 0; }
inline bool operator!=(Ldoub_I x1, Limag_I z2) { return !(x1 == z2); }

inline Lcomp operator+(Limag_I z1, Ldoub_I x2) { return Lcomp(x2, imag(z1)); }
inline Lcomp operator-(Limag_I z1, Ldoub_I x2) { return Lcomp(-x2, imag(z1)); }
inline Limag operator*(Limag_I z1, Ldoub_I x2) { return Limag(x2 * imag(z1)); }
inline Limag operator/(Limag_I z1, Ldoub_I x2) { return Limag(imag(z1) / x2); }
inline bool operator==(Limag_I z1, Ldoub_I x2) { return imag(z1) == 0 && x2 == 0; }
inline bool operator!=(Limag_I z1, Ldoub_I x2) { return !(z1 == x2); }

inline Lcomp operator+(Lcomp_I z1, Limag_I z2) { return Lcomp(real(z1), imag(z1) + imag(z2)); }
inline Lcomp operator-(Lcomp_I z1, Limag_I z2) { return Lcomp(real(z1), imag(z1) - imag(z2)); }
inline Lcomp operator*(Lcomp_I z1, Limag_I z2) { return Lcomp(-imag(z1)*imag(z2), real(z1)*imag(z2)); }
inline Lcomp operator/(Lcomp_I z1, Limag_I z2) { return Lcomp(imag(z1)/imag(z2), -real(z1)/imag(z2)); }
inline bool operator==(Lcomp_I z1, Limag_I z2) { return real(z1) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Lcomp_I z1, Limag_I z2) { return !(z1 == z2); }

inline Lcomp operator+(Limag_I z1, Lcomp_I z2) { return Lcomp(real(z2), imag(z2) + imag(z1)); }
inline Lcomp operator-(Limag_I z1, Lcomp_I z2) { return Lcomp(-real(z2), imag(z1) - imag(z2)); }
inline Lcomp operator*(Limag_I z1, Lcomp_I z2) { return Lcomp(-imag(z2)*imag(z1), real(z2)*imag(z1)); }
inline Lcomp operator/(Limag_I z1, Lcomp_I z2) {
	const Ldoub &x2 = real(z2), &y2 = imag(z2);
	return Lcomp(y2, x2) * Ldoub(imag(z1) / (x2*x2 + y2*y2));
}
inline bool operator==(Limag_I z1, Lcomp_I z2) { return real(z2) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Limag_I z1, Lcomp_I z2) { return !(z1 == z2); }

inline Qimag  operator+(Qimag_I z1, Qimag_I z2) { return Qimag(imag(z1) + imag(z2)); }
inline Qimag operator-(Qimag_I z1, Qimag_I z2) { return Qimag(imag(z1) - imag(z2)); }
inline Qdoub  operator*(Qimag_I z1, Qimag_I z2) { return -imag(z1) * imag(z2); }
inline Qdoub  operator/(Qimag_I z1, Qimag_I z2) { return imag(z1) / imag(z2); }
inline bool operator==(Qimag_I z1, Qimag_I z2) { return imag(z1) == imag(z2); }
inline bool operator!=(Qimag_I z1, Qimag_I z2) { return !(z1 == z2); }

inline Qcomp operator+(Qdoub_I x1, Qimag_I z2) { return Qcomp(x1, imag(z2)); }
inline Qcomp operator-(Qdoub_I x1, Qimag_I z2) { return Qcomp(x1, -imag(z2)); }
inline Qimag operator*(Qdoub_I x1, Qimag_I z2) { return Qimag(x1 * imag(z2)); }
inline Qimag operator/(Qdoub_I x1, Qimag_I z2) { return Qimag(-x1 / imag(z2)); }
inline bool operator==(Qdoub_I x1, Qimag_I z2) { return x1 == 0 && imag(z2) == 0; }
inline bool operator!=(Qdoub_I x1, Qimag_I z2) { return !(x1 == z2); }

inline Qcomp operator+(Qimag_I z1, Qdoub_I x2) { return Qcomp(x2, imag(z1)); }
inline Qcomp operator-(Qimag_I z1, Qdoub_I x2) { return Qcomp(-x2, imag(z1)); }
inline Qimag operator*(Qimag_I z1, Qdoub_I x2) { return Qimag(x2 * imag(z1)); }
inline Qimag operator/(Qimag_I z1, Qdoub_I x2) { return Qimag(imag(z1) / x2); }
inline bool operator==(Qimag_I z1, Qdoub_I x2) { return imag(z1) == 0 && x2 == 0; }
inline bool operator!=(Qimag_I z1, Qdoub_I x2) { return !(z1 == x2); }

inline Qcomp operator+(Qcomp_I z1, Qimag_I z2) { return Qcomp(real(z1), imag(z1) + imag(z2)); }
inline Qcomp operator-(Qcomp_I z1, Qimag_I z2) { return Qcomp(real(z1), imag(z1) - imag(z2)); }
inline Qcomp operator*(Qcomp_I z1, Qimag_I z2) { return Qcomp(-imag(z1)*imag(z2), real(z1)*imag(z2)); }
inline Qcomp operator/(Qcomp_I z1, Qimag_I z2) { return Qcomp(imag(z1)/imag(z2), -real(z1)/imag(z2)); }
inline bool operator==(Qcomp_I z1, Qimag_I z2) { return real(z1) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Qcomp_I z1, Qimag_I z2) { return !(z1 == z2); }

inline Qcomp operator+(Qimag_I z1, Qcomp_I z2) { return Qcomp(real(z2), imag(z2) + imag(z1)); }
inline Qcomp operator-(Qimag_I z1, Qcomp_I z2) { return Qcomp(-real(z2), imag(z1) - imag(z2)); }
inline Qcomp operator*(Qimag_I z1, Qcomp_I z2) { return Qcomp(-imag(z2)*imag(z1), real(z2)*imag(z1)); }
inline Qcomp operator/(Qimag_I z1, Qcomp_I z2) {
	const Qdoub &x2 = real(z2), &y2 = imag(z2);
	return Qcomp(y2, x2) * Qdoub(imag(z1) / (x2*x2 + y2*y2));
}
inline bool operator==(Qimag_I z1, Qcomp_I z2) { return real(z2) == 0 && imag(z1) == imag(z2); }
inline bool operator!=(Qimag_I z1, Qcomp_I z2) { return !(z1 == z2); }


// operator-
inline Fimag operator-(Fimag_I z) { return Fimag(-z.imag()); }
inline Imag operator-(Imag_I z) { return Imag(-z.imag()); }
inline Limag operator-(Limag_I z) { return Limag(-z.imag()); }
#ifdef SLS_USE_QUAD_MATH
inline Qimag operator-(Qimag_I z) { return Qimag(-z.imag()); }
#endif

inline void operator+=(Comp_IO z1, Imag_I z2) { z1.imag(z1.imag() + imag(z2)); }
inline void operator-=(Comp_IO z1, Imag_I z2) { z1.imag(z1.imag() - imag(z2)); }
inline void operator*=(Comp_IO z1, Imag_I z2) { z1 = z1 * z2; }
inline void operator/=(Comp_IO z1, Imag_I z2) { z1 = z1 / z2; }

#ifdef SLS_USE_QUAD_MATH
inline void operator+=(Qcomp_IO z1, Qimag_I z2) { z1.imag(z1.imag() + imag(z2)); }
inline void operator-=(Qcomp_IO z1, Qimag_I z2) { z1.imag(z1.imag() - imag(z2)); }
inline void operator*=(Qcomp_IO z1, Qimag_I z2) { z1 = z1 * z2; }
inline void operator/=(Qcomp_IO z1, Qimag_I z2) { z1 = z1 / z2; }
#endif

// operator<<
inline std::ostream &operator<<(std::ostream &out, Imag_I num)
{
	out << num.imag() << 'i';
	return out;
}

#ifdef SLS_USE_QUAD_MATH
inline std::ostream &operator<<(std::ostream &out, Qimag_I num)
{
	out << num.imag() << 'i';
	return out;
}
#endif

} // namespace slisc
