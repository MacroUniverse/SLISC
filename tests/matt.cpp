#define SLS_RAND_SEED 0
#include "../SLISC/arith/arith4.h"
#include "../SLISC/file/matt.h"
#include "../SLISC/util/random.h"
// #include "../SLISC/str/disp.h"

void test_matt()
{
	using namespace slisc;

	// write to file
	Matt matt;
	if (file_exist("test.matt"))
		remove("test.matt");
	matt.open("test.matt", "w");

	// scalars
	Char s8 = 88;
	save(s8, "s8", matt);

	Int si = 99;
	save(si, "si", matt);

	Doub s(3.14159265358979323);
	save(s, "s", matt);

	Comp sc(s, -s);
	save(sc, "sc", matt);

	// TODO
	// vectors
	// VecChar v8(3);
	// v8[0] = 1; v8[1] = 2; v8[2] = 3;
	// save(v8, "v8", matt);

	VecInt vi(3);
	vi[0] = 1; vi[1] = 2; vi[2] = 3;
	save(vi, "vi", matt);
	VecDoub v(3);
	v[0] = 1.; v[1] = 2.; v[2] = 3.;
	save(v, "v", matt);
	VecComp vc(3);
	for (Int i = 0; i < 3; ++i)
		vc[i] = 1 + (Doub)i - I * (Doub)i;
	save(vc, "vc", matt);

	vecDoub vd(3); vd[0] = 1.1; vd[1] = 2.2; vd[2] = 3.3;
	save(vd, "vd", matt);

	// matrices

	CmatInt AI(2, 3); copy(AI, 0);
	AI(0, 0) = 1; AI(0, 1) = 3; AI(0, 2) = 5; AI(1, 2) = 11;
	save(AI, "AI", matt);

	CmatDoub A(2, 3); copy(A, 0);
	A(0, 0) = 1; A(0, 1) = 3; A(0, 2) = 5; A(1, 2) = 11;
	save(A, "A", matt);

	CmatComp C(3, 3);
	Comp *pC{ &C(0, 0) };
	for (Int i = 0; i < 9; ++i) {
		pC[i] = 1 + (Doub)i + I * (Doub)i;
	}
	save(C, "C", matt);

	// 3d arrays
	// Cmat3Doub A3(2, 2, 2);
	// for (Int i = 0; i < 8; ++i)
	//     A3[i] = 1. + (Doub)i;
	// save(A3, "A3", matt);

	// Cmat3Comp C3(2, 2, 2);
	// for (Int i = 0; i < 8; ++i)
	//     C3[i] = Comp(1. + (Doub)i, (Doub)i);
	// save(C3, "C3", matt);

	Cmat3Comp CC3(10, 12, 15);
	for (Int i = 0; i < CC3.size(); ++i)
		CC3[i] = Comp(randDoub(), randDoub());
	save(CC3, "CC3", matt);

	matt.close();

	// read test

	// scalars
	matt.open("test.matt", "r");

	Int r_si;
	load(r_si, "si", matt);
	if (r_si != si) SLS_FAIL;

	Doub r_s;
	load(r_s, "s", matt);
	if (r_s != s) SLS_FAIL;

	Comp r_sc;
	load(r_sc, "sc", matt);
	if (r_sc != sc) SLS_FAIL;

	// vectors
	// TODO: Char
	
	VecInt r_vi(0);
	load(r_vi, "vi", matt);
	if (r_vi != vi) SLS_FAIL;

	VecDoub r_v(0);
	load(r_v, "v", matt);
	if (r_v != v) SLS_FAIL;

	VecComp r_vc(0);
	load(r_vc, "vc", matt);
	if (r_vc != vc) SLS_FAIL;

	VecDoub r_vd(0);
	load(r_vd, "vd", matt);
	if (r_vd[0] != 1.1 || r_vd[1] != 2.2 || r_vd[2] != 3.3)
		SLS_FAIL;

	// matrices
	// TODO: Char

	CmatInt r_AI(0,0);
	load(r_AI, "AI", matt);
	if (r_AI != AI) SLS_FAIL;

	CmatDoub r_A(0,0);
	load(r_A, "A", matt);
	if (r_A != A) SLS_FAIL;

	CmatComp r_C(0,0);
	load(r_C, "C", matt);
	if (r_C != C) SLS_FAIL;

	// 3D arrays
	// Cmat3Doub r_A3(0,0,0);
	// load(r_A3, "A3", matt);
	// if (r_A3 != A3) SLS_FAIL;

	// Cmat3Comp r_C3(0,0,0);
	// load(r_C3, "C3", matt);
	// if (r_C3 != C3) SLS_FAIL;

	Cmat3Comp r_CC3(0, 0, 0);
	load(r_CC3, "CC3", matt);
	cout.precision(18);
	if (r_CC3 != CC3) SLS_FAIL;

	matt.close();
}

#ifndef SLS_TEST_ALL
int main() { test_matt(); }
#endif
