#include "../SLISC/str/str.h"
#include "../SLISC/str/disp.h"

void test_str()
{
	using namespace slisc;
	Str str = "abcdefghijklmnopqrstuvwxyz", str1;
	Str STR = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", STR1;
	to_lower(str1, STR);
	if (str1 != str)
		SLS_FAIL;
	to_upper(STR1, str);
	if (STR1 != STR)
		SLS_FAIL;

	replace(str1, str, "abcd", "12");
	if (str1 != "12efghijklmnopqrstuvwxyz")
		SLS_FAIL;
	replace(str1, "12", "abcd");
	if (str1 != str)
		SLS_FAIL;

	// for (Long i : {98765, 90765, 98065, 98705, 98760,
	// 	90065, 98005, 98700, 90705, 98060, 90760,
	// 	90005, 98000, 90060, 90700,
	// 	90000})
	// 	cout << i << ": " << num2chinese(i) << endl;

	str = "123.501203000";
	rm_float_zeros(str);
	SLS_ASSERT(str == "123.501203");

	str = "123.501203000e-18";
	rm_float_zeros(str);
	SLS_ASSERT(str == "123.501203e-18");

	// num2str()
	Int i = 0;
	str = "2147483647"; // INT_MAX
	Long ind = str2int(i, str);
	SLS_ASSERT(ind == size(str));
	SLS_ASSERT(i == INT_MAX);

	str = "-2147483648";
	ind = str2int(i, str);
	SLS_ASSERT(ind == size(str));
	SLS_ASSERT(i == INT_MIN);

	str = "2147483648";
	ind = str2int(i, str);
	SLS_ASSERT(ind < 0);
	SLS_ASSERT(i == 214748364);

	str = "-2147483649";
	ind = str2int(i, str);
	SLS_ASSERT(ind < 0);
	SLS_ASSERT(i == -214748364);

	Llong j;
	str = " +9223372036854775807";
	ind = str2int(j, str);
	SLS_ASSERT(ind == size(str));
	SLS_ASSERT(j == INT64_MAX);

	str = " -9223372036854775808";
	ind = str2int(j, str);
	SLS_ASSERT(ind == size(str));
	SLS_ASSERT(j == INT64_MIN);

	str = "9223372036854775808";
	ind = str2int(j, str);
	SLS_ASSERT(ind < 0);
	SLS_ASSERT(j == 922337203685477580LL);

	str = "-9223372036854775809";
	ind = str2int(j, str);
	SLS_ASSERT(ind < 0);
	SLS_ASSERT(j == -922337203685477580LL);

	// split()
	str = "123 2 13 4";
	vecStr res, res0{"123", "2", "13", "4"};
	vecLlong vl, vl0{123, 2, 13, 4};

	split(res, str);
	SLS_ASSERT(res == res0);

	split(vl, str);
	SLS_ASSERT(vl == vl0);

	str = " 123  2 13  4 ";
	split(res, str);
	SLS_ASSERT(res == res0);

	split(vl, str);
	SLS_ASSERT(vl == vl0);

	split(res, str, " ", true);
	res0 = {"", "123", "", "2", "13", "", "4", ""};
	SLS_ASSERT(res == res0);
}

#ifndef SLS_TEST_ALL
int main() { test_str(); }
#endif
