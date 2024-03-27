#include "../SLISC/util/AnyRef.h"
#include "../SLISC/util/STL_util.h"

void test_AnyRef()
{
	using namespace slisc;
	vecStr vs = {"abc", "bcd", "cde"};
	vecInt vi = {1, 2, 3};
	AnyRef ref;
	auto hash_any = std::hash<AnyRef>{};
	ref.bind(vs[1]);
	SLS_ASSERT(ref.is<Str>());
	SLS_ASSERT(ref.get<Str>() == "bcd");
	SLS_ASSERT(hash_any(ref) == std::hash<Str>{}(vs[1]));
	ref.bind(vi[2]);
	SLS_ASSERT(ref.is<Int>());
	SLS_ASSERT(ref.get<Int>() == 3);
	SLS_ASSERT(hash_any(ref) == std::hash<Int>{}(vi[2]));
	vector<AnyRef> vany(3);
	vany[0].bind(vs[0]);
	vany[1].bind(vi[1]);
	vany[2].bind(vs[2]);
	size_t hash = 0;
	hash = hash_combine(hash, std::hash<Str>{}(vs[0]));
	hash = hash_combine(hash, std::hash<Int>{}(vi[1]));
	hash = hash_combine(hash, std::hash<Str>{}(vs[2]));
	SLS_ASSERT(std::hash<vector<AnyRef>>{}(vany) == hash);
}

#ifndef SLS_TEST_ALL
int main() { test_AnyRef(); }
#endif
