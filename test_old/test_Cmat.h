// test dense containers here
#pragma once
#include "../SLISC/Cmat.h"
#include "../SLISC/arithmetic.h"

void test_Cmat()
{
    using namespace slisc;
	CmatDoub a2(4, 5), b2(4, 5);
	linspace(a2, 1, 20); copy(b2, a2);
	// resize_cpy(b2, 7, 9);
	// if (slice(b2, 0, 4, 0, 5) != a2)
	// 	SLS_ERR("failed!");
	// resize_cpy(b2, 4, 5);
	// if (b2 != a2)
	// 	SLS_ERR("failed!");
}
