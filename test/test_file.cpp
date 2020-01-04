#include "../SLISC/file.h"

void test_file()
{
	using namespace slisc;
	vecStr names;
	file_list(names, "./");
	if (names.size() < 3)
		SLS_ERR("failed!");
}
