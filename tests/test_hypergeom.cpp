#include "../SLISC/spec/hypergeom.h"

void test_hypergeom()
{
	using std::cout; using std::endl;
	using namespace slisc;

#ifdef SLS_USE_ARB
	Doub val = 3.421229536289674;
	if (abs((arb_hypergeom1F1(1.23,1.23,1.23) - val)/val) > 1e-14)
		SLS_FAIL;

	val = 1.3500415304621376612;
	if (abs((arb_WhittakerM(5.1, 2.5, 11) - val)/val) > 1e-14)
		SLS_FAIL;

	Comp val1(1.143503984180676, 3.224470526790991);
	if (abs((arb_hypergeom1F1(Comp(1.23,1.23),Comp(1.23,1.23),Comp(1.23,1.23)) - val1)/val1) > 1e-14)
		SLS_FAIL;
#else
    cout << "---------- disabled! ----------" << endl;
#endif
}
