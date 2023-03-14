#include "../SLISC/dense/Scmat.h"
#include "../SLISC/util/random.h"

void test_Scmat()
{
	using namespace slisc;
	ScmatDoub sli;
	Long N = 4;
	CmatDoub v(N, N); rand(v);
	sli.set(v.p(), N, N-2);
	for (Long j = 0; j < N-2; ++j) {
		for (Long i = 0; i < N; ++i) {
			if (sli(i, j) != v(i, j))
				SLS_FAIL;
		}
	}
}
