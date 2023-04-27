#include "../SLISC/file/matfile.h"
#include "../SLISC/util/random.h"
// #include "../SLISC/str/disp.h"

void test_matfile()
{
	using namespace slisc;
#ifdef SLS_USE_MATFILE
	// write to file
	if (file_exist("test.mat"))
		remove("test.mat");
	Mat mat("test.mat", "w", true);
	
	// scalars
	Char c8 = 56;
	save(c8, "c8", mat);

	Uchar s8 = 88;
	save(s8, "s8", mat);

	Int si = 99;
	save(si, "si", mat);

	Llong sl = 123456;
	save(sl, "sl", mat);

	Doub s(3.14159265358979323);
	save(s, "s", mat);

	Comp sc(s, -s);
	save(sc, "sc", mat);

	// vectors
	VecChar v8(3);
	v8[0] = 1; v8[1] = 2; v8[2] = 3;
	save(v8, "v8", mat);

	VecInt vi(3);
	vi[0] = 1; vi[1] = 2; vi[2] = 3;
	save(vi, "vi", mat);

	VecLlong vl(3);
	vl[0] = 1; vl[1] = 2; vl[2] = 3;
	save(vl, "vl", mat);

	VecDoub v(3);
	v[0] = 1.; v[1] = 2.; v[2] = 3.;
	save(v, "v", mat);

	VecComp vc(3);
	for (Int i = 0; i < 3; ++i)
		vc[i] = 1 + (Doub)i - I * (Doub)i;
	save(vc, "vc", mat);

	// vecDoub vd(3); vd[0] = 1.1; vd[1] = 2.2; vd[2] = 3.3;
	// save(vd, "vd", mat);

	// matrices

	CmatInt AI(2, 3); copy(AI, 0);
	AI(0, 0) = 1; AI(0, 1) = 3; AI(0, 2) = 5; AI(1, 2) = 11;
	save(AI, "AI", mat);

	CmatLlong AL(2, 3); copy(AL, 0);
	AL(0, 0) = 1; AL(0, 1) = 3; AL(0, 2) = 5; AL(1, 2) = 11;
	save(AL, "AL", mat);

	CmatDoub A(2, 3); copy(A, 0);
	A(0, 0) = 1; A(0, 1) = 3; A(0, 2) = 5; A(1, 2) = 11;
	save(A, "A", mat);

	CmatComp C(3, 3);
	for (Int i = 0; i < 9; ++i)
		C[i] = 1 + (Doub)i + I * (Doub)i;
	save(C, "C", mat);

	// 3d arrays
	Cmat3Llong A3L(2, 2, 2);
	for (Int i = 0; i < 8; ++i)
		A3L[i] = 1. + (Doub)i;
	save(A3L, "A3L", mat);

	Cmat3Doub A3(2, 2, 2);
	for (Int i = 0; i < 8; ++i)
		A3[i] = 1. + (Doub)i;
	save(A3, "A3", mat);

	Cmat3Comp CC3(10, 12, 15);
	for (Int i = 0; i < CC3.size(); ++i)
		CC3[i] = Comp(randDoub(), randDoub());
	save(CC3, "CC3", mat);

	mat.close();

	// // -----------  read test -------------

	// scalars
	mat.open("test.mat", "r");

	Char r_c8;
	load(r_c8, "c8", mat);
	if (r_c8 != c8) SLS_FAIL;

	Uchar r_s8;
	load(r_s8, "s8", mat);
	if (r_s8 != s8) SLS_FAIL;

	Int r_si;
	load(r_si, "si", mat);
	if (r_si != si) SLS_FAIL;

	Llong r_sl;
	load(r_sl, "sl", mat);
	if (r_sl != sl) SLS_FAIL;

	Doub r_s;
	load(r_s, "s", mat);
	if (r_s != s) SLS_FAIL;

	Comp r_sc;
	load(r_sc, "sc", mat);
	if (r_sc != sc) SLS_FAIL;

	// vectors
	VecChar r_v8;
	load(r_v8, "v8", mat);
	if (r_v8 != v8) SLS_FAIL;

	VecInt r_vi;
	load(r_vi, "vi", mat);
	if (r_vi != vi) SLS_FAIL;

	VecLlong r_vl;
	load(r_vl, "vl", mat);
	if (r_vl != vl) SLS_FAIL;

	VecDoub r_v;
	load(r_v, "v", mat);
	if (r_v != v) SLS_FAIL;

	VecComp r_vc;
	load(r_vc, "vc", mat);
	if (r_vc != vc) SLS_FAIL;

	// matrices

	CmatInt r_AI;
	load(r_AI, "AI", mat);
	if (r_AI != AI) SLS_FAIL;

	CmatLlong r_AL;
	load(r_AL, "AL", mat);
	if (r_AL != AL) SLS_FAIL;

	CmatDoub r_A;
	load(r_A, "A", mat);
	if (r_A != A) SLS_FAIL;

	CmatComp r_C;
	load(r_C, "C", mat);
	if (r_C != C) SLS_FAIL;

	// 3D arrays
	Cmat3Llong r_A3L;
	load(r_A3L, "A3L", mat);
	if (r_A3L != A3L) SLS_FAIL;

	Cmat3Doub r_A3;
	load(r_A3, "A3", mat);
	if (r_A3 != A3) SLS_FAIL;

	Cmat3Comp r_CC3;
	load(r_CC3, "CC3", mat);
	if (r_CC3 != CC3) SLS_FAIL;

	mat.close();

	// // matb2matt: convert mat to matt
	// {
	//     remove("test.matt");
	//     matb2matt("test.mat");

	//     Matt matt("test.matt", "r");

	//     Int r_si;
	//     load(r_si, "si", matt);
	//     if (r_si != si) SLS_FAIL;

	//     Doub r_s;
	//     load(r_s, "s", matt);
	//     if (abs(r_s-s) > 1e-15) SLS_FAIL;

	//     Comp r_sc;
	//     load(r_sc, "sc", matt);
	//     if (abs(r_sc-sc) > 1e-15) SLS_FAIL;

	//     // vectors
	//     // TODO: Char
		
	//     VecInt r_vi(0);
	//     load(r_vi, "vi", matt);
	//     if (r_vi != vi) SLS_FAIL;

	//     VecDoub r_v(0);
	//     load(r_v, "v", matt);
	//     r_v -= v;
	//     if (norm(r_v) > 1e-15) SLS_FAIL;

	//     VecComp r_vc(0);
	//     load(r_vc, "vc", matt);
	//     r_vc -= vc;
	//     if (norm(r_v) > 1e-15) SLS_FAIL;

	//     // matrices
	//     // TODO: Char

	//     MatInt r_AI(0,0);
	//     load(r_AI, "AI", matt);
	//     if (r_AI != AI) SLS_FAIL;

	//     MatDoub r_A(0,0);
	//     load(r_A, "A", matt);
	//     r_A -= A;
	//     if (norm(r_A) > 1e-15) SLS_FAIL;

	//     MatComp r_C(0,0);
	//     load(r_C, "C", matt);
	//     r_C -= C;
	//     if (norm(r_C) > 1e-15) SLS_FAIL;

	//     // 3D arrays
	//     // Mat3Doub r_A3(0,0,0);
	//     // load(r_A3, "A3", matt);
	//     // r_A3 -= A3;
	//     // if (norm(r_A3) > 1e-15) SLS_FAIL;

	//     // Mat3Comp r_C3(0,0,0);
	//     // load(r_C3, "C3", matt);
	//     // r_C3 -= C3;
	//     // if (norm(r_C3) > 1e-15) SLS_FAIL;

	//     Cmat3Comp r_CC3(0, 0, 0);
	//     load(r_CC3, "CC3", matt);
	//     r_CC3 -= CC3;
	//     if (norm(r_CC3) > 1e-15) SLS_FAIL;

	//     matt.close();
	// }

	// // matt2matb: convert matt to mat
	// {
	//     remove("test.mat");
	//     matt2matb("test.matt");

	//     Matb mat("test.mat", 'r');

	//     Int r_si;
	//     load(r_si, "si", mat);
	//     if (r_si != si) SLS_FAIL;

	//     Doub r_s;
	//     load(r_s, "s", mat);
	//     if (abs(r_s-s) > 1e-15) SLS_FAIL;

	//     Comp r_sc;
	//     load(r_sc, "sc", mat);
	//     if (abs(r_sc-sc) > 1e-15) SLS_FAIL;

	//     // vectors
	//     // TODO: Char
		
	//     VecInt r_vi(0);
	//     load(r_vi, "vi", mat);
	//     if (r_vi != vi) SLS_FAIL;

	//     VecDoub r_v(0);
	//     load(r_v, "v", mat);
	//     r_v -= v;
	//     if (norm(r_v) > 1e-15) SLS_FAIL;

	//     VecComp r_vc(0);
	//     load(r_vc, "vc", mat);
	//     r_vc -= vc;
	//     if (norm(r_v) > 1e-15) SLS_FAIL;

	//     // matrices
	//     // TODO: Char

	//     MatInt r_AI(0,0);
	//     load(r_AI, "AI", mat);
	//     if (r_AI != AI) SLS_FAIL;

	//     MatDoub r_A(0,0);
	//     load(r_A, "A", mat);
	//     r_A -= A;
	//     if (norm(r_A) > 1e-15) SLS_FAIL;

	//     MatComp r_C(0,0);
	//     load(r_C, "C", mat);
	//     r_C -= C;
	//     if (norm(r_C) > 1e-15) SLS_FAIL;

	//     // 3D arrays
	//     // Mat3Doub r_A3(0,0,0);
	//     // load(r_A3, "A3", mat);
	//     // r_A3 -= A3;
	//     // if (norm(r_A3) > 1e-15) SLS_FAIL;

	//     // Mat3Comp r_C3(0,0,0);
	//     // load(r_C3, "C3", mat);
	//     // r_C3 -= C3;
	//     // if (norm(r_C3) > 1e-15) SLS_FAIL;

	//     Cmat3Comp r_CC3(0, 0, 0);
	//     load(r_CC3, "CC3", mat);
	//     r_CC3 -= CC3;
	//     if (norm(r_CC3) > 1e-15) SLS_FAIL;

	//     mat.close();
	// }
#else
	cout << "---------- disabled! ----------" << endl;
#endif
}

#ifndef SLS_TEST_ALL
int main() { test_matfile(); }
#endif
