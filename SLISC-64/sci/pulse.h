#pragma once

#include "../spec/coulomb.h"

namespace slisc {

// A * sin(w*(t-t_mid)) * exp(-a*(t-t_mid)^2)
// ref: eq_GausPk_3
inline void gaussian_pulse(VecDoub_O y, Doub_I A, Doub_I FWHMI, Doub_I w, Doub_I t_mid, VecDoub_I t)
{
#ifdef SLS_CHECK_SHAPES
	if (y.size() != t.size())
		SLS_ERR("workspace too small!");
#endif
	Doub a = 2*log(2.) / sqr(FWHMI);
	for (Long i = 0; i < size(t); ++i) {
		Doub tt = t[i] - t_mid;
		y[i] = A * sin(w*tt) * exp(-a*sqr(tt));
	}
}

// vector potential of gaussian_pulse()
// ref: eq_GausPk_3
inline void gaussian_pulse_A(VecDoub_O y, Doub_I A, Doub_I FWHMI, Doub_I w, Doub_I t_mid, VecDoub_I t)
{
#ifdef SLS_CHECK_SHAPES
	if (y.size() != t.size())
		SLS_ERR("wrong shape!");
#endif
	Doub a = 2*log(2.) / sqr(FWHMI), sqrt_a = sqrt(a);
	Doub coeff = 0.5 * A * sqrt(PI/a) * exp(-sqr(w)/(4*a));
	for (Long i = 0; i < size(t); ++i) {
		Doub tt = t[i] - t_mid;
		y[i] = coeff * real(arb_erf(Comp(w, 2*a*tt)/(2*sqrt_a)));
	}
}

// A * sin(w*(t-t_mid))) * sqr(cos(b*(t-t_mid))))
// ref: eq_GausPk_5
inline void cos2_pulse(VecDoub_O y, Doub_I A, Doub_I full_width, Doub_I w, Doub_I t_mid, VecDoub_I t)
{
#ifdef SLS_CHECK_SHAPES
	if (y.size() != t.size())
		SLS_ERR("wrong shape!");
#endif
	Doub b = PI / full_width;
	for (Long i = 0; i < size(t); ++i) {
		Doub tt = t[i] - t_mid;
		if (abs(tt) < PI/(2*b))
			y[i] = A * sin(w*tt) * sqr(cos(b*tt));
		else
			y[i] = 0;
	}
}

// vector potential of sin2_pulse()
// ref: eq_GausPk_2
inline void cos2_pulse_A(VecDoub_O y, Doub_I A, Doub_I full_width, Doub_I w, Doub_I t_mid, VecDoub_I t)
{
#ifdef SLS_CHECK_SHAPES
	if (y.size() != t.size())
		SLS_ERR("wrong shape!");
#endif
	Doub b = PI / full_width;
	for (Long i = 0; i < size(t); ++i) {
		Doub tt = t[i] - t_mid;
		if (abs(tt) < 0.5*full_width) {
			y[i] = -0.25 * A * (-2*cos(w*tt)/w
				-cos((2*b + w)*tt)/(2*b + w) + cos((2*b - w)*tt)/(2*b - w));
		}
		else
			y[i] = 0;
	}
}

} // namespace slisc
