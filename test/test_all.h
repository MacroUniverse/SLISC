// do all available tests of SLISC
// TODO: test mparith.h not finished
#pragma once
#include <iostream>
void test_Imag();
void test_scalar_arith();
void test_Vbase();
void test_Vec();
void test_Mat();
void test_Cmat();
void test_Cmat3();
void test_Cmat4();
void test_Mcoo();
void test_Svec();
void test_Dvec();
void test_Scmat();
void test_dense();
void test_slice_arith();
void test_copy();
void test_compare();
void test_arithmetics();
void test_disp();
void test_random();
void test_sort();
void test_ylm();
void test_anglib();
void test_search();
void test_lin_eq();
void test_file();
void test_matt();
void test_fedvr();
void test_mat_fun();
void test_gsl();

void test_all()
{
	using std::cout; using std::endl;
	cout << "test_imag()" << endl;
	test_Imag();
	cout << "test_scalar_arith()" << endl;
	test_scalar_arith();
	cout << "test_Vbase()" << endl;
	test_Vbase();
	cout << "test_Vec()" << endl;
	test_Vec();
	cout << "test_Mat()" << endl;
	test_Mat();
	cout << "test_Cmat()" << endl;
	test_Cmat();
	cout << "test_Cmat3()" << endl;
	test_Cmat3();
	cout << "test_Cmat4()" << endl;
	test_Cmat4();
	cout << "test_Mcoo()" << endl;
	test_Mcoo();
	cout << "test_Svec()" << endl;
	test_Svec();
	cout << "test_Dvec()" << endl;
	test_Dvec();
	cout << "test_Scmat()" << endl;
	test_Scmat();
	cout << "test_dense()" << endl;
	test_dense();
	cout << "test_slice_arith()" << endl;
	test_slice_arith();
	cout << "test_copy()" << endl;
	test_copy();
	cout << "test_compare()" << endl;
	test_compare();
	cout << "test_arithmetics()" << endl;
	test_arithmetics();
	cout << "test_random()" << endl;
	test_random();
	cout << "test_sort()" << endl;
	test_sort();
	cout << "test_ylm()" << endl;
	test_ylm();
	cout << "test_anglib()" << endl;
	test_anglib();
	cout << "test_search()" << endl;
	test_search();
	cout << "test_lin_eq()" << endl;
	test_lin_eq();
	cout << "test_file()" << endl;
	test_file();
	cout << "test_matt()" << endl;
	test_matt();
	cout << "test_fedvr()" << endl;
	test_fedvr();
	cout << "test_mat_fun()" << endl;
	test_mat_fun();
	cout << "test_gsl()" << endl;
	test_gsl();
	
	cout << "do optional tests? (y/n)" << endl;
	if (getchar() == 'y') {
		cout << "test_disp()" << endl;
		test_disp();
	}
	else
		cout << "optional tests skipped." << endl;
	cout << "testing successful!" << endl;
}
