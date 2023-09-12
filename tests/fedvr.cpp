#include "../SLISC/lin/eig.h"
#include "../SLISC/tdse/fedvr.h"
#include "../SLISC/file/matb.h"
#include "../SLISC/str/disp.h"

using namespace slisc;

void test_gauss_lobatto()
{
	for (Long N = 4; N <= 20; N += 2) {
		// cout << "N = " << N << endl;
		VecDoub x(N), w(N);
		GaussLobatto(x, w);
		GaussLobatto_check(x, w);
	}
	#ifdef SLS_USE_QUAD_MATH
	for (Long N = 4; N <= 20; N += 2) {
		{
			// cout << "N = " << N << endl;
			VecQdoub x(N), w(N);
			GaussLobatto(x, w);
			GaussLobatto_check(x, w);
		}
	}
	#endif
}

// polynomial of order n, in [-1, 1]
Doub test_fedvr_fun(Doub_I x, Int_I n)
{
	Doub y = (x + 1)*(x - 1);
	Doub dx = 2 / (n - 1.);
	for (Int i = 0; i < n - 2; ++i) {
		y *= x - (-1 + dx*(i + 1));
	}
	return y;
}

// test Gauss integration and second derivative matrix
void test_gauss()
{
	Int Ngs = 10;
	VecDoub x0(Ngs), w0(Ngs);

	// test Gauss-Lobatto integration
	// int_{-1}^1 (x+1)(x-1) dx = -4/3

	Int i;
	GaussLobatto(x0, w0);

	VecDoub y(Ngs);
	for (i = 0; i < Ngs; ++i)
		y[i] = test_fedvr_fun(x0[i], 2);
	Doub res = dot(y, w0);
	if (abs(res + 4. / 3.) > 1e-14) SLS_FAIL;
}

// test second derivative matrix
// y(x) = x^2 - 1, y"(x) = 2
void test_D2_mat()
{
	Int Nfe = 2, Ngs = 10;
	Long Nx = Nfe * (Ngs - 1) - 1;
	VecDoub bounds(Nfe + 1); linspace(bounds, -1., 1.);

	// second derivative matrix
	McooDoub D2s(Nx, Nx);
	VecDoub x(Nx), w(Nx), u(Nx);
	D2_matrix(D2s, x, w, u, bounds, Ngs);
	VecDoub y(Nx);
	VecDoub d2y(D2s.n0()); // second derivative

	for (Long i = 0; i < Nx; ++i)
		y[i] = test_fedvr_fun(x[i], 2);
	y /= u;
	mul(d2y, D2s, y);
	d2y *= u;
	d2y -= 2;
	SLS_ASSERT(max_abs(d2y) < 5e-13);
}

void test_D_mat()
{
	Int Nfe = 2, Ngs = 10;
	Long Nx = Nfe * (Ngs - 1) - 1;
	VecDoub bounds(Nfe + 1); linspace(bounds, -1., 1.);

	// second derivative matrix
	McooDoub Ds(Nx, Nx);
	VecDoub x(Nx), w(Nx), u(Nx);
	D_matrix(Ds, x, w, u, bounds, Ngs);
	VecDoub y(Nx);
	VecDoub dy(Ds.n0()); // second derivative

	for (Long i = 0; i < Nx; ++i)
		y[i] = test_fedvr_fun(x[i], 2);
	cout << "x = " << endl;
	disp(x);
	cout << "y = " << endl;
	disp(y);
	y /= u;
	mul(dy, Ds, y);
	dy *= u;
	cout << "dy = " << endl;
	disp(dy);
	// cout << "D = " << endl;
	// disp(Ds);
	for (Long i = 0; i < Nx; ++i)
		dy[i] -= 2*x[i];
	SLS_ASSERT(max_abs(dy) < 5e-13);
}

// bound states of infinite square well
#ifdef SLS_USE_LAPACKE
void test_inf_sqr_well()
{
	// === params ===
	Doub xmin = 0, xmax = 1; // box boundary
	Int Ngs = 10, Nfe = 5; // grid points per finite element (including boundaries)
	// =============

	Long Nx = Nfe * (Ngs - 1) - 1;
	VecDoub bounds(Nfe + 1); linspace(bounds, xmin, xmax);

	VecDoub x(Nx), w(Nx), u(Nx);
	CmatDoub H(Nx, Nx); McooDoub Hs(Nx, Nx); // dense and sparse Hamiltonian
	D2_matrix(Hs, x, w, u, bounds, Ngs);
	H.resize(Hs.n0(), Hs.n1()); copy(H, Hs);
	H *= -0.5; Hs *= -0.5;

	// solve eigen states
	VecDoub eigVal(H.n0()); // eigen values / bound state energies
	CmatDoub eigVec; eigVec.resize(H.n0(), H.n1()); // eigen vectors / bound states wave functions
	eig_sym(eigVal, eigVec, H);

	// test energies

	VecDoub eng(8);
	for (Int n = 1; n <= 8; ++n)
		eng[n - 1] = sqr(PI) / 2. * sqr(n);
	sub_eq_vv(eng.p(), eigVal.p(), 8);
	if (max_abs_v(eng.p(), 8) > 1e-5) SLS_FAIL;

	// TODO: test wave function using analytical solution
}
#endif

// bound states of simple harmonic oscillator
#ifdef SLS_USE_LAPACKE
void test_SHO()
{
	// === params ===
	Doub xmin = -10, xmax = 10; // box boundary
	Int Ngs = 10, Nfe = 10; // grid points per finite element (including boundaries)
	// ==============

	Long Nx = Nfe * (Ngs - 1) - 1;
	VecDoub bounds(Nfe + 1); linspace(bounds, xmin, xmax);

	VecDoub x(Nx), w(Nx), u(Nx);
	CmatDoub H(Nx, Nx); McooDoub Hs(Nx, Nx); // dense and sparse Hamiltonian
	D2_matrix(Hs, x, w, u, bounds, Ngs);

	H.resize(Hs.n0(), Hs.n1()); copy(H, Hs);
	H *= -0.5; Hs *= -0.5;

	// add potential to Hamiltonian
	for (Long i = 0; i < x.size(); ++i) {
		H(i, i) += 0.5*sqr(x[i]);
	}

	// solve eigen states
	VecDoub eigVal(H.n0()); // eigen values / bound state energies
	CmatDoub eigVec; eigVec.resize(H.n0(), H.n1()); // eigen vectors / bound states wave functions
	eig_sym(eigVal, eigVec, H);

	// test energies
	VecDoub Eng(8); linspace(Eng, 0.5, 7.5);
	sub_eq_vv(Eng.p(), eigVal.p(), 8);
	if (max_abs_v(Eng.p(), 8) > 1e-5) SLS_FAIL;

	// TODO: test wave function using analytical solution.
}
#endif

#ifdef SLS_USE_GSL
void test_fedvr_interp1()
{
	// === params ===
	Long Nfe = 3, Ngs = 6, Nx = Nfe*(Ngs-1)-1;
	Long ibasis = 13; // index of basis
	Long Neval = 301; // number of points to eval
	// ==============

	VecDoub x(Nx), w(Nx), bounds(Nfe+1);
	VecComp y(Nx);
	bounds[0] = 0; bounds[1] = 1; bounds[2] = 3; bounds[3] = 6;
	FEDVR_grid(x, w, bounds, Ngs);
	copy(y, 0); y[ibasis] = 1;
	
	VecDoub xeval(Neval), yeval(Neval);
	VecComp yeval2(Neval);
	linspace(xeval, bounds[0], bounds.end());
	for (Long i = 0; i < Neval; ++i) {
		yeval[i] = fedvr_basis(x, Ngs, ibasis, xeval[i]);
		yeval2[i] = fedvr_interp1(x, y, Ngs, xeval[i]);
	}
	yeval2 -= yeval;
	if (max_abs(yeval2) > 1e-10)
		SLS_FAIL;
}
#endif

void test_fedvr()
{
	test_gauss_lobatto();
	test_gauss();
	test_D2_mat();
	test_D_mat();
#ifdef SLS_USE_LAPACKE
	test_SHO();
	test_inf_sqr_well();
#endif
#ifdef SLS_USE_GSL
	test_fedvr_interp1();
#endif

	{ // plot fedvr basis and check orthogonality
		file_remove("fedvr_orthor.matb");
		Matb matb("fedvr_orthor.matb", "w");
		Long Nplot = 3001;
		VecDoub x_plot(Nplot);
		linspace(x_plot, -1.5, 1.5);
		for (Long Ngs = 6; Ngs <= 18; Ngs += 4) {
			CmatDoub y_plot(Nplot, Ngs);
			CmatDoub mat(Ngs, Ngs);
			VecDoub x(Ngs), w(Ngs);
			GaussLobatto_check_orthogonal(y_plot, x, w, mat, x_plot);
			save(x_plot, "x_plot"+num2str(Ngs), matb); save(y_plot, "y_plot"+num2str(Ngs), matb);
			save(x, "x"+num2str(Ngs), matb); save(w, "w"+num2str(Ngs), matb);
			save(mat, "mat"+num2str(Ngs), matb);
		}
	}
}

#ifndef SLS_TEST_ALL
int main() { test_fedvr(); }
#endif
