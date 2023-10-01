#include "../SLISC/dense/Cmat3.h"

using namespace slisc;

void my_fun(Cmat3Doub_I x) { printf("Cmat3Doub\n"); }

void my_fun(Scmat3Doub_I x) { printf("Scat3Doub\n"); }

void my_fun(SvecDoub_I x) {}

void test_Cmat3()
{
	
	Long N1 = 3, N2 = 4, N3 = 2;
	Cmat3Doub v(N1, N2, N3);
	if (v.n0() != N1)
		SLS_FAIL;
	if (v.n1() != N2)
		SLS_FAIL;
	if (v.n2() != N3)
		SLS_FAIL;
	v(1, 2, 1) = 2;
	if (v(1, 2, 1) != 2)
		SLS_FAIL;
	my_fun(v);
}

#ifndef SLS_TEST_ALL
int main() { test_Cmat3(); }
#endif
