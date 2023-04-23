#include "../SLISC/str/unicode.h"

void test_unicode()
{
	using namespace slisc;
	cout << u8"显示一些 UTF-8 字符" << endl;
}

#ifndef SLS_TEST_ALL
int main() { test_unicode(); }
#endif
