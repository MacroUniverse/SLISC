// associated legendre polynomial
// code from GSL-2.5

#include "global.h"

namespace slisc {

/* Calculate P_m^m(x) from the analytic result:
 *   P_m^m(x) = (-1)^m (2m-1)!! (1-x^2)^(m/2) , m > 0
 *            = 1 , m = 0
 */

Doub legendre_Pmm(int m, Doub_I x)
{
  if(m == 0)
  {
    return 1.0;
  }
  else
  {
    Doub p_mm = 1;
    Doub root_factor = sqrt(1-x)*sqrt(1+x);
    Doub fact_coeff = 1;
    int i;
    for(i=1; i<=m; i++) {
      p_mm *= -fact_coeff * root_factor;
      fact_coeff += 2;
    }
    return p_mm;
  }
}

Qdoub legendre_Pmm(int m, Qdoub_I x)
{
  if(m == 0)
  {
    return 1.0;
  }
  else
  {
    Qdoub p_mm = 1;
    Qdoub root_factor = sqrt(1-x)*sqrt(1+x);
    Qdoub fact_coeff = 1;
    int i;
    for(i=1; i<=m; i++) {
      p_mm *= -fact_coeff * root_factor;
      fact_coeff += 2;
    }
    return p_mm;
  }
}


Doub legendre_Plm(Int_I l, Int_I m, Doub_I x)
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

if(l == m){
	return p_mm;
}
else if(l == m + 1) {
	return p_mmp1;
}
else{
	/* upward recurrence: (l-m) P(l,m) = (2l-1) z P(l-1,m) - (l+m-1) P(l-2,m)
	* start at P(m,m), P(m+1,m)
	*/

	Doub p_ellm2 = p_mm;
	Doub p_ellm1 = p_mmp1;
	Doub p_ell = 0.0;
	Int ell;

	for(ell=m+2; ell <= l; ell++){
    p_ell = (x*(2*ell-1)*p_ellm1 - (ell+m-1)*p_ellm2) / (ell-m);
    p_ellm2 = p_ellm1;
    p_ellm1 = p_ell;
	}

	return p_ell;
}
}

Qdoub legendre_Plm(Int_I l, Int_I m, Qdoub_I x)
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

if(l == m){
	return p_mm;
}
else if(l == m + 1) {
	return p_mmp1;
}
else{
	/* upward recurrence: (l-m) P(l,m) = (2l-1) z P(l-1,m) - (l+m-1) P(l-2,m)
	* start at P(m,m), P(m+1,m)
	*/

	Qdoub p_ellm2 = p_mm;
	Qdoub p_ellm1 = p_mmp1;
	Qdoub p_ell = 0.0;
	Int ell;

	for(ell=m+2; ell <= l; ell++){
    p_ell = (x*(2*ell-1)*p_ellm1 - (ell+m-1)*p_ellm2) / (ell-m);
    p_ellm2 = p_ellm1;
    p_ellm1 = p_ell;
	}

	return p_ell;
}
}


} // namespace slisc
