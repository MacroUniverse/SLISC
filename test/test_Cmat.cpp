#include "../SLISC/Cmat.h"
#include "../SLISC/compare.h"
#include "../SLISC/random.h"

void test_Cmat()
{
	using namespace slisc;
	Long N1 = 3, N2 = 4;
	CmatDoub v(N1, N2);
	if (v.n0() != N1)
		SLS_FAIL;
	if (v.n1() != N2)
		SLS_FAIL;
	v(1, 2) = 2;
	if (v(1, 2) != 2)
		SLS_FAIL;

	// copy constructor
	{
		CmatDoub a; a.resize(4, 3); rand(a);
		CmatDoub b(a);
		if (a != b)
			SLS_FAIL;
	}

	// CmatBool
	{
		Long N1 = 2; N2 = 3;
		CmatBool v(N1, N2);
		if (v.n0() != N1 || v.n1() != N2)
			SLS_FAIL;
		v[0] = 1; v[1] = 0; v[2] = 1; v[3] = 0;
		if (!v[0] || v[1] || !v[2] || v[3])
			SLS_FAIL;
		v(1, 2) = true;
		if (!v(1, 2))
			SLS_FAIL;
        v.resize(N1+1, N2+1);
        if (v.n0() != N1+1 || v.n1() != N2+1)
            SLS_FAIL;
	}
}
