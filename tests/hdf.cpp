#include "../SLISC/file/hdf.h"
#include "../SLISC/str/disp.h"
#include "../SLISC/arith/arith2.h"

using namespace slisc;

void test_hdf()
{
#ifdef SLS_USE_HDF
	CmatDoub a(3,2);
	linspace(a, 1, 6);
	disp(a);

	H5File file("test.h5", H5F_ACC_TRUNC);
	save(a, "a", file);
#else
    printf("---------- disabled! ----------\n");
#endif
}

#ifndef SLS_TEST_ALL
int main() { test_hdf(); }
#endif
