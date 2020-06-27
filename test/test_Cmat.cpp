#include "../SLISC/Cmat.h"
#include "../SLISC/compare.h"
#include "../SLISC/random.h"

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

	// copy constructor
	{
		CmatDoub a; a.resize(4, 3); rand(a);
		CmatDoub b(a);
		if (a != b)
			SLS_ERR("failed!");
	}

	// CmatBool
	{
		Long N1 = 2; N2 = 3;
		CmatBool v(N1, N2);
		if (v.n1() != N1 || v.n2() != N2)
			SLS_ERR("failed!");
		v[0] = 1; v[1] = 0; v[2] = 1; v[3] = 0;
		if (!v[0] || v[1] || !v[2] || v[3])
			SLS_ERR("failed!");
		v(1, 2) = true;
		if (!v(1, 2))
			SLS_ERR("failed!");
        v.resize(N1+1, N2+1);
        if (v.n1() != N1+1 || v.n2() != N2+1)
            SLS_ERR("failed!");
	}

	// reshape
	{
		Cmat3Doub a3(2, 3, 4), b3(2, 3, 4);
		copy(b3, a3);
		a3.reshape(2, 6, 2); a3.reshape(2, 3, 4);
		if (a3 != b3)
			SLS_ERR("failed!");
	}
}
