// associated legendre polynomial
// code adapted from GSL-2.5
#pragma once
#include "../arith/scalar_arith.h"

namespace slisc {

/* Calculate P_m^m(x) from the analytic result:
 *   P_m^m(x) = (-1)^m (2m-1)!! (1-x^2)^(m/2) , m > 0
 *            = 1 , m = 0
 */

inline Doub legendre_Pmm(Long m, Doub_I x)
{
  if (m == 0)
	return 1;
  else
  {
	Doub p_mm = 1;
	Doub root_factor = sqrt(1-x)*sqrt(1+x);
	Doub fact_coeff = 1;
	for(Long i=1; i <= m; ++i) {
	  p_mm *= -fact_coeff * root_factor;
	  fact_coeff += 2;
	}
	return p_mm;
  }
}

inline Qdoub legendre_Pmm(Long m, Qdoub_I x)
{
  if (m == 0)
	return 1;
  else
  {
	Qdoub p_mm = 1;
	Qdoub root_factor = sqrt(1-x)*sqrt(1+x);
	Qdoub fact_coeff = 1;
	for(Long i=1; i <= m; ++i) {
	  p_mm *= -fact_coeff * root_factor;
	  fact_coeff += 2;
	}
	return p_mm;
  }
}


inline Doub legendre_Plm(Long_I l, Long_I m, Doub_I x)
{
  /* If l is large and m is large, then we have to worry
   * about overflow. Calculate an approximate exponent which
   * measures the normalization of this thing.
   */

/* Account for the error due to the
	* representation of 1-x.
	*/

	/* P_m^m(x) and P_{m+1}^m(x) */
	Doub p_mm   = legendre_Pmm(m, x);
	Doub p_mmp1 = x * (2*m + 1) * p_mm;

	if (l == m) {
		return p_mm;
	}
	else if (l == m + 1) {
		return p_mmp1;
	}
	else {
		/* upward recurrence: (l-m) P(l,m) = (2l-1) z P(l-1,m) - (l+m-1) P(l-2,m)
		* start at P(m,m), P(m+1,m)
		*/

		Doub p_ellm2 = p_mm;
		Doub p_ellm1 = p_mmp1;
		Doub p_ell = 0.0;
		for(Long ell=m+2; ell <= l; ++ell) {
			p_ell = (x*(2*ell-1)*p_ellm1 - (ell+m-1)*p_ellm2) / (ell-m);
			p_ellm2 = p_ellm1;
			p_ellm1 = p_ell;
		}
		return p_ell;
	}
}

inline Qdoub legendre_Plm(Long_I l, Long_I m, Qdoub_I x)
{
  /* If l is large and m is large, then we have to worry
   * about overflow. Calculate an approximate exponent which
   * measures the normalization of this thing.
   */

/* Account for the error due to the
	* representation of 1-x.
	*/

	/* P_m^m(x) and P_{m+1}^m(x) */
	Qdoub p_mm   = legendre_Pmm(m, x);
	Qdoub p_mmp1 = x * (2*m + 1) * p_mm;

	if (l == m) {
		return p_mm;
	}
	else if (l == m + 1) {
		return p_mmp1;
	}
	else {
		/* upward recurrence: (l-m) P(l,m) = (2l-1) z P(l-1,m) - (l+m-1) P(l-2,m)
		* start at P(m,m), P(m+1,m)
		*/

		Qdoub p_ellm2 = p_mm;
		Qdoub p_ellm1 = p_mmp1;
		Qdoub p_ell = 0.0;
		for(Long ell=m+2; ell <= l; ++ell) {
			p_ell = (x*(2*ell-1)*p_ellm1 - (ell+m-1)*p_ellm2) / (ell-m);
			p_ellm2 = p_ellm1;
			p_ellm1 = p_ell;
		}
		return p_ell;
	}
}


// derivative of Legendre polynomial
// ref: https://wuli.wiki/changed/Legen.html#Legen_eq6
inline Doub legendreP_der(Long_I l, Doub_I x)
{
	if (x == 1) return l*(l+1)/Doub(2);
	if (x == -1) return isodd(l) ? l*(l+1)/Doub(2) : -l*(l+1)/Doub(2);
	return (l+1)/(1-x*x)*(x*legendre_Plm(l,0,x) - legendre_Plm(l+1,0,x));
}

inline Qdoub legendreP_der(Long_I l, Qdoub_I x)
{
	if (x == 1) return l*(l+1)/Qdoub(2);
	if (x == -1) return isodd(l) ? l*(l+1)/Qdoub(2) : -l*(l+1)/Qdoub(2);
	return (l+1)/(1-x*x)*(x*legendre_Plm(l,0,x) - legendre_Plm(l+1,0,x));
}


} // namespace slisc
