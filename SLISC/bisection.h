#include "arithmetic.h"

namespace slisc {

// bisection method to get the root of a function
template <class Tfun>
inline Doub bisection(Tfun f, Doub_I x1, Doub_I x2, Doub_I tol_x)
{
	Doub a = x1, b = x2, mid;
	Doub fl = f(a), fr = f(b), fm;
	if (fl == 0)
		return a;
	else if (fr == 0)
		return b;

	if (fl * fr > 0)
		SLS_ERR("bisection: function have the same sign on both side!");

	do {
		mid = 0.5*(a + b);
		fm = f(mid);
		if (fm * fl > 0)
			a = mid;
		else if (fm * fr > 0)
			b = mid;
		else
			break;
	} while(b - a > tol_x);
	return mid;
}

// multi-intervel bisection method
// not optimized
template <class Tfun>
void bisectionN(vecDoub_O roots, Tfun f, Doub_I x1, Doub_I x2, Long N, Doub_I tol_x)
{
	roots.clear();
	Doub dx = (x2 - x1) / (N-1);
	for (Long i = 0; i < N - 1; ++i) {
		Doub a = x1 + dx*i, b = a + dx;
		if (f(a) * f(b) <= 0) {
			Doub x = bisection(f, a, b, tol_x);
			roots.push_back(x);
		}
	}
}

} // namespace slisc
