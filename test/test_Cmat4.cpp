#include "../SLISC/Cmat4.h"

void test_Cmat4()
{
	using namespace slisc;
	Long N1 = 3, N2 = 4, N3 = 2, N4 = 3;
	Cmat4Doub v(N1, N2, N3, N4);
	if (v.n1() != N1)
		SLS_ERR("failed!");
	if (v.n2() != N2)
		SLS_ERR("failed!");
	if (v.n3() != N3)
		SLS_ERR("failed!");
	if (v.n4() != N4)
		SLS_ERR("failed!");
	v(1, 2, 1, 2) = 2;
	if (v(1, 2, 1, 2) != 2)
		SLS_ERR("failed!");
}
