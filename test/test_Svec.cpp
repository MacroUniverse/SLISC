#include "../SLISC/arithmetic.h"

void test_Svec()
{
	using namespace slisc;
	SvecDoub sli;
	Long N = 3;
	VecDoub v(N); linspace(v, 1, N);
	sli.set(v.p(), N);
	for (Long i = 0; i < N; ++i) {
		if (sli[i] != v[i])
			SLS_ERR("failed!");
	}
}
