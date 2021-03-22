#include "../SLISC/complex_arith.h"

void test_complex_arith()
{
	using namespace slisc;
	if (Comp(2, 3) != Fcomp(2, 3))
		SLS_ERR("failed!");
	if (Comp(1, 2) + Llong(3) != Comp(4, 2))
		SLS_ERR("failed!");
	Comp c(1,1);
	c.real(3.1); c.imag(4.2);
	if (c != Comp(3.1, 4.2))
		SLS_ERR("failed!");
}
