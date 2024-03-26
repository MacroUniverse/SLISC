#include "../SLISC/util/safe_union.h"

void test_safe_union()
{
	using namespace slisc;
	SafeUnion a;
	a = 123;
	SLS_ASSERT(a.Int_() == 123);
	a = Llong(234);
	SLS_ASSERT(a.Llong_() == 234);
	a = Str("abc");
	SLS_ASSERT(a.Str_() == "abc");
	a = 1.23;
	SLS_ASSERT(a.Doub_() == 1.23);
	a = Comp(1.1, 2.2);
	SLS_ASSERT(a.Comp_() == Comp(1.1, 2.2));
}

#ifndef SLS_TEST_ALL
int main() { test_safe_union(); }
#endif
