// convert .matt files into .matb files
#include "SLISC/matt.h"
#include "SLISC/matb.h"

int main(int argc, char *argv[])
{
    using namespace slisc;
	for (Long i = 1; i < argc; ++i)
		matt2matb(argv[i]);
}
