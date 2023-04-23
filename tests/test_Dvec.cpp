#include "../SLISC/arith/arith2.h"

void test_Dvec()
{
	using namespace slisc;
	DvecDoub cut;
	Long N = 6;
	VecDoub v(N); linspace(v, 1, N);
    cut.set(v.p(), N/2, 2);
	for (Long i = 0; i < N/2; ++i) {
		if (cut[i] != v[2*i])
			SLS_FAIL;
	}
}

#ifndef SLS_TEST_ALL
int main() { test_Dvec(); }
#endif
