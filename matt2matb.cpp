// convert .matt files into .matb files
#include <omp.h>
#define SLS_MATB_REPLACE
#include "SLISC/matt.h"
#include "SLISC/matb.h"
#include "SLISC/time.h"

    using namespace slisc;
Int main(Int argc, Char *argv[])
{
	Bool rm = false;
	if (strcmp(argv[argc-1], "-d") == 0) {
		rm = true;
		--argc;
	}
	omp_set_num_threads(8);
	Int N = 0;
	Timer timer; timer.tic();
#pragma omp parallel for schedule(dynamic, 3)
	for (Int i = 1; i < argc; ++i) {
#pragma omp atomic
		++N;
		printf("%s  %i/%i  %es\n", argv[i], N, argc-1, timer.toc());
		matt2matb(argv[i]);
		if (rm)
			remove(argv[i]);
	}
}
