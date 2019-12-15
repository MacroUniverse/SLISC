#include "../SLISC/search.h"

void test_search()
{
	using namespace slisc;
	// test lookup
	{
		Long N = 10;
		VecLong v(N); linspace(v, 2, 2*N);
		Long ind;
		if (lookup(ind, v, 1))
			SLS_ERR("failed!");
		if (ind != -1)
			SLS_ERR("failed!");
		if (!lookup(ind, v, 2))
			SLS_ERR("failed!");
		if (ind != 0)
			SLS_ERR("failed!");
		if (lookup(ind, v, 3))
			SLS_ERR("failed!");
		if (ind != 0)
			SLS_ERR("failed!");
		if (!lookup(ind, v, 4))
			SLS_ERR("failed!");
		if (ind != 1)
			SLS_ERR("failed!");
		if (!lookup(ind, v, 2*N))
			SLS_ERR("failed!");
		if (ind != N-1)
			SLS_ERR("failed!");
		if (lookup(ind, v, 2*N+2))
			SLS_ERR("failed!");
		if (ind != N-1)
			SLS_ERR("failed!");
	}

	// test search_row
    { 
        Long N1 = 10, N2 = 10;
        CmatDoub a(N1, N2); linspace(a, 1, N1*N2);
        VecDoub v(N2); linspace(v, 2, 2 + N1*(N2-1));
        if (search_row(v, a) != 1)
            SLS_ERR("failed!");
    }
}
