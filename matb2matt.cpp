// convert .matb files into .matt files
#include "SLISC/matt.h"
#include "SLISC/matb.h"

int main(int argc, char *argv[])
{
    using namespace slisc;
	for (Long i = 1; i < argc; ++i)
		matb2matt(argv[i]);
}
