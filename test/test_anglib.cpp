#include "../SLISC/spec/anglib.h"

void test_anglib()
{
	using namespace slisc;
	SLS_ASSERT(factorial(5) == 120);
	SLS_ASSERT(factorial(6) == 720);
	SLS_ASSERT(binom(5, 3) == 10);
	SLS_ASSERT(binom(10, 6) == 210);

	SLS_ASSERT(abs(cleb(10, 0, 8, 0, 2, 0) - sqrt(5. / 33.)) < 1e-15);
	SLS_ASSERT(abs(cleb_int(5, 0, 4, 0, 1, 0) - sqrt(5. / 33.)) < 1e-15);
	SLS_ASSERT(abs(threej(12, 0, 8, 0, 4, 0) - sqrt(5. / 143.)) < 1e-15);
	SLS_ASSERT(abs(threej_int(6, 0, 4, 0, 2, 0) - sqrt(5. / 143.)) < 1e-15);
	SLS_ASSERT(abs(sixj(2, 4, 6, 4, 2, 4) - 1. / (5 * sqrt(21.))) < 1e-15);
}
