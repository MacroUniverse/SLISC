#include "test_Vbase.h"

int test_Vbase()
{
	using namespace slisc;
	Long N = 3;
	VbaseDoub v(N);
	if (v.size() != 3)
		SLS_ERR("failed!");
}
