#pragma once
#include "global.h"
#ifdef SLS_USE_ARB
#include "arb_hypgeom.h" // real functions
#include "acb_hypgeom.h" // complex functions
#endif
#ifdef SLS_USE_GSL
#include <gsl/gsl_specfunc.h>
#include <gsl/gsl_sf_gamma.h>
#include <gsl/gsl_errno.h>
#include "cwfcomp/cwfcomp.h"
#endif

namespace slisc {
#ifdef SLS_USE_ARB
// Coulomb function (normalized)
inline Doub arb_coulombF(Doub_I l, Doub_I eta, Doub_I x)
{
	slong prec = 64; // set precision bit (log10/log2 = 3.322)
	Doub F = 0;
	arb_t l1, eta1, x1, F1;
	arb_init(l1); arb_init(eta1); arb_init(x1); arb_init(F1);
	arb_set_d(l1, l); arb_set_d(eta1, eta); arb_set_d(x1, x);

	arb_hypgeom_coulomb(F1, NULL, l1, eta1, x1, prec);

	Int digits = arb_rel_accuracy_bits(F1)/3.321928;
	if (digits < 15) {
		cout << "warning: hypergeom1F1 error too large : " << digits << " digits" << endl;
	}
	F = arf_get_d(arb_midref(F1), ARF_RND_NEAR);
	arb_clear(l1); arb_clear(eta1); arb_clear(x1); arb_clear(F1);
	return F;
}

inline Comp arb_gamma(Comp_I z)
{
    Comp res;
    acb_t z1, res1;
    arb_t temp1;
    acb_init(z1); acb_init(res1); arb_init(temp1);
    acb_set_d_d(z1, real(z), imag(z));
    acb_gamma(res1, z1, 64);
    int digits = acb_rel_accuracy_bits(res1)/3.321928;
	if (digits < 15)
		SLS_WARN("warning: arb_gamma error too large!");
	acb_get_real(temp1, res1);
	res.real(arf_get_d(arb_midref(temp1), ARF_RND_NEAR));
	acb_get_imag(temp1, res1);
	res.imag(arf_get_d(arb_midref(temp1), ARF_RND_NEAR));
	acb_clear(z1); acb_clear(res1); arb_clear(temp1);
	return res;
}

inline Comp arb_ln_gamma(Comp_I c)
{
    SLS_ERR("not implemented!");
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
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(F, r))
        SLS_ERR("wrong shape!");
#endif

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
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(F, r))
        SLS_ERR("wrong shape!");
#endif

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
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(F, r))
        SLS_ERR("wrong shape!");
#endif

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
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(F, r))
        SLS_ERR("wrong shape!");
#endif

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
Doub coulomb_sigma(Int_I l, Doub_I eta)
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
