#pragma once
#include <quadmath.h>
#include "global.h"

namespace slisc {

typedef __float128 Qdoub;
typedef const Qdoub Qdoub_I;
typedef Qdoub &Qdoub_O, &Qdoub_IO;

typedef  __complex128 Qcomp;
typedef const Qcomp &Qcomp_I;
typedef Qcomp &Qcomp_O, &Qcomp_IO;

inline Str quad2str(Qdoub_I x, Int_I prec = 5)
{
	char buf[128];
	int width = 46;
	quadmath_snprintf(buf, sizeof buf, ("%." + to_string(prec-1) + "Qe").c_str(), width, x);
	return buf;
}

inline std::ostream& operator<<(std::ostream& os, Qdoub_I x)
{
	os << quad2str(x, os.precision());
    return os;
}

inline Qdoub acos(Qdoub_I x) { return acosq(x); }
inline Qdoub acosh(Qdoub_I x) { return acoshq(x); }
inline Qdoub asin(Qdoub_I x) { return asinq(x); }
inline Qdoub asinh(Qdoub_I x) { return asinhq(x); }
inline Qdoub atan(Qdoub_I x) { return atanq(x); }
inline Qdoub atanh(Qdoub_I x) { return atanhq(x); }
inline Qdoub atan2(Qdoub_I y, Qdoub_I x) { return atan2q(y, x); }
inline Qdoub cos(Qdoub_I x) { return cos(x); }
inline Qdoub exp(Qdoub_I x) { return exp(x); }
inline Qcomp exp(Qcomp_I x) { return exp(x); }

inline Qdoub sin(Qdoub_I x) { return sinq(x); }
inline Qdoub sqrt(Qdoub_I x) { return sqrtq(x); }
inline Qdoub tan(Qdoub_I x) { return tanq(x); }

} // namespace slisc
