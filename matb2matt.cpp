// convert .matb files into .matt files
#define SLS_MATB_REPLACE
#include "SLISC/matt.h"
#include "SLISC/matb.h"

int main(int argc, char *argv[])
{
    using namespace slisc;
	Bool rm = false;
	if (strcmp(argv[argc-1], "-d")) {
		rm = true;
		--argc;
	}
	for (Long i = 1; i < argc; ++i) {
		cout << argv[i] << endl;
		matb2matt(argv[i]);
		if (rm)
			remove(argv[i]);
	}
}
