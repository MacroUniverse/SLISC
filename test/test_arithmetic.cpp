#include "../SLISC/arith/arithmetic.h"
#include "../SLISC/util/random.h"
#include "../SLISC/algo/sort.h"
// #include "../SLISC/str/disp.h"

void test_arithmetic()
{
	using namespace slisc;

	// resize_cpy()
	{
		Long N = 4;
		VecDoub v(N), v1(N); linspace(v, 1, N);
		copy(v1, v);
		resize_cpy(v, 2*N);
		SLS_ASSERT(equals_vv(v.p(), v1.p(), N));
	}

	// linspace()
	{
		Long N = 3;
		VecDoub v(N), v1(N); v[0] = 0; v[1] = 1; v[2] = 2;
		linspace(v1, 0, N-1);
		SLS_ASSERT(equals_vv(v.p(), v1.p(), N));
	}

	// reorder()
	{
		VecLlong v(4), order(4); linspace(v, 0, 3);
		order[0] = 2; order[1] = 1; order[2] = 0; order[3] = 3;
		reorder(v, order);
		SLS_ASSERT(v == order);
	}
	
	// mul_gen()
	{
		Long N1 = 4, N2 = 5;
		CmatDoub a(N1, N2);
		VecDoub x(N2), y(N1), y1(N1);
		linspace(x, 1, N2);
		linspace(a, 1, N1*N2);
		mul_gen(y, a, x);
		mul(y1, a, x);
		SLS_ASSERT(y == y1);
	}

	// mul_sym()
	{
#ifdef SLS_USE_CBLAS
		Long N = 5;
		CmatDoub a(N, N);
		VecDoub x(N), y(N), y1(N);
		linspace(x, 1, N);
		linspace(a, 1, N*N);
		mul_sym(y, a, x);
		for (Long i = 0; i < N; ++i)
			for (Long j = i+1; j < N; ++j)
				a(j, i) = a(i, j);
		mul(y1, a, x);
		SLS_ASSERT(y == y1);
		
		VecComp xc(N), yc(N), yc1(N);
		linspace(xc, Comp(1,1), Comp(N,N));
		linspace(a, 1, N*N);
		mul_sym(yc, a, xc);
		for (Long i = 0; i < N; ++i)
			for (Long j = i+1; j < N; ++j)
				a(j, i) = a(i, j);
		mul(yc1, a, xc);
		SLS_ASSERT(y == y1);
#endif
	}

	// quad precision mul
#ifdef SLS_USE_QUAD_MATH
	{
		CmatQdoub a(2, 3);
		VecQdoub x(3), y(2);
		rand(x); rand(a);
		mul(y, a, x);
	}
#endif

	// trans()
	{
		Long N = 4;
		CmatDoub a(N, N), b(N, N);
		linspace(a, 1, N*N); copy(b, a);
		trans(a); trans(a);
		SLS_ASSERT(a == b);

		Long N1 = 5, N2 = 6;
		CmatDoub c(N1, N2), d(N2, N1), e(N1, N2);
		linspace(c, 1, N1*N2);
		copy(e, c);
		trans(d, c); trans(c, d);
		SLS_ASSERT(c == e);
	}

	// test shape_cmp
	{
		SLS_ASSERT(shape_cmp(Mat3Doub(7, 3, 5), Mat3Comp(7, 3, 5)));
	}

	// copy from column major matrix to vector
	{
		CmatInt a(3, 4);
		linspace(a, 1, 12);
		VecInt vc(3), vr(4);
		for (Long i = 0; i < 3; ++i) {
			copy(vr, cut1(a, i));
			for (Long j = 0; j < 4; ++j) {
				SLS_ASSERT(vr[j] == a(i, j));
			}
		}
		for (Long j = 0; j < 4; ++j) {
			copy(vc, cut0(a, j));
			for (Long i = 0; i < 3; ++i) {
				SLS_ASSERT(vc[i] == a(i, j));
			}
		}
	}
	// copy from row major matrix to vector
	{
		MatInt a(3, 4);
		linspace(a, 1, 12);
		VecInt vc(3), vr(4);
		for (Long i = 0; i < 3; ++i) {
			copy(vr, cut1(a, i));
			for (Long j = 0; j < 4; ++j) {
				SLS_ASSERT(vr[j] == a(i, j));
			}
		}
		for (Long j = 0; j < 4; ++j) {
			copy(vc, cut0(a, j));
			for (Long i = 0; i < 3; ++i) {
				SLS_ASSERT(vc[i] == a(i, j));
			}
		}
	}

	// copy between matrices of different major
	{
		Long N1 = 3, N2 = 4;
		CmatDoub a1(N1, N2); rand(a1);
		MatDoub a2(N1, N2);
		copy(a2, a1);
		SLS_ASSERT(a1 == a2);

		rand(a2);
		copy(a1, a2);
		SLS_ASSERT(a1 == a2);
	}
	
	// reorder
	{
		Long N = 10;
		VecLong v1(N), order(N), v2(N);
		rand(v1);
		copy(v2, v1);
		linspace(order, 0, N - 1);
		sort(v1, order);
		reorder(v2, order);
		SLS_ASSERT(v1 == v2);
	}

	// sum, max, max_abs, norm2
	{
		Long ind = 0;
		VecInt a(4); a[0] = 1; a[1] = 0; a[2] = 1; a[3] = 1;
		SLS_ASSERT(sum(a) == Llong(3));

		VecInt b(4); b[0] = 2; b[1] = 3; b[2] = -1; b[3] = 5;
		SLS_ASSERT(sum(b) == 9);
		SLS_ASSERT(max(b) == 5);
		max(ind, b); SLS_ASSERT(ind == 3);
		SLS_ASSERT(max_abs(b) == 5);

		VecDoub c(10); linspace(c, 1., 10.);
		SLS_ASSERT(sum(c) == 55);
		SLS_ASSERT(max(c) == 10.);
		max(ind, c); SLS_ASSERT(ind == 9);
		SLS_ASSERT(max_abs(c) == 10.);
		SLS_ASSERT(norm2(c) == 385.);

		CmatDoub cc(4, 5); linspace(cc, 1, 20);
		DcmatDoub dc = cut(cc, 1, 2, 2, 3);
		SLS_ASSERT(max(dc) == 19 && min(dc) == 10);
		Long i, j;
		SLS_ASSERT(slisc::max2(i, j, dc) == 19 && i == 1 && j == 2 && slisc::min2(i, j, dc) == 10 && i == 0 && j == 0);
		SLS_ASSERT(max_abs(dc) == 19);
		SLS_ASSERT(max_abs(i, j, dc) == 19 && i == 1 && j == 2);

		MatComp d(3, 3); linspace(d, Comp(1., -1.), Comp(9., -9.));
		if (sum(d) != Comp(45.,-45.)) SLS_FAIL;
		if (max_abs(d) != abs(Comp(9,9))) SLS_FAIL;
		if (norm2(d) != 285.*2) SLS_FAIL;

		CmatComp e(3, 3); linspace(e, Comp(1., -1.), Comp(9., -9.));
		if (sum(e) != Comp(45., -45.)) SLS_FAIL;
		if (max_abs(e) != abs(Comp(9, 9))) SLS_FAIL;
		if (norm2(e) != 285. * 2) SLS_FAIL;
		if (norm2(cut(e, 0, 2, 0, 2)) != 46. * 2)
			SLS_FAIL;
	}
	// sum_abs
	{
		VecDoub v(10); linspace(v, -4, 5);
		if (sum_abs(v) != 25)
			SLS_FAIL;
	}

	// flip
	{
		VecInt v(6), v1(6), v2(6);
		linspace(v, -2, 3); copy(v2, v);
		linspace(v1, 3, -2);
		flip(v);
		if (v != v1) SLS_FAIL;
		flip(v, v1);
		if (v != v2) SLS_FAIL;
	}

	// trans
	{
		CmatComp a(3,3); linspace(a, Comp(0, 0), Comp(8, 8));
		MatComp b(3,3); linspace(b, Comp(0, 0), Comp(8, 8));
		trans(a);
		if (a != b) SLS_FAIL;

		a.resize(2, 3);
		linspace(a, Comp(0, 0), Comp(5, 5));
		b.resize(3, 2);
		linspace(b, Comp(0, 0), Comp(5, 5));
		MatComp c(a.n1(), a.n0()); trans(c, a);
		if (c != b)  SLS_FAIL;
	}

	// her
	{
		CmatComp a(3,3); linspace(a, Comp(0, 0), Comp(8, 8));
		MatComp b(3,3); linspace(b, Comp(0, 0), Comp(8, -8));
		her(a);
		if (a != b) SLS_FAIL;

		a.resize(2, 3);
		linspace(a, Comp(0, 0), Comp(5, 5));
		b.resize(3, 2);
		linspace(b, Comp(0, 0), Comp(5, -5));
		MatComp c(a.n1(), a.n0()); her(c, a);
		if (c != b)  SLS_FAIL;
	}

	// +=, -=, *=, /=
	{
		VecInt vLlong(3), vLlong1(3), vLlong2(3), vLlong3(3);
		VecDoub vDoub(3), vDoub1(3), vDoub2(3), vDoub3(3);
		VecComp vComp(3), vComp1(3), vComp2(3), vComp3(3);

		// v ?= s
		copy(vLlong, 1);
		vLlong += 1;
		if (vLlong != 2) SLS_FAIL;
		vLlong -= 1;
		if (vLlong != 1) SLS_FAIL;
		vLlong *= 2;
		if (vLlong != 2) SLS_FAIL;
		vLlong /= 2;
		if (vLlong != 1) SLS_FAIL;

		copy(vDoub, 1);
		vDoub += 1.;
		if (vDoub != 2.) SLS_FAIL;
		vDoub -= 1.;
		if (vDoub != 1.) SLS_FAIL;
		vDoub *= 2.;
		if (vDoub != 2.) SLS_FAIL;
		vDoub /= 2.;
		if (vDoub != 1.) SLS_FAIL;

		copy(vComp, Comp(1, 1));
		vComp += Comp(1., 1.);
		if (vComp != Comp(2., 2.)) SLS_FAIL;
		vComp -= Comp(1., 1.);
		if (vComp != Comp(1., 1.)) SLS_FAIL;
		vComp *= 2.;
		if (vComp != Comp(2., 2.)) SLS_FAIL;
		vComp /= 2.;
		if (vComp != Comp(1., 1.)) SLS_FAIL;

		// v ?= v

		copy(vLlong, 1); copy(vLlong1, 1);
		vLlong += vLlong1;
		if (vLlong != 2) SLS_FAIL;
		vLlong -= vLlong1;
		if (vLlong != 1) SLS_FAIL;
		copy(vLlong2, 2);
		vLlong *= vLlong2;
		if (vLlong != 2) SLS_FAIL;
		vLlong /= vLlong2;
		if (vLlong != 1) SLS_FAIL;

		copy(vDoub, 1); copy(vDoub1, 1);
		vDoub += vDoub1;
		if (vDoub != 2.) SLS_FAIL;
		vDoub -= vDoub1;
		if (vDoub != 1.) SLS_FAIL;
		copy(vDoub2, 2);
		vDoub *= vDoub2;
		if (vDoub != 2.) SLS_FAIL;
		vDoub /= vDoub2;
		if (vDoub != 1.) SLS_FAIL;

		copy(vComp, Comp(1, 1)); copy(vComp1, Comp(1, 1));
		vComp += vComp1;
		if (vComp != Comp(2., 2.)) SLS_FAIL;
		vComp -= vComp1;
		if (vComp != Comp(1., 1.)) SLS_FAIL;
		copy(vComp2, 2);
		vComp *= vComp2;
		if (vComp != Comp(2., 2.)) SLS_FAIL;
		vComp /= vComp2;
		if (vComp != Comp(1., 1.)) SLS_FAIL;
	}

	// mod()
	{
		VecInt v(40);
		linspace(v, -20, 19);;
		mod(v, v, 5);
	}

	// add(), sub(), times(), div()
	{
		VecInt vLlong(3), vLlong1(3), vLlong2(3), vLlong3(3);
		VecDoub vDoub(3), vDoub1(3), vDoub2(3), vDoub3(3);
		VecComp vComp(3), vComp1(3), vComp2(3), vComp3(3);

		// v = v ? s
		copy(vLlong1, 1);
		add(vLlong, vLlong1, 1);
		if (vLlong != 2) SLS_FAIL;
		sub(vLlong, vLlong1, 1);
		if (vLlong != 0) SLS_FAIL;
		times(vLlong, vLlong1, 2);
		if (vLlong != 2) SLS_FAIL;
		div(vLlong, vLlong1, 2);
		if (vLlong != 0) SLS_FAIL;

		copy(vDoub1, 1);
		add(vDoub, vDoub1, 1.);
		if (vDoub != 2.) SLS_FAIL;
		sub(vDoub, vDoub1, 1.);
		if (vDoub != 0.) SLS_FAIL;
		times(vDoub, vDoub1, 2.);
		if (vDoub != 2.) SLS_FAIL;
		div(vDoub, vDoub1, 2.);
		if (vDoub != 0.5) SLS_FAIL;
		
		copy(vComp1, 1);
		add(vComp, vComp1, 1.);
		if (vComp != 2.) SLS_FAIL;
		sub(vComp, vComp1, 1.);
		if (vComp != 0.) SLS_FAIL;
		times(vComp, vComp1, 2.);
		if (vComp != 2.) SLS_FAIL;
		div(vComp, vComp1, 2.);
		if (vComp != 0.5) SLS_FAIL;

		// v = s ? v

		copy(vLlong1, 1);
		add(vLlong, 1, vLlong1);
		if (vLlong != 2) SLS_FAIL;
		sub(vLlong, 1, vLlong1);
		if (vLlong != 0) SLS_FAIL;
		times(vLlong, 2, vLlong1);
		if (vLlong != 2) SLS_FAIL;
		copy(vLlong1, 2);
		div(vLlong, 2, vLlong1);
		if (vLlong != 1) SLS_FAIL;

		copy(vDoub1, 1);
		add(vDoub, 1., vDoub1);
		if (vDoub != 2.) SLS_FAIL;
		sub(vDoub, 1., vDoub1);
		if (vDoub != 0.) SLS_FAIL;
		times(vDoub, 2., vDoub1);
		if (vDoub != 2.) SLS_FAIL;
		copy(vDoub1, 2);
		div(vDoub, 2., vDoub1);
		if (vDoub != 1.) SLS_FAIL;

		copy(vComp1, Comp(1,1));
		add(vComp, Comp(1., 1.), vComp1);
		if (vComp != Comp(2.,2.)) SLS_FAIL;
		sub(vComp, Comp(1.,1.), vComp1);
		if (vComp != 0.) SLS_FAIL;
		times(vComp, 2., vComp1);
		if (vComp != Comp(2.,2.)) SLS_FAIL;
		copy(vComp1, 2);
		div(vComp, Comp(2.,2.), vComp1);
		if (vComp != Comp(1.,1.)) SLS_FAIL;

		// v = v ? v

		copy(vLlong1, 4); copy(vLlong2, 2);
		add(vLlong, vLlong1, vLlong2);
		if (vLlong != 6) SLS_FAIL;
		sub(vLlong, vLlong1, vLlong2);
		if (vLlong != 2) SLS_FAIL;
		times(vLlong, vLlong1, vLlong2);
		if (vLlong != 8) SLS_FAIL;
		div(vLlong, vLlong1, vLlong2);
		if (vLlong != 2) SLS_FAIL;

		copy(vDoub1, 1); copy(vDoub2, 2);
		add(vDoub, vDoub1, vDoub2);
		if (vDoub != 3.) SLS_FAIL;
		sub(vDoub, vDoub2, vDoub1);
		if (vDoub != 1.) SLS_FAIL;
		times(vDoub, vDoub1, vDoub2);
		if (vDoub != 2.) SLS_FAIL;
		div(vDoub, vDoub1, vDoub2);
		if (vDoub != 0.5) SLS_FAIL;

		copy(vComp1, Comp(1, 1)); copy(vComp2, Comp(2, 2));
		add(vComp, vComp1, vComp2);
		if (vComp != Comp(3., 3.)) SLS_FAIL;
		sub(vComp, vComp2, vComp1);
		if (vComp != Comp(1., 1.)) SLS_FAIL;
		copy(vComp2, 2);
		times(vComp, vComp1, vComp2);
		if (vComp != Comp(2., 2.)) SLS_FAIL;
		div(vComp, vComp1, vComp2);
		if (vComp != Comp(0.5, 0.5)) SLS_FAIL;
	}

	// real(v), v = real(v)
	{
		VecComp v(3); linspace(v, Comp(1.1,1.1), Comp(3.3,3.3));
		VecComp v1(3); linspace(v1, 1.1, 3.3);
		real(v);
		if (v != v1) SLS_FAIL;
		linspace(v, Comp(1.1, 1.1), Comp(3.3, 3.3));
		VecDoub v2(v.size());
		real(v2, v);
		if(v2 != v1) SLS_FAIL;
	}

	// imag(v), v = imag(v)
	{
		VecComp v(3); linspace(v, Comp(1.1, 1.1), Comp(3.3, 3.3));
		VecComp v1(3); linspace(v1, 1.1, 3.3);
		imag(v);
		if (v != v1) SLS_FAIL;
		linspace(v, Comp(1.1, 1.1), Comp(3.3, 3.3));
		VecDoub v2(v.size());
		imag(v2, v);
		if (v2 != v1) SLS_FAIL;
	}

	// abs(v), v = abs(v)
	{
		// doub
		{
			VecDoub v(5); linspace(v, -2, 2);
			VecComp v1(5); v1[0] = 2; v1[1] = 1; v1[2] = 0; v1[3] = 1; v1[4] = 2;
			abs(v);
			if (v != v1) SLS_FAIL;
			linspace(v, -2, 2);
			VecDoub v2(v1.size());
			abs(v2, v);
			if (v2 != v1) SLS_FAIL;
		}
		
		// comp
		{
			VecComp v(3); linspace(v, Comp(3, 4), Comp(9, 12));
			VecComp v1(3); linspace(v1, 5, 15);
			abs(v);
			if (v != v1) SLS_FAIL;
			linspace(v, Comp(3, 4), Comp(9, 12));
			VecDoub v2(v.size());
			abs(v2, v);
			if (v2 != v1) SLS_FAIL;
		}
	}

	// conj(v), v = conj(v)
	{
		VecComp v(3); linspace(v, Comp(1.1, 1.1), Comp(3.3, 3.3));
		VecComp v1(3); linspace(v1, Comp(1.1, -1.1), Comp(3.3, -3.3));
		conj(v);
		if (v != v1) SLS_FAIL;
		linspace(v, Comp(1.1, 1.1), Comp(3.3, 3.3));
		// VecLcomp v2(v.size());
		// conj(v2, v);
		// if (v2 != v1) SLS_FAIL;
	}

	// s = dot(v, v)
	{
		{
			VecComp x(3); VecDoub y(3);
			linspace(x, Comp(1.1, 1.1), Comp(3.3, 3.3));
			linspace(y, 1., 3.);
			auto s = dot(x, y);
			if (abs(s - Comp(15.4, -15.4)) > 1e-14) SLS_FAIL;
		}

		{
			VecDoub x(3); VecDoub y(3);
			linspace(x, 1.1, 3.3);
			linspace(y, 1, 3);
			auto s = dot(x, y);
			if (abs(s - 15.4) > 1e-14) SLS_FAIL;
		}
	}

	// matrix-vector multiplication (row-major)
	{
		MatComp a(4,7); linspace(a, Comp(1, -1), Comp(28, -28));
		VecDoub v(7); linspace(v, 1, 7);
		VecComp v1(4), v2(a.n0());
		v1[0] = Comp(140, -140); v1[1] = Comp(336, -336);
		v1[2] = Comp(532, -532); v1[3] = Comp(728, -728);
		mul(v2, a, v);
		if (v2 != v1)
			SLS_FAIL;
	}

	// matrix-vector multiplication (column-major)
	{
		CmatInt a(3, 4);
		linspace(a, 1, 12);
		VecInt x(4), y(3);
		linspace(x, 1, 4);
		copy(y, 1);
		mul(y, a, x);
		if (y[0] != 70 || y[1] != 80 || y[2] != 90)
			SLS_FAIL;
	}

	// matrix-vector multiplication using cblas
	{
		VecComp x(11), y(13), y1(13); rand(x); rand(y);
		CmatDoub a(13, 11); rand(a);
		mul(y, a, x);
		mul_gen(y1, a, x);
		y1 -= y;
		if (max_abs(y1) > 1e-13)
			SLS_FAIL;

		SvecComp cut_x, cut_y, cut_y1;
		cut_x.set(cut(x, 1, 5));
		cut_y.set(cut(y, 1, 6));
		cut_y1.set(cut(y1, 1, 6));
		DcmatDoub cut_a(cut(a, 2, 6, 2, 5));
		mul(cut_y, cut_a, cut_x);
		mul_gen(cut_y1, cut_a, cut_x);
		cut_y1 -= cut_y;
		if (max_abs(cut_y1) > 1e-13)
			SLS_FAIL;
	}

	// vector-matrix multiplication
	{
		MatComp a(7,4); linspace(a, Comp(1, -1), Comp(28, -28));
		VecDoub v(7); linspace(v, 1, 7);
		VecComp v1(4), v2(a.n1());
		v1[0] = Comp(476, -476); v1[1] = Comp(504, -504);
		v1[2] = Comp(532, -532); v1[3] = Comp(560, -560);
		mul(v2, v, a);
		if (v2 != v1) SLS_FAIL;
	}

	// matrix-matrix multiplication
	{
		MatComp a(7,4); linspace(a, Comp(1, -1), Comp(28, -28));
		CmatComp b(4, 7); her(b, a);
		CmatComp c(b.n0(), a.n1());
		mul(c, b, a);
		if (c(0, 0) != 3262 || c(0, 2) != 3626 || c(1, 1) != 3640 || c(1, 3) != 4032 ||
			c(2, 2) != 4046 || c(2, 3) != 4256 || c(3, 3) != 4480)
			SLS_FAIL;
	}

	// v = cumsum(v)
	{
		VecInt v(4); linspace(v, 1, 4);
		VecInt v1(v.size());
		cumsum(v1, v);
		if (v1[0] != 1 || v1[1] != 3 || v1[2] != 6 || v1[3] != 10)
			SLS_FAIL;
	}

	// uniq_elm()
	{
		vecInt v = {1,3,2,5,8,1,8,5,3,2,6,7,6};
		vecInt v1 = {1,3,2,5,8,6,7};
		uniq_elm(v);
		if (v != v1)
			SLS_FAIL;
	}

	// uniq_rows()
	{
		CmatInt a(5, 2), a1;
		a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 2; a[4] = 3;
		a[5] = 2; a[6] = 3; a[7] = 4; a[8] = 3; a[9] = 4;
		uniq_rows(a1, a);
		CmatInt a2(3, 2);
		a2[0] = 1; a2[1] = 2; a2[2] = 3;
		a2[3] = 2; a2[4] = 3; a2[5] = 4;
		if (a1 != a2)
			SLS_FAIL;
	}
}
