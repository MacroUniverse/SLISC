#include "../SLISC/arithmetics.h"
#include "../SLISC/compare.h"

void test_arithmetics()
{
	using namespace slisc;
	// linspace()
	{
		Long N = 3;
		VecDoub v(N), v1(N); v[0] = 0; v[1] = 1; v[2] = 2;
		linspace(v, 0, N-1);
		if (!equals_to_vv(v.ptr(), v1.ptr(), N))
			SLS_ERR("failed!");
	}
	
	// mul_gen()
	{
		Long N1 = 4, N2 = 5;
		CmatDoub a(N1, N2);
		VecDoub x(N2), y(N1), y1(N1);
		linspace(x, 1, N2);
		mul_gen(y, a, x);
		mul(y1, a, x);
		if (y != y1)
			SLS_ERR("failed!");
	}
}
