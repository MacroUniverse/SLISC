#include "../SLISC/algo/bisection.h"
using namespace slisc;

class Sinfun
{
public:
	Doub operator()(Doub_I x) {
		return sin(x);
	}
};

void test_bisection()
{
	// test bisection
	Sinfun f;
	Doub x = bisection(f, PI-0.1, PI+0.1, 1e-5);
	if (abs(x-PI) > 1e-5)
		SLS_FAIL;

	// test bisectionN
	vecDoub vx;
	bisectionN(vx, f, -0.1, 2*PI + 0.1, 20, 1e-5);
	if (vx.size() != 3)
		SLS_FAIL;
	for (Long i = 0; i < 3; ++i) {
		if (abs(vx[i] - i*PI) > 1e-5)
			SLS_FAIL;
	}
}
