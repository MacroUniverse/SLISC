#include "../SLISC/str/str.h"

int main()
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
}
