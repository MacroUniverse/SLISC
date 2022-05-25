#pragma once
#if !defined(__GNUC__) && !defined(__ICC)
#error quad_math.h only supports g++ compiler or intel compiler
#endif
#include <math.h>
#include <cmath>
#include <complex>
#include <vector>
#include <iostream>
#include <quadmath.h>

/* experimental */

namespace slisc {
#ifdef SLS_USE_QUAD_MATH

class Ddoub {
	__float128 x;
	Ddoub() {};
	Ddoub(const __float128 &q): x(q) {};
	Ddoub(Ddoub &q) { x = q.x; } // copy constructor
	void operator=(Ddoub &q) { x = q.x; }
	operator __float128() { return x; }
};

#else

// define dummy type
class Ddoub {
	Doub x;
	Ddoub() { SLS_ERR("Ddoub not implemented!"); }
	Ddoub(const Doub &q) { SLS_ERR("Ddoub not implemented!"); }
	Ddoub(Ddoub &q) { SLS_ERR("Ddoub not implemented!"); } // copy constructor
	void operator=(Ddoub &q) { x = q.x; }
	operator Doub() { return 0; }
};

#endif

typedef const Ddoub & Ddoub_I;
typedef Ddoub & Ddoub_O, & Ddoub_IO;

inline Ddoub operator+(Ddoub_I x, Ddoub_I y) { return x.x + y.x; }
inline Ddoub operator-(Ddoub_I x, Ddoub_I y) { return x.x - y.x; }
inline Ddoub operator*(Ddoub_I x, Ddoub_I y) { return x.x * y.x; }
inline Ddoub operator/(Ddoub_I x, Ddoub_I y) { return x.x / y.x; }
inline operator+=(Ddoub_IO x, Ddoub_I y) { x.x += y.x; }
inline operator-=(Ddoub_IO x, Ddoub_I y) { x.x -= y.x; }
inline operator*=(Ddoub_IO x, Ddoub_I y) { x.x *= y.x; }
inline operator/=(Ddoub_IO x, Ddoub_I y) { x.x /= y.x; }
inline Bool operator>(Ddoub_I x, Ddoub_I y) { return x.x > y.x; }
inline Bool operator<(Ddoub_I x, Ddoub_I y) { return x.x < y.x; }
inline Bool operator>=(Ddoub_I x, Ddoub_I y) { return x.x >= y.x; }
inline Bool operator<=(Ddoub_I x, Ddoub_I y) { return x.x <= y.x; }
inline Bool operator==(Ddoub_I x, Ddoub_I y) { return x.x == y.x; }
inline Bool operator!=(Ddoub_I x, Ddoub_I y) { return x.x != y.x; }

inline Ddoub sqr(Ddoub_I x) { return x*x; }
inline Ddoub abs(Ddoub_I x) { return fabsq((__float128)x); }
inline Ddoub abs2(Ddoub_I x) { return x*x; }
inline Ddoub acos(Ddoub_I x) { return acosq((__float128)x); }
inline Ddoub acosh(Ddoub_I x) { return acoshq((__float128)x); }
inline Ddoub asin(Ddoub_I x) { return asinq((__float128)x); }
inline Ddoub asinh(Ddoub_I x) { return asinhq((__float128)x); }
inline Ddoub atan(Ddoub_I x) { return atanq((__float128)x); }
inline Ddoub atanh(Ddoub_I x) { return atanhq((__float128)x); }
inline Ddoub atan2(Ddoub_I y, Ddoub_I x) { return atan2q((__float128)y, (__float128)x); }
inline Ddoub ceil(Ddoub_I x) { return ceilq((__float128)x); }
inline Ddoub cos(Ddoub_I x) { return cosq((__float128)x); }
inline Ddoub erf(Ddoub_I x) { return erfq((__float128)x); }
inline Ddoub exp(Ddoub_I x) { return expq((__float128)x); }
inline Ddoub floor(Ddoub_I x) { return floorq((__float128)x); }
inline Ddoub isinf(Ddoub_I x) { return isinfq((__float128)x); }
inline Ddoub isnan(Ddoub_I x) { return isnanq((__float128)x); }
inline Ddoub log(Ddoub_I x) { return logq((__float128)x); }
inline Ddoub log2(Ddoub_I x) { return log2q((__float128)x); }
inline Ddoub log10(Ddoub_I x) { return log10q((__float128)x); }
inline Ddoub round(Ddoub_I x) { return rintq((__float128)x); }
inline Ddoub sin(Ddoub_I x) { return sinq((__float128)x); }
inline Ddoub sqrt(Ddoub_I x) { return sqrtq((__float128)x); }
inline Ddoub tan(Ddoub_I x) { return tanq((__float128)x); }

} // namespace slisc

/* end experimental */

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

// extension for Eigen library
#ifdef SLS_USE_EIGEN
namespace Eigen {
	template<> struct NumTraits<Qdoub> : GenericNumTraits<Qdoub>
	{
		typedef Qdoub Real;
		typedef Qdoub NonInteger;
		typedef Qdoub Nested;

		static inline Real epsilon() { return FLT128_EPSILON; }
		static inline Real dummy_precision() { return 0; }
		static inline int digits10() { return FLT128_DIG; }

		enum {
			IsInteger = 0,
			IsSigned = 1,
			IsComplex = 0,
			RequireInitialization = 1,
			ReadCost = 2,
			AddCost = 2,
			MulCost = 6
		};
	};

	typedef Matrix<Qdoub, Dynamic, Dynamic> MatrixXq;
	typedef Matrix<Qdoub, Dynamic, 1> VectorXq;
} // namespace Eigen
#endif
