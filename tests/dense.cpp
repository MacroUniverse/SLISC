// test dense containers here
#include "../SLISC/arith/arith2.h"
#include "../SLISC/arith/copy.h"
#include "../SLISC/arith/reorder.h"
#include "../SLISC/util/random.h"
#include "../SLISC/dense/WorkSpace.h"
// #include "../SLISC/str/disp.h"

void test_dense()
{
	using namespace slisc;

	// size initialize
	{
		VecDoub vDoub(3);
		if (vDoub.size() != 3) SLS_FAIL;
		if (vDoub.p() != &vDoub[0]) SLS_FAIL;
		MatDoub aDoub(3, 3);
		if (aDoub.size() != 9) SLS_FAIL;
		if (aDoub.n0() != 3) SLS_FAIL;
		if (aDoub.n1() != 3) SLS_FAIL;
		if (aDoub.p() != &aDoub(0, 0)) SLS_FAIL;
		Mat3Doub a3Doub(3, 3, 3);
		if (a3Doub.size() != 27) SLS_FAIL;
		if (a3Doub.n0() != 3) SLS_FAIL;
		if (a3Doub.n1() != 3) SLS_FAIL;
		if (a3Doub.n2() != 3) SLS_FAIL;
		if (a3Doub.p() != &a3Doub(0,0,0)) SLS_FAIL;
		Cmat3Doub c3Doub(3, 3, 3);
		if (c3Doub.size() != 27) SLS_FAIL;
		if (c3Doub.n0() != 3) SLS_FAIL;
		if (c3Doub.n1() != 3) SLS_FAIL;
		if (c3Doub.n2() != 3) SLS_FAIL;
		if (c3Doub.p() != &c3Doub(0, 0, 0)) SLS_FAIL;
	}

	// const initialize
	VecDoub vDoub(3); copy(vDoub, 1);
	if (vDoub != 1.) SLS_FAIL;
	MatDoub aDoub(3, 3); copy(aDoub, 1);
	if (aDoub != 1.) SLS_FAIL;
	Mat3Doub a3Doub(3, 3, 3); copy(a3Doub, 1);
	if (a3Doub != 1.) SLS_FAIL;
	Cmat3Doub c3Doub(3, 3, 3); copy(c3Doub, 1);
	if (c3Doub != 1.) SLS_FAIL;

	// resize
	vDoub.resize(0);
	if (vDoub.size() != 0) SLS_FAIL;
	vDoub.resize(4);
	if (vDoub.size() != 4) SLS_FAIL;
	if (vDoub.p() != &vDoub[0]) SLS_FAIL;
	aDoub.resize(0, 3);
	if (aDoub.size() != 0) SLS_FAIL;
	aDoub.resize(3, 0);
	if (aDoub.size() != 0) SLS_FAIL;
	aDoub.resize(4, 4);
	if (aDoub.size() != 16) SLS_FAIL;
	if (aDoub.n0() != 4) SLS_FAIL;
	if (aDoub.n1() != 4) SLS_FAIL;
	if (aDoub.p() != &aDoub(0,0)) SLS_FAIL;
	a3Doub.resize(0, 0, 4);
	if (a3Doub.size() != 0) SLS_FAIL;
	a3Doub.resize(0, 4, 0);
	if (a3Doub.size() != 0) SLS_FAIL;
	a3Doub.resize(4, 0, 0);
	if (a3Doub.size() != 0) SLS_FAIL;
	a3Doub.resize(4, 4, 4);
	if (a3Doub.size() != 64) SLS_FAIL;
	if (a3Doub.n0() != 4) SLS_FAIL;
	if (a3Doub.n1() != 4) SLS_FAIL;
	if (a3Doub.n2() != 4) SLS_FAIL;
	if (a3Doub.p() != &a3Doub(0,0,0)) SLS_FAIL;
	c3Doub.resize(0, 0, 4);
	if (c3Doub.size() != 0) SLS_FAIL;
	c3Doub.resize(0, 4, 0);
	if (c3Doub.size() != 0) SLS_FAIL;
	c3Doub.resize(4, 0, 0);
	if (c3Doub.size() != 0) SLS_FAIL;
	c3Doub.resize(4, 4, 4);
	if (c3Doub.size() != 64) SLS_FAIL;
	if (c3Doub.n0() != 4) SLS_FAIL;
	if (c3Doub.n1() != 4) SLS_FAIL;
	if (c3Doub.n2() != 4) SLS_FAIL;
	if (c3Doub.p() != &c3Doub(0, 0, 0)) SLS_FAIL;

	// resize and copy old data
	{
		VecInt v(3);
		v[0] = 100; v[1] = 101; v[2] = 102;
		resize_cpy(v, 5);
		if (v[0] != 100 || v[1] != 101 || v[2] != 102 || v[3] != 0 || v[4] != 0)
			SLS_FAIL;
		resize_cpy(v, 2);
		if (v[0] != 100 || v[1] != 101)
			SLS_FAIL;

		CmatDoub a2(4, 5), b2(4, 5);
		linspace(a2, 1, 20); copy(b2, a2);
		resize_cpy(b2, 7, 9);
		if (cut(b2, 0, 4, 0, 5) != a2)
			SLS_FAIL;
		resize_cpy(b2, 4, 5);
		if (b2 != a2)
			SLS_FAIL;

		Cmat3Doub a3(2, 3, 4), b3(2, 3, 4);
		rand(a3); copy(b3, a3);
		resize_cpy(b3, 3, 4, 5);
		if (cut(b3, 0, 2, 0, 3, 0, 4) != a3)
			SLS_FAIL;
		resize_cpy(b3, 2, 3, 4);
		if (b3 != a3)
			SLS_FAIL;
	}

	// assignment operator
	copy(vDoub, 1); if (vDoub != 1.) SLS_FAIL;
	copy(aDoub, 1); if (aDoub != 1.) SLS_FAIL;
	copy(a3Doub, 1); if (a3Doub != 1.) SLS_FAIL;
	VecDoub vDoub1(4);
	copy(vDoub1, 2);
	copy(vDoub, vDoub1);
	if (vDoub != vDoub1) SLS_FAIL;
	MatDoub aDoub1(4, 4);
	copy(aDoub1, 2);
	copy(aDoub, aDoub1);
	if (aDoub != aDoub1) SLS_FAIL;
	Mat3Doub a3Doub1(4, 4, 4);
	copy(a3Doub1, 2);
	copy(a3Doub, a3Doub1);
	if (a3Doub != a3Doub1) SLS_FAIL;
	Cmat3Doub c3Doub1(4, 4, 4);
	copy(c3Doub1, 2);
	copy(c3Doub, c3Doub1);
	if (c3Doub != c3Doub1) SLS_FAIL;

	// move operator
	VecDoub vDoub2;
	MatDoub aDoub2;
	Mat3Doub a3Doub2;
	Cmat3Doub c3Doub2;
	vDoub2 << vDoub;
	if (vDoub2 != vDoub1) SLS_FAIL;
	if (vDoub.size() != 0) SLS_FAIL;
	aDoub2 << aDoub;
	if (aDoub2 != aDoub1)  SLS_FAIL;
	if (aDoub.size() != 0) SLS_FAIL;
	if (aDoub.n0() != 0) SLS_FAIL;
	if (aDoub.n1() != 0) SLS_FAIL;
	a3Doub2 << a3Doub;
	if (a3Doub2 != a3Doub1) SLS_FAIL;
	if (a3Doub.size() != 0) SLS_FAIL;
	if (a3Doub.n0() != 0) SLS_FAIL;
	if (a3Doub.n1() != 0) SLS_FAIL;
	if (a3Doub.n2() != 0) SLS_FAIL;
	c3Doub2 << c3Doub;
	if (c3Doub2 != c3Doub1) SLS_FAIL;
	if (a3Doub.size() != 0) SLS_FAIL;
	if (a3Doub.n0() != 0) SLS_FAIL;
	if (a3Doub.n1() != 0) SLS_FAIL;
	if (a3Doub.n2() != 0) SLS_FAIL;

	// end()
	vDoub1[vDoub1.size()-1] = 3.1;
	if (vDoub1.end() != 3.1)  SLS_FAIL;
	if (vDoub1.end(1) != 3.1)  SLS_FAIL;
	aDoub1[aDoub1.size()-1] = 3.1;
	if (aDoub1.end() != 3.1)  SLS_FAIL;
	if (aDoub1.end(1) != 3.1)  SLS_FAIL;
	a3Doub1[a3Doub1.size()-1] = 3.1;
	if (a3Doub1.end() != 3.1)  SLS_FAIL;
	if (a3Doub1.end(1) != 3.1)  SLS_FAIL;
	c3Doub1[c3Doub1.size() - 1] = 3.1;
	if (c3Doub1.end() != 3.1)  SLS_FAIL;
	if (c3Doub1.end(1) != 3.1)  SLS_FAIL;
	vDoub1[vDoub1.size()-2] = 3.2;
	if (vDoub1.end(2) != 3.2)  SLS_FAIL;
	aDoub1[aDoub1.size()-2] = 3.2;
	if (aDoub1.end(2) != 3.2)  SLS_FAIL;
	a3Doub1[a3Doub1.size()-2] = 3.2;
	if (a3Doub1.end(2) != 3.2)  SLS_FAIL;
	c3Doub1[c3Doub1.size() - 2] = 3.2;
	if (c3Doub1.end(2) != 3.2)  SLS_FAIL;

	// operator()
	vDoub1[vDoub1.size()-1] = 5.5;
	if (vDoub1[vDoub1.size()-1] != 5.5 ) SLS_FAIL;
	if (vDoub1.end() != 5.5)  SLS_FAIL;
	aDoub1(aDoub1.n0()-1, aDoub1.n1()-1) = 5.5;
	if (aDoub1(aDoub1.n0()-1, aDoub1.n1()-1) != 5.5 ) SLS_FAIL;
	if (aDoub1.end() != 5.5)  SLS_FAIL;
	a3Doub1(a3Doub1.n0()-1, a3Doub1.n1()-1, a3Doub1.n2()-1) = 5.5;
	if (a3Doub1(a3Doub1.n0()-1, a3Doub1.n1()-1, a3Doub1.n2()-1) != 5.5 ) SLS_FAIL;
	if (a3Doub1.end() != 5.5)  SLS_FAIL;

	Cmat3Doub c3d(2, 3, 4);
	linspace(c3d, 1, 24);
	if (c3d(0, 0, 0) != 1 || c3d(1,0,0) != 2)
		SLS_FAIL;
	if (c3d(0, 1, 0) != 3 || c3d(0, 2, 0) != 5)
		SLS_FAIL;
	if (c3d(0, 0, 1) != 7 || c3d(0, 0, 2) != 13)
		SLS_FAIL;

	
	// test WorkSpace
	{
		WorkSpace wsp(1024);
		SLS_ASSERT(wsp.size() == 1024);
		SLS_ASSERT((size_t)wsp.p() > 0);
		SLS_ASSERT(wsp.align() == 64);
		SLS_ASSERT(wsp.used() == 0);

		auto svd = wsp.SvecDoub(5);
		SLS_ASSERT(svd.size() == 5);
		SLS_ASSERT((size_t)svd.p() > (size_t)wsp.p());
		SLS_ASSERT(wsp.used() > svd.size()*(Long)sizeof(Doub));

		auto scmc = wsp.ScmatComp(2,2);
		SLS_ASSERT(scmc.size() == 4);
		SLS_ASSERT((size_t)scmc.p() > (size_t)svd.p());
		SLS_ASSERT(wsp.used() > svd.size()*(Long)sizeof(Doub) + scmc.size()*(Long)sizeof(Comp));
	}
}

#ifndef SLS_TEST_ALL
int main() { test_dense(); }
#endif
