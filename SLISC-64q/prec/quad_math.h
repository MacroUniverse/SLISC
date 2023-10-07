#pragma once

#ifdef SLS_USE_QUAD_MATH
#if !defined(SLS_USE_GCC) && !defined(SLS_USE_ICC)
#error quad_math.h only supports g++ compiler or intel compiler
#endif
#include <math.h>
#include <cmath>
#include <complex>
#include <vector>
#include <iostream>
#include <quadmath.h>

// #ifdef SLS_USE_ICC
// typedef _Quad __float128;
// typedef std::complex<_Quad> __complex128;
// #endif

namespace std {

inline const __complex128 &to_c(const complex<__float128> &x)
{
	return *(const __complex128 *)&x;
	// Qcomp0 y;
	// __real__ y = x.real();
	// __imag__ y = x.imag();
}

inline const complex<__float128> &to_std(const __complex128 &x)
{
	return *(const complex<__float128> *)&x;
}

inline string quad2str(const __float128 x, const int prec = 5)
{
	char buf[128];
	int width = 46;
	quadmath_snprintf(buf, sizeof buf, ("%." + to_string(prec-1) + "Qe").c_str(), width, x);
	return buf;
}

inline string quad2str(const __complex128 x, const int prec = 5)
{
	string str;
	str += "(" + quad2str(crealq(x), prec) + "," + quad2str(cimagq(x), prec) + ")";
	return str;
}

inline string quad2str(const complex<__float128> x, const int prec = 5)
{
	return quad2str(to_c(x), prec);
}

inline ostream& operator<<(ostream& os, const __float128 &x)
{
	os << quad2str(x, os.precision());
	return os;
}

inline ostream& operator<<(ostream& os, const __complex128 &x)
{
	os << quad2str(x, os.precision());
	return os;
}

inline ostream& operator<<(ostream& os, const complex<__float128> &x)
{
	os << quad2str(x, os.precision());
	return os;
}

// scanf("%Qe") doesn't work, not enough precision
inline istream& operator>>(istream& is, __float128 &x)
{
	// ignore space and 0
	bool has_dot = false;
	int dot_pos = 0;
	bool negative = false;
	char c;
	while (true) {
		is.get(c);
		if (!is) break;
		else if (c == ' ' || c == '\r' || c == '\t' ||
			c == '\n' || c == '+')
			continue;
		else if (c == '-') {
			negative = !negative; continue;
		}
		else if ('0' <= c && c <= '9') {
			// first number
			x = __float128(c - '0');
			break;
		}
		else if (c == '.') {
			x = 0.Q; has_dot = true; break;
		}
		else
			SLS_ERR("unexpected stdin char!");
	}

	// get rest of 0-9 and '.'
	while (is) {
		is.get(c);
		if (!is) break;
		if ('0' <= c && c <= '9') {
			x = 10.Q*x + __float128(c - '0');
			if (has_dot) { ++dot_pos; }
		}
		else if (c == '.')
			has_dot = true;
		else if (c == 'e' || c == 'E') {
			long long expo;
			cin >> expo;
			x *= pow(10.Q, expo - dot_pos);
			break;
		}
		else {
			x *= pow(10.Q, -dot_pos);
			break;
		}
	}
	if (negative) x = -x;
	return is;
}

// === C++ function overloading ===

// real = fun(real)
#define SLS_QMATH_RFUNR2(name, name0) inline __float128 name(const __float128 &x) { return name0(x); }

#define SLS_QMATH_RFUNR(name) SLS_QMATH_RFUNR2(name, name##q)

// real = fun(real, real)
#define SLS_QMATH_RFUNRR2(name, name0) inline __float128 name(const __float128 &x, const __float128 &y) { return name0(x, y); }

#define SLS_QMATH_RFUNRR(name) SLS_QMATH_RFUNRR2(name, name##q)

// real = fun(comp)
#define SLS_QMATH_RFUNC2(name, name0) inline __float128 name(const complex<__float128> &z) { return name0(to_c(z)); }

#define SLS_QMATH_RFUNC(name) SLS_QMATH_RFUNC2(name, c##name##q)

// comp = fun(comp)
#define SLS_QMATH_CFUNC2(name, name0) inline complex<__float128> name(const complex<__float128> &z) { return to_std(name0(to_c(z))); }

#define SLS_QMATH_CFUNC(name) SLS_QMATH_CFUNC2(name, c##name##q)

// comp = fun(comp, comp)
#define SLS_QMATH_CFUNCC2(name, name0) inline complex<__float128> name(const complex<__float128> &z1, const complex<__float128> &z2) { return to_std(name0(to_c(z1), to_c(z2))); }

#define SLS_QMATH_CFUNCC(name) SLS_QMATH_CFUNCC2(name, c##name##q)

// ref: quadmath.h
SLS_QMATH_RFUNR2(abs, fabsq)
SLS_QMATH_RFUNR(acos)
SLS_QMATH_RFUNR(acosh)
SLS_QMATH_RFUNR(asin)
SLS_QMATH_RFUNR(asinh)
SLS_QMATH_RFUNR(atan)
SLS_QMATH_RFUNR(atanh)
SLS_QMATH_RFUNRR(atan2)
SLS_QMATH_RFUNR(cbrt)
SLS_QMATH_RFUNR(ceil)
SLS_QMATH_RFUNRR(copysign)
SLS_QMATH_RFUNR(cos)
SLS_QMATH_RFUNR(cosh)
SLS_QMATH_RFUNR(erf)
SLS_QMATH_RFUNR(exp)
// SLS_QMATH_RFUNR(exp2) // not supported in earlier g++
SLS_QMATH_RFUNR(expm1)
SLS_QMATH_RFUNR(fabs)
SLS_QMATH_RFUNRR(fdim)
SLS_QMATH_RFUNR(floor)
// fma
SLS_QMATH_RFUNR(isinf)
SLS_QMATH_RFUNR(isnan)
SLS_QMATH_RFUNR(j0)
SLS_QMATH_RFUNR(j1)
SLS_QMATH_RFUNR(lgamma)
// not defined in older version of GCC
// SLS_QMATH_RFUNR(logb)
SLS_QMATH_RFUNR(log)
SLS_QMATH_RFUNR(log10)
SLS_QMATH_RFUNR(log2)
SLS_QMATH_RFUNR(log1p)
SLS_QMATH_RFUNRR(nextafter)
SLS_QMATH_RFUNRR(pow)
SLS_QMATH_RFUNRR(remainder)
SLS_QMATH_RFUNR(rint)
SLS_QMATH_RFUNR(round)
SLS_QMATH_RFUNR(sinh)
SLS_QMATH_RFUNR(sin)
SLS_QMATH_RFUNR(sqrt)
SLS_QMATH_RFUNR(tan)
SLS_QMATH_RFUNR(tanh)
SLS_QMATH_RFUNR(tgamma)
SLS_QMATH_RFUNR(trunc)
SLS_QMATH_RFUNR(y0)
SLS_QMATH_RFUNR(y1)
// yn

SLS_QMATH_RFUNC(abs)
SLS_QMATH_RFUNC(arg)
SLS_QMATH_RFUNC(imag)
SLS_QMATH_RFUNC(real)
SLS_QMATH_CFUNC(acos)
SLS_QMATH_CFUNC(acosh)
SLS_QMATH_CFUNC(asin)
SLS_QMATH_CFUNC(asinh)
SLS_QMATH_CFUNC(atan)
SLS_QMATH_CFUNC(atanh)
SLS_QMATH_CFUNC(cos)
SLS_QMATH_CFUNC(cosh)
SLS_QMATH_CFUNC(exp)
// expi
SLS_QMATH_CFUNC(log)
SLS_QMATH_CFUNC(log10)
SLS_QMATH_CFUNC2(conj, conjq)
SLS_QMATH_CFUNCC(pow)
SLS_QMATH_CFUNC(proj)
SLS_QMATH_CFUNC(sin)
SLS_QMATH_CFUNC(sinh)
SLS_QMATH_CFUNC(sqrt)
SLS_QMATH_CFUNC(tan)
SLS_QMATH_CFUNC(tanh)

} // namespace std


namespace slisc {

inline __float128 sqr(const __float128 &x) { return x*x; }
inline std::complex<__float128> sqr(const std::complex<__float128> &x) { return x*x; }

inline __float128 abs2(const __float128 &x) { return x*x; }
inline __float128 abs2(const std::complex<__float128> &x) { return sqr(abs(x)); }

typedef __float128 Qdoub;
typedef const Qdoub &Qdoub_I;
typedef Qdoub &Qdoub_O, &Qdoub_IO;

typedef  __complex128 Qcomp0;
typedef const Qcomp0 &Qcomp0_I;
typedef Qcomp0 &Qcomp0_O, &Qcomp0_IO;

// another definition
typedef std::complex<Qdoub> Qcomp;
typedef const Qcomp &Qcomp_I;
typedef Qcomp &Qcomp_O, &Qcomp_IO;

typedef std::vector<Qdoub> vecQdoub;
typedef const vecQdoub &vecQdoub_I;
typedef vecQdoub &vecQdoub_O, &vecQdoub_IO;

typedef std::vector<Qcomp> vecQcomp;
typedef const vecQcomp &vecQcomp_I;
typedef vecQcomp &vecQcomp_O, &vecQcomp_IO;
} // namespace slisc

#endif // SLS_USE_QUAD_MATH

// #else
// // TODO: maybe use DD library in here
// struct Qdoub {
// 	double x[2];
// 	Qdoub() { SLS_ERR("Qdoub not implemented!"); }
// 	Qdoub(const int &q) { SLS_ERR("Qdoub not implemented!"); }
// 	Qdoub(const long long &q) { SLS_ERR("Qdoub not implemented!"); }
// 	Qdoub(const double &q) { SLS_ERR("Qdoub not implemented!"); }
// 	Qdoub(const Qdoub &q) { SLS_ERR("Qdoub not implemented!"); } // copy constructor
// 	void operator=(const Qdoub &q) { SLS_ERR("Qdoub not implemented!"); }
// 	operator double() { SLS_ERR("Qdoub not implemented!"); }
// };

// struct Qcomp {
// 	double x[4];
// 	Qcomp() { SLS_ERR("Qcomp not implemented!"); }
// 	Qcomp(const int &q) { SLS_ERR("Qcomp not implemented!"); }
// 	Qcomp(const long long &q) { SLS_ERR("Qcomp not implemented!"); }
// 	Qcomp(const double &q) { SLS_ERR("Qcomp not implemented!"); }
// 	Qcomp(const Qcomp &q) { SLS_ERR("Qcomp not implemented!"); } // copy constructor
// 	void operator=(const Qcomp &q) { SLS_ERR("Qcomp not implemented!"); }
// 	operator double() { SLS_ERR("Qcomp not implemented!"); }
// };

// typedef const Qdoub &Qdoub_I;
// typedef Qdoub &Qdoub_O, &Qdoub_IO;

// namespace std {
// 	inline double sqr(Qdoub_I x) { return 0; }
// }

// // another definition
// typedef const Qcomp &Qcomp_I;
// typedef Qcomp &Qcomp_O, &Qcomp_IO;

// typedef std::vector<Qdoub> vecQdoub;
// typedef const vecQdoub &vecQdoub_I;
// typedef vecQdoub &vecQdoub_O, &vecQdoub_IO;

// typedef std::vector<Qcomp> vecQcomp;
// typedef const vecQcomp &vecQcomp_I;
// typedef vecQcomp &vecQcomp_O, &vecQcomp_IO;

// inline bool operator>(Qdoub_I x, Qdoub_I y) { return false; }
// inline bool operator>=(Qdoub_I x, Qdoub_I y) { return false; }
// inline bool operator<(Qdoub_I x, Qdoub_I y) { return false; }
// inline bool operator<=(Qdoub_I x, Qdoub_I y) { return false; }
// inline bool operator==(Qdoub_I x, Qdoub_I y) { return false; }
// inline bool operator!=(Qdoub_I x, Qdoub_I y) { return false; }
// #endif
