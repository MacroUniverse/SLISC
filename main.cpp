// comprehensive test of SLISC
#include "tests/test_all.h"

int main (int argc, char **argv)
{
	std::cout << "SLISC version: " <<
		SLS_MAJOR << '.' << SLS_MINOR << '.' << SLS_PATCH << std::endl;
	if (argc == 1)
		test_all("");
	else
		test_all(argv[1]);
}
