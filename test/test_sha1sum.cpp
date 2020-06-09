#include "../SLISC/sha1sum.h"
using namespace slisc;

void test_sha1sum() {
	if (sha1sum("The quick brown fox jumps over the lazy dog") != "2fd4e1c67a2d28fced849ee1bb76e7391b93eb12")
		SLS_ERR("failed!");
	
	if (sha1sum("The quick brown fox jumps over the lazy cog") != "de9f2c7fd25e1b3afad3e85a0bd17d9b100db4b3")
		SLS_ERR("failed!");
}
