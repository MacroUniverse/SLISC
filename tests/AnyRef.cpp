#include "../SLISC/util/AnyRef.h"

void test_AnyRef()
{
	using namespace slisc;
	vecStr vs = {"abc", "bcd", "cde"};
	vecInt vi = {1, 2, 3};
	AnyRef ref;
	ref.set(vs[1]);
	SLS_ASSERT(ref.getStr() == "bcd");
}

#ifndef SLS_TEST_ALL
int main() { test_AnyRef(); }
#endif
