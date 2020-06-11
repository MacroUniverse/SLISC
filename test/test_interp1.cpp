#include "../SLISC/interp1.h"

void test_interp1()
{
	// real polynomial interp with gsl
	// extrapolation not allowed
	{
		using namespace slisc;
		Long N0 = 3, N = 21;
		VecDoub x0(N0), y0(N0), x(N), y(N), y1(N), y2(N), y_ev(N);
		linspace(x0, 0, 2);
		y0[0] = 1; y0[1] = 0; y0[2] = 1;
		linspace(x, 0, 2);
		for (Long i = 0; i < N; ++i) {
			y[i] = sqr(x[i]-1);
			y1[i] = 2*(x[i]-1);
			y2[i] = 2;
		}

		poly_interp1 poly(x0, y0);
		for (Long i = 0; i < N; ++i)
			y_ev[i] = poly(x[i]);
		y_ev -= y;
		if (max_abs(y_ev) > 1e-10)
			SLS_ERR("error");
		for (Long i = 0; i < N; ++i)
			y_ev[i] = poly.der(x[i]);
		y_ev -= y1;
		if (max_abs(y_ev) > 1e-10)
			SLS_ERR("error");
		for (Long i = 0; i < N; ++i)
			y_ev[i] = poly.der2(x[i]);
		y_ev -= y2;
		if (max_abs(y_ev) > 1e-10)
			SLS_ERR("error");
	}

	// complex valued polynomial interp with gsl
	// extrapolation not allowed
	{
		using namespace slisc;
		Long N0 = 3, N = 21;
		VecDoub x0(N0), x(N);
		VecComp y0(N0), y(N), y1(N), y2(N), y_ev(N);
		linspace(x0, 0, 2);
		y0[0] = Comp(1,-1); y0[1] = Comp(0,0); y0[2] = Comp(1,-1);
		linspace(x, 0, 2);
		for (Long i = 0; i < N; ++i) {
			y[i] = Comp(sqr(x[i]-1), -sqr(x[i]-1));
			y1[i] = Comp(2*(x[i]-1), -2*(x[i]-1));
			y2[i] = Comp(2,-2);
		}

		poly_comp_interp1 poly(x0, y0);
		for (Long i = 0; i < N; ++i)
			y_ev[i] = poly(x[i]);
		y_ev -= y;
		if (max_abs(y_ev) > 1e-10)
			SLS_ERR("error");
		for (Long i = 0; i < N; ++i)
			y_ev[i] = poly.der(x[i]);
		y_ev -= y1;
		if (max_abs(y_ev) > 1e-10)
			SLS_ERR("error");
		for (Long i = 0; i < N; ++i)
			y_ev[i] = poly.der2(x[i]);
		y_ev -= y2;
		if (max_abs(y_ev) > 1e-10)
			SLS_ERR("error");
	}

	// spline interp
	{
		using namespace slisc;
		Long N0 = 30;
		VecDoub x0(N0); linspace(x0, 0, 2*PI);
		VecDoub x1(N0); plus(x1, x0, 0.1);
		VecDoub y0(N0), y1(N0);
		for (Long i = 0; i < N0; ++i) {
			y0[i] = sin(x0[i]);
			y1[i] = sin(x1[i]);
		}
			
		Spline_interp spline(x0.ptr(), x0.size(), y0.ptr());
		for (Long i = 0; i < N0; ++i) {
			if (abs(spline.interp(x1[i]) - y1[i]) > 1e-5)
				SLS_ERR("failed!");
		}

		linspace(x0, 1, N0);
		Spline_interp spline1(x0, x0);
		for (Long i = 1; i < N0; ++i) {
			if (abs(spline1.interp(x0[i] - 0.5) - (x0[i]-0.5)) > 1e-10)
				SLS_ERR("failed!");
		}
	}
}
