// do all available tests of SLISC
// TODO: test mparith.h not finished
#pragma once
#include <iostream>
void test_Vbase();
void test_Vec();
void test_Cmat();

void test_all()
{
	using std::cout; using std::endl;
	cout << "test_Vbase()" << endl;
	test_Vbase();
	cout << "test_Vec()" << endl;
	test_Vec();
	cout << "test_Cmat()" << endl;
	test_Cmat();
    cout << "testing successful!" << endl;
}
