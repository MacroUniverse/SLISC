// convert .matb files into .matt files
#include <omp.h>
#define SLS_MATB_REPLACE
#include "SLISC/matt.h"
#include "SLISC/matb.h"
#include "SLISC/time.h"

int main(int argc, char *argv[])
{
    using namespace slisc;
	Bool rm = false;
	if (strcmp(argv[argc-1], "-d") == 0) {
		rm = true;
		--argc;
	}
	omp_set_num_threads(8);
	Long N = 0;
	Timer timer; timer.tic();
#pragma omp parallel for schedule(dynamic, 3)
	for (Long i = 1; i < argc; ++i) {
#pragma omp atomic
		++N;
		cout << argv[i] << "  " << N << "/" << argc-1 << "  " << timer.toc() << endl;
		matb2matt(argv[i]);
		if (rm)
			remove(argv[i]);
	}
}
