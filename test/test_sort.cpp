#include "../SLISC/sort.h"
#include "../SLISC/random.h"
#include "../SLISC/copy.h"
#include "../SLISC/compare.h"
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

	// test quicksort()
	{
		Long N = 10;
		VecInt v(N);
		for (Long i = 0; i < N; ++i)
			v[i] = randInt(N);
		quicksort0(v.p(), N);
		for (Long i = 1; i < N; ++i) {
			if (v[i] < v[i-1])
				SLS_ERR("failed!");
		}
        VecInt order(N), v1(N);
        for (Long i = 0; i < N; ++i)
            v[i] = randInt(N);
        copy(v1, v);
        linspace(order, 0, N-1);
        quicksort0(v.p(), order.p(), N);
        quicksort0(order.p(), v.p(), N);
        if (v != v1) SLS_ERR("failed!");

		for (Long i = 0; i < N; ++i)
			v[i] = randInt(N);
		quicksort3(v.p(), N);
		for (Long i = 1; i < N; ++i)
			if (v[i] < v[i-1])
				SLS_ERR("failed!");
        for (Long i = 0; i < N; ++i)
            v[i] = randInt(N);
        copy(v1, v);
        linspace(order, 0, N-1);
        quicksort3(v.p(), order.p(), N);
        quicksort3(order.p(), v.p(), N);
        if (v != v1) SLS_ERR("failed!");
	}

	// test mergesort()
	{
		Long N = 101;
		VecInt v(N), wsp((N+1)/2);
		for (Long i = 0; i < N; ++i)
			v[i] = randInt(N);
		mergesort(v.p(), v.size(), wsp.p());
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
		vecStr vs =  {"a", "ab", "bd", "AD", "1234", "A3", "B", "bC"};
		sort(vs);
		vecStr vs1 = {"1234", "A3", "AD", "B", "a", "ab", "bC", "bd"};
		if (vs != vs1)
			SLS_ERR("failed!");
		sort_case_insens(vs);
		vs1 = {"1234", "a", "A3", "ab", "AD", "B", "bC", "bd"};
		if (vs != vs1)
			SLS_ERR("failed!");
	}
}
