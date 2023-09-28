#include "../SLISC/spec/legendreP.h"

void test_legendreP()
{
	using namespace slisc;
	if (abs(legendre_Plm(20, 4, 0.7) + 3.59207482646089431761e4) > 1e-11)
		SLS_FAIL;
#ifdef SLS_USE_QUAD_MATH
	using namespace slisc;
	if (abs(legendre_Plm(20, 4, 0.7Q) + 3.5920748264608943176145619300842e4Q) > 1e-26)
		SLS_FAIL;
#endif
}

#ifndef SLS_TEST_ALL
int main() { test_legendreP(); }
#endif
