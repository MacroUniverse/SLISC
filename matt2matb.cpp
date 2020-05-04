// convert .matt files into .matb files
#define SLS_MATB_REPLACE
#include "SLISC/matt.h"
#include "SLISC/matb.h"

int main(int argc, char *argv[])
{
    using namespace slisc;
	Bool rm = false;
	if (strcmp(argv[argc-1], "-d") == 0) {
		rm = true;
		--argc;
	}
#pragma omp parallel for schedule(dynamic, 3)
	for (Long i = 1; i < argc; ++i) {
		cout << argv[i] << endl;
		matt2matb(argv[i]);
		if (rm)
			remove(argv[i]);
	}
}
