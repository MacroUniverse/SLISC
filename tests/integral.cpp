#include "../SLISC/sci/integral.h"

using namespace slisc;

static Long Ncall_fun1 = 0;

static Doub fun1(Doub x)
{
	++Ncall_fun1;
	return sin(1/x);
}

void test_integral()
{
	{
		Ncall_fun1 = 0;
		Doub a = 1e-2, b = 1;
		Doub ret = integral_romb(fun1, a, b);
		Doub ret0 = 0.5039818931754155; // from mathematica
		Doub rel_err = abs(ret-ret0)/ret0;
		SLS_ASSERT(rel_err <= 1.0e-10);
		// cout << "Ncall_fun1 = " << Ncall_fun1 << endl;
	}
	{
		Ncall_fun1 = 0;
		Doub a = 5e-3, b = 1;
		Doub ret = integral_romb(fun1, a, b);
		Doub ret0 = 0.5040551022999705; // from mathematica
		Doub rel_err = abs(ret-ret0)/ret0;
		SLS_ASSERT(rel_err <= 1.0e-10);
		// cout << "Ncall_fun1 = " << Ncall_fun1 << endl;
	}
}

#ifndef SLS_TEST_ALL
int main() { test_integral(); }
#endif
