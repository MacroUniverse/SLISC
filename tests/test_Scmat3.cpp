#include "../SLISC/dense/Scmat3.h"
#include "../SLISC/util/random.h"

void test_Scmat3()
{
	using namespace slisc;
	Long N1 = 3, N2 = 4, N3 = 5;
	Cmat3Doub a(N1, N2, N3); rand(a);
	Scmat3Doub sli; sli.set(a.p(), N1, N2, N3);
	if (sli.n0() != N1 || sli.n1() != N2 || sli.n2() != N3)
		SLS_FAIL;
	if (sli.p() != a.p())
		SLS_FAIL;
	for (Long k = 0; k < N3; ++k) {
		for (Long j = 0; j < N2; ++j) {
			for (Long i = 0; i < N1; ++i) {
				if (sli(i, j, k) != a(i, j, k))
					SLS_FAIL;
			}
		}
	}
	Scmat3Doub sli1(sli);
	if (sli1.n0() != N1 || sli1.n1() != N2 || sli1.n2() != N3)
		SLS_FAIL;
	if (sli1.p() != a.p())
		SLS_FAIL;
}
