#include "../SLISC/file.h"

void test_file()
{
	using namespace slisc;
	// file_list
	vecStr names;
	file_list(names, "./");
	if (names.size() < 3)
		SLS_ERR("failed!");

	// write_bin()
	Str data = "abcdefghijklmnopqrstuvwxyz";
	write_bin(data, "test_bin");
	if (file_size("test_bin") != size(data))
		SLS_ERR("failed!");
	Str data1;
	read_bin(data1, "test_bin");
	if (data1 != data)
		SLS_ERR("failed!");
	remove("test_bin");
}
