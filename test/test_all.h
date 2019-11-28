// do all available tests of SLISC
// TODO: test mparith.h not finished
#pragma once
#include "test_Vec.h"
void test_all()
{
	using std::cout; using std::endl;
	test_Vec();
    cout << "testing successful!" << endl;
}
