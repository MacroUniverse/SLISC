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

inline __complex128 to_Qcomp0(const complex<__float128> x)
{
	return *(__complex128 *)&x;
	// Qcomp0 y;
	// __real__ y = x.real();
	// __imag__ y = x.imag();
}

inline complex<__float128> to_Qcomp(const __complex128 &x)
{
	return *(complex<__float128> *)&x;
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
	return quad2str(to_Qcomp0(x), prec);
}

inline ostream& operator<<(ostream& os, const __float128 & x)
{
	os << quad2str(x, os.precision());
		return os;
}

inline ostream& operator<<(ostream& os, const __complex128 &x)
{
	os << quad2str(x, os.precision());
		return os;
}

inline ostream& operator<<(ostream& os, const complex<__float128> & x)
{
	os << quad2str(x, os.precision());
		return os;
}

inline __float128 sqr(const __float128 & x) { return x*x; }
inline __float128 abs(const __float128 & x) { return fabsq(x); }
inline __float128 abs2(const __float128 & x) { return x*x; }
inline __float128 acos(const __float128 & x) { return acosq(x); }
inline __float128 acosh(const __float128 & x) { return acoshq(x); }
inline __float128 asin(const __float128 & x) { return asinq(x); }
inline __float128 asinh(const __float128 & x) { return asinhq(x); }
inline __float128 atan(const __float128 & x) { return atanq(x); }
inline __float128 atanh(const __float128 & x) { return atanhq(x); }
inline __float128 atan2(const __float128 & y, const __float128 & x) { return atan2q(y, x); }
inline __float128 ceil(const __float128 & x) { return ceilq(x); }
inline __float128 cos(const __float128 & x) { return cosq(x); }
inline __float128 erf(const __float128 & x) { return erfq(x); }
inline __float128 exp(const __float128 & x) { return expq(x); }
inline __float128 floor(const __float128 & x) { return floorq(x); }
inline __float128 isinf(const __float128 & x) { return isinfq(x); }
inline __float128 isnan(const __float128 & x) { return isnanq(x); }
inline __float128 log(const __float128 & x) { return logq(x); }
inline __float128 log2(const __float128 & x) { return log2q(x); }
inline __float128 log10(const __float128 & x) { return log10q(x); }
inline __float128 round(const __float128 & x) { return rintq(x); }
inline __float128 sin(const __float128 & x) { return sinq(x); }
inline __float128 sqrt(const __float128 & x) { return sqrtq(x); }
inline __float128 tan(const __float128 & x) { return tanq(x); }

inline complex<__float128> sqr(const complex<__float128> & x) { return x*x; }
inline __float128 abs(const complex<__float128> & x) { return cabsq(to_Qcomp0(x)); }
inline __float128 abs2(const complex<__float128> & x) { return sqr(abs(x)); }
inline __float128 arg(const complex<__float128> & x) { return cargq(to_Qcomp0(x)); }
inline complex<__float128> exp(const complex<__float128> & x) { return to_Qcomp(cexpq(to_Qcomp0(x))); }
inline __float128 imag(const complex<__float128> & x) { return cimagq(to_Qcomp0(x)); }
inline complex<__float128> log(const complex<__float128> & x) { return to_Qcomp(clogq(to_Qcomp0(x))); }
inline __float128 real(const complex<__float128> & x) { return crealq(to_Qcomp0(x)); }
inline complex<__float128> sqrt(const complex<__float128> & x) { return to_Qcomp(csqrtq(to_Qcomp0(x))); }

} // namespace std

namespace slisc {
typedef __float128 Qdoub;
typedef const Qdoub &Qdoub_I;
typedef Qdoub &Qdoub_O, &Qdoub_IO;

typedef  __complex128 Qcomp0;
typedef const Qcomp0 &Qcomp0_I;
typedef Qcomp0 &Qcomp0_O, &Qcomp0_IO;

// another definition
typedef std::complex<Qdoub> Qcomp;
typedef const Qcomp &Qcomp_I;
typedef Qcomp &Qcomp_O, &Qcomp2_IO;

typedef std::vector<Qdoub> vecQdoub;
typedef const vecQdoub &vecQdoub_I;
typedef vecQdoub &vecQdoub_O, &vecQdoub_IO;

typedef std::vector<Qcomp> vecQcomp;
typedef const vecQcomp &vecQcomp_I;
typedef vecQcomp &vecQcomp_O, &vecQcomp_IO;
} // namespace slisc

#else // SLS_USE_QUAD_MATH
// define dummy type for Qdoub to suppress error
struct Qdoub {
	double x[2];
	Qdoub() { SLS_ERR("Qdoub not implemented!"); }
	Qdoub(const int &q) { SLS_ERR("Qdoub not implemented!"); }
	Qdoub(const long long &q) { SLS_ERR("Qdoub not implemented!"); }
	Qdoub(const double &q) { SLS_ERR("Qdoub not implemented!"); }
	Qdoub(const Qdoub &q) { SLS_ERR("Qdoub not implemented!"); } // copy constructor
	void operator=(const Qdoub &q) { SLS_ERR("Qdoub not implemented!"); }
	operator double() { SLS_ERR("Qdoub not implemented!"); }
};

struct Qcomp {
	double x[4];
	Qcomp() { SLS_ERR("Qcomp not implemented!"); }
	Qcomp(const int &q) { SLS_ERR("Qcomp not implemented!"); }
	Qcomp(const long long &q) { SLS_ERR("Qcomp not implemented!"); }
	Qcomp(const double &q) { SLS_ERR("Qcomp not implemented!"); }
	Qcomp(const Qcomp &q) { SLS_ERR("Qcomp not implemented!"); } // copy constructor
	void operator=(const Qcomp &q) { SLS_ERR("Qcomp not implemented!"); }
	operator double() { SLS_ERR("Qcomp not implemented!"); }
};

typedef const Qdoub &Qdoub_I;
typedef Qdoub &Qdoub_O, &Qdoub_IO;

namespace std {
	inline double sqr(Qdoub_I x) { return 0; }
}

// another definition
typedef const Qcomp &Qcomp_I;
typedef Qcomp &Qcomp_O, &Qcomp2_IO;

typedef std::vector<Qdoub> vecQdoub;
typedef const vecQdoub &vecQdoub_I;
typedef vecQdoub &vecQdoub_O, &vecQdoub_IO;

typedef std::vector<Qcomp> vecQcomp;
typedef const vecQcomp &vecQcomp_I;
typedef vecQcomp &vecQcomp_O, &vecQcomp_IO;

inline bool operator>(Qdoub_I x, Qdoub_I y) { return false; }
inline bool operator>=(Qdoub_I x, Qdoub_I y) { return false; }
inline bool operator<(Qdoub_I x, Qdoub_I y) { return false; }
inline bool operator<=(Qdoub_I x, Qdoub_I y) { return false; }
inline bool operator==(Qdoub_I x, Qdoub_I y) { return false; }
inline bool operator!=(Qdoub_I x, Qdoub_I y) { return false; }

#endif // SLS_USE_QUAD_MATH
