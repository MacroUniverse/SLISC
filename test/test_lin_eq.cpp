#include "../SLISC/lin_eq.h"
#include "../SLISC/arithmetic.h"
#include "../SLISC/disp.h"
#include "../SLISC/random.h"

void test_lin_eq()
{
    using namespace slisc;
	{
		CmatDoub a(3, 3), a_inv(3, 3), b(3, 3);
		copy(a, 1); a(0, 0) += 2; a(1, 1) += 2; a(2, 2) += 2;    
		copy(a_inv, a);
		inv_mat(a_inv);
		mul(b, a, a_inv);
		b(0, 0) -= 1; b(1, 1) -= 1; b(2, 2) -= 1;
		if (norm(b) > 2e-15)
			SLS_ERR("failed!");
	}
    
	// solve band matrix
	{
		Long N1 = 10, N2 = 10, Nup = 3, Nlow = 4;
		CmatDoub a(N1, N2);
		CbandDoub b(N1, N2, Nup, Nlow);
		VecDoub x(N2), ya(N2), yb(N2), xa(N2), xb(N2);
		rand(x);
		rand(b.cmat());
		copy(a, b);
		mul(ya, a, x); mul(yb, b, x);
		lin_eq(ya, a);
		lin_eq(yb, b);
		yb -= ya;
		if (max_abs(yb) > 1e-14)
			SLS_ERR("failed!");
	}
}
