#include "../SLISC/sha1sum.h"
using namespace slisc;

void test_sha1sum() {
	Str str = "The quick brown fox jumps over the lazy dog";
	if (sha1sum(str.c_str(), str.size()) != "2fd4e1c67a2d28fced849ee1bb76e7391b93eb12")
		SLS_ERR("failed!");
	
	str = "The quick brown fox jumps over the lazy cog";
	if (sha1sum(str) != "de9f2c7fd25e1b3afad3e85a0bd17d9b100db4b3")
		SLS_ERR("failed!");

	if (sha1sum_f("test/test_sha1sum.txt") != "f99cf75b4d3e9d76ce38a2d0cc88f23ae9e6b505")
		SLS_ERR("failed!");
}
