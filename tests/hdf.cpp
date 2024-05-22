#include "../SLISC/file/hdf.h"
#include "../SLISC/str/disp.h"
#include "../SLISC/arith/arith2.h"

using namespace slisc;

void test_hdf()
{
#ifdef SLS_USE_HDF
	remove("test.h5");
	VecDoub v(3), v_r; copy(v, {1.2, 2.3, 3.4});
	CmatDoub a;
	CmatComp b(3, 2); // will save as a 6x2 double matrix with attribute "SLS_Comp" and a description.
	linspace(b, Comp(1.1,2.2), Comp(6.6,7.7));
	Cmat3Doub c(2,3,4);
	linspace(c, 1, 24);
	McooDoub d(2,5,10);
	d.push(2,1,3); d.push(1.1,0,4); d.push(3.1,0,1);

	H5File hdf("test.h5", H5F_ACC_TRUNC);
	save(v, "v", hdf);
	save(PI, "pi", hdf);
	save(a, "a", hdf);
	save(b, "b", hdf);
	save(c, "c", hdf);
	save(d, "d", hdf);
	save("hello, world!", "s", hdf);
	hdf.close();

	hdf.openFile("test.h5", H5F_ACC_RDONLY);
	Doub pi;
	load(pi, "pi", hdf);
	SLS_ASSERT(pi == PI);
	load(v_r, "v", hdf);
	SLS_ASSERT(v == v_r);
	hdf.close();
#else
    printf("---------- disabled! ----------\n");
#endif
}

#ifndef SLS_TEST_ALL
int main() { test_hdf(); }
#endif
 