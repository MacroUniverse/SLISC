#include "../SLISC/Cmat.h"

void test_Cmat()
{
	using namespace slisc;
	Long N1 = 3, N2 = 4;
	CmatDoub v(N1, N2);
	if (v.n1() != N1)
		SLS_ERR("failed!");
	if (v.n2() != N2)
		SLS_ERR("failed!");
	v(1, 2) = 2;
	if (v(1, 2) != 2)
		SLS_ERR("failed!");
}
