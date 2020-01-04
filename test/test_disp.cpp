#include "../SLISC/disp.h"

void test_disp()
{
	using namespace slisc;
	CmatDoub a(3, 4);
	linspace(a, 1, 12);
	disp(a);
}
