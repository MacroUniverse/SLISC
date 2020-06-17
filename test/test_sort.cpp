#include "../SLISC/sort.h"
#include "../SLISC/random.h"
#include "../SLISC/disp.h"

void test_sort()
{
    using namespace slisc;

	// test sort()
	{
		Long N = 100;
		VecInt v(N);
		for (Long i = 0; i < N; ++i) {
			v[i] = randInt(N);
		}
		sort(v);
		for (Long i = 1; i < N; ++i) {
			if (v[i] < v[i-1])
				SLS_ERR("failed!");
		}
	}

    // test sort(v, v)
	{
		Long N = 100;
		VecInt a(N), a0(N), order(N);
		for (Long i = 0; i < N; ++i) {
			a0[i] = randInt(N);
		}
		copy(a, a0);
		linspace(order, 0, N - 1);
		sort(a, order);
		
		for (Long i = 1; i < N; ++i) {
			if (a[i] < a[i-1])
				SLS_ERR("failed!");
		}

		for (Long i = 0; i < N; ++i) {
			if (a[i] != a0[order[i]])
				SLS_ERR("failed!");
		}
	}

	// sort string
	{
		vecStr vs = {"ABC3", "aBC2", "abc1"}, vs1 = {"abc1", "aBC2", "ABC3"};
		sort_case_insens(vs);
		if (vs != vs1)
			SLS_ERR("failed!");
	}
}
