#pragma once
#include "global.h"
#ifdef SLS_USE_GSL
#include <gsl/gsl_sf_gamma.h>
#include <gsl/gsl_errno.h>
#endif

namespace slisc {

// === coulomb phase shift ===
#ifdef SLS_USE_GSL
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
