// do all available tests of SLISC
// TODO: test mparith.h not finished
#pragma once
#include "test_Vec.h"
// #include "test_Cmat.h"
// #include "test_copy.h"
void test_all()
{
	using std::cout; using std::endl;
	test_Vec();
	// test_Cmat();
	// test_copy();
    cout << "testing successful!" << endl;
}
