// do all available tests of SLISC
// TODO: test mparith.h not finished

#pragma once
#include <iostream>
#define SLS_TEST(name) do{void test_##name(); cout << "test_" << #name << ".cpp" << endl; test_##name();} while(0)

void test_all()
{
    using std::cout; using std::endl;
    SLS_TEST(anglib); SLS_TEST(arb); SLS_TEST(arithmetic); SLS_TEST(arpack); SLS_TEST(band); SLS_TEST(bisection);
    SLS_TEST(Bit); SLS_TEST(boost); SLS_TEST(Cmat); SLS_TEST(Cmat3); SLS_TEST(Cmat4); SLS_TEST(Cmobd);
    SLS_TEST(compare); SLS_TEST(complex_arith); SLS_TEST(copy); SLS_TEST(coulomb); SLS_TEST(cpp11); SLS_TEST(cut);
    SLS_TEST(dense); SLS_TEST(Dvec); SLS_TEST(Eigen); SLS_TEST(expokit); SLS_TEST(fedvr); SLS_TEST(file);
    SLS_TEST(global); SLS_TEST(GSL); SLS_TEST(hydrogen); SLS_TEST(hypergeom); SLS_TEST(Imag); SLS_TEST(interp1);
    SLS_TEST(lanczos); SLS_TEST(legendreP); SLS_TEST(linbcg); SLS_TEST(linux); SLS_TEST(lin_eq); SLS_TEST(Mat);
    SLS_TEST(matt); SLS_TEST(matb); SLS_TEST(mat_fun); SLS_TEST(Mcoo); SLS_TEST(quad_math); SLS_TEST(random);
    SLS_TEST(scalar_arith); SLS_TEST(Scmat); SLS_TEST(Scmat3); SLS_TEST(search); SLS_TEST(sha1sum); SLS_TEST(sort);
    SLS_TEST(string); SLS_TEST(Svec); SLS_TEST(time); SLS_TEST(unicode); SLS_TEST(Vbase); SLS_TEST(Vec); SLS_TEST(ylm);
    
    cout << "do optional tests? (y/n)" << endl;
    if (getchar() == 'y') {
        SLS_TEST(disp); SLS_TEST(input);
        cout << "WARNING: test_coulomb() has memory leak from the library itself!" << endl;
    }
    else
        cout << "optional tests skipped." << endl;
    cout << "testing successful!" << endl;
}
