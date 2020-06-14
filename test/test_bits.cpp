#include "../SLISC/Bit.h"

void test_bits()
{
	using namespace slisc;
	if (!little_endian())
		SLS_WARN("this system is using big endian, is it x86 or x64 architecture?");

	Int byte = 0;
	for (Long i = 0; i < 8; ++i) {
		if (bitL((Uchar*)(&byte), i) != 0 || bitR((Uchar*)(&byte), i) != 0)
			SLS_ERR("failed!");
	}

	for (Long i = 0; i < 8; ++i) {
		Uchar byte = 0;
		set_bitR(&byte, i);
		if (byte != pow(2, i))
			SLS_ERR("failed!");
		unset_bitR(&byte, i);
		if (byte != 0)
			SLS_ERR("failed!");

		byte = 0;
		set_bitL(&byte, i);
		if (byte != pow(2, 7-i))
			SLS_ERR("failed!");
		unset_bitL(&byte, i);
		if (byte != 0)
			SLS_ERR("failed!");
	}

	Uchar ui[] = {255, 128, 85};
	if (bit2str(ui) != "11111111")
		SLS_ERR("failed!");
	if (bit2str(ui+1) != "10000000")
		SLS_ERR("failed!");
	if (bit2str(ui+2) != "01010101")
		SLS_ERR("failed!");
	if (str2bit("10100101") != Uchar(0b10100101))
		SLS_ERR("failed!");
	
	Uchar uc = 0b10100101;
	toggle_bitL(&uc, 1);
	if (uc != Uchar(0b11100101))
		SLS_ERR("failed!");
}
