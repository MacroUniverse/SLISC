#include "../SLISC/copy.h"
#include "../SLISC/arithmetics.h"
#include "../SLISC/compare.h"

void test_copy()
{
	using namespace slisc;
	Long N = 3;
	VecDoub v1(N), v(N);
	v[0] = 1; v[1] = 2; v[2] = 3;
	veccpy(v1.ptr(), v.ptr(), N);
	if (v1[0] != 1 || v1[1] != 2 || v1[2] != 3)
		SLS_ERR("failed!");
	
	v[0] = 3; v[1] = 2; v[2] = 1;
	copy(v1, v);
	if (v1[0] != 3 || v1[1] != 2 || v1[2] != 1)
		SLS_ERR("failed!");

	CmatDoub a(3, 4);
	MatDoub a1(3, 4);
	linspace(a, 0, 12);
	copy(a1, a);
	if (a1 != a)
		SLS_ERR("failed!");
}
