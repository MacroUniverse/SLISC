#include "../SLISC/interp1.h"

void test_interp1()
{
    using namespace slisc;
    Int i, N0 = 30;
    VecDoub x0(N0); linspace(x0, 0, 2*PI);
	VecDoub x1(N0); plus(x1, x0, 0.1);
    VecDoub y0(N0), y1(N0);
    for (Long i = 0; i < N0; ++i) {
		y0[i] = sin(x0[i]);
		y1[i] = sin(x1[i]);
	}
        
    Spline_interp spline(x0.ptr(), x0.size(), y0.ptr());
    for (i = 0; i < N0; ++i) {
        if (abs(spline.interp(x1[i]) - y1[i]) > 1e-5)
            SLS_ERR("failed!");
    }

    linspace(x0, 1, N0);
    Spline_interp spline1(x0, x0);
    for (i = 1; i < N0; ++i) {
        if (abs(spline1.interp(x0[i] - 0.5) - (x0[i]-0.5)) > 1e-10)
            SLS_ERR("failed!");
    }
}
