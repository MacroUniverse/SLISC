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
	CmatDoub b(3,4), b_r; linspace(b, 1, 12);
	Cmat3Doub b3(2,3,4), b3_r; linspace(b3, 1, 24);
	CmatComp c(3, 2), c_r; // will save as a 6x2 double matrix with attribute "SLS_Comp" and a description.
	linspace(c, Comp(1.1,2.2), Comp(6.6,7.7));
	Cmat3Comp c3(3, 2, 4), c3_r;
	linspace(c3, Comp(1.1,2.2), Comp(3.5,4.6));
	McooDoub d(2,5,10);
	d.push(2,1,3); d.push(1.1,0,4); d.push(3.1,0,1);
	Str str = "hello, world!", str_r;

	H5File hdf("test.h5", H5F_ACC_TRUNC);
	save(v, "v", hdf);
	save(PI, "pi", hdf);
	save(a, "a", hdf);
	save(b, "b", hdf);
	save(b3, "b3", hdf);
	save(c, "c", hdf);
	save(c3, "c3", hdf);
	save(d, "d", hdf);
	save(str, "str", hdf);
	hdf.close();

	hdf.openFile("test.h5", H5F_ACC_RDONLY);
	Doub pi;
	load(pi, "pi", hdf);
	SLS_ASSERT(pi == PI);
	load(v_r, "v", hdf);
	SLS_ASSERT(v == v_r);
	load(b_r, "b", hdf);
	SLS_ASSERT(b == b_r);
	load(b3_r, "b3", hdf);
	SLS_ASSERT(b3 == b3_r);
	load(c_r, "c", hdf);
	SLS_ASSERT(c == c_r);
	load(c3_r, "c3", hdf);
	SLS_ASSERT(c3 == c3_r);
	load(str_r, "str", hdf);
	SLS_ASSERT(str == str_r);
	hdf.close();
#else
    printf("---------- disabled! ----------\n");
#endif
}

#ifndef SLS_TEST_ALL
int main() { test_hdf(); }
#endif
 