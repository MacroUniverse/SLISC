#include "../SLISC/bits.h"

void test_bits()
{
	using namespace slisc;
	Int a = little_endian(); ++a;

	Int byte = 0;
	for (Long i = 0; i < 8; ++i) {
		if (bitL(byte, i) != 0 || bitR(byte, i) != 0)
			SLS_ERR("failed!");
	}

	for (Long i = 0; i < 8; ++i) {
		Uchar byte = 0;
		set_bitR(byte, i);
		if (byte != pow(2, i))
			SLS_ERR("failed!");
		unset_bitR(byte, i);
		if (byte != 0)
			SLS_ERR("failed!");

		byte = 0;
		set_bitL(byte, i);
		if (byte != pow(2, 7-i))
			SLS_ERR("failed!");
		unset_bitL(byte, i);
		if (byte != 0)
			SLS_ERR("failed!");
	}

	if (bit_str(255) != "11111111")
		SLS_ERR("failed!");
	if (bit_str(128) != "10000000")
		SLS_ERR("failed!");
	if (bit_str(85) != "01010101")
		SLS_ERR("failed!");
}
