#include "../SLISC/file/hdf.h"
#include "../SLISC/str/disp.h"
#include "../SLISC/arith/arith2.h"

using namespace slisc;

void test_hdf()
{
#ifdef SLS_USE_HDF
	CmatDoub a;
	CmatDoub b(3, 2);
	linspace(b, 1, 6);
	Cmat3Doub c(2,3,4);
	linspace(c, 1, 24);

	H5File hdf("test.h5", H5F_ACC_TRUNC);
	save(a, "a", hdf);
	save(b, "b", hdf);
	save(c, "c", hdf);
	hdf.close();
#else
    printf("---------- disabled! ----------\n");
#endif
}

#ifndef SLS_TEST_ALL
int main() { test_hdf(); }
#endif
