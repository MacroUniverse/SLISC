#include "../SLISC/algo/heap.h"

using namespace slisc;

int main()
{
	// heapsort is tested in "test_sort()"

	Long N = randInt(150);
    vecLong v(N);
    randPerm(v);
    heapsort(v.data(), v.size());
    // btree_print(v.data(), v.size());
    for (Long i = 0; i < N; ++i)
        SLS_ASSERT(v[i] == i);
}
