// do all available tests of SLISC
// TODO: test mparith.h not finished
#pragma once
#include <iostream>
void test_Vbase();
void test_Vec();
void test_Mat();
void test_Cmat();
void test_copy();
void test_compare();
void test_complex_arith();
void test_arithmetics();
void test_disp();

void test_all()
{
	using std::cout; using std::endl;
	cout << "test_complex_arith()" << endl;
	test_complex_arith();
	cout << "test_Vbase()" << endl;
	test_Vbase();
	cout << "test_Vec()" << endl;
	test_Vec();
	cout << "test_Mat()" << endl;
	test_Mat();
	cout << "test_Cmat()" << endl;
	test_Cmat();
	cout << "test_copy()" << endl;
	test_copy();
	cout << "test_compare()" << endl;
	test_compare();
	cout << "test_arithmetics()" << endl;
	test_arithmetics();
	cout << "test_disp()" << endl;
	test_disp();
    cout << "testing successful!" << endl;
}
