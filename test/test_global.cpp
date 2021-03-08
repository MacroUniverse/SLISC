#include "../SLISC/global.h"

void test_global()
{
	using namespace slisc;
	// test isnan()
	Doub x = NaN;
	if (!isnan(x) || isnan(1))
		SLS_ERR("failed!");
	Comp c(NaN, NaN);
	if (!isnan(c) || isnan(Comp(1,2)))
		SLS_ERR("failed!");
}
