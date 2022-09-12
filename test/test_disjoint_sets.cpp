#include "../SLISC/disjoint_sets.h"

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
			SLS_ASSERT(s.parent[i] == 6);
	}
}
