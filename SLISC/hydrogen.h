#pragma once
#include "Vec.h"
#include "Svec.h"
#ifdef SLS_USE_GSL
#include <gsl/gsl_sf_coulomb.h>
#include <gsl/gsl_errno.h>
#endif

namespace slisc {

// === coulomb phase shift ===
#ifdef SLS_USE_GSL
// scaled hydrogen bound state radial wave function
inline void hydrogen_rR(VecDoub_O rR, Int_I n, Int_I l, Doub_I Z, VecDoub_I r)
{
#ifdef SLS_CHECK_SHAPES
	if (rR.size() != r.size())
		SLS_ERR("wrong shape!");
#endif
	gsl_set_error_handler_off(); // turn off error for possible underflow
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = r[i] * gsl_sf_hydrogenicR(n, l, Z, r[i]);
	gsl_set_error_handler(NULL);
}

// unscaled hydrogen bound state radial wave function
inline void hydrogen_R(VecDoub_O rR, Int_I n, Int_I l, Doub_I Z, VecDoub_I r)
{
#ifdef SLS_CHECK_SHAPES
	if (rR.size() != r.size())
		SLS_ERR("wrong shape!");
#endif
	gsl_set_error_handler_off(); // turn off error for possible underflow
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = gsl_sf_hydrogenicR(n, l, Z, r[i]);
	gsl_set_error_handler(NULL);
}

// scaled hydrogen bound state radial wave function
inline void hydrogen_rR(VecDoub_O rR, Int_I n, Int_I l, Doub_I Z, SvecDoub_I r)
{
#ifdef SLS_CHECK_SHAPES
	if (rR.size() != r.size())
		SLS_ERR("wrong shape!");
#endif
	gsl_set_error_handler_off(); // turn off error for possible underflow
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = r[i] * gsl_sf_hydrogenicR(n, l, Z, r[i]);
	gsl_set_error_handler(NULL);
}

// unscaled hydrogen bound state radial wave function
inline void hydrogen_R(VecDoub_O rR, Int_I n, Int_I l, Doub_I Z, SvecDoub_I r)
{
#ifdef SLS_CHECK_SHAPES
	if (rR.size() != r.size())
		SLS_ERR("wrong shape!");
#endif
	gsl_set_error_handler_off(); // turn off error for possible underflow
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = gsl_sf_hydrogenicR(n, l, Z, r[i]);
	gsl_set_error_handler(NULL);
}

// scaled hydrogen bound state radial wave function
inline void hydrogen_rR(SvecDoub_O rR, Int_I n, Int_I l, Doub_I Z, VecDoub_I r)
{
#ifdef SLS_CHECK_SHAPES
	if (rR.size() != r.size())
		SLS_ERR("wrong shape!");
#endif
	gsl_set_error_handler_off(); // turn off error for possible underflow
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = r[i] * gsl_sf_hydrogenicR(n, l, Z, r[i]);
	gsl_set_error_handler(NULL);
}

// unscaled hydrogen bound state radial wave function
inline void hydrogen_R(SvecDoub_O rR, Int_I n, Int_I l, Doub_I Z, VecDoub_I r)
{
#ifdef SLS_CHECK_SHAPES
	if (rR.size() != r.size())
		SLS_ERR("wrong shape!");
#endif
	gsl_set_error_handler_off(); // turn off error for possible underflow
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = gsl_sf_hydrogenicR(n, l, Z, r[i]);
	gsl_set_error_handler(NULL);
}

// scaled hydrogen bound state radial wave function
inline void hydrogen_rR(SvecDoub_O rR, Int_I n, Int_I l, Doub_I Z, SvecDoub_I r)
{
#ifdef SLS_CHECK_SHAPES
	if (rR.size() != r.size())
		SLS_ERR("wrong shape!");
#endif
	gsl_set_error_handler_off(); // turn off error for possible underflow
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = r[i] * gsl_sf_hydrogenicR(n, l, Z, r[i]);
	gsl_set_error_handler(NULL);
}

// unscaled hydrogen bound state radial wave function
inline void hydrogen_R(SvecDoub_O rR, Int_I n, Int_I l, Doub_I Z, SvecDoub_I r)
{
#ifdef SLS_CHECK_SHAPES
	if (rR.size() != r.size())
		SLS_ERR("wrong shape!");
#endif
	gsl_set_error_handler_off(); // turn off error for possible underflow
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = gsl_sf_hydrogenicR(n, l, Z, r[i]);
	gsl_set_error_handler(NULL);
}

#endif
} // namespace slisc
