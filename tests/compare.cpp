#include "../SLISC/arith/copy.h"

void test_compare()
{
	using namespace slisc;
	Long N = 3;
	VecDoub v(N), v1(N); v[0] = 0; v[1] = 1; v[2] = 2;
	copy(v1, v);
	if (!equals_vv(v.p(), v1.p(), N))
		SLS_FAIL;
	if (!shape_cmp1(v, v1))
		SLS_FAIL;
}

#ifndef SLS_TEST_ALL
int main() { test_compare(); }
#endif
