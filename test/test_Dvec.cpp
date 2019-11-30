#include "../SLISC/arithmetics.h"

void test_Dvec()
{
	using namespace slisc;
	DvecDoub sli;
	Long N = 6;
	VecDoub v(N); linspace(v, 1, N);
	sli.set(v.ptr(), N/2, 2);
	for (Long i = 0; i < N/2; ++i) {
		if (sli[i] != v[2*i])
			SLS_ERR("failed!");
	}
}
