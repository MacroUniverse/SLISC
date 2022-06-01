#include "../SLISC/linbcg.h"
#include "../SLISC/copy.h"
#include "../SLISC/arithmetic.h"
#include "../SLISC/disp.h"

using namespace slisc;

// define preconditioner matrix in asolve()
// and matrix-vector multiplication in atimes()
class LinbcgDoub2: public LinbcgDoub
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

#ifdef SLS_USE_QUAD_MATH
class LinbcgQdoub2: public LinbcgQdoub
{
	void asolve(VecQdoub_I b, VecQdoub_O x, const Int itrnsp) {
		copy(x, b);
	}
	void atimes(VecQdoub_I x, VecQdoub_O r, const Int itrnsp) {
		CmatQdoub a(3,3), at(3,3); assign(a, 1.Q, 0.Q, 5.Q, 0.Q, 3.Q, 0.Q, 2.Q, 4.Q, 6.Q);
		trans(at, a);
		if (!itrnsp)
			mul(r, a, x);
		else
			mul(r, at, x);
	}
};
#endif

void test_linbcg()
{
	{
		LinbcgDoub2 solver;
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

#ifdef SLS_USE_QUAD_MATH
	{
		LinbcgQdoub2 solver;
		CmatQdoub a(3,3); assign(a, 1.Q, 0.Q, 5.Q, 0.Q, 3.Q, 0.Q, 2.Q, 4.Q, 6.Q);
		VecQdoub x(3), x1(3), b(3);
		assign(b, 6.Q, 7.Q, 8.Q); copy(x, 0.Q);
		assign(x1, -5.Q, -5.Q, 5.5Q);
		Qdoub err; Int iter;
		solver.solve(b, x, 1, 1e-8Q, 100, iter, err);
		// cout << "a = " << endl; disp(a);
		// cout << "b = " << endl; disp(b);
		// cout << "x = " << endl; disp(x);
		// cout << "iter = " << iter << endl;
		// cout << "err = " << err << endl;
		x1 -= x;
		if (max_abs(x1) > 1e-30)
			SLS_ERR("failed!");
	}
#endif
}
