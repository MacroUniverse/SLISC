#include "../SLISC/lin/linbcg.h"
#include "../SLISC/arith/reorder.h"
// #include "../SLISC/str/disp.h"

using namespace slisc;

// define preconditioner matrix in asolve()
// and matrix-vector multiplication in atimes()
class LinbcgDoub2: public LinbcgDoub
{
	void asolve(SvbaseDoub_I b, SvbaseDoub_O x, const Int itrnsp) {
		copy(x, b);
	}
	void atimes(SvbaseDoub_I x, SvbaseDoub_O r, const Int itrnsp) {
		CmatDoub a(3,3), at(3,3); copy(a, {1., 0., 5., 0., 3., 0., 2., 4., 6.});
		trans(at, a);
		if (!itrnsp)
			mul((SvecDoub_O)r, a, (SvecDoub_I)x);
		else
			mul((SvecDoub_O)r, at, (SvecDoub_I)x);
	}
};

#ifdef SLS_USE_QUAD_MATH
class LinbcgQdoub2: public LinbcgQdoub
{
	void asolve(SvbaseQdoub_I b, SvbaseQdoub_O x, const Int itrnsp) {
		copy(x, b);
	}
	void atimes(SvbaseQdoub_I x, SvbaseQdoub_O r, const Int itrnsp) {
		CmatQdoub a(3,3), at(3,3); copy(a, {1.Q, 0.Q, 5.Q, 0.Q, 3.Q, 0.Q, 2.Q, 4.Q, 6.Q});
		trans(at, a);
		if (!itrnsp)
			mul((SvecQdoub_O)r, a, (SvecQdoub_I)x);
		else
			mul((SvecQdoub_O)r, at, (SvecQdoub_I)x);
	}
};
#endif

void test_linbcg()
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
		VecDoub x(3), x1(3), b(3);
		VecUchar wsp_mem(bicgstab_matlab_optim_Nwsp<Doub>(3));
		WorkSpace wsp(wsp_mem);
		copy(b, {6., 7., 8.}); copy(x, 0);
		copy(x1, {-5., -5., 5.5});
		Doub relres; Long iter;
		auto mul_fun = [&a](SvbaseDoub_O y, SvbaseDoub_I x) { mul((SvecDoub_O)y, a, (SvecDoub_I)x); };
		if (bicgstab_matlab_optim(relres, iter, x, mul_fun, b,  1e-15, 30, wsp) != 0) SLS_FAIL;
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
		VecComp x(3), b1(3), b(3);
		VecUchar wsp_mem(bicgstab_matlab_optim_Nwsp<Comp>(3));
		WorkSpace wsp(wsp_mem);
		copy(b, {Comp(6,3), Comp(7,-3), Comp(8,-1)}); copy(x, 0);
		Doub relres; Long iter;
		auto mul_fun = [&a](SvbaseComp_O y, SvbaseComp_I x) { mul((SvecComp_O)y, a, (SvecComp_I)x); };
		if (bicgstab_matlab_optim(relres, iter, x, mul_fun, b,  1e-15, 30, wsp) != 0) SLS_FAIL;
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
		auto mul_fun = [&a](SvbaseDoub_O y, SvbaseDoub_I x) { mul((SvecDoub_O)y, a, (SvecDoub_I)x); };
		lin_eq_bcg_sym(iter, err, x, mul_fun, b, itol, tol, itmax, swsp);
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

#ifndef SLS_TEST_ALL
int main() { test_linbcg(); }
#endif
