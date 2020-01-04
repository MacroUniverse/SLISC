#include "../SLISC/Scmat3.h"
#include "../SLISC/random.h"

void test_Scmat3()
{
	using namespace slisc;
	Long N1 = 3, N2 = 4, N3 = 5;
	Cmat3Doub a(N1, N2, N3); rand(a);
	Scmat3Doub sli; sli.set(a.ptr(), N1, N2, N3);
	if (sli.n1() != N1 || sli.n2() != N2 || sli.n3() != N3)
		SLS_ERR("failed!");
	if (sli.ptr() != a.ptr())
		SLS_ERR("failed!");
	for (Long k = 0; k < N3; ++k) {
		for (Long j = 0; j < N2; ++j) {
			for (Long i = 0; i < N1; ++i) {
				if (sli(i, j, k) != a(i, j, k))
					SLS_ERR("failed!");
			}
		}
	}
	Scmat3Doub sli1(sli);
	if (sli1.n1() != N1 || sli1.n2() != N2 || sli1.n3() != N3)
		SLS_ERR("failed!");
	if (sli1.ptr() != a.ptr())
		SLS_ERR("failed!");
}
