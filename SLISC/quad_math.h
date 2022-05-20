#pragma once
#include "global.h"
#include <quadmath.h>

namespace slisc {
typedef __float128 Qdoub;
typedef const Qdoub Qdoub_I;
typedef Qdoub &Qdoub_O, &Qdoub_IO;

typedef  __complex128 Qcomp;
typedef const Qcomp &Qcomp_I;
typedef Qcomp &Qcomp_O, &Qcomp_IO;

inline Str quad2str(Qdoub_I x, Int_I prec = 5)
{
	Char buf[128];
	Int width = 46;
	quadmath_snprintf(buf, sizeof buf, ("%." + to_string(prec-1) + "Qe").c_str(), width, x);
	return buf;
}
} // namespace slisc

inline slisc::Qdoub sqr(slisc::Qdoub_I x) { return x*x; }
inline slisc::Qcomp sqr(slisc::Qcomp_I x) { return x*x; }
inline slisc::Qdoub abs(slisc::Qdoub_I x) { return fabsq(x); }
inline slisc::Qdoub abs(slisc::Qcomp_I x) { return cabsq(x); }
inline slisc::Qdoub abs2(slisc::Qdoub_I x) { return sqr(abs(x)); }
inline slisc::Qdoub abs2(slisc::Qcomp_I x) { return sqr(abs(x)); }
inline slisc::Qdoub acos(slisc::Qdoub_I x) { return acosq(x); }
inline slisc::Qdoub acosh(slisc::Qdoub_I x) { return acoshq(x); }
inline slisc::Qdoub arg(slisc::Qcomp_I x) { return cargq(x); }
inline slisc::Qdoub asin(slisc::Qdoub_I x) { return asinq(x); }
inline slisc::Qdoub asinh(slisc::Qdoub_I x) { return asinhq(x); }
inline slisc::Qdoub atan(slisc::Qdoub_I x) { return atanq(x); }
inline slisc::Qdoub atanh(slisc::Qdoub_I x) { return atanhq(x); }
inline slisc::Qdoub atan2(slisc::Qdoub_I y, slisc::Qdoub_I x) { return atan2q(y, x); }
inline slisc::Qdoub ceil(slisc::Qdoub_I x) { return ceilq(x); }
inline slisc::Qdoub cos(slisc::Qdoub_I x) { return cos(x); }
inline slisc::Qdoub erf(slisc::Qdoub_I x) { return erf(x); }
inline slisc::Qdoub exp(slisc::Qdoub_I x) { return exp(x); }
inline slisc::Qcomp exp(slisc::Qcomp_I x) { return exp(x); }
inline slisc::Qdoub floor(slisc::Qdoub_I x) { return floorq(x); }
inline slisc::Qdoub imag(slisc::Qcomp_I x) { return cimagq(x); }
inline slisc::Qdoub isinf(slisc::Qdoub_I x) { return isinfq(x); }
inline slisc::Qdoub isnan(slisc::Qdoub_I x) { return isnanq(x); }
inline slisc::Qdoub log(slisc::Qdoub_I x) { return logq(x); }
inline slisc::Qcomp log(slisc::Qcomp_I x) { return clogq(x); }
inline slisc::Qdoub log2(slisc::Qdoub_I x) { return log2q(x); }
inline slisc::Qdoub log10(slisc::Qdoub_I x) { return log10q(x); }
inline slisc::Qdoub real(slisc::Qcomp_I x) { return crealq(x); }
inline slisc::Qdoub round(slisc::Qdoub_I x) { return rintq(x); }
inline slisc::Qdoub sin(slisc::Qdoub_I x) { return sinq(x); }
inline slisc::Qdoub sqrt(slisc::Qdoub_I x) { return sqrtq(x); }
inline slisc::Qcomp sqrt(slisc::Qcomp_I x) { return csqrtq(x); }
inline slisc::Qdoub tan(slisc::Qdoub_I x) { return tanq(x); }

namespace std {

inline std::ostream& operator<<(std::ostream& os, slisc::Qdoub_I x)
{
	os << slisc::quad2str(x, os.precision());
    return os;
}

inline slisc::Qdoub sqr(slisc::Qdoub_I x) { return x*x; }
inline slisc::Qcomp sqr(slisc::Qcomp_I x) { return x*x; }
inline slisc::Qdoub abs(slisc::Qdoub_I x) { return fabsq(x); }
inline slisc::Qdoub abs(slisc::Qcomp_I x) { return cabsq(x); }
inline slisc::Qdoub abs2(slisc::Qdoub_I x) { return sqr(abs(x)); }
inline slisc::Qdoub abs2(slisc::Qcomp_I x) { return sqr(abs(x)); }
inline slisc::Qdoub acos(slisc::Qdoub_I x) { return acosq(x); }
inline slisc::Qdoub acosh(slisc::Qdoub_I x) { return acoshq(x); }
inline slisc::Qdoub arg(slisc::Qcomp_I x) { return cargq(x); }
inline slisc::Qdoub asin(slisc::Qdoub_I x) { return asinq(x); }
inline slisc::Qdoub asinh(slisc::Qdoub_I x) { return asinhq(x); }
inline slisc::Qdoub atan(slisc::Qdoub_I x) { return atanq(x); }
inline slisc::Qdoub atanh(slisc::Qdoub_I x) { return atanhq(x); }
inline slisc::Qdoub atan2(slisc::Qdoub_I y, slisc::Qdoub_I x) { return atan2q(y, x); }
inline slisc::Qdoub ceil(slisc::Qdoub_I x) { return ceilq(x); }
inline slisc::Qdoub cos(slisc::Qdoub_I x) { return cos(x); }
inline slisc::Qdoub erf(slisc::Qdoub_I x) { return erf(x); }
inline slisc::Qdoub exp(slisc::Qdoub_I x) { return exp(x); }
inline slisc::Qcomp exp(slisc::Qcomp_I x) { return exp(x); }
inline slisc::Qdoub floor(slisc::Qdoub_I x) { return floorq(x); }
inline slisc::Qdoub imag(slisc::Qcomp_I x) { return cimagq(x); }
inline slisc::Qdoub isinf(slisc::Qdoub_I x) { return isinfq(x); }
inline slisc::Qdoub isnan(slisc::Qdoub_I x) { return isnanq(x); }
inline slisc::Qdoub log(slisc::Qdoub_I x) { return logq(x); }
inline slisc::Qcomp log(slisc::Qcomp_I x) { return clogq(x); }
inline slisc::Qdoub log2(slisc::Qdoub_I x) { return log2q(x); }
inline slisc::Qdoub log10(slisc::Qdoub_I x) { return log10q(x); }
inline slisc::Qdoub real(slisc::Qcomp_I x) { return crealq(x); }
inline slisc::Qdoub round(slisc::Qdoub_I x) { return rintq(x); }
inline slisc::Qdoub sin(slisc::Qdoub_I x) { return sinq(x); }
inline slisc::Qdoub sqrt(slisc::Qdoub_I x) { return sqrtq(x); }
inline slisc::Qcomp sqrt(slisc::Qcomp_I x) { return csqrtq(x); }
inline slisc::Qdoub tan(slisc::Qdoub_I x) { return tanq(x); }

} // namespace std

// extension for Eigen library
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
