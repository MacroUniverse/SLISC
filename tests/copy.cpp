#include "../SLISC/arith/copy.h"
#include "../SLISC/arith/arith2.h"

void test_copy()
{
	using namespace slisc;

	Long N = 3;
	VecDoub v1(N), v(N);
	v[0] = 1; v[1] = 2; v[2] = 3;
	veccpy(v1.p(), v.p(), N);
	if (v1[0] != 1 || v1[1] != 2 || v1[2] != 3)
		SLS_FAIL;
	
	v[0] = 3; v[1] = 2; v[2] = 1;
	copy(v1, v);
	if (v1[0] != 3 || v1[1] != 2 || v1[2] != 1)
		SLS_FAIL;

	// copy/compare from initializer list
	{
		VecDoub v(3);
		copy(v, {1, 2, 3});
		if (v[0] != 1 || v[1] != 2 || v[2] != 3)
			SLS_FAIL;
		CmatDoub a(2,3);
		copy(a, {1, 2, 3, 4, 5, 6});
		if (a[0] != 1 || a[1] != 2 || a[2] != 3 || a[3] != 4 || a[4] != 5 || a[5] != 6)
			SLS_FAIL;
		ScmatDoub sa = cut(a, 0, 2);
		copy(sa, {7., 8., 9., 0.});
		if (sa[0] != 7 || sa[1] != 8 || sa[2] != 9 || sa[3] != 0)
			SLS_FAIL;
		CmatComp ac(2, 2);
		copy(sa, {1.1, 2.2, 3.3, 4.4});
		if (sa[0] != 1.1 || sa[1] != 2.2 || sa[2] != 3.3 || sa[3] != 4.4)
			SLS_FAIL;
	}
}

#ifndef SLS_TEST_ALL
int main() { test_copy(); }
#endif
