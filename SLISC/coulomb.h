#pragma once
#include "global.h"
#ifdef SLS_USE_GSL
#include <gsl/gsl_specfunc.h>
#include <gsl/gsl_sf_gamma.h>
#include <gsl/gsl_errno.h>
#include "cwfcomp/cwfcomp.h"
#endif

namespace slisc {
using cwfcomp::Coulomb_wave_functions;

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

#endif
} // namespace slisc
