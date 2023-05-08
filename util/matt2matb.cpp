// convert .matt files into .matb files
// usage: `find ... -exec matt2matb [-d] {} +`
#include <omp.h>
#define SLS_MATB_REPLACE
#include "../SLISC/matb.h"
#include "../SLISC/time.h"

using namespace slisc;
Int main(Int argc, Char *argv[])
{
	bool rm = false, replace = false;
	for (Int i = 1; i <= 2; ++i) {
		if (argc > i && strcmp(argv[i], "-d") == 0)
			rm = true; // remove original
		else if (argc > i && strcmp(argv[i], "-r") == 0)
			replace = true; // output overwrite
	}
	cout << "delete original [-d]: " << rm << endl;
	cout << "replace destination [-r]: " << replace << endl;
	Int start = 1 + rm + replace;
	Int N = 0;
	Timer timer; timer.tic();
	omp_set_num_threads(8);
#pragma omp parallel for schedule(dynamic, 3)
	for (Int i = start; i < argc; ++i) {
		fflush(stdout);
		Long ret;
		try {ret = matt2matb(argv[i], replace);}
		catch (...) {
			printf("warning: exception found, skipping... file might be corrupted\n");
			continue;
		}
		if (rm)
			remove(argv[i]);
#pragma omp atomic
		++N;
		if (ret == 0)
			printf("%s  %i/%i  %is\n", argv[i], N, argc-start, Int(timer.toc()));
		if (ret == -1)
			printf("%s  %i/%i  destination exist, skipped\n", argv[i], N, argc-start);
	}
}
