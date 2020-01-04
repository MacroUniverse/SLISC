#include "../SLISC/sort.h"
#include "../SLISC/random.h"

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

    // test sort2()
	{
		Long N = 100;
		VecInt a(N), a0(N), order(N);
		for (Long i = 0; i < N; ++i) {
			a0[i] = randInt(N);
		}
		copy(a, a0);
		linspace(order, 0, N - 1);
		sort2(a, order);
		
		for (Long i = 1; i < N; ++i) {
			if (a[i] < a[i-1])
				SLS_ERR("failed!");
		}

		for (Long i = 0; i < N; ++i) {
			if (a[i] != a0[order[i]])
				SLS_ERR("failed!");
		}
	}
}
