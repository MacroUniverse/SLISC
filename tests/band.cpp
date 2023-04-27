#include "../SLISC/arith/arith1.h"
#include "../SLISC/sparse/band_arith.h"
#include "../SLISC/lin/mul.h"
#include "../SLISC/util/random.h"
// #include "../SLISC/str/disp.h"

using namespace slisc;
void test_band()
{
	// copy scalar
	{
		CbandDoub a;
		a.resize(5, 6, 2, 3);
		copy(a, 3.1);
		if (a.cmat() != 3.1)
			SLS_FAIL;
	}

	// conversion to/from dense matrix
	{
		Long N1 = 5, N2 = 6, Nlow = 2, Nup = 1;
		CmatDoub matrix(N1, N2), matrix1(N1, N2);
		linspace(matrix, 1, N1*N2); linspace(matrix1, 1, N1*N2);
		CbandDoub a(N1, N2, Nup, Nlow);
		copy(a, matrix);
		copy(matrix1, a);
		for (Long j = 0; j < N2; ++j)
			for (Long i = max(Long(0), j - Nup); i < min(N1, j + Nup + 1); ++i)
				if (matrix(i, j) != matrix1(i, j))
					SLS_FAIL;
	}

	{
		// Long N1 = 5, N2 = 6, kl = 2, ku = 1;
		// Long lda = kl + ku + 1;
		// MatDoub matrix(N1, N2), matrix1(N1, N2);
		// linspace(matrix, 1, N1*N2); linspace(matrix1, 1, N1*N2);
		// MatDoub a(N1, lda); copy(a, 0);
		// copy(a, matrix, ku, kl);
		// copy(matrix1, a, ku, kl);
		// if (matrix != matrix1)
		//     SLS_FAIL;
	}

	// test double index
	{
		Long N1 = 5, N2 = 6, Nlow = 2, Nup = 1;
		CmatDoub den(N1, N2);
		CbandDoub ban(N1, N2, Nup, Nlow); rand(ban.cmat());
		copy(den, ban);
		for (Long j = 0; j < N2; ++j) {
			for (Long i = 0; i < N1; ++i) {
				if (den(i, j) != ban(i, j))
					SLS_FAIL;
			}
		}
	}

	// nband()
	{
		Long Nup, Nlow;
		CmatComp a(6, 7); copy(a, 0);
		nband(Nup, Nlow, a);
		if (Nup != 0 && Nlow != 0)
			SLS_FAIL;
		a(4, 2) = a(2, 5) = 5;
		nband(Nup, Nlow, a);
		if (Nup != 3 || Nlow != 2)
			SLS_FAIL;
	}

	// test band() diag()
	{
		CbandDoub a(4, 4, 1, 1);
		DcmatDoub b = a.band();
		if (b.p() != &a.cmat()[a.idiag()-a.nup()] || b.n0() != 3 || b.n1() != 4)
			SLS_FAIL;
		DvecDoub v = a.diag();
		if (v.p() != &a.cmat()[a.idiag()] || v.step() != a.lda() || v.size() != 4)
			SLS_FAIL;
	}

#ifdef SLS_USE_CBLAS
	// test band matrix-vector multiplication
	{
		Long N1 = 5, N2 = 6, Nlow = 2, Nup = 1;
		CmatDoub den(N1, N2);
		rand(den);
		CbandDoub ban(N1, N2, Nup, Nlow);
		copy(ban, den);
		copy(den, 0);
		copy(den, ban);

		VecDoub x(N2); rand(x);
		VecDoub y(N1), y1(N1);
		mul(y, den, x);
		mul(y1, ban, x);
		y1 -= y;
		if (max_abs(y1) > 1e-13)
			SLS_ERR("failed");
	}

	{
		Long N = 6;
		CbandDoub a(N, N, 2, 3);
		rand(a.cmat());
		CmatDoub d(N, N);
		copy(d, a);
		VecComp ya(N), yd(N), x(N);
		rand(x);
		mul(ya, a, x);
		mul(yd, d, x);
		yd -= ya;
		if (max_abs(yd) > 1e-8)
			SLS_FAIL;
	}

	{
		Long N1 = 5, N2 = 6, Nlow = 2, Nup = 1;
		CmatComp den(N1, N2);
		rand(den);
		CbandComp ban(N1, N2, Nup, Nlow);
		copy(ban, den);
		copy(den, 0);
		copy(den, ban);
		
		VecComp x(N2); rand(x);
		VecComp y(N1), y1(N1);
		mul(y, den, x);
		mul(y1, ban, x);
		y1 -= y;
		if (max_abs(y1) > 1e-13)
			SLS_ERR("failed");
	}
#endif
}

#ifndef SLS_TEST_ALL
int main() { test_band(); }
#endif
