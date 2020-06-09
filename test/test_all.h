// do all available tests of SLISC
// TODO: test mparith.h not finished

#pragma once
#include <iostream>
void test_time(); void test_Imag(); void test_scalar_arith(); void test_Vbase(); void test_Vec();
void test_Mat(); void test_Cmat(); void test_Cmat3(); void test_Cmat4(); void test_band();
void test_Mcoo(); void test_Cmobd(); void test_Svec(); void test_Dvec(); void test_Scmat();
void test_Scmat3(); void test_dense(); void test_slice_arith(); void test_copy();
void test_compare(); void test_arithmetic(); void test_disp(); void test_random();
void test_sort(); void test_ylm(); void test_anglib(); void test_search(); void test_lin_eq();
void test_linux(); void test_file(); void test_matt(); void test_matb(); void test_fedvr();
void test_mat_fun(); void test_gsl(); void test_coulomb(); void test_unicode(); void test_bits();
void test_interp1(); void test_sha1sum();

void test_all()
{
    using std::cout; using std::endl;
    cout << "test_time()" << endl; test_time();
    cout << "test_imag()" << endl; test_Imag();
    cout << "test_scalar_arith()" << endl; test_scalar_arith();
    cout << "test_Vbase()" << endl; test_Vbase();
    cout << "test_Vec()" << endl; test_Vec();
    cout << "test_Mat()" << endl; test_Mat();
    cout << "test_Cmat()" << endl; test_Cmat();
    cout << "test_Cmat3()" << endl; test_Cmat3();
    cout << "test_Cmat4()" << endl; test_Cmat4();
    cout << "test_band()" << endl; test_band();
    cout << "test_Mcoo()" << endl; test_Mcoo();
    cout << "test_Cmobd()" << endl; test_Cmobd();
    cout << "test_Svec()" << endl; test_Svec();
    cout << "test_Dvec()" << endl; test_Dvec();
    cout << "test_Scmat()" << endl; test_Scmat();
    cout << "test_Scmat3()" << endl; test_Scmat3();
    cout << "test_dense()" << endl; test_dense();
    cout << "test_slice_arith()" << endl; test_slice_arith();
    cout << "test_copy()" << endl; test_copy();
    cout << "test_compare()" << endl; test_compare();
    cout << "test_arithmetic()" << endl; test_arithmetic();
    cout << "test_random()" << endl; test_random();
    cout << "test_sort()" << endl; test_sort();
    cout << "test_ylm()" << endl; test_ylm();
    cout << "test_anglib()" << endl; test_anglib();
    cout << "test_search()" << endl; test_search();
    cout << "test_lin_eq()" << endl; test_lin_eq();
    cout << "test_linux()" << endl; test_linux();
    cout << "test_file()" << endl; test_file();
    cout << "test_matt()" << endl; test_matt();
    cout << "test_matb()" << endl; test_matb();
    cout << "test_fedvr()" << endl; test_fedvr();
    cout << "test_mat_fun()" << endl; test_mat_fun();
    cout << "test_gsl()" << endl; test_gsl();
    cout << "test_coulomb()" << endl; test_coulomb();
    cout << "test_bits()" << endl; test_bits();
    cout << "test_interp1()" << endl; test_interp1();
	cout << "test_sha1sum()" << endl; test_sha1sum();
    cout << "test_unicode()" << endl; test_unicode();
    
    cout << "do optional tests? (y/n)" << endl;
    if (getchar() == 'y') {
        cout << "test_disp()" << endl; test_disp();
    }
    else
        cout << "optional tests skipped." << endl;
    cout << "testing successful!" << endl;
}
