#include "../SLISC/queue.h"

void test_queue()
{
	using namespace slisc;
	Long N = 100;
    deque<int> q;
    vector<int> v(N); randPerm(v);
    for (Long i = 0; i < N; ++i)
        sorted_insert(q, v[i]);
    Long i = 0;
    for (auto &elm : q) {
        SLS_ASSERT(elm == i); ++i;
    }

    deque<int> q1;
    vector<int> elms(N), vals(N);
    randPerm(elms); randPerm(vals);
    for (Long i = 0; i < N; ++i)
        sorted_insert(q1, vals, v[i]);
    i = 0;
    for (auto &elm : q1) {
        SLS_ASSERT(vals[elm] == i); ++i;
    }
}
