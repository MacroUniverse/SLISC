#include "../SLISC/dense/Scmat.h"
#include "../SLISC/util/random.h"

using namespace slisc;

int my_fun(SvecDoub_I ) { return 1; }

int my_fun(ScmatDoub_I ) { return 2; }

int my_fun(const SvbaseDoub &) { return 3; }

void test_Scmat()
{
	ScmatDoub sv;
	Long N = 4;
	CmatDoub v(N, N); rand(v);
	sv.set(v.p(), N, N-2);
	for (Long j = 0; j < N-2; ++j) {
		for (Long i = 0; i < N; ++i) {
			if (sv(i, j) != v(i, j))
				SLS_FAIL;
		}
	}
	SLS_ASSERT(my_fun(sv) == 3);
}

#ifndef SLS_TEST_ALL
int main() { test_Scmat(); }
#endif
