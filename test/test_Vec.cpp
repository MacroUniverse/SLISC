#include "../SLISC/Vec.h"
#include "../SLISC/compare.h"

void test_Vec()
{
    using namespace slisc;
    Long N = 3;

    {
        VecDoub v;
        if (v.size() != 0)
            SLS_FAIL;
    }

    {
        VecDoub v(N);
        if (v.size() != N)
            SLS_FAIL;
        v[1] = 2;
        if (v[1] != 2)
            SLS_FAIL;
    }

    // VecBool
	{
		Long N = 4;
		VecBool v(N);
		if (v.size() != N)
			SLS_FAIL;
		v[0] = 1; v[1] = 0; v[2] = 1; v[3] = 0;
		if (!v[0] || v[1] || !v[2] || v[3])
			SLS_FAIL;
        v.resize(N + 1);
        if (v.size() != N+1)
            SLS_FAIL;
	}

    // copy constructor
    {
        Long N = 4;
		VecBool v(N), v1(v);
        if (v1 != v)
            SLS_FAIL;
    }
}
