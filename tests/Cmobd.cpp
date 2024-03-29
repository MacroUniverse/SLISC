#include "../SLISC/sparse/sparse_arith.h"
#include "../SLISC/str/disp.h"

void test_Cmobd()
{
	using namespace slisc;

	Cmat3Int a0(3, 3, 4);
	for (Long k = 0; k < 4; ++k) {
		ScmatInt sli = cut01(a0, k);
		linspace(sli, 1, 9); sli.end() = 1;
	}
	CmobdInt a(3, 4); a.set(a0);

	// construct from Cmat3d
	{
		VecInt x(7), y(7); linspace(x, 1, 7);
		mul(y, a, x);
		if (y[0] != 21 || y[1] != 48 || y[2] != 51 || y[3] != 90 ||
			y[4] != 81 || y[5] != 76 || y[6] != 47)
			SLS_FAIL;
	}
	
	// construct from Mcoo
	{
		McooInt a1(7, 7, 49);
		for (Long i = 0; i < 7; ++i) {
			for (Long j = 0; j < 7; ++j) {
				if (a(i, j) != 0)
					a1.push(a(i, j), i, j);
			}
		}
		CmobdInt a2(3, 4); copy(a2, a1);

		VecInt x(7), y(7); linspace(x, 1, 7);
		vecInt y1{21, 48, 51, 90, 81, 76, 47};
		mul(y, a2, x);
		for (Long i = 0; i < 7; ++i)
			SLS_ASSERT(y[i] == y1[i]);

		// test mul(y, a, x, step_y, step_x, alpha, beta)
		VecInt x2(14), y2(21);
		DvecInt xs(x2.p(), 7, 2), ys(y2.p(), 7, 3);
		for (Long i = 0; i < 7; ++i) {
			xs[i] = x[i];
			ys[i] = i;
		}
		mul(ys, a2, xs, -5, 3);
		for (Long i = 0; i < 7; ++i)
			SLS_ASSERT(ys[i] == -5*y1[i] + 3*i);
	}
	
	// qref() and find() for diagonal elements
	// fix()
	{
		VecInt diag(7);
		diag[0] = 5; diag[1] = 1; diag[2] = 5; diag[3] = 1;
		diag[4] = 5; diag[5] = 1; diag[6] = 5;
		VecLong ind(7);
		ind[0] = 4; ind[1] = 9; ind[2] = 13; ind[3] = 18;
		ind[4] = 22; ind[5] = 27; ind[6] = 31;
		for (Long i = 0; i < 7; ++i) {
			Long ind0 = a.find(i, i);
			if (ind0 != ind[i])
				SLS_FAIL;
			if (a[ind0] != diag[i] || a(i,i) != diag[i])
				SLS_FAIL;
			if (i % 2 == 1) {
				if (a[ind0 - 1] != 0)
					SLS_FAIL;
			}
			a.ref(i,i) = 111;
			if (a[ind0] != 111)
				SLS_FAIL;
		}

		for (Long i = 0; i < 7; ++i) {
			Long ind0 = a.find(i, i);
			a[ind0] = 100;
		}
		for (Long i = 0; i < 7; ++i) {
			if (a(i, i) != 100)
				SLS_FAIL;
		}
	}

	// norm_inf()
	{
		if (norm_inf(a) != 120)
			SLS_FAIL;
	}

	// copy from and to Cmat
	{
		CmobdDoub a(3, 4), a1(3, 4);
		CmatDoub b(a.n0(), a.n1());
		auto &m_data = a.cmat3();
		for (Long i = 0; i < m_data.size(); ++i)
			m_data[i] = randDoub()-0.5;
		copy(b, a); copy(a1, b);
		for (Long i = 0; i < a.n0(); ++i)
			for (Long j = 0; j < a.n1(); ++j)
				SLS_ASSERT(a(i, j) == a1(i, j));
	}
}

#ifndef SLS_TEST_ALL
int main() { test_Cmobd(); }
#endif
