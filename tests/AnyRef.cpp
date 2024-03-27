#include "../SLISC/util/AnyRef.h"

void test_AnyRef()
{
	using namespace slisc;
	vecStr vs = {"abc", "bcd", "cde"};
	vecInt vi = {1, 2, 3};
	AnyRef ref;
	ref.bind(vs[1]);
	SLS_ASSERT(ref.is<Str>());
	SLS_ASSERT(ref.get<Str>() == "bcd");
	ref.bind(vi[2]);
	SLS_ASSERT(ref.is<Int>());
	SLS_ASSERT(ref.get<Int>() == 3);
}

#ifndef SLS_TEST_ALL
int main() { test_AnyRef(); }
#endif
