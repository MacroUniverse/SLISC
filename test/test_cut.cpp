#include "../SLISC/cut.h"
#include "../SLISC/arithmetic.h"

void test_cut()
{
	using namespace slisc;

	// cut vec
	{
		Long N = 3;
		VecDoub v(N); linspace(v, 1, N);
		SvecDoub sli = cut(v, 0, N);
		for (Long i = 0; i < N; ++i) {
			if (sli[i] != v[i])
				SLS_ERR("failed!");
		}
	}

	// cut Cmat
	{
		Long N1 = 4, N2 = 5;
		CmatDoub v(N1, N2); linspace(v, 1, N1*N2);
		ScmatDoub sli = cut(v, 0, N2 - 2);
		if (sli.p() != v.p())
			SLS_ERR("failed!");
		if (sli.n0() != N1 || sli.n1() != N2 - 2)
			SLS_ERR("failed!");
	}

	{
		Long N1 = 4, N2 = 5;
		CmatDoub v(N1, N2); linspace(v, 1, N1*N2);
		DcmatDoub sli = cut(v, 0, N1 - 2, 0, N2 - 2);
		if (sli.p() != v.p())
			SLS_ERR("failed!");
		if (sli.n0() != N1 - 2 || sli.n1() != N2 - 2)
			SLS_ERR("failed!");
	}
}
