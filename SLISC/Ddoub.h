#include "global.h"

namespace slisc {
#ifdef SLS_USE_QUAD_MATH

// use Qdoub in quad_math.h instead of this.
// this will be slower than directly using __float128, due to copy constructor in return-by-value
// testing: copy elision will not happen even -O3 is turned on for g++ for operator+

struct Ddoub {
	__float128 x;
	Ddoub() {}
	Ddoub(const Ddoub &q) { x = q.x; } // copy constructor
	explicit Ddoub(const __float128 &q): x(q) {}
	void operator=(const Ddoub &q) { x = q.x; }
};

#else

// define dummy type, to suppress compilation error
struct Ddoub {
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

typedef const complex<Ddoub> & Dcomp;
typedef const Dcomp & Dcomp_I;
typedef Dcomp & Dcomp_O, & Dcomp_IO;

inline Ddoub operator+(Ddoub_I x, Ddoub_I y) { return Ddoub(x.x + y.x); }
inline Ddoub operator-(Ddoub_I x, Ddoub_I y) { return Ddoub(x.x - y.x); }
inline Ddoub operator*(Ddoub_I x, Ddoub_I y) { return Ddoub(x.x * y.x); }
inline Ddoub operator/(Ddoub_I x, Ddoub_I y) { return Ddoub(x.x / y.x); }
inline Ddoub &operator+=(Ddoub_IO x, Ddoub_I y) { x.x += y.x; return x; }
inline Ddoub &operator-=(Ddoub_IO x, Ddoub_I y) { x.x -= y.x; return x; }
inline Ddoub &operator*=(Ddoub_IO x, Ddoub_I y) { x.x *= y.x; return x; }
inline Ddoub &operator/=(Ddoub_IO x, Ddoub_I y) { x.x /= y.x; return x; }
inline Bool operator>(Ddoub_I x, Ddoub_I y) { return x.x > y.x; }
inline Bool operator<(Ddoub_I x, Ddoub_I y) { return x.x < y.x; }
inline Bool operator>=(Ddoub_I x, Ddoub_I y) { return x.x >= y.x; }
inline Bool operator<=(Ddoub_I x, Ddoub_I y) { return x.x <= y.x; }
inline Bool operator==(Ddoub_I x, Ddoub_I y) { return x.x == y.x; }
inline Bool operator!=(Ddoub_I x, Ddoub_I y) { return x.x != y.x; }

inline Ddoub sqr(Ddoub_I x) { return x*x; }
inline Ddoub abs(Ddoub_I x) { return Ddoub(fabsq(x.x)); }
inline Ddoub abs2(Ddoub_I x) { return x*x; }
inline Ddoub acos(Ddoub_I x) { return Ddoub(acosq(x.x)); }
inline Ddoub acosh(Ddoub_I x) { return Ddoub(acoshq(x.x)); }
inline Ddoub asin(Ddoub_I x) { return Ddoub(asinq(x.x)); }
inline Ddoub asinh(Ddoub_I x) { return Ddoub(asinhq(x.x)); }
inline Ddoub atan(Ddoub_I x) { return Ddoub(atanq(x.x)); }
inline Ddoub atanh(Ddoub_I x) { return Ddoub(atanhq(x.x)); }
inline Ddoub atan2(Ddoub_I y, Ddoub_I x) { return Ddoub(atan2q(y.x, x.x)); }
inline Ddoub ceil(Ddoub_I x) { return Ddoub(ceilq(x.x)); }
inline Ddoub cos(Ddoub_I x) { return Ddoub(cosq(x.x)); }
inline Ddoub erf(Ddoub_I x) { return Ddoub(erfq(x.x)); }
inline Ddoub exp(Ddoub_I x) { return Ddoub(expq(x.x)); }
inline Ddoub floor(Ddoub_I x) { return Ddoub(floorq(x.x)); }
inline Ddoub isinf(Ddoub_I x) { return Ddoub(isinfq(x.x)); }
inline Ddoub isnan(Ddoub_I x) { return Ddoub(isnanq(x.x)); }
inline Ddoub log(Ddoub_I x) { return Ddoub(logq(x.x)); }
inline Ddoub log2(Ddoub_I x) { return Ddoub(log2q(x.x)); }
inline Ddoub log10(Ddoub_I x) { return Ddoub(log10q(x.x)); }
inline Ddoub round(Ddoub_I x) { return Ddoub(rintq(x.x)); }
inline Ddoub sin(Ddoub_I x) { return Ddoub(sinq(x.x)); }
inline Ddoub sqrt(Ddoub_I x) { return Ddoub(sqrtq(x.x)); }
inline Ddoub tan(Ddoub_I x) { return Ddoub(tanq(x.x)); }

} // namespace slisc
