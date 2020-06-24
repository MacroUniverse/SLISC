// convert .matt files into .matb files
// usage: `find ... -exec matt2matb [-d] {} +`
#include <omp.h>
#define SLS_MATB_REPLACE
#include "SLISC/matt.h"
#include "SLISC/matb.h"
#include "SLISC/time.h"

    using namespace slisc;
Int main(Int argc, Char *argv[])
{
	Bool rm = false;
	Long start = 1;
	if (strcmp(argv[1], "-d") == 0) {
		rm = true;
		++start;
	}
	omp_set_num_threads(8);
	Int N = 0;
	Timer timer; timer.tic();
#pragma omp parallel for schedule(dynamic, 3)
	for (Int i = start; i < argc; ++i) {
#pragma omp atomic
		++N;
		printf("%s  %i/%i  %es\n", argv[i], N, argc-1, timer.toc());
		fflush(stdout);
		try {matt2matb(argv[i]);}
		catch (...) {
			cout << "warning: exception found, skipping..." << endl;
			continue;
		}
		if (rm)
			remove(argv[i]);
	}
}
