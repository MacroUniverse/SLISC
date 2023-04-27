#include "../SLISC/util/bit.h"
// #include "../SLISC/file/file.h"

// >> and << operating on signed integer is "undefined"!
// Char and Uchar reinterpret cast conserves bit, but static cast might not (for older architecture)

void test_bit()
{
	using namespace slisc;
	if (!little_endian())
		SLS_WARN("this system is using big endian, is it x86 or x64 architecture?");

	Char byte = 0;
	for (Long i = 0; i < 8; ++i) {
		if (bitL(&byte, i) != 0 || bitR(&byte, i) != 0)
			SLS_FAIL;
	}

	if (to_bitstr(-128) != "10000000")
		SLS_FAIL;

	for (Long i = 0; i < 8; ++i) {
		Char byte = 0;
		set_bitR(byte, i);
		if (byte != (Char)pow(2, i)) {
			SLS_FAIL;
		}
		unset_bitR(byte, i);
		if (byte != 0)
			SLS_FAIL;

		byte = 0;
		set_bitL(byte, i);
		if (byte != Char((int)pow(2, 7-i))) {
			SLS_FAIL;
		}
		unset_bitL(byte, i);
		if (byte != 0)
			SLS_FAIL;
	}

	Char ui[] = {Char(255), Char(128), 85};
	if (to_bitstr(ui) != "11111111")
		SLS_FAIL;
	if (to_bitstr(ui+1) != "10000000")
		SLS_FAIL;
	if (to_bitstr(ui+2) != "01010101")
		SLS_FAIL;
	if (str2bit("10100101") != Char(165))
		SLS_FAIL;

	Char uc = (Char)165; // 0b10100101
	toggle_bitL(&uc, 1);
	if (uc != Char(229)) // 0b11100101
		SLS_FAIL;

	// base conversion
	Uchar num[4], num1[4];
	num[0] = 1; num[1] = 0; num[2] = 1; num[3] = 1;
	Int n = baseN2Int(num, 4, 2);
	num1[0] = 3; num1[1] = 3; num1[2] = 3; num1[3] = 3;
	Int2baseN(num1, 4, 2, n);
	for (Long i = 0; i < 4; ++i)
		if (num[i] != num1[i])
			SLS_FAIL;

	// base85 and int conversion (5 char = 4 bytes = 1 int)
	Str str1 = "1;^cB", str2(str1.size(), 'a');
	Int a = b872Int(&str1[0]);
	Int2b87(&str2[0], a);
	if (str1 != str2)
		SLS_FAIL;

	// base87 encoding
	// Str str87;
	// int2b87(str87, "12345");
	// cout << str87 << endl;
}

#ifndef SLS_TEST_ALL
int main() { test_bit(); }
#endif
