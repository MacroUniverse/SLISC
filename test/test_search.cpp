#include "../SLISC/search.h"

void test_search()
{
	using namespace slisc;
	// test search_row
    { 
        Long N1 = 10, N2 = 10;
        CmatDoub a(N1, N2); linspace(a, 1, N1*N2);
        VecDoub v(N2); linspace(v, 2, 2 + N1*(N2-1));
        if (search_row(v, a) != 1)
            SLS_ERR("failed!");
    }
}
