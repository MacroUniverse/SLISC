#include "../SLISC/util/input.h"

void test_input()
{
	using namespace slisc;
	Long i1, i2, i3, i4;
	Doub d1, d2, d3;
	Str s1, s2;

	cin_comment(); cin_LF();
	cin_LF();
	cin_comment(); cin_LF();
	SLS_INP(i1); SLS_INP(i2); SLS_INP(d1); cin_comment(); cin_LF();
	SLS_INP(d2); SLS_INP(s1); SLS_INP(i3); cin_comment(); cin_LF();
	cin_LF();
	cin_comment(); cin_LF();
	SLS_INP(d3); SLS_INP(i4); SLS_INP(s2); cin_comment(); cin_LF();

	if (i1 != 123 || i2 != 234 || d1 != 345.6)
		SLS_FAIL;
	if (d2 != 456.7 || s1 != "a567" || i3 != 678)
		SLS_FAIL;
	if (d3 != 789.1 || i4 != 890 || s2 != "yoyo")
		SLS_FAIL;
}

#ifndef SLS_TEST_ALL
int main() { test_input(); }
#endif
