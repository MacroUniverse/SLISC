#include "../SLISC/file/matb.h"
#include "../SLISC/util/random.h"
#include "../SLISC/str/disp.h"
#include "../SLISC/util/sha1sum.h"

void test_matb()
{
#if !(defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__) || defined(__MSYS__))
	using namespace slisc;

	// write to file
	Matb matb;
	if (file_exist("test.matb"))
		remove("test.matb");
	matb.open("test.matb", "w");

	// scalars
	Char s8 = 88;
	save(s8, "s8", matb);

	Int si = 99;
	save(si, "si", matb);

	Doub s(3.14159265358979323);
	save(s, "s", matb);

	Comp sc(s, -s);
	save(sc, "sc", matb);

#ifdef SLS_USE_QUAD_MATH
	Qdoub sq(-1.234567890223456789032345678904234567);
	save(sq, "sq", matb);

	Qcomp scq(sq, -sq);
	save(scq, "scq", matb);
#endif

	// TODO
	// vectors
	// VecChar v8(3);
	// v8[0] = 1; v8[1] = 2; v8[2] = 3;
	// save(v8, "v8", matb);

	VecInt vi(3);
	vi[0] = 1; vi[1] = 2; vi[2] = 3;
	save(vi, "vi", matb);

	VecDoub v(3);
	v[0] = 1.; v[1] = 2.; v[2] = 3.;
	save(v, "v", matb);
	VecComp vc(3);
	for (Long i = 0; i < 3; ++i)
		vc[i] = 1 + (Doub)i - I * (Doub)i;
	save(vc, "vc", matb);
	vecDoub vd(3); vd[0] = 1.1; vd[1] = 2.2; vd[2] = 3.3;
	save(vd, "vd", matb);

#ifdef SLS_USE_QUAD_MATH
	VecQdoub vq(3);
	vq[0] = 1.Q; vq[1] = 2.Q; vq[2] = 3.Q;
	save(vq, "vq", matb);

	VecQcomp vcq(3);
	for (Long i = 0; i < 3; ++i)
		vcq[i] = 1 + (Qdoub)i - Iq * (Qdoub)i;
	save(vcq, "vcq", matb);

	vecQdoub vdq(3); vdq[0] = 1.1Q; vdq[1] = 2.2Q; vdq[2] = 3.3Q;
	save(vdq, "vdq", matb);
#endif

	// matrices
	MatInt AI(2, 3); copy(AI, 0);
	AI(0, 0) = 1; AI(0, 1) = 3; AI(0, 2) = 5; AI(1, 2) = 11;
	save(AI, "AI", matb);

	MatDoub A(2, 3); copy(A, 0);
	A(0, 0) = 1; A(0, 1) = 3; A(0, 2) = 5; A(1, 2) = 11;
	save(A, "A", matb);

	MatComp C(3, 3);
	for (Long i = 0; i < 9; ++i)
		C[i] = 1 + Comp(i,i);
	save(C, "C", matb);

	CmatDoub CD(2, 3); copy(CD, 0);
	CD(0, 0) = 1; CD(0, 1) = 3; CD(0, 2) = 5; CD(1, 2) = 11;
	save(CD, "CD", matb);

	CmatComp CC(3, 3);
	for (Long i = 0; i < 9; ++i)
		CC[i] = 1 + Comp(i,i);
	save(CC, "CC", matb);

#ifdef SLS_USE_QUAD_MATH
	CmatQdoub CDQ(2, 3); copy(CDQ, 0);
	CDQ(0, 0) = 1; CDQ(0, 1) = 3; CDQ(0, 2) = 5; CDQ(1, 2) = 11;
	save(CDQ, "CDQ", matb);

	CmatQcomp CCQ(3, 3);
	for (Long i = 0; i < 9; ++i)
		CCQ[i] = 1 + Qcomp(i,i);
	save(CCQ, "CCQ", matb);
#endif

	// 3d arrays
	Mat3Doub A3(2, 2, 2);
	for (Long i = 0; i < 8; ++i)
		A3[i] = 1. + (Doub)i;
	save(A3, "A3", matb);

	Mat3Comp C3(2, 2, 2);
	for (Long i = 0; i < 8; ++i)
		C3[i] = Comp(1. + (Doub)i, (Doub)i);
	save(C3, "C3", matb);

	Cmat3Doub CD3(10, 12, 15);
	for (Long i = 0; i < CD3.size(); ++i)
		CD3[i] = randDoub();
	save(CD3, "CD3", matb);

	Cmat3Comp CC3(10, 12, 15);
	for (Long i = 0; i < CC3.size(); ++i)
		CC3[i] = Comp(randDoub(), randDoub());
	save(CC3, "CC3", matb);

#ifdef SLS_USE_QUAD_MATH
	Cmat3Qdoub CD3Q(10, 12, 15);
	for (Long i = 0; i < CD3.size(); ++i)
		CD3Q[i] = randQdoub();
	save(CD3Q, "CD3Q", matb);

	Cmat3Qcomp CC3Q(10, 12, 15);
	for (Long i = 0; i < CC3Q.size(); ++i)
		CC3Q[i] = Qcomp(randQdoub(), randQdoub());
	save(CC3Q, "CC3Q", matb);
#endif

	matb.close();


	// test 'm' mode
	{
		matb.open("test.matb", "m");
		matb.read_data();
		matb.write_data("test1.matb");
		matb.close();
	}

	// -----------  read test -------------

	// scalars
	matb.open("test1.matb", "r");


	Int r_si;
	load(r_si, "si", matb);
	if (r_si != si) SLS_FAIL;

	Doub r_s;
	load(r_s, "s", matb);
	if (abs(r_s-s) != 0) SLS_FAIL;

	Comp r_sc;
	load(r_sc, "sc", matb);
	if (abs(r_sc-sc) != 0) SLS_FAIL;

#ifdef SLS_USE_QUAD_MATH
	Qdoub r_sq;
	load(r_sq, "sq", matb);
	SLS_ASSERT(r_sq == sq);

	Qcomp r_scq;
	load(r_scq, "scq", matb);
	SLS_ASSERT(r_scq == scq);
#endif

	// vectors
	// TODO: Char

	VecInt r_vi;
	load(r_vi, "vi", matb);
	if (r_vi != vi)
		SLS_FAIL;

	VecDoub r_v;
	load(r_v, "v", matb);
	r_v -= v;
	if (norm(r_v) != 0)
		SLS_FAIL;

	VecComp r_vc;
	load(r_vc, "vc", matb);
	r_vc -= vc;
	if (norm(r_v) != 0)
		SLS_FAIL;

	VecDoub r_vd;
	load(r_vd, "vd", matb);
	if (r_vd[0] != 1.1 || r_vd[1] != 2.2 || r_vd[2] != 3.3)
		SLS_FAIL;

#ifdef SLS_USE_QUAD_MATH
	VecQdoub r_vq;
	load(r_vq, "vq", matb);
	SLS_ASSERT(r_vq == vq);

	VecQcomp r_vcq;
	load(r_vcq, "vcq", matb);
	SLS_ASSERT(r_vcq == vcq);

	vecQdoub r_vdq;
	load(r_vdq, "vdq", matb);
	SLS_ASSERT(r_vdq == vdq);
#endif

	// matrices
	// TODO: Char

	MatInt r_AI(0,0);
	load(r_AI, "AI", matb);
	if (r_AI != AI) SLS_FAIL;

	MatDoub r_A(0,0);
	load(r_A, "A", matb);
	r_A -= A;
	if (norm(r_A) != 0) SLS_FAIL;

	MatComp r_C(0,0);
	load(r_C, "C", matb);
	r_C -= C;
	if (norm(r_C) != 0) SLS_FAIL;

	CmatDoub r_CD;
	load(r_CD, "CD", matb);
	SLS_ASSERT(r_CD == CD);

	CmatComp r_CC;
	load(r_CC, "CC", matb);
	SLS_ASSERT(r_CC == CC);

#ifdef SLS_USE_QUAD_MATH
	CmatQdoub r_CDQ;
	load(r_CDQ, "CDQ", matb);
	SLS_ASSERT(r_CDQ == CDQ);

	CmatQcomp r_CCQ;
	load(r_CCQ, "CCQ", matb);
	SLS_ASSERT(r_CCQ == CCQ);
#endif

	// 3D arrays
	Mat3Doub r_A3;
	load(r_A3, "A3", matb);
	SLS_ASSERT(r_A3 == A3);

	Mat3Comp r_C3;
	load(r_C3, "C3", matb);
	r_C3 -= C3;
	SLS_ASSERT(norm(r_C3) == 0);

	Cmat3Doub r_CD3;
	load(r_CD3, "CD3", matb);
	SLS_ASSERT(r_CD3 == CD3);

	Cmat3Comp r_CC3;
	load(r_CC3, "CC3", matb);
	SLS_ASSERT(r_CC3 == CC3);

#ifdef SLS_USE_QUAD_MATH
	Cmat3Qdoub r_CD3Q;
	load(r_CD3Q, "CD3Q", matb);
	SLS_ASSERT(r_CD3Q == CD3Q);

	Cmat3Qcomp r_CC3Q;
	load(r_CC3Q, "CC3Q", matb);
	SLS_ASSERT(r_CC3Q == CC3Q);
#endif

	// matb2matt: convert matb to matt
#ifndef SLS_USE_QUAD_MATH
	{
		remove("test.matt");
		matb2matt("test.matb");

		Matt matt("test.matt", "r");

		Int r_si;
		load(r_si, "si", matt);
		if (r_si != si) SLS_FAIL;

		Doub r_s;
		load(r_s, "s", matt);
		if (abs(r_s-s) > 1e-15) SLS_FAIL;

		Comp r_sc;
		load(r_sc, "sc", matt);
		if (abs(r_sc-sc) > 1e-15) SLS_FAIL;

		// vectors
		// TODO: Char
		
		VecInt r_vi;
		load(r_vi, "vi", matt);
		if (r_vi != vi) SLS_FAIL;

		VecDoub r_v;
		load(r_v, "v", matt);
		r_v -= v;
		if (norm(r_v) > 1e-15) SLS_FAIL;

		VecComp r_vc;
		load(r_vc, "vc", matt);
		r_vc -= vc;
		if (norm(r_v) > 1e-15) SLS_FAIL;

		// matrices
		// TODO: Char

		MatInt r_AI(0,0);
		load(r_AI, "AI", matt);
		if (r_AI != AI) SLS_FAIL;

		MatDoub r_A(0,0);
		load(r_A, "A", matt);
		r_A -= A;
		if (norm(r_A) > 1e-15) SLS_FAIL;

		MatComp r_C(0,0);
		load(r_C, "C", matt);
		r_C -= C;
		if (norm(r_C) > 1e-15) SLS_FAIL;

		// 3D arrays
		// Mat3Doub r_A3(0,0,0);
		// load(r_A3, "A3", matt);
		// r_A3 -= A3;
		// if (norm(r_A3) > 1e-15) SLS_FAIL;

		// Mat3Comp r_C3(0,0,0);
		// load(r_C3, "C3", matt);
		// r_C3 -= C3;
		// if (norm(r_C3) > 1e-15) SLS_FAIL;

		Cmat3Comp r_CC3;
		load(r_CC3, "CC3", matt);
		r_CC3 -= CC3;
		if (norm(r_CC3) > 1e-15) SLS_FAIL;

		matt.close();
	}

	// matt2matb: convert matt to matb
	{
		remove("test.matb");
		matt2matb("test.matt");

		Matb matb("test.matb", "r");

		Int r_si;
		load(r_si, "si", matb);
		if (r_si != si) SLS_FAIL;

		Doub r_s;
		load(r_s, "s", matb);
		if (abs(r_s-s) > 1e-15) SLS_FAIL;

		Comp r_sc;
		load(r_sc, "sc", matb);
		if (abs(r_sc-sc) > 1e-15) SLS_FAIL;

		// vectors
		// TODO: Char
		
		VecInt r_vi;
		load(r_vi, "vi", matb);
		if (r_vi != vi) SLS_FAIL;

		VecDoub r_v;
		load(r_v, "v", matb);
		r_v -= v;
		if (norm(r_v) > 1e-15) SLS_FAIL;

		VecComp r_vc;
		load(r_vc, "vc", matb);
		r_vc -= vc;
		if (norm(r_v) > 1e-15) SLS_FAIL;

		// matrices
		// TODO: Char

		MatInt r_AI(0,0);
		load(r_AI, "AI", matb);
		if (r_AI != AI) SLS_FAIL;

		MatDoub r_A(0,0);
		load(r_A, "A", matb);
		r_A -= A;
		if (norm(r_A) > 1e-15) SLS_FAIL;

		MatComp r_C(0,0);
		load(r_C, "C", matb);
		r_C -= C;
		if (norm(r_C) > 1e-15) SLS_FAIL;

		// 3D arrays
		// Mat3Doub r_A3(0,0,0);
		// load(r_A3, "A3", matb);
		// r_A3 -= A3;
		// if (norm(r_A3) > 1e-15) SLS_FAIL;

		// Mat3Comp r_C3(0,0,0);
		// load(r_C3, "C3", matb);
		// r_C3 -= C3;
		// if (norm(r_C3) > 1e-15) SLS_FAIL;

		Cmat3Doub r_CD3;
		load(r_CD3, "CD3", matb);
		SLS_ASSERT(r_CD3 == CD3);

		Cmat3Comp r_CC3;
		load(r_CC3, "CC3", matb);
		SLS_ASSERT(r_CC3 == CC3);

		matb.close();
	}
#endif

#ifdef SLS_USE_QUAD_MATH
	// matb_q2d: convert all Qdoub and Qcomp to Doub and Comp
	{
		// scalars
		remove("q2d-test.matb");
		matb_q2d("test.matb", true);
		Matb matb("q2d-test.matb", "r");

		Int r_si;
		load(r_si, "si", matb);
		if (r_si != si) SLS_FAIL;

		Doub r_s;
		load(r_s, "s", matb);
		if (abs(r_s-s) != 0) SLS_FAIL;

		Comp r_sc;
		load(r_sc, "sc", matb);
		if (abs(r_sc-sc) != 0) SLS_FAIL;

	#ifdef SLS_USE_QUAD_MATH
		Doub r_sq;
		load(r_sq, "sq", matb);
		SLS_ASSERT(r_sq == Doub(sq));

		Comp r_scq;
		load(r_scq, "scq", matb);
		SLS_ASSERT(r_scq == Comp(scq.real(), scq.imag()));
	#endif

		// vectors
		// TODO: Char

		VecInt r_vi;
		load(r_vi, "vi", matb);
		if (r_vi != vi)
			SLS_FAIL;

		VecDoub r_v;
		load(r_v, "v", matb);
		r_v -= v;
		if (norm(r_v) != 0)
			SLS_FAIL;

		VecComp r_vc;
		load(r_vc, "vc", matb);
		r_vc -= vc;
		if (norm(r_v) != 0)
			SLS_FAIL;

		VecDoub r_vd;
		load(r_vd, "vd", matb);
		if (r_vd[0] != 1.1 || r_vd[1] != 2.2 || r_vd[2] != 3.3)
			SLS_FAIL;

	#ifdef SLS_USE_QUAD_MATH
		VecDoub r_vq;
		load(r_vq, "vq", matb);
		SLS_ASSERT(r_vq.size() == vq.size());
		for (Long i = 0; i < r_vq.size(); ++i)
			SLS_ASSERT(r_vq[i] == Doub(vq[i]));

		VecComp r_vcq;
		load(r_vcq, "vcq", matb);
		SLS_ASSERT(r_vcq.size() == vcq.size());
		for (Long i = 0; i < r_vcq.size(); ++i)
			SLS_ASSERT(r_vcq[i] == Comp(vcq[i].real(),vcq[i].imag()));

		vecDoub r_vdq;
		load(r_vdq, "vdq", matb);
		SLS_ASSERT(r_vdq.size() == vdq.size());
		for (Long i = 0; i < size(r_vdq); ++i)
			SLS_ASSERT(r_vdq[i] == Doub(vdq[i]));
	#endif

		// matrices
		// TODO: Char

		MatInt r_AI(0,0);
		load(r_AI, "AI", matb);
		if (r_AI != AI) SLS_FAIL;

		MatDoub r_A(0,0);
		load(r_A, "A", matb);
		r_A -= A;
		if (norm(r_A) != 0) SLS_FAIL;

		MatComp r_C(0,0);
		load(r_C, "C", matb);
		r_C -= C;
		if (norm(r_C) != 0) SLS_FAIL;

		CmatDoub r_CD;
		load(r_CD, "CD", matb);
		SLS_ASSERT(r_CD == CD);

		CmatComp r_CC;
		load(r_CC, "CC", matb);
		SLS_ASSERT(r_CC == CC);

	#ifdef SLS_USE_QUAD_MATH
		CmatDoub r_CDQ;
		load(r_CDQ, "CDQ", matb);
		SLS_ASSERT(r_CDQ.n0() == CDQ.n0());
		SLS_ASSERT(r_CDQ.n1() == CDQ.n1());
		for (Long i = 0; i < r_CDQ.size(); ++i)
			SLS_ASSERT(r_CDQ[i] == Doub(CDQ[i]));

		CmatComp r_CCQ;
		load(r_CCQ, "CCQ", matb);
		SLS_ASSERT(r_CCQ.n0() == CCQ.n0());
		SLS_ASSERT(r_CCQ.n1() == CCQ.n1());
		for (Long i = 0; i < r_CCQ.size(); ++i)
			SLS_ASSERT(r_CCQ[i] == Comp(CCQ[i].real(), CCQ[i].imag()));
	#endif

		// 3D arrays
		Mat3Doub r_A3;
		load(r_A3, "A3", matb);
		SLS_ASSERT(r_A3 == A3);

		Mat3Comp r_C3;
		load(r_C3, "C3", matb);
		r_C3 -= C3;
		SLS_ASSERT(norm(r_C3) == 0);

		Cmat3Doub r_CD3;
		load(r_CD3, "CD3", matb);
		SLS_ASSERT(r_CD3 == CD3);

		Cmat3Comp r_CC3;
		load(r_CC3, "CC3", matb);
		SLS_ASSERT(r_CC3 == CC3);

	#ifdef SLS_USE_QUAD_MATH
		Cmat3Doub r_CD3Q;
		load(r_CD3Q, "CD3Q", matb);
		SLS_ASSERT(r_CD3Q.n0() == CD3Q.n0());
		SLS_ASSERT(r_CD3Q.n1() == CD3Q.n1());
		SLS_ASSERT(r_CD3Q.n1() == CD3Q.n1());
		for (Long i = 0; i < CD3Q.size(); ++i)
			SLS_ASSERT(r_CD3Q[i] == Doub(CD3Q[i]));

		Cmat3Comp r_CC3Q;
		load(r_CC3Q, "CC3Q", matb);
		SLS_ASSERT(r_CC3Q.n0() == CC3Q.n0());
		SLS_ASSERT(r_CC3Q.n1() == CC3Q.n1());
		SLS_ASSERT(r_CC3Q.n1() == CC3Q.n1());
		for (Long i = 0; i < CC3Q.size(); ++i)
			SLS_ASSERT(r_CC3Q[i] == Comp(CC3Q[i].real(),CC3Q[i].imag()));
	#endif
	}
#endif

#else
	std::cout << "---------- disabled! ----------" << std::endl;
#endif
}
