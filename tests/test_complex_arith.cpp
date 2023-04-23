#include "../SLISC/arith/complex_arith.h"

void test_complex_arith()
{
	using namespace slisc;
	if (Comp(2, 3) != Fcomp(2, 3))
		SLS_FAIL;
	if (Comp(1, 2) + Llong(3) != Comp(4, 2))
		SLS_FAIL;
	Comp c(1,1);
	c.real(3.1); c.imag(4.2);
	if (c != Comp(3.1, 4.2))
		SLS_FAIL;
	real_r(c) += 1.1;
	imag_r(c) += 2.2;
	if (c != Comp(4.2, 6.4))
		SLS_FAIL;
}

#ifndef SLS_TEST_ALL
int main() { test_complex_arith(); }
#endif
