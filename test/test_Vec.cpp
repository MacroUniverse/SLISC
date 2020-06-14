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
}
