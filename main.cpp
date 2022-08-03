// comprehensive test of SLISC
#include "test/test_all.h"

int main (int argc, char **argv)
{
	if (argc == 1)
		test_all("");
	else
		test_all(argv[1]);
}
