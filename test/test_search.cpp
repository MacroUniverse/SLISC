#include "../SLISC/arith/search.h"

void test_search()
{
	using namespace slisc;
	// test lookup
	{
		Long N = 10;
		VecLong v(N); linspace(v, 2, 2*N);
		Long ind;
		if (lookup(ind, v, 1))
			SLS_FAIL;
		if (ind != -1)
			SLS_FAIL;
		if (!lookup(ind, v, 2))
			SLS_FAIL;
		if (ind != 0)
			SLS_FAIL;
		if (lookup(ind, v, 3))
			SLS_FAIL;
		if (ind != 0)
			SLS_FAIL;
		if (!lookup(ind, v, 4))
			SLS_FAIL;
		if (ind != 1)
			SLS_FAIL;
		if (!lookup(ind, v, 2*N))
			SLS_FAIL;
		if (ind != N-1)
			SLS_FAIL;
		if (lookup(ind, v, 2*N+2))
			SLS_FAIL;
		if (ind != N-1)
			SLS_FAIL;
	}

	// test search_row
	{ 
		Long N1 = 10, N2 = 10;
		CmatDoub a(N1, N2); linspace(a, 1, N1*N2);
		VecDoub v(N2); linspace(v, 2, 2 + N1*(N2-1));
		if (search_row(v, a) != 1)
			SLS_FAIL;
	}
}
