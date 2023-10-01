#pragma once
#include "../dense/Vec.h"
#include "../dense/Svec.h"
#ifdef SLS_USE_GSL
#include <gsl/gsl_sf_coulomb.h>
#include <gsl/gsl_errno.h>
#endif

namespace slisc {

// === coulomb phase shift ===
#ifdef SLS_USE_GSL
// scaled hydrogen bound state radial wave function, normalized
inline void hydrogen_rR(VecDoub_O rR, Int_I n, Int_I l, Doub_I Z, VecDoub_I r)
{
	assert_same_shape1(rR, r);
	gsl_set_error_handler_off(); // turn off error for possible underflow
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = r[i] * gsl_sf_hydrogenicR(n, l, Z, r[i]);
	gsl_set_error_handler(NULL);
}

// unscaled hydrogen bound state radial wave function
inline void hydrogen_R(VecDoub_O rR, Int_I n, Int_I l, Doub_I Z, VecDoub_I r)
{
	assert_same_shape1(rR, r);
	gsl_set_error_handler_off(); // turn off error for possible underflow
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = gsl_sf_hydrogenicR(n, l, Z, r[i]);
	gsl_set_error_handler(NULL);
}

// ref: https://wuli.wiki/online/HWF.html#HWF_eq7
inline void hydrogen_rR(VecQdoub_O rR, Long_I n, Long_I l, Qdoub_I Z, VecQdoub_I r)
{
	assert_same_shape1(rR, r);
	if (n == 1 && l == 0) {
		Qdoub coef = 2.Q*pow(Z, 3.Q/2.Q);
		for (Long i = 0; i < r.size(); ++i)
			rR[i] = r[i] * coef *exp(-Z*r[i]);
		return;
	}
	else if (n == 2) {
		if (l == 0) {
			Qdoub coef = 1.Q/sqrt(2.Q)*pow(Z, 3.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * (1.Q - 0.5Q*Z*r[i]) * exp(-Z*r[i]*0.5Q);
			return;
		}
		else if (l == 1) {
			Qdoub coef = 0.5Q/sqrt(6.Q) * pow(Z, 5.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * r[i] * exp(-Z*r[i]*0.5Q);
			return;
		}
	}
	else if (n == 3) {
		if (l == 0) {
			Qdoub coef = 2.Q/(3.Q*sqrt(3.Q))*pow(Z, 3.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * (1.Q - 2.Q/3.Q*Z*r[i] + 2.Q/27.Q*sqr(Z*r[i]))
				 * exp(-Z*r[i]/3.Q);
			return;
		}
		else if (l == 1) {
			Qdoub coef = 8.Q/(27.Q*sqrt(6.Q))*pow(Z, 5.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * (1.Q - 1.Q/6.Q*Z*r[i]) *
					r[i] * exp(-Z*r[i]/3.Q);
			return;
		}
		else if (l == 2) {
			Qdoub coef = 4.Q/(81.Q*sqrt(30.Q)) * pow(Z, 7.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * sqr(r[i]) * exp(-Z*r[i]/3.Q);
			return;
		}
	}
	SLS_ERR("not implemented!");
}

// unscaled hydrogen bound state radial wave function
inline void hydrogen_R(VecQdoub_O rR, Long_I n, Long_I l, Qdoub_I Z, VecQdoub_I r)
{
	assert_same_shape1(rR, r);
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = gsl_sf_hydrogenicR(n, l, Z, r[i]);
}

// scaled hydrogen bound state radial wave function, normalized
inline void hydrogen_rR(VecDoub_O rR, Int_I n, Int_I l, Doub_I Z, SvecDoub_I r)
{
	assert_same_shape1(rR, r);
	gsl_set_error_handler_off(); // turn off error for possible underflow
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = r[i] * gsl_sf_hydrogenicR(n, l, Z, r[i]);
	gsl_set_error_handler(NULL);
}

// unscaled hydrogen bound state radial wave function
inline void hydrogen_R(VecDoub_O rR, Int_I n, Int_I l, Doub_I Z, SvecDoub_I r)
{
	assert_same_shape1(rR, r);
	gsl_set_error_handler_off(); // turn off error for possible underflow
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = gsl_sf_hydrogenicR(n, l, Z, r[i]);
	gsl_set_error_handler(NULL);
}

// ref: https://wuli.wiki/online/HWF.html#HWF_eq7
inline void hydrogen_rR(VecQdoub_O rR, Long_I n, Long_I l, Qdoub_I Z, SvecQdoub_I r)
{
	assert_same_shape1(rR, r);
	if (n == 1 && l == 0) {
		Qdoub coef = 2.Q*pow(Z, 3.Q/2.Q);
		for (Long i = 0; i < r.size(); ++i)
			rR[i] = r[i] * coef *exp(-Z*r[i]);
		return;
	}
	else if (n == 2) {
		if (l == 0) {
			Qdoub coef = 1.Q/sqrt(2.Q)*pow(Z, 3.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * (1.Q - 0.5Q*Z*r[i]) * exp(-Z*r[i]*0.5Q);
			return;
		}
		else if (l == 1) {
			Qdoub coef = 0.5Q/sqrt(6.Q) * pow(Z, 5.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * r[i] * exp(-Z*r[i]*0.5Q);
			return;
		}
	}
	else if (n == 3) {
		if (l == 0) {
			Qdoub coef = 2.Q/(3.Q*sqrt(3.Q))*pow(Z, 3.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * (1.Q - 2.Q/3.Q*Z*r[i] + 2.Q/27.Q*sqr(Z*r[i]))
				 * exp(-Z*r[i]/3.Q);
			return;
		}
		else if (l == 1) {
			Qdoub coef = 8.Q/(27.Q*sqrt(6.Q))*pow(Z, 5.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * (1.Q - 1.Q/6.Q*Z*r[i]) *
					r[i] * exp(-Z*r[i]/3.Q);
			return;
		}
		else if (l == 2) {
			Qdoub coef = 4.Q/(81.Q*sqrt(30.Q)) * pow(Z, 7.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * sqr(r[i]) * exp(-Z*r[i]/3.Q);
			return;
		}
	}
	SLS_ERR("not implemented!");
}

// unscaled hydrogen bound state radial wave function
inline void hydrogen_R(VecQdoub_O rR, Long_I n, Long_I l, Qdoub_I Z, SvecQdoub_I r)
{
	assert_same_shape1(rR, r);
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = gsl_sf_hydrogenicR(n, l, Z, r[i]);
}

// scaled hydrogen bound state radial wave function, normalized
inline void hydrogen_rR(SvecDoub_O rR, Int_I n, Int_I l, Doub_I Z, VecDoub_I r)
{
	assert_same_shape1(rR, r);
	gsl_set_error_handler_off(); // turn off error for possible underflow
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = r[i] * gsl_sf_hydrogenicR(n, l, Z, r[i]);
	gsl_set_error_handler(NULL);
}

// unscaled hydrogen bound state radial wave function
inline void hydrogen_R(SvecDoub_O rR, Int_I n, Int_I l, Doub_I Z, VecDoub_I r)
{
	assert_same_shape1(rR, r);
	gsl_set_error_handler_off(); // turn off error for possible underflow
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = gsl_sf_hydrogenicR(n, l, Z, r[i]);
	gsl_set_error_handler(NULL);
}

// ref: https://wuli.wiki/online/HWF.html#HWF_eq7
inline void hydrogen_rR(SvecQdoub_O rR, Long_I n, Long_I l, Qdoub_I Z, VecQdoub_I r)
{
	assert_same_shape1(rR, r);
	if (n == 1 && l == 0) {
		Qdoub coef = 2.Q*pow(Z, 3.Q/2.Q);
		for (Long i = 0; i < r.size(); ++i)
			rR[i] = r[i] * coef *exp(-Z*r[i]);
		return;
	}
	else if (n == 2) {
		if (l == 0) {
			Qdoub coef = 1.Q/sqrt(2.Q)*pow(Z, 3.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * (1.Q - 0.5Q*Z*r[i]) * exp(-Z*r[i]*0.5Q);
			return;
		}
		else if (l == 1) {
			Qdoub coef = 0.5Q/sqrt(6.Q) * pow(Z, 5.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * r[i] * exp(-Z*r[i]*0.5Q);
			return;
		}
	}
	else if (n == 3) {
		if (l == 0) {
			Qdoub coef = 2.Q/(3.Q*sqrt(3.Q))*pow(Z, 3.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * (1.Q - 2.Q/3.Q*Z*r[i] + 2.Q/27.Q*sqr(Z*r[i]))
				 * exp(-Z*r[i]/3.Q);
			return;
		}
		else if (l == 1) {
			Qdoub coef = 8.Q/(27.Q*sqrt(6.Q))*pow(Z, 5.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * (1.Q - 1.Q/6.Q*Z*r[i]) *
					r[i] * exp(-Z*r[i]/3.Q);
			return;
		}
		else if (l == 2) {
			Qdoub coef = 4.Q/(81.Q*sqrt(30.Q)) * pow(Z, 7.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * sqr(r[i]) * exp(-Z*r[i]/3.Q);
			return;
		}
	}
	SLS_ERR("not implemented!");
}

// unscaled hydrogen bound state radial wave function
inline void hydrogen_R(SvecQdoub_O rR, Long_I n, Long_I l, Qdoub_I Z, VecQdoub_I r)
{
	assert_same_shape1(rR, r);
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = gsl_sf_hydrogenicR(n, l, Z, r[i]);
}

// scaled hydrogen bound state radial wave function, normalized
inline void hydrogen_rR(SvecDoub_O rR, Int_I n, Int_I l, Doub_I Z, SvecDoub_I r)
{
	assert_same_shape1(rR, r);
	gsl_set_error_handler_off(); // turn off error for possible underflow
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = r[i] * gsl_sf_hydrogenicR(n, l, Z, r[i]);
	gsl_set_error_handler(NULL);
}

// unscaled hydrogen bound state radial wave function
inline void hydrogen_R(SvecDoub_O rR, Int_I n, Int_I l, Doub_I Z, SvecDoub_I r)
{
	assert_same_shape1(rR, r);
	gsl_set_error_handler_off(); // turn off error for possible underflow
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = gsl_sf_hydrogenicR(n, l, Z, r[i]);
	gsl_set_error_handler(NULL);
}

// ref: https://wuli.wiki/online/HWF.html#HWF_eq7
inline void hydrogen_rR(SvecQdoub_O rR, Long_I n, Long_I l, Qdoub_I Z, SvecQdoub_I r)
{
	assert_same_shape1(rR, r);
	if (n == 1 && l == 0) {
		Qdoub coef = 2.Q*pow(Z, 3.Q/2.Q);
		for (Long i = 0; i < r.size(); ++i)
			rR[i] = r[i] * coef *exp(-Z*r[i]);
		return;
	}
	else if (n == 2) {
		if (l == 0) {
			Qdoub coef = 1.Q/sqrt(2.Q)*pow(Z, 3.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * (1.Q - 0.5Q*Z*r[i]) * exp(-Z*r[i]*0.5Q);
			return;
		}
		else if (l == 1) {
			Qdoub coef = 0.5Q/sqrt(6.Q) * pow(Z, 5.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * r[i] * exp(-Z*r[i]*0.5Q);
			return;
		}
	}
	else if (n == 3) {
		if (l == 0) {
			Qdoub coef = 2.Q/(3.Q*sqrt(3.Q))*pow(Z, 3.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * (1.Q - 2.Q/3.Q*Z*r[i] + 2.Q/27.Q*sqr(Z*r[i]))
				 * exp(-Z*r[i]/3.Q);
			return;
		}
		else if (l == 1) {
			Qdoub coef = 8.Q/(27.Q*sqrt(6.Q))*pow(Z, 5.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * (1.Q - 1.Q/6.Q*Z*r[i]) *
					r[i] * exp(-Z*r[i]/3.Q);
			return;
		}
		else if (l == 2) {
			Qdoub coef = 4.Q/(81.Q*sqrt(30.Q)) * pow(Z, 7.Q/2.Q);
			for (Long i = 0; i < r.size(); ++i)
				rR[i] = r[i] * coef * sqr(r[i]) * exp(-Z*r[i]/3.Q);
			return;
		}
	}
	SLS_ERR("not implemented!");
}

// unscaled hydrogen bound state radial wave function
inline void hydrogen_R(SvecQdoub_O rR, Long_I n, Long_I l, Qdoub_I Z, SvecQdoub_I r)
{
	assert_same_shape1(rR, r);
	for (Long i = 0; i < r.size(); ++i)
		rR[i] = gsl_sf_hydrogenicR(n, l, Z, r[i]);
}

#endif
} // namespace slisc
