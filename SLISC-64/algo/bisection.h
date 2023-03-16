#pragma once
#include "../global.h"

namespace slisc {

// bisection method to get the root of a function
template <class Tfun, class Ts>
inline Ts bisection(Tfun f, const Ts &x1, const Ts &x2, const Ts &tol_x)
{
	Ts a = x1, b = x2, mid;
	Ts fl = f(a), fr = f(b), fm;
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
template <class Tfun, class Ts>
void bisectionN(vector<Ts> &roots, Tfun f, const Ts &x1, const Ts &x2, Long N, const Ts &tol_x)
{
	roots.clear();
	Ts dx = (x2 - x1) / (N-1);
	for (Long i = 0; i < N - 1; ++i) {
		Ts a = x1 + dx*i, b = a + dx;
		if (f(a) * f(b) <= 0) {
			Ts x = bisection(f, a, b, tol_x);
			roots.push_back(x);
		}
	}
}

} // namespace slisc
