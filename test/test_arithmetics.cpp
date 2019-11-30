#include "../SLISC/arithmetics.h"
#include "../SLISC/compare.h"

void test_arithmetics()
{
	using namespace slisc;

	// resize_cpy()
	{
		Long N = 4;
		VecDoub v(N), v1(N); linspace(v, 1, N);
		copy(v1, v);
		resize_cpy(v, 2*N);
		if (!equals_to_vv(v.ptr(), v1.ptr(), N))
			SLS_ERR("failed!");
	}

	// linspace()
	{
		Long N = 3;
		VecDoub v(N), v1(N); v[0] = 0; v[1] = 1; v[2] = 2;
		linspace(v, 0, N-1);
		if (!equals_to_vv(v.ptr(), v1.ptr(), N))
			SLS_ERR("failed!");
	}

	// reorder()
	{
		VecLlong v(4), order(4); linspace(v, 0, 3);
		order[0] = 2; order[1] = 1; order[2] = 0; order[3] = 3;
		reorder(v, order);
		if (v != order)
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

	// trans()
	{
		Long N = 4;
		CmatDoub a(N, N), b(N, N);
		linspace(a, 1, N*N); copy(b, a);
		trans(a); trans(a);
		if (a != b)
			SLS_ERR("failed!");

		Long N1 = 5, N2 = 6;
		CmatDoub c(N1, N2), d(N2, N1), e(N1, N2);
		linspace(c, 1, N1*N2);
		copy(e, c);
		trans(d, c); trans(c, d);
		if (c != e)
			SLS_ERR("failed!");
	}
}
