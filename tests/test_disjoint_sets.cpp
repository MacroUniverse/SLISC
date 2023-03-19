#include "../SLISC/algo/disjoint_sets.h"
#include "../SLISC/util/random.h"
// #include "../SLISC/str/disp.h"

void test_disjoint_sets()
{
	using namespace slisc;
	{
		Long N = 10;
		disjoint_sets s(N);
		SLS_ASSERT(s.size() == N);
		SLS_ASSERT(s.num_set() == N);
		SLS_ASSERT(s.num_set2() == 0);
		for (Long i = 0; i < N; ++i)
			SLS_ASSERT(s.find(i) == i);
		for (Long i = 0; i < 4; ++i)
			s.parent[i] = i + 1;
		s.find(0);
		for (Long i = 0; i <= 4; ++i) {
			SLS_ASSERT(s.check(i, 0));
			SLS_ASSERT(s.parent[i] == 4);
		}
	}
	{
		Long N = 10;
		disjoint_sets s(N);
		for (Long i = 0; i < 4; ++i)
			s.merge(i, i + 1);
		SLS_ASSERT(s.num_set() == 6);
		SLS_ASSERT(s.num_set2() == 1);
		for (Long i = 5; i < N-1; ++i)
			s.merge(i, i + 1);
		SLS_ASSERT(s.num_set() == 2);
		SLS_ASSERT(s.num_set2() == 2);
		s.merge(2, 7);
		SLS_ASSERT(s.num_set() == 1);
		SLS_ASSERT(s.num_set2() == 1);
		s.update();
		for (Long i = 0; i < N; ++i)
			SLS_ASSERT(s.parent[i] == 0);
	}

	// disjoint_sets2
	{
		disjoint_sets2<Long> s;
		SLS_ASSERT(s.size() == 0);
		SLS_ASSERT(s.num_set() == 0);
		SLS_ASSERT(s.num_set2() == 0);
		Long N = 10;
		vecLong v(N); randPerm(v);
		for (Long i = 0; i < N; ++i) {
			s.push(v[i]);
			SLS_ASSERT(s.find(v[i]) == v[i]);
		}
		for (Long i = 0; i < 4; ++i)
			s.merge(v[i], v[i+1]);
		for (Long i = 0; i < 4; ++i) {
			SLS_ASSERT(s.check(v[i], v[i+1]));
			SLS_ASSERT(s.check(v[i], v[4]));
		}
		SLS_ASSERT(s.num_set() == 6);
		SLS_ASSERT(s.num_set2() == 1);
		for (Long i = 5; i < N-1; ++i)
			s.merge(v[i], v[i + 1]);
		SLS_ASSERT(s.num_set() == 2);
		SLS_ASSERT(s.num_set2() == 2);
		s.merge(v[2], v[7]);
		SLS_ASSERT(s.num_set() == 1);
		SLS_ASSERT(s.num_set2() == 1);
		s.update();
		for (Long i = 0; i < N; ++i)
			SLS_ASSERT(s.parent[i] == v[0]);
	}
}
