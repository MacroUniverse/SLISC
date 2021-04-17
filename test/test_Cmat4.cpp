#include "../SLISC/arithmetic.h"
#include "../SLISC/cut.h"

void test_Cmat4()
{
	using namespace slisc;
	{
		Long N1 = 3, N2 = 4, N3 = 2, N4 = 3;
		Cmat4Doub v(N1, N2, N3, N4);
		if (v.n0() != N1)
			SLS_ERR("failed!");
		if (v.n1() != N2)
			SLS_ERR("failed!");
		if (v.n2() != N3)
			SLS_ERR("failed!");
		if (v.n3() != N4)
			SLS_ERR("failed!");
		v(1, 2, 1, 2) = 2;
		if (v(1, 2, 1, 2) != 2)
			SLS_ERR("failed!");
	}

    Cmat4Int a(2, 3, 4, 5);
    linspace(a, 1, a.size());
    if (a.n0() != 2 || a.n1() != 3 ||
        a.n2() != 4 || a.n3() != 5)
        SLS_ERR("failed!");

    Long ind = 0;
    for (Long l = 0; l < 5; ++l) {
        for (Long k = 0; k < 4; ++k) {
            for (Long j = 0; j < 3; ++j) {
                for (Long i = 0; i < 2; ++i) {
                    ++ind;
                    if (a(i, j, k, l) != ind)
                        SLS_ERR("failed!");
                }
			}
		}
	}

	ScmatInt sli; 
    for (Long l = 0; l < 5; ++l) {
        for (Long k = 0; k < 4; ++k) {
			sli.set(cut01(a, k, l));
            if (sli.p() != &a(0, 0, k, l))
                SLS_ERR("failed!");
        }
    }
}
