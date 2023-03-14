#include "../SLISC/dense/Vbase.h"

void test_Vbase()
{
	using namespace slisc;
	Long N = 3;
	VbaseDoub v(N);
	if (v.size() != N)
		SLS_FAIL;
	v[1] = 2;
	if (v[1] != 2)
		SLS_FAIL;
}
