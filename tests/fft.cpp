#include "../SLISC/sci/fft.h"
#include "../SLISC/arith/arith1.h"
#include "../SLISC/arith/arith2.h"
#include "../SLISC/arith/arith4.h"

// test fft module
void test_fft()
{
	using namespace slisc;
	// test bit_inv()
	VecComp v(16); linspace(v, 1., 16.);
	VecComp v1(16);
	bit_inv(v1.p(), v.p(), v.size());
	VecComp v2(v.size()); copy(v2, v);
	bit_inv(v2.p(), v2.size());
	if (v1 != v2) SLS_FAIL;
	bit_inv(v1.p(), v1.size());
	if (v1 != v) SLS_FAIL;

	// fft(VecComp_IO) and ifft(VecComp_IO)
	v.resize(4); v[0] = 1; v[1] = I;  v[2] = -1; v[3] = -I;
	fft(v);
	v1.resize(4); copy(v1, 0); v1[1] = 4.;
	v -= v1;
	if (max_abs(v) > 1.5e-15) SLS_FAIL;
	ifft(v1);
	v[0] = 1; v[1] = I;  v[2] = -1; v[3] = -I;
	v1 /= 4.; v1 -= v;
	if (max_abs(v1) > 1e-15) SLS_FAIL;

	// fft_interp()
	VecDoub x(3); linspace(x, 1., 3.);
	VecComp y(3); linspace(y, Comp(1., 1.), Comp(3., 3.));
	if (abs(fft_interp(x[0], x, y) - y[0]) > 1e-15) SLS_FAIL;
	if (abs(fft_interp(x[1], x, y) - y[1]) > 1e-15) SLS_FAIL;
	if (abs(fft_interp(x[2], x, y) - y[2]) > 1e-15) SLS_FAIL;

	// fftshift()
	VecInt vInt(4); linspace(vInt, 1, 4);
	fftshift(vInt);
	VecInt vInt1(4); vInt1[0] = 3; vInt1[1] = 4; vInt1[2] = 1; vInt1[3] = 2;
	if (vInt != vInt1) SLS_FAIL;

	// test fft2x(), ifft2x, fft4x(), ifft4x
	v.resize(4); v[0] = Comp(1., 1.); v[1] = Comp(2., 2.); v[2] = Comp(3., 5.); v[3] = Comp(4., 7.);
	fft2x(v2, v);
	VecComp v3(8); copy(v3, 0);
	v3[0] = v[0]; v3[1] = v[1]; v3[6] = v[2]; v3[7] = v[3];
	fft(v3);
	if (v2 != v3) SLS_FAIL;

	ifft2x(v2, v);
	copy(v3, 0);
	v3[0] = v[0]; v3[1] = v[1]; v3[6] = v[2]; v3[7] = v[3];
	ifft(v3);
	if (v2 != v3) SLS_FAIL;

	VecComp v4(v.size()*4);
	fft4x(v4, v);
	VecComp v5(16); copy(v5, 0);
	v5[0] = v[0]; v5[1] = v[1]; v5[14] = v[2]; v5[15] = v[3];
	fft(v5);
	v4 -= v5;
	if (max_abs(v4) > 1e-14) SLS_FAIL;

	ifft4x(v4, v);
	copy(v5, 0);
	v5[0] = v[0]; v5[1] = v[1]; v5[14] = v[2]; v5[15] = v[3];
	ifft(v5);
	v4 -= v5;
	if (max_abs(v4) > 1e-14) SLS_FAIL;
}

#ifndef SLS_TEST_ALL
int main() { test_fft(); }
#endif
