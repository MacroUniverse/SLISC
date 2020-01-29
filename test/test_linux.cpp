#include "../SLISC/linux.h"

void test_linux()
{
	using namespace slisc;
	if (exec_str("echo hello world!") != "hello world!\n")
		SLS_ERR("failed!");
}
