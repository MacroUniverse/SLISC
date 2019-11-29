#include "../SLISC/copy.h"

void test_copy()
{
	using namespace slisc;
	Long N = 3;
	VbaseDoub v1(N), v(N);
	v[0] = 1; v[1] = 2; v[2] = 3;
	veccpy(v1.ptr(), v.ptr(), N);
	if (v1[0] != 1 || v1[1] != 2 || v1[2] != 3)
		SLS_ERR("failed!");
	
	v[0] = 3; v[1] = 2; v[2] = 1;
	copy(v1, v);
	if (v1[0] != 3 || v1[1] != 2 || v1[2] != 1)
		SLS_ERR("failed!");
}
