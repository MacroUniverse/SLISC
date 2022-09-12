#include "../SLISC/arithmetic.h"
#include "../SLISC/coulomb.h"
#include "../SLISC/time.h"
#include "../SLISC/disp.h"

void test_coulomb()
{
	using std::cout; using std::endl;
	using namespace slisc;

	// coulomb phase shift
#ifdef SLS_USE_GSL
	Doub ret = coulomb_sigma(3, -2./5);
	if (abs(ret + 0.503297642943251313) > 1e-15)
		SLS_FAIL;
	ret = coulomb_sigma(4, -2. / 9);
	if (abs(ret + 0.3347819876751476) > 1e-15)
		SLS_FAIL;

	Long Nr = 20;
	VecDoub r(Nr); linspace(r, 0, 200);
	Doub k = 0.5, F_exp = 0; //  = 3.1415; // F_exp = 0;
	VecDoub F(Nr);
	for (Long l = 50; l < 52; ++l) {
		// ret = gsl_sf_coulomb_wave_F_array(l, 0, eta, k*r[i], &F, &F_exp);
		// cout << "l = " << l << endl;
		coulombF(F, l, k, r);
		for (Long i = 0; i < r.size(); ++i) {
			if (slisc::isnan(F[i])) {
				cout << "(ret, l, i, F_exp) = " << ret << ", " << l << ", " << i << ", " << F_exp << endl;
				SLS_FAIL;
			}
			if (isinf(F[i])) {
				cout << "(ret, l, i, F_exp) = " << ret << ", " << l << ", " << i << ", " << F_exp << endl;
				SLS_FAIL;
			}
		}
	}
#endif
#ifdef SLS_USE_ARB
	Doub val = 4.5882301380287637784e-286;
	if (abs((arb_coulombF(203, -0.1, 6) - val)/val) > 1e-15)
		SLS_FAIL;
	val = -0.22430046820226034798;
	if (abs((arb_coulombF(204, -1.3, 1000) - val)/val) > 1e-15)
		SLS_FAIL;
	
	Comp val1(-0.006461649191133419760, 0.027616334359445151916);
	if (abs((arb_gamma(Comp(1.2, 3.4))-val1)/val1) > 1e-14)
		SLS_FAIL;

	val1 = Comp(-3.5626977297536895250, 1.8006407379666919011);
	if (abs((arb_lngamma(Comp(1.2, 3.4))-val1)/val1) > 1e-14)
		SLS_FAIL;

	val = -1.8006407379666919011;
	if (abs(arb_coulomb_sigma(0.2, -3.4) - val)/val > 1e-14)
		SLS_FAIL;

#ifdef SLS_USE_QUAD_MATH
	// Qdoub coulomb function
	Qdoub valq = 4.58823013802876377840937975619267858e-286Q;
	if (abs((arb_coulombF(203.Q, -0.1Q, 6.Q) - valq)/valq) > 1e-33Q)
		SLS_FAIL;
#endif
	flint_cleanup();
#endif
}
