#include "../SLISC/dense/Mat.h"

void test_Mat()
{
	using namespace slisc;
	MatDoub a(3, 4);
	a(2, 3) = 2;
	if (a.end() != 2)
		SLS_FAIL;
}

#ifndef SLS_TEST_ALL
int main() { test_Mat(); }
#endif
