#pragma once
#include <complex>
#include <algorithm>
#include <iostream>

namespace cwfcomp {
using namespace std;

typedef std::complex<double> Comp;
const double C_LN2 = 0.693147180559945309417;
const double C_PI_2 = 1.57079632679489661923;
const double C_PI = 3.14159265358979323846;

template <typename T>
inline T SIGN(T a) {
	return a < 0 ? (-1) : 1;
}

// Infinite norm of a complex number.
// ----------------------------------
// It is max(|Re[z]|,|Im[z]|)

inline double inf_norm (const Comp &z)
{
  return max (abs (real (z)),abs (imag (z)));
}


// Test of finiteness of a complex number
// --------------------------------------
// If real or imaginary parts are finite, true is returned.
// Otherwise, false is returned

inline bool isfinite (const Comp &z)
{
  const double x = real (z), y = imag (z);

  return (std::isfinite (x) && std::isfinite (y));
}




// Usual operator overloads of complex numbers with integers
// ---------------------------------------------------------
// Recent complex libraries do not accept for example z+n or z==n with n integer, signed or unsigned.
// The operator overload is done here, by simply putting a cast on double to the integer.

inline Comp operator + (const Comp &z,const int n)
{
  return (z+static_cast<double> (n));
}

inline Comp operator - (const Comp &z,const int n)
{
  return (z-static_cast<double> (n));
}

inline Comp operator * (const Comp &z,const int n)
{
  return (z*static_cast<double> (n));
}

inline Comp operator / (const Comp &z,const int n)
{
  return (z/static_cast<double> (n));
}

inline Comp operator + (const int n,const Comp &z)
{
  return (static_cast<double> (n)+z);
}

inline Comp operator - (const int n,const Comp &z)
{
  return (static_cast<double> (n)-z);
}

inline Comp operator * (const int n,const Comp &z)
{
  return (static_cast<double> (n)*z);
}

inline Comp operator / (const int n,const Comp &z)
{
  return (static_cast<double> (n)/z);
}








inline Comp operator + (const Comp &z,const unsigned int n)
{
  return (z+static_cast<double> (n));
}

inline Comp operator - (const Comp &z,const unsigned int n)
{
  return (z-static_cast<double> (n));
}

inline Comp operator * (const Comp &z,const unsigned int n)
{
  return (z*static_cast<double> (n));
}

inline Comp operator / (const Comp &z,const unsigned int n)
{
  return (z/static_cast<double> (n));
}

inline Comp operator + (const unsigned int n,const Comp &z)
{
  return (static_cast<double> (n)+z);
}

inline Comp operator - (const unsigned int n,const Comp &z)
{
  return (static_cast<double> (n)-z);
}

inline Comp operator * (const unsigned int n,const Comp &z)
{
  return (static_cast<double> (n)*z);
}

inline Comp operator / (const unsigned int n,const Comp &z)
{
  return (static_cast<double> (n)/z);
}




inline bool operator == (const Comp &z,const int n)
{
  return (z == static_cast<double> (n));
}

inline bool operator != (const Comp &z,const int n)
{
  return (z != static_cast<double> (n));
}

inline bool operator == (const int n,const Comp &z)
{
  return (static_cast<double> (n) == z);
}

inline bool operator != (const int n,const Comp &z)
{
  return (static_cast<double> (n) != z);
}







inline bool operator == (const Comp &z,const unsigned int n)
{
  return (z == static_cast<double> (n));
}

inline bool operator != (const Comp &z,const unsigned int n)
{
  return (z != static_cast<double> (n));
}

inline bool operator == (const unsigned int n,const Comp &z)
{
  return (static_cast<double> (n) == z);
}

inline bool operator != (const unsigned int n,const Comp &z)
{
  return (static_cast<double> (n) != z);
}






// Precise evaluation of exp[z]-1 for z complex
// --------------------------------------------
// When |Re[z]| >= 1 or |Im[z]| >= 1, one uses directly the standard exp function as it is precise.
// Otherwise, numerical cancellations can occur.
// So, one uses the always stable formula exp[z]-1 = expm1(x) - 2.exp(x).sin^2(y/2) + i.exp(x).sin(y) 
// with x = Re[z] and y = Im[z]. expm1(x) gives a precise evaluation of exp(x)-1 for x double.

inline Comp expm1 (const Comp &z)
{
  const double x = real (z),y = imag (z);

  if ((abs (x) >= 1.0) || (abs (y) >= 1.0)) return (exp (z) - 1.0);

  const double expm1_x = std::expm1 (x),exp_x = 1.0 + expm1_x,sin_y_over_two = sin (0.5*y),sin_y = sin (y);

  return Comp (expm1_x - 2.0*exp_x*sin_y_over_two*sin_y_over_two,exp_x*sin_y);
}



// Precise evaluation of log[1+z] for z complex
// --------------------------------------------
// When |Re[z]| >= 1 or |Im[z]| >= 1, one uses directly the standard log function as it is precise.
// Otherwise, numerical cancellations can occur.
// So, one uses the always stable formula log[1+z] = log1p(x) + log1p([y/(1+x)]^2)/2 + i.atan2(y,1+x)
// with x = Re[z] and y = Im[z]. log1p(x) gives a precise evaluation of log(1+x) for x double.
// atan2(x,y) gives the arc tangent of y/x so it is in ]-Pi:Pi]. 

inline Comp log1p (const Comp &z)
{
  const double x = real (z),y = imag (z); 

  const double xp1 = 1.0 + x,abs_x = abs (x), abs_y = abs (y);

  if ((abs_x >= 1.0) || (abs_y >= 1.0)) return log (1.0 + z);
 
  const double y_over_xp1 = y/xp1;

  return Comp (std::log1p (x) + 0.5*std::log1p (y_over_xp1*y_over_xp1),atan2 (y,xp1));
}




// Logarithm of Gamma[z], z anywhere in the complex plane except in the Gamma function poles.
// ------------------------------------------------------------------------------------------
// If z is not finite or is a negative integer, the program returns an error message and stops.
// The Lanczos method is used. Precision : < 2E-10 in theory, < 1E-12 in almost every case.
// The method works for Re[z] > 0.
// If Re[z] <= 0, one uses the formula Gamma[z].Gamma[1-z] = Pi/sin (Pi.z).
// log[sin(Pi.z)] is calculated with the Kolbig method (K.S. Kolbig, Comp. Phys. Comm., Vol. 4, p.221 (1972)) : 
// If z = x+iy and y >= 0, log[sin(Pi.z)] = log[sin(Pi.eps)] - i.Pi.n, with z = n + eps so 0 <= Re[eps] < 1 and n integer.
// If y > 110, log[sin(Pi.z)] = -i.Pi.z + log[0.5] + i.Pi/2 numerically so that no overflow can occur.
// If z = x+iy and y < 0, log[Gamma(z)] = [log[Gamma(z*)]]*, so that one can use the previous formula with z*.
//
// Variables:
// ----------
// z,z_p_0p5,z_p_5p5 : argument of the Gamma function, z+0.5, z+5.5 
// sqrt_2Pi,log_Pi : sqrt(2.Pi), log(Pi).
// sum : Rational function in the Lanczos method.
// log_Gamma_z : log[Gamma(z)] value.
// c : table containing the seven coefficients in the expansion used in the Lanczos method.
// eps : z = n + eps so 0 <= Re[eps] < 1 and n integer.
// log_const : log[0.5] + i.Pi/2

inline Comp log_Gamma (const Comp &z)
{
  if (!isfinite (z)) cout<<"z is not finite in log_Gamma."<<endl, abort ();

  const double x = real (z),y = imag (z);

  if ((z == rint (x)) && (x <= 0)) cout<<"z is negative integer in log_Gamma."<<endl, abort ();

  if (x > 0.0)
  {
	const Comp z_p_0p5 = z + 0.5, z_p_5p5 = z + 5.5;
	const double sqrt_2Pi = 2.5066282746310005;
	const double c[7] = {1.000000000190015,
			 7.618009172947146E+1,
			-8.650532032941677E+1,
			 2.401409824083091E+1,
			-1.231739572450155,
			 0.1208650973866179E-2,
			-0.5395239384953000E-5};
	  
	Comp sum = c[0];
	for (int i = 1 ; i < 7 ; i++) sum += c[i]/(z + i);
	sum *= sqrt_2Pi;

	const Comp log_Gamma_z = log (sum) - log (z) + z_p_0p5*log (z_p_5p5) - z_p_5p5;

	return log_Gamma_z;
  }
  else if (y >= 0.0)
  {
	const int n = (x < rint (x)) ? (static_cast<int> (rint (x)) - 1) : (static_cast<int> (rint (x)));
	const double log_Pi = 1.1447298858494002;
	const Comp log_const(-C_LN2, C_PI_2),i_Pi(0.0, C_PI);
	const Comp eps = z - n,log_sin_Pi_z = (y > 110) ? (-i_Pi*z + log_const) : (log (sin (C_PI*eps)) - i_Pi*n);
	const Comp log_Gamma_z = log_Pi - log_sin_Pi_z - log_Gamma (1.0 - z);
	
	return log_Gamma_z;
  }
  else
	return conj (log_Gamma (conj (z)));
}



// Coulomb phase shift.
// --------------------
// It is given by the formula [Gamma[1+l+I.eta] - Gamma[1+l-I.eta]]/[2i].
// 0 is returned if 1+l+/-I.eta is a negative integer.
//
// Variables:
// ----------
// l : orbital angular momentum l.
// eta : Sommerfeld parameter.
// Ieta,one_over_two_I : i.eta,1/[2.i] .
// arg_plus,arg_minus : 1+l+i.eta, 1+l-i.eta.
// log_Gamma_plus,log_Gamma_minus : logs of Gamma[1+l+I.eta], Gamma[1+l-I.eta].
// sigma_l : returned result.

inline Comp sigma_l_calc (const Comp &l,const Comp &eta)
{
  const Comp Ieta(-imag (eta),real (eta)),one_over_two_I(0,-0.5);
  const Comp arg_plus = 1.0 + l + Ieta, arg_minus = 1.0 + l - Ieta;

  if ((rint (real (arg_plus)) == arg_plus) && (rint (real (arg_plus)) <= 0.0)) return 0.0;
  if ((rint (real (arg_minus)) == arg_minus) && (rint (real (arg_minus)) <= 0.0)) return 0.0;

  const Comp log_Gamma_plus = log_Gamma (arg_plus),log_Gamma_minus = log_Gamma (arg_minus);  
  const Comp sigma_l = (log_Gamma_plus - log_Gamma_minus)*one_over_two_I;

  return sigma_l;
}






// log of C(l,eta)
// ---------------
// It is given by the formula l*log[2] - eta.Pi/2 + (log[Gamma[1+l+I.eta]] + log[Gamma[1+l-I.eta]])/2.0 - log[Gamma[2l+2]].
// 0 is returned if 1+l+/-I.eta is a negative integer.
// 2l+2 should not be a negative integer : one has to use -l-1 instead of l in this case.
//
// Variables:
// ----------
// l : orbital angular momentum l.
// eta : Sommerfeld parameter.
// Ieta : i.eta .
// arg_plus,arg_minus : 1+l+i.eta, 1+l-i.eta.
// log_Gamma_plus,log_Gamma_minus,log_Gamma_2l_plus_2 : logs of Gamma[1+l+I.eta], Gamma[1+l-I.eta], Gamma[2l+2].
// log_Cl_eta : returned result.

inline Comp log_Cl_eta_calc (const Comp &l,const Comp &eta)
{
  const Comp Ieta(-imag (eta),real (eta));
  const Comp arg_plus = 1.0 + l + Ieta, arg_minus = 1.0 + l - Ieta; 

  if ((rint (real (arg_plus)) == arg_plus) && (rint (real (arg_plus)) <= 0.0)) return 0.0;
  if ((rint (real (arg_minus)) == arg_minus) && (rint (real (arg_minus)) <= 0.0)) return 0.0;

  const Comp log_Gamma_plus = log_Gamma (arg_plus),log_Gamma_minus = log_Gamma (arg_minus),log_Gamma_2l_plus_2 = log_Gamma (2.0*l + 2.0);
  const Comp log_Cl_eta = l* C_LN2 - C_PI_2 *eta + 0.5*(log_Gamma_plus + log_Gamma_minus) - log_Gamma_2l_plus_2;

  return log_Cl_eta;
}



// Cut constant log for the asymptotic series.
// -------------------------------------------
// The asymptotic series and H[omega] behave differently near the negative real axis.
// Then, if one is in the bad quadrant of H[omega], one has to take into account the cut directly.
// One is in the bad quadrant of H[omega] if Re[z] < 0.0 and sign(Im[z]) = -omega.
// 
// H[omega] = [H[omega] from asymptotic function formula] + (1 - exp(2.i.Pi.(i.eta - l.omega))).[H[-omega] from asymptotic function formula]
//
//
// The cut constant log is then log [1 - exp(2.i.Pi.(i.eta - l.omega))].
// Its returned imaginary part is not necessarily in ]-Pi:Pi]
//
//
// Variables:
// ----------
// omega : 1 or -1.
// l : orbital angular momentum l.
// eta : Sommerfeld parameter.
// Ieta : i.eta
// l_int,Ieta_int : closest integers to Re[l],Re[i.eta]
// eps :  (Ieta - Ieta_int) - (l.omega - l_int.omega)
// two_I_Pi, two_I_Pi_eps : 2.i.Pi, 2.i.Pi.eps .
// log_cut_constant : returned result.

inline Comp log_cut_constant_AS_calc (const int omega,const Comp &l,const Comp &eta)
{
  const Comp Ieta(-imag (eta),real (eta));
  const double l_int = rint (real (l)), Ieta_int = rint (real (Ieta));
  const Comp eps = (Ieta - Ieta_int) - omega*(l - l_int);

  const Comp two_I_Pi(0,2.0*C_PI),two_I_Pi_eps = two_I_Pi*eps;

  if (real (two_I_Pi_eps) > -0.1)
  {
	const Comp log_cut_constant = log (expm1 (-two_I_Pi_eps)) + two_I_Pi_eps;

	return log_cut_constant;
  }
  else
  {
	const Comp log_cut_constant = log1p (-exp (two_I_Pi_eps));

	return log_cut_constant;
  }
}





// Cut constant log for continued fractions : H[omega] from H[omega, not corrected] case.
// --------------------------------------------------------------------------------------
// The continued fraction has no cut on the negative real axis, whereas H[omega] has one.
// Then, if one is in the bad quadrant of H[omega], one has to take into account the cut directly.
// One is in the bad quadrant of H[omega] if Re[z] < 0.0 and sign(Im[z]) = -omega.
// 
// H[omega] = H[omega, not corrected] - cut_constant.F .
//
// The cut constant is 2i.omega.norm.(exp (2.i.Pi.[l.omega - i.eta]) - 1), and one takes its log.
// The imaginary part of the log is not necessarily in ]-Pi:Pi].
// Norm is 1.0 for normalized wave functions, C(l,eta)^2 for unnormalized wave functions.
//
//
// Variables:
// ----------  
// is_it_normalized : true if one wants normalized functions, i.e. the standard normalization,
//                    false if one wants F -> F/C(l,eta) and H+/H-/G -> H+/H-/G.C(l,eta), to avoid overflows for |eta| >> 1 and |z| small.
// omega : 1 or -1.
// l : orbital angular momentum l.
// eta : Sommerfeld parameter.
// Ieta : i.eta .
// l_int,Ieta_int : closest integers to Re[l],Re[i.eta]
// eps : (l.omega - l_int.omega) - (Ieta - Ieta_int)
// log_norm : log[C(l,eta)^2] if is_it_normalized is false, 0.0 if it is true.
// two_I_Pi, two_I_Pi_eps : 2.i.Pi, 2.i.Pi.eps .
// log_two_I_omega : log[2.i.omega] = log[2] + i.omega.Pi/2 .
// log_cut_constant : returned result.

inline Comp log_cut_constant_CFa_calc (const bool is_it_normalized,const int omega,const Comp &l,const Comp &eta)
{
  const Comp Ieta(-imag (eta),real (eta));
  const double l_int = rint (real (l)), Ieta_int = rint (real (Ieta));
  const Comp eps = omega*(l - l_int) - (Ieta - Ieta_int);
  const Comp log_norm = (!is_it_normalized) ? (2.0*log_Cl_eta_calc (l,eta)) : (0.0);
  const Comp two_I_Pi(0,2.0*C_PI),two_I_Pi_eps = two_I_Pi*eps,log_two_I_omega(C_LN2,omega*C_PI_2);

  if (real (two_I_Pi_eps) < 0.1)
  {
	const Comp log_cut_constant = log_two_I_omega + log (expm1 (two_I_Pi_eps)) + log_norm;

	return log_cut_constant;
  }
  else
  {
	const Comp log_cut_constant = log_two_I_omega + log1p (-exp (-two_I_Pi_eps)) + two_I_Pi_eps + log_norm;

	return log_cut_constant; 
  }
}




// Cut constant log for continued fractions : H[omega] from H[-omega, not corrected] case.
// ---------------------------------------------------------------------------------------
// The continued fraction has no cut on the negative real axis, whereas H[-omega] has one.
// Then, if one is in the bad quadrant of H[-omega], one has to take into account the cut directly.
// One is in the bad quadrant of H[-omega] if Re[z] < 0.0 and sign(Im[z]) = omega.
// 
// H[omega] = H[-omega, not corrected] - cut_constant.F .
//
// The cut constant is 2i.omega.norm.exp (-2.i.Pi.[l.omega + i.eta]), and one takes its log.
// The returned imaginary part of the log is not necessarily in ]-Pi:Pi].
// Norm is 1.0 for normalized wave functions, C(l,eta)^2 for unnormalized wave functions.
//
//
// Variables:
// ----------
// is_it_normalized : true if one wants normalized functions, i.e. the standard normalization,
//                    false if one wants F -> F/C(l,eta) and H+/H-/G -> H+/H-/G.C(l,eta), to avoid overflows for |eta| >> 1 and |z| small.
// omega : 1 or -1.
// l : orbital angular momentum l.
// eta : Sommerfeld parameter = Coulomb_constant.Z.(2.mu/hbar^2)/(2k).
// Ieta : i.eta .
// l_int,Ieta_int : closest integers to Re[l],Re[i.eta]
// eps : (l.omega - l_int.omega) + (Ieta - Ieta_int)
// two_I_Pi : 2.i.Pi .
// log_norm : log[C(l,eta)^2] if is_it_normalized is false, 0.0 if it is true.
// log_two_I_omega : log[2.i.omega] = log[2] + i.omega.Pi/2 .
// log_cut_constant : returned result.

inline Comp log_cut_constant_CFb_calc (const bool is_it_normalized,const int omega,const Comp &l,const Comp &eta)
{
  const Comp Ieta(-imag (eta),real (eta));
  const double l_int = rint (real (l)), Ieta_int = rint (real (Ieta));
  const Comp eps = omega*(l - l_int) + (Ieta - Ieta_int);
  const Comp log_norm = (!is_it_normalized) ? (2.0*log_Cl_eta_calc (l,eta)) : (0.0);
  const Comp two_I_Pi(0,2.0*C_PI),log_two_I_omega(C_LN2,omega*C_PI_2),log_cut_constant = log_two_I_omega - two_I_Pi*eps + log_norm;

  return log_cut_constant;
}



















// Sin (chi) calculation
// ---------------------
// If 2l is integer, 0.0 is returned as chi is zero.
// If not, one calculates sin (chi) with chi = sigma(l,eta) - sigma(-l-1,eta) - (l+1/2).Pi .
// One uses the stable formula sin (chi) = -(2l+1).C(l,eta).C(-l-1,eta).
//
// Variables
// ---------
// l : orbital angular momentum l.
// eta : Sommerfeld parameter.
// sin_chi : sin (chi)

inline Comp sin_chi_calc (const Comp &l,const Comp &eta)
{
  if (rint (real (2.0*l)) == 2.0*l) return 0.0;

  const Comp sin_chi = -(2*l+1)*exp (log_Cl_eta_calc (l,eta) + log_Cl_eta_calc (-l-1,eta));
  
  return sin_chi;
}







// exp (i.omega.chi) calculation.
// ------------------------------
// One calculates exp (i.omega.chi), with chi = sigma(l,eta) - sigma(l,-eta) - (l+1/2).Pi .
// If 2l is integer, 1.0 is returned as chi is zero.
// If not, one first calculates sin (chi) with the previous routine.
// If |sin (chi)| > 0.5, chi obtained with the formula sigma(l,eta) - sigma(l,-eta) - (l+1/2).Pi is stable so exp[i.omega.chi] follows directly.
// If not, one uses exp[i.omega.chi] = cos (chi) + i.omega.sin (chi), with cos (chi) = sqrt [1 - sin (chi)*sin (chi)].sign[Re[cos (chi)]],
// with chi given by sigma(l,eta) - sigma(l,-eta) - (l+1/2).Pi .
//
// Variables
// ---------
// omega : 1 or -1
// l : orbital angular momentum l.
// eta : Sommerfeld parameter = Coulomb_constant.Z.(2.mu/hbar^2)/(2k).
// I_omega : i.omega
// sin_chi : sin (chi)
// chi : sigma(l,eta) - sigma(l,-eta) - (l+1/2).Pi . 
// cos_chi : sign[Re[cos (chi)]].sqrt[1 - [sin(chi)]^2]
// exp_I_omega_chi : exp[i.omega.chi], returned result.

inline Comp exp_I_omega_chi_calc (const int omega,const Comp &l,const Comp &eta)
{
  if (rint (real (2.0*l)) == 2.0*l) return 1.0;

  const Comp I_omega(0,omega),sin_chi = sin_chi_calc (l,eta);
  const Comp chi = sigma_l_calc (l,eta) - sigma_l_calc (-l-1,eta) - (l+0.5)*C_PI;

  if (abs (sin_chi) > 0.5)
  {
	const Comp exp_I_omega_chi = exp (I_omega*chi);

	return exp_I_omega_chi;
  }
  else
  {
	const Comp cos_chi = SIGN (real (cos (chi)))*sqrt (1.0 - sin_chi*sin_chi),exp_I_omega_chi = cos_chi + I_omega*sin_chi;

	return exp_I_omega_chi;
  }
}

} // namespace cwfcomp
