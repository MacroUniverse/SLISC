#include "../SLISC/arithmetic.h"

void test_Scmat()
{
	using namespace slisc;
	ScmatDoub sli;
	Long N = 4;
	CmatDoub v(N, N); linspace(v, 1, N*N);
	sli.set(v.ptr(), N, N-2);
	for (Long j = 0; j < N-2; ++j) {
		for (Long i = 0; i < N; ++i) {
			if (sli(i, j) != v(i, j))
				SLS_ERR("failed!");
		}
	}
}
