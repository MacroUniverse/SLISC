#include "../SLISC/arithmetic.h"
#include "../SLISC/hydrogen.h"

void test_hydrogen()
{
#ifdef SLS_USE_GSL
	using namespace slisc;
	Long Nr = 2000;
	VecDoub r(Nr), rR1(Nr), rR2(Nr);
	linspace(r, 0, 20);
	Doub dr = r[2] - r[1];
	Doub Z = 2;
	Long n1 = 2, n2 = 3, l = 1;
	hydrogen_rR(rR1, n1, l, Z, r);
	hydrogen_rR(rR2, n2, l, Z, r);
	if (abs(dot(rR1, rR1)*dr - 1) > 1e-11)
		SLS_FAIL;
	if (abs(dot(rR2, rR2)*dr - 1) > 1e-5)
		SLS_FAIL;
	if (abs(dot(rR1, rR2)*dr) > 1e-8)
		SLS_FAIL;
#endif
}
