#include "../SLISC/lanczos.h"
#include "../SLISC/disp.h"
#include "../SLISC/random.h"
#include "../SLISC/mat_fun.h"
#include "../SLISC/cut.h"

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

        // test expv_lanc();
        {
			VecComp x(3), y(3), y0(3);
            VecDoub wsp_d(15);
            VecComp wsp_c(12);
			for (Long i = 0; i < 5; ++i) {
				rand(x);
				mul(y0, expH, x);
				expv_lanc(y, H, x, 1, 3, wsp_d, wsp_c);
				y -= y0;
				if (max_abs(y) > 1e-8)
					SLS_ERR("failed!");
			}
        }
    }
#endif
}
