#include "../SLISC/lin/linbcg.h"
#include "../SLISC/arith/reorder.h"
// #include "../SLISC/str/disp.h"

using namespace slisc;

// define preconditioner matrix in asolve()
// and matrix-vector multiplication in atimes()
class LinbcgDoub2: public LinbcgDoub
{
	void asolve(VecDoub_I b, VecDoub_O x, const Int itrnsp) {
		copy(x, b);
	}
	void atimes(VecDoub_I x, VecDoub_O r, const Int itrnsp) {
		CmatDoub a(3,3), at(3,3); copy(a, {1., 0., 5., 0., 3., 0., 2., 4., 6.});
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
		CmatQdoub a(3,3), at(3,3); copy(a, {1.Q, 0.Q, 5.Q, 0.Q, 3.Q, 0.Q, 2.Q, 4.Q, 6.Q});
		trans(at, a);
		if (!itrnsp)
			mul(r, a, x);
		else
			mul(r, at, x);
	}
};
#endif

int main()
{
	{
		LinbcgDoub2 solver;
		CmatDoub a(3,3); copy(a, {1., 0., 5., 0., 3., 0., 2., 4., 6.});
		VecDoub x(3), x1(3), b(3);
		copy(b, {6., 7., 8.}); copy(x, 0);
		copy(x1, {-5., -5., 5.5});
		Doub err; Int iter;
		solver.solve(b, x, 1, 1e-8, 100, iter, err);
		// cout << "a = " << endl; disp(a);
		// cout << "b = " << endl; disp(b);
		// cout << "x = " << endl; disp(x);
		// cout << "iter = " << iter << endl;
		// cout << "err = " << err << endl;
		x1 -= x;
		if (max_abs(x1) > 1e-10)
			SLS_FAIL;
	}

	{
		CmatDoub a(3,3); copy(a, {1., 0., 5., 0., 3., 0., 2., 4., 6.});
		VecDoub x(3), x1(3), b(3); VecDoub wsp_d(3*8);
		copy(b, {6., 7., 8.}); copy(x, 0);
		copy(x1, {-5., -5., 5.5});
		Doub relres; Long iter;
		if (bicgstab_matlab_optim(relres, iter, x, a, b,  1e-15, 30, wsp_d) != 0) SLS_FAIL;
		// cout << "a = " << endl; disp(a);
		// cout << "b = " << endl; disp(b);
		// cout << "x = " << endl; disp(x);
		// cout << "iter = " << iter << endl;
		// cout << "relres = " << relres << endl;
		x1 -= x;
		if (max_abs(x1) > 1e-10)
			SLS_FAIL;
	}

	{
		CmatComp a(3,3); copy(a, {Comp(1,1), Comp(0,0), Comp(5,2), Comp(0,0), Comp(3.,-1), Comp(0,0), Comp(2,-3), Comp(4,5), Comp(6,-1)});
		VecComp x(3), b1(3), b(3); VecComp wsp_c(3*8);
		copy(b, {Comp(6,3), Comp(7,-3), Comp(8,-1)}); copy(x, 0);
		Doub relres; Long iter;
		if (bicgstab_matlab_optim(relres, iter, x, a, b,  1e-15, 30, wsp_c) != 0) SLS_FAIL;
		// cout << "a = " << endl; disp(a);
		// cout << "b = " << endl; disp(b);
		// cout << "x = " << endl; disp(x);
		// cout << "iter = " << iter << endl;
		// cout << "relres = " << relres << endl;
		mul(b1, a, x); b1 -= b;
		if (max_abs(b1) > 1e-13)
			SLS_FAIL;
	}

#ifdef SLS_USE_QUAD_MATH
	{
		LinbcgQdoub2 solver;
		CmatQdoub a(3,3); copy(a, {1.Q, 0.Q, 5.Q, 0.Q, 3.Q, 0.Q, 2.Q, 4.Q, 6.Q});
		VecQdoub x(3), x1(3), b(3);
		copy(b, {6.Q, 7.Q, 8.Q}); copy(x, 0.Q);
		copy(x1, {-5.Q, -5.Q, 5.5Q});
		Qdoub err; Int iter;
		solver.solve(b, x, 1, 1e-8Q, 100, iter, err);
		// cout << "a = " << endl; disp(a);
		// cout << "b = " << endl; disp(b);
		// cout << "x = " << endl; disp(x);
		// cout << "iter = " << iter << endl;
		// cout << "err = " << err << endl;
		x1 -= x;
		if (max_abs(x1) > 1e-30)
			SLS_FAIL;
	}
#endif


	// for symmetric, no preconditioner
	{
		CmatDoub a(3,3); copy(a, {1., 0., 5., 0., 3., 4., 5., 4., 6.});
		VecDoub x(3), b1(3), b(3); copy(x, 1);
		copy(b, {6., 7., 8.}); copy(x, 0);
		Doub err, tol = 1e-8; Int iter, itmax = 100, itol = 4;
		VecDoub wsp(3*6); SvecDoub swsp = cut(wsp, 0, 3*6);
		lin_eq_bcg_sym(iter, err, x, a, b, itol, tol, itmax, swsp);
		// cout << "a = " << endl; disp(a);
		// cout << "b = " << endl; disp(b);
		// cout << "x = " << endl; disp(x);
		// cout << "iter = " << iter << endl;
		// cout << "err = " << err << endl;
		mul(b1, a, x);
		b1 -= b;
		if (max_abs(b1) > 1e-10)
			SLS_FAIL;
	}
}
