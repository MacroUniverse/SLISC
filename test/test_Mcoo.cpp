#include "../SLISC/Mcoo.h"

void test_Mcoo()
{
	using namespace slisc;
	McooDoub a(3, 3, 4);
	a.push(2, 1, 2);
	if (a(1, 2) != 2)
		SLS_ERR("failed!");
}
