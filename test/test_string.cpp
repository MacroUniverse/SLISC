#include "../SLISC/string.h"

void test_string()
{
    using namespace slisc;
    Str str = "abcdefghijklmnopqrstuvwxyz", str1;
    Str STR = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", STR1;
	to_lower(str1, STR);
	if (str1 != str)
		SLS_ERR("failed!");
	to_upper(STR1, str);
	if (STR1 != STR)
		SLS_ERR("failed!");
}
