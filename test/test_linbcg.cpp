#include "../SLISC/linbcg.h"
#include "../SLISC/copy.h"
#include "../SLISC/arithmetic.h"
#include "../SLISC/disp.h"

using namespace slisc;

// define preconditioner matrix in asolve()
// and matrix-vector multiplication in atimes()
class Linbcg2: public Linbcg
{
	void asolve(VecDoub_I b, VecDoub_O x, const Int itrnsp) {
		copy(x, b);
	}
	void atimes(VecDoub_I x, VecDoub_O r, const Int itrnsp) {
		CmatDoub a(3,3), at(3,3); assign(a, 1., 0., 5., 0., 3., 0., 2., 4., 6.);
		trans(at, a);
		if (!itrnsp)
			mul(r, a, x);
		else
			mul(r, at, x);
	}
};

void test_linbcg()
{
	Linbcg2 solver;
	CmatDoub a(3,3); assign(a, 1., 0., 5., 0., 3., 0., 2., 4., 6.);
	VecDoub x(3), x1(3), b(3);
	assign(b, 6., 7., 8.); copy(x, 0);
	assign(x1, -5., -5., 5.5);
	Doub err; Int iter;
	solver.solve(b, x, 1, 1e-8, 100, iter, err);
	// cout << "a = " << endl; disp(a);
	// cout << "b = " << endl; disp(b);
	// cout << "x = " << endl; disp(x);
	// cout << "iter = " << iter << endl;
	// cout << "err = " << err << endl;
	x1 -= x;
	if (max_abs(x1) > 1e-10)
		SLS_ERR("failed!");
}
