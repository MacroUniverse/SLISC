#include "../SLISC/lin_eq.h"
#include "../SLISC/arithmetic.h"
#include "../SLISC/disp.h"
#include "../SLISC/random.h"

void test_lin_eq()
{
#ifdef SLS_USE_LAPACKE
	using namespace slisc;
	{
		CmatDoub a(3, 3), a_inv(3, 3), b(3, 3);
		copy(a, 1); a(0, 0) += 2; a(1, 1) += 2; a(2, 2) += 2;    
		copy(a_inv, a);
		inv_mat(a_inv);
		mul(b, a, a_inv);
		b(0, 0) -= 1; b(1, 1) -= 1; b(2, 2) -= 1;
		if (norm(b) > 2e-15)
			SLS_FAIL;
	}
	
	// solve general matrix
	{
		Long N1 = 10, N2 = 10;
		CmatDoub a(N1, N2);
		VecDoub x(N2), y(N2);
		rand(x); rand(a);
		mul(y, a, x);
		lin_eq(y, a);
		y -= x;
		if (max_abs(y) > 1e-10) {
			cout << "max_abs(y) = " << max_abs(y) << endl;
			SLS_FAIL;
		}
	}

	{
		Long N1 = 10, N2 = 10;
		CmatComp a(N1, N2);
		VecComp x(N2), y(N2);
		rand(x); rand(a);
		mul(y, a, x);
		lin_eq(y, a);
		y -= x;
		if (max_abs(y) > 2e-13) {
			cout << "max_abs(y) = " << max_abs(y) << endl;
			SLS_FAIL;
		}
	}

	// solve band matrix
	{
		Long N1 = 10, N2 = 10, Nup = 3, Nlow = 4;
		CbandDoub b(N1, N2, Nup, Nlow);
		VecDoub x(N2), y(N2);
		rand(x); rand(b.cmat());
		mul(y, b, x);
		lin_eq(y, b);
		y -= x;
		if (max_abs(y) > 1e-13) {
			cout << "max_abs(y) = " << max_abs(y) << endl;
			SLS_FAIL;
		}
	}

	{
		Long N1 = 10, N2 = 10, Nup = 3, Nlow = 4;
		CbandComp b(N1, N2, Nup, Nlow);
		VecComp x(N2), y(N2);
		rand(x); rand(b.cmat());
		mul(y, b, x);
		lin_eq(y, b);
		y -= x;
		if (max_abs(y) > 5e-14) {
			cout << "max_abs(y) = " << max_abs(y) << endl;
			SLS_FAIL;
		}
	}

	{
		Long N1 = 10, N2 = 10, Nup = 3, Nlow = 4;
		CbandComp b;
		b.resize(N1, N2, Nup, Nlow, Nup + 2*Nlow + 1, Nlow + Nup);
		VecLong ipiv(N1);
		VecComp x(N2), y(N2);
		rand(x); rand(b.cmat());
		mul(y, b, x);
		lin_eq(y, b, ipiv);
		y -= x;
		if (max_abs(y) > 5e-14) {
			cout << "max_abs(y) = " << max_abs(y) << endl;
			SLS_FAIL;
		}
	}
#endif

#ifdef SLS_USE_MPLAPACK
	// Qcomp band matrix
	{
		Long N1 = 10, N2 = 10, Nup = 3, Nlow = 4;
		CbandQcomp b;
		b.resize(N1, N2, Nup, Nlow, Nup + 2*Nlow + 1, Nlow + Nup);
		VecLong ipiv(N1);
		VecQcomp x(N2), y(N2);
		rand(x); rand(b.cmat());
		mul(y, b, x);
		lin_eq(y, b, ipiv);
		y -= x;
		if (max_abs(y) > 5e-30Q) {
			cout << "max_abs(y) = " << max_abs(y) << endl;
			SLS_FAIL;
		}
	}
#endif
}
