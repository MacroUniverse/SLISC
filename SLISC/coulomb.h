#pragma once
#include "compare.h"
#ifdef SLS_USE_ARB
#include <gmp.h>
#include <flint.h>
#include "arb_hypgeom.h" // real functions
#include "acb_hypgeom.h" // complex functions
#include "arb_extension.h"
#endif
#ifdef SLS_USE_GSL
#include <gsl/gsl_specfunc.h>
#include <gsl/gsl_sf_gamma.h>
#include <gsl/gsl_errno.h>
#endif
#include "cwfcomp/cwfcomp.h"

namespace slisc {
#ifdef SLS_USE_ARB
// Coulomb function (normalized)
inline Doub arb_coulombF(Doub_I l, Doub_I eta, Doub_I x)
{
	slong prec = 80; // set precision bit (log10/log2 = 3.322)
	Doub F = 0;
	arb_t l1, eta1, x1, F1;
	arb_init(l1); arb_init(eta1); arb_init(x1); arb_init(F1);
	// can use _arb_init_set_d() instead
	arb_set_d(l1, l); arb_set_d(eta1, eta); arb_set_d(x1, x);
	Int digits;
	for (Long i = 0; i < 6; ++i) {
		arb_hypgeom_coulomb(F1, NULL, l1, eta1, x1, prec);
		digits = floor(arb_rel_accuracy_bits(F1)/3.321928);
		if (digits >= 16)
			break;
		prec *= 2;
	}
	if (digits < 16)
		SLS_ERR("arb_coulombF error too large : " + num2str(digits) + " digits");
	F = arf_get_d(arb_midref(F1), ARF_RND_NEAR);
	arb_clear(l1); arb_clear(eta1); arb_clear(x1); arb_clear(F1);
	return F;
}



// complex version
// warning: this function differs from my Mathematica definition (FlCode.tex)
inline Comp acb_coulombF(Comp_I l, Comp_I eta, Comp_I x)
{
	slong prec = 80; // set precision bit (log10/log2 = 3.322)
	acb_t l1, eta1, x1, F1; arb_t F1_re, F1_im;
	acb_init(l1); acb_init(eta1); acb_init(x1); acb_init(F1);
	arb_init(F1_re); arb_init(F1_im);
	acb_set_d_d(l1, l.real(), l.imag());
	acb_set_d_d(eta1, eta.real(), eta.imag()); acb_set_d_d(x1, x.real(), x.imag());
	Int digits;
	for (Long i = 0; i < 6; ++i) {
		acb_hypgeom_coulomb(F1, NULL, NULL, NULL, l1, eta1, x1, prec);
		digits = acb_rel_accuracy_bits(F1)/3.321928;
		if (digits >= 16)
			break;
		prec *= 2;
	}
	if (digits < 16)
		SLS_ERR("arb_coulombF error too large : " + num2str(digits) + " digits");
	acb_get_real(F1_re, F1); acb_get_imag(F1_im, F1);
	Comp F(arf_get_d(arb_midref(F1_re), ARF_RND_NEAR), arf_get_d(arb_midref(F1_im), ARF_RND_NEAR));
	acb_clear(l1); acb_clear(eta1); acb_clear(x1); acb_clear(F1);
	arb_clear(F1_re); arb_clear(F1_im);
	return F;
}

inline Doub arb_gamma(Doub_I x)
{
	slong prec = 80; // set precision bit (log10/log2 = 3.322)
	Doub res = 0;
	arb_t x1, res1;
	arb_init(x1); arb_init(res1);
	// can use _arb_init_set_d() instead
	arb_set_d(x1, x);
	Int digits;
	for (Long i = 0; i < 6; ++i) {
		arb_gamma(res1, x1, prec);
		digits = floor(arb_rel_accuracy_bits(res1)/3.321928);
		if (digits >= 16)
			break;
		prec *= 2;
	}
	if (digits < 16)
		SLS_ERR("arb_gamma error too large : " + num2str(digits) + " digits");
	res = arf_get_d(arb_midref(res1), ARF_RND_NEAR);
	arb_clear(x1); arb_clear(res1);
	return res;
}

inline Comp arb_gamma(Comp_I z)
{
	slong prec = 80;
	Comp res;
	acb_t z1, res1;
	arb_t temp1;
	Int digits;
	acb_init(z1); acb_init(res1); arb_init(temp1);
	acb_set_d_d(z1, real(z), imag(z));
	for (Long i = 0; i < 6; ++i) {
		acb_gamma(res1, z1, prec);
		digits = acb_rel_accuracy_bits(res1)/3.321928;
		if (digits >= 16)
			break;
		prec *= 2;
	}
	if (digits < 16)
		SLS_ERR("arb_gamma error too large : " + num2str(digits) + " digits");
	acb_get_real(temp1, res1);
	res.real(arf_get_d(arb_midref(temp1), ARF_RND_NEAR));
	acb_get_imag(temp1, res1);
	res.imag(arf_get_d(arb_midref(temp1), ARF_RND_NEAR));
	acb_clear(z1); acb_clear(res1); arb_clear(temp1);
	return res;
}

inline Comp arb_lngamma(Comp_I z)
{
	slong prec = 80;
	Comp res;
	acb_t z1, res1;
	arb_t temp1;
	Int digits;
	acb_init(z1); acb_init(res1); arb_init(temp1);
	acb_set_d_d(z1, real(z), imag(z));
	for (Long i = 0; i < 6; ++i) {
		acb_lgamma(res1, z1, prec);
		digits = acb_rel_accuracy_bits(res1)/3.321928;
		if (digits >= 16)
			break;
		prec *= 2;
	}
	if (digits < 16)
		SLS_ERR("arb_lngamma error too large : " + num2str(digits) + " digits");
	acb_get_real(temp1, res1);
	res.real(arf_get_d(arb_midref(temp1), ARF_RND_NEAR));
	acb_get_imag(temp1, res1);
	res.imag(arf_get_d(arb_midref(temp1), ARF_RND_NEAR));
	acb_clear(z1); acb_clear(res1); arb_clear(temp1);
	return res;
}

inline Doub arb_coulomb_sigma(Doub_I l, Doub_I eta)
{
	if (eta > 0)
		SLS_ERR("are you sure?");
	return imag(arb_lngamma(Comp(l + 1, eta)));
}
#endif

using cwfcomp::Coulomb_wave_functions;
inline Doub coulombF(Int_I l, Doub_I k, Doub_I r, Doub_I Z = -1.)
{
	Comp F, dF;
	Doub eta = Z / k;
	cwfcomp::Coulomb_wave_functions f(true, l, eta);
	f.F_dF(k * r, F, dF);
	return real(F);
}

// cut the non-zero band
inline void coulombF(VecDoub_O F, Int_I l, Doub_I k, VecDoub_I r, Doub_I Z = -1.)
{
	assert_same_shape(F, r);
	Comp F1, dF1;
	Doub eta = Z / k;
	for (Long i = 0; i < r.size(); ++i) {
		// must use a new "Coulomb_wave_functions" to keep accuracy
		// if the same object is used, the ODE solver might solve next point based on the previous point
		// constructor time is only 1/60 to 1/10 of the calculation time, so don't try to optimize this!
		cwfcomp::Coulomb_wave_functions f(true, l, eta);
		f.F_dF(k * r[i], F1, dF1);
		F[i] = real(F1);
	}
}

inline void coulombF(VecDoub_O F, Int_I l, Doub_I k, SvecDoub_I r, Doub_I Z = -1.)
{
	assert_same_shape(F, r);
	Comp F1, dF1;
	Doub eta = Z / k;
	for (Long i = 0; i < r.size(); ++i) {
		// must use a new "Coulomb_wave_functions" to keep accuracy
		// if the same object is used, the ODE solver might solve next point based on the previous point
		// constructor time is only 1/60 to 1/10 of the calculation time, so don't try to optimize this!
		cwfcomp::Coulomb_wave_functions f(true, l, eta);
		f.F_dF(k * r[i], F1, dF1);
		F[i] = real(F1);
	}
}

inline void coulombF(SvecDoub_O F, Int_I l, Doub_I k, VecDoub_I r, Doub_I Z = -1.)
{
	assert_same_shape(F, r);
	Comp F1, dF1;
	Doub eta = Z / k;
	for (Long i = 0; i < r.size(); ++i) {
		// must use a new "Coulomb_wave_functions" to keep accuracy
		// if the same object is used, the ODE solver might solve next point based on the previous point
		// constructor time is only 1/60 to 1/10 of the calculation time, so don't try to optimize this!
		cwfcomp::Coulomb_wave_functions f(true, l, eta);
		f.F_dF(k * r[i], F1, dF1);
		F[i] = real(F1);
	}
}

inline void coulombF(SvecDoub_O F, Int_I l, Doub_I k, SvecDoub_I r, Doub_I Z = -1.)
{
	assert_same_shape(F, r);
	Comp F1, dF1;
	Doub eta = Z / k;
	for (Long i = 0; i < r.size(); ++i) {
		// must use a new "Coulomb_wave_functions" to keep accuracy
		// if the same object is used, the ODE solver might solve next point based on the previous point
		// constructor time is only 1/60 to 1/10 of the calculation time, so don't try to optimize this!
		cwfcomp::Coulomb_wave_functions f(true, l, eta);
		f.F_dF(k * r[i], F1, dF1);
		F[i] = real(F1);
	}
}


#ifdef SLS_USE_GSL
// === coulomb phase shift ===
inline Doub coulomb_sigma(Int_I l, Doub_I eta)
{
	if (eta > 0)
		SLS_ERR("are you sure?");
	gsl_sf_result lnr, arg;
	if (gsl_sf_lngamma_complex_e(l + 1, eta, &lnr, &arg) == GSL_ELOSS)
		SLS_ERR("arg has loss!");
	return arg.val;
}
#endif
} // namespace slisc
