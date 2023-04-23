#include "../SLISC/tdse/lanczos.h"
// #include "../SLISC/str/disp.h"

void test_lanczos()
{
#ifdef SLS_USE_LAPACKE
	using namespace slisc;
	{
		CmatDoub H(3, 3); // symmetric matrix
		H(0, 0) = H(1, 1) = H(2, 2) = 1.;
		H(0, 1) = H(1, 0) = -2.;
		H(0, 2) = H(2, 0) = 3.;
		H(1, 2) = H(2, 1) = -4.;
		CmatDoub expH(3, 3); // exp(H)
		expH(0, 0) = 3.025725493155477e2;
		expH(1, 1) = 4.036648217771199e2;
		expH(2, 2) = 4.758735878210995e2;
		expH(0, 1) = expH(1, 0) = -3.490811211849774e2;
		expH(0, 2) = expH(2, 0) = 3.792041496895060e2;
		expH(1, 2) = expH(2, 1) = -4.382106846116269e2;

		CmatComp exp_miH(3, 3);
		exp_miH(0, 0) = Comp(0.543799, 0.341283);
		exp_miH(1, 1) = Comp(0.0664594, -0.0295234);
		exp_miH(2, 2) = Comp(-0.274497, -0.294385);
		exp_miH(0, 1) = exp_miH(1, 0) = Comp(0.229334, 0.565395);
		exp_miH(0, 2) = exp_miH(2, 0) = Comp(0.337912, -0.318369);
		exp_miH(1, 2) = exp_miH(2, 1) = Comp(-0.768775, 0.177287);

		// test expHdt_v_lanc(), exp_miHdt_v_lanc;
		{
			VecComp x(3), y(3), y0(3), x6(6);
			VecDoub wsp_d(20);
			VecComp wsp_c(20);
			for (Long i = 0; i < 5; ++i) {
				rand(x);
				mul(y0, expH, x);
				exp_Hdt_v_lanc(y, H, x, 1, 3, wsp_d, wsp_c);
				y -= y0;
				if (max_abs(y) > 1e-8)
					SLS_FAIL;

				mul(y0, exp_miH, x);
				copy(y, x);
				exp_miHdt_v_lanc(y, H, y, 1, 3, wsp_d, wsp_c); // for dense y
				y -= y0;
				if (max_abs(y) > 1e-4)
					SLS_FAIL;

				DvecComp y1(x6.p(), 3, 2);
				copy(y1, x);
				exp_miHdt_v_lanc(y1, H, y1, 1, 3, wsp_d, wsp_c); // for Dvec y1
				y1 -= y0;
				if (max_abs(y1) > 1e-4)
					SLS_FAIL;
			}
		}
	}
#endif
}

#ifndef SLS_TEST_ALL
int main() { test_lanczos(); }
#endif
