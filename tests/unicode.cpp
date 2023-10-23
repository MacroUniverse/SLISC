#include "../SLISC/str/unicode.h"

void test_unicode()
{
	using namespace slisc;
	cout << u8"显示一些 UTF-8 字符" << endl;

	// u8_iter
	Str str = u8"显示一些 UTF-8 字符";
	u8_iter it(str, size(str));
	it -= 1;
	SLS_ASSERT(*it == u8"符");
}

#ifndef SLS_TEST_ALL
int main() { test_unicode(); }
#endif
