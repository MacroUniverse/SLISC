#include "../SLISC/Vec.h"

void test_Vec()
{
    using namespace slisc;
    Long N = 3;

    {
        VecDoub v;
        if (v.size() != 0)
            SLS_ERR("failed!");
    }

    {
        VecDoub v(N);
        if (v.size() != N)
            SLS_ERR("failed!");
        v[1] = 2;
        if (v[1] != 2)
            SLS_ERR("failed!");
    }

    // VecBool
	{
		Long N = 4;
		VecBool v(N);
		if (v.size() != N)
			SLS_ERR("failed!");
		v[0] = 1; v[1] = 0; v[2] = 1; v[3] = 0;
		if (!v[0] || v[1] || !v[2] || v[3])
			SLS_ERR("failed!");
        v.resize(N + 1);
        if (v.size() != N+1)
            SLS_ERR("failed!");
	}
}
