#include "../SLISC/algo/sort.h"
#include "../SLISC/arith/arith4.h"
#include "../SLISC/str/disp.h"

void test_sort()
{
	using namespace slisc;

	// test sort_NR3_v() and sort_NR3_vv()
	{
		Long N = 100;
		VecInt v(N), v1(N), v2(N), order(N);
		for (Long i = 0; i < N; ++i) {
			v[i] = randInt(N);
		}
		linspace(order, 0, N-1);
		copy(v1, v); copy(v2, v);
		sort_NR3_v(&v1[0], N);
		sort_vv(&v2[0], &order[0], N);
		for (Long i = 1; i < N; ++i)
			SLS_ASSERT(v1[i] >= v1[i-1]);
		SLS_ASSERT(v1 == v2);
		sort(order, v2);
		SLS_ASSERT(v2 == v);
	}

	// test quicksort()
	{
		Long N = 100;
		VecInt v(N);
		for (Long i = 0; i < N; ++i)
			v[i] = randInt(N);
		quicksort0(v.p(), N);
		for (Long i = 1; i < N; ++i) {
			if (v[i] < v[i-1])
				SLS_FAIL;
		}
		VecInt order(N), v1(N);
		for (Long i = 0; i < N; ++i)
			v[i] = randInt(N);
		copy(v1, v);
		linspace(order, 0, N-1);
		quicksort0(v.p(), order.p(), N);
		quicksort0(order.p(), v.p(), N);
		if (v != v1) SLS_FAIL;

		for (Long i = 0; i < N; ++i)
			v[i] = randInt(N);
		quicksort3(v.p(), N);
		for (Long i = 1; i < N; ++i)
			if (v[i] < v[i-1])
				SLS_FAIL;
		for (Long i = 0; i < N; ++i)
			v[i] = randInt(N);
		copy(v1, v);
		linspace(order, 0, N-1);
		quicksort3(v.p(), order.p(), N);
		quicksort3(order.p(), v.p(), N);
		if (v != v1) SLS_FAIL;
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
				SLS_FAIL;
		}
	}

	// test heapsort()
	{
		Long N = 101;
		VecInt v(N);
		for (Long i = 0; i < N; ++i)
			v[i] = randInt(N);
		heapsort(v.p(), v.size());
		for (Long i = 1; i < N; ++i) {
			if (v[i] < v[i-1])
				SLS_FAIL;
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
			if (a[i] < a[i-1]) {
				disp(a);
				SLS_FAIL;
			}
		}

		for (Long i = 0; i < N; ++i) {
			if (a[i] != a0[order[i]])
				SLS_FAIL;
		}
	}

	// sort string
	{
		vecStr vs =  {"a", "ab", "bd", "AD", "1234", "A3", "B", "bC"};
		sort(vs);
		vecStr vs1 = {"1234", "A3", "AD", "B", "a", "ab", "bC", "bd"};
		if (vs != vs1)
			SLS_FAIL;
		sort_case_insens(vs);
		vs1 = {"1234", "a", "A3", "ab", "AD", "B", "bC", "bd"};
		if (vs != vs1)
			SLS_FAIL;
	}

	// minN(), maxN()
	{
		Long N = 20, Nmax = 3;
		vector<Long> v(N), vals, inds;
		v -= N/2;
		randPerm(v);
		maxN(vals, inds, &v[0], N, Nmax);
		for (Long i = 0; i < Nmax; ++i) {
			SLS_ASSERT(vals[i] == N-1-i);
			SLS_ASSERT(vals[i] == v[inds[i]]);
		}
		minN(vals, inds, &v[0], N, Nmax);
		for (Long i = 0; i < Nmax; ++i) {
			SLS_ASSERT(vals[i] == i);
			SLS_ASSERT(vals[i] == v[inds[i]]);
		}
	}

	// maxN_heap()
	{
		Long N = 100, Nmax = 11;
		vecLong v(N), vals, inds;
		for (Long i = 0; i < N; ++i)
			v[i] = randLong(N);
		maxN(vals, inds, v.data(), N, Nmax);
		maxN_heap(v.data(), N, Nmax);
		for (Long i = 0; i < Nmax; ++i)
			SLS_ASSERT(vals[i] == v[N-i-1]);
	}

	// maxN_quick0()
	{
		Long N = 100, Nmax = 11;
		vecLong v(N), vals, inds;
		for (Long i = 0; i < N; ++i)
			v[i] = randLong(N);
		maxN(vals, inds, v.data(), N, Nmax);
		maxN_quick0(v.data(), N, Nmax);
		for (Long i = 0; i < Nmax; ++i)
			SLS_ASSERT(vals[i] == v[N-i-1]);
	}

	// maxN_quick3()
	{
		Long N = 100, Nmax = 11;
		vecLong v(N), vals, inds;
		for (Long i = 0; i < N; ++i)
			v[i] = randLong(N);
		maxN(vals, inds, v.data(), N, Nmax);
		maxN_quick3(v.data(), N, Nmax);
		for (Long i = 0; i < Nmax; ++i)
			SLS_ASSERT(vals[i] == v[N-i-1]);
	}
}

#ifndef SLS_TEST_ALL
int main() { test_sort(); }
#endif
