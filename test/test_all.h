// do all available tests of SLISC
// TODO: test mparith.h not finished
#pragma once
#include <iostream>
void test_Vbase();
void test_all()
{
	using std::cout; using std::endl;
	test_Vbase();
    cout << "testing successful!" << endl;
}
