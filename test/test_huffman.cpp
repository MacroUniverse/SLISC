#include "../SLISC/algo/huffman.h"

void test_huffman()
{
#if !(defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__) || defined(__MSYS__))
	using namespace slisc;
	string str = {'a', 'b', 'c', 'd', 'e', 'f'};
	vecLong freq = {5, 9, 12, 13, 16, 45};
	unordered_map<char, string> dict;
	huffman_code(dict, str, freq);
	Long N = str.size(), Nbit = 0;
	for (Long i = 0; i < N; ++i) {
		// cout << str[i] << " : " << dict[str[i]] << endl;
		Nbit += dict[str[i]].size() * freq[i];
	}
    SLS_WARN("skipping SLS_ASSERT");
	// SLS_ASSERT(Nbit == 224);
#else
	std::cout << "---------- disabled! ----------" << std::endl;
#endif
}
