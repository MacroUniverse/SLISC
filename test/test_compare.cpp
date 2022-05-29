#include "../SLISC/copy.h"
#include "../SLISC/compare.h"

void test_compare()
{
	using namespace slisc;
	Long N = 3;
	VecDoub v(N), v1(N); v[0] = 0; v[1] = 1; v[2] = 2;
	copy(v1, v);
	if (!equals_to_vv(v.p(), v1.p(), N))
		SLS_ERR("failed!");
	if (!shape_cmp(v, v1))
		SLS_ERR("failed!");
}
