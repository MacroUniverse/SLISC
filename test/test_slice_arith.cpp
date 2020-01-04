#include "../SLISC/arithmetic.h"
#include "../SLISC/slice_arith.h"

void test_slice_arith()
{
	using namespace slisc;

	// slice vec
	{
		Long N = 3;
		VecDoub v(N); linspace(v, 1, N);
		SvecDoub sli = slice(v, 0, N);
		for (Long i = 0; i < N; ++i) {
			if (sli[i] != v[i])
				SLS_ERR("failed!");
		}
	}

	// slice Cmat
	{
		Long N1 = 4, N2 = 5;
		CmatDoub v(N1, N2); linspace(v, 1, N1*N2);
		ScmatDoub sli = slice(v, 0, N2 - 2);
		if (sli.ptr() != v.ptr())
			SLS_ERR("failed!");
		if (sli.n1() != N1 || sli.n2() != N2 - 2)
			SLS_ERR("failed!");
	}

	{
		Long N1 = 4, N2 = 5;
		CmatDoub v(N1, N2); linspace(v, 1, N1*N2);
		DcmatDoub sli = slice(v, 0, N1 - 2, 0, N2 - 2);
		if (sli.ptr() != v.ptr())
			SLS_ERR("failed!");
		if (sli.n1() != N1 - 2 || sli.n2() != N2 - 2)
			SLS_ERR("failed!");
	}
}
