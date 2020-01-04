#include "../SLISC/Cmat3.h"

void test_Cmat3()
{
	using namespace slisc;
	Long N1 = 3, N2 = 4, N3 = 2;
	Cmat3Doub v(N1, N2, N3);
	if (v.n1() != N1)
		SLS_ERR("failed!");
	if (v.n2() != N2)
		SLS_ERR("failed!");
	if (v.n3() != N3)
		SLS_ERR("failed!");
	v(1, 2, 1) = 2;
	if (v(1, 2, 1) != 2)
		SLS_ERR("failed!");
}
