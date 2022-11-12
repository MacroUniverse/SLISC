// do all available tests of SLISC
#pragma once
#include "../SLISC/unicode.h"

#define SLS_TEST(name) do{ if (test_name.empty() || test_name == #name) {void test_##name(); cout << "test_" << #name << ".cpp" << endl; test_##name();} } while(0)

#ifdef SLS_USE_MSVC
slisc::turn_on_floating_exceptions yes_turn_on_floating_exceptions;
slisc::set_windows_console_utf8 yes_set_windows_console_utf8;
#endif

void test_all(const std::string &test_name)
{
	using std::cout; using std::endl;
	SLS_TEST(anglib);
	SLS_TEST(arb);
	SLS_TEST(arithmetic);
	SLS_TEST(arpack);
	SLS_TEST(band);
	SLS_TEST(bin_tree);
	SLS_TEST(bisection);
	SLS_TEST(Bit);
	SLS_TEST(boost);
	SLS_TEST(Cmat);
	SLS_TEST(Cmat3);
	SLS_TEST(Cmat4);
	SLS_TEST(Cmobd);
	SLS_TEST(compare);
	SLS_TEST(complex_arith);
	SLS_TEST(copy);
	SLS_TEST(coulomb);
	SLS_TEST(cpp11);
	SLS_TEST(cut);
	SLS_TEST(dense);
	SLS_TEST(Dcmat);
	SLS_TEST(disjoint_sets);
	SLS_TEST(Dvec);
	SLS_TEST(eigen);
	SLS_TEST(expokit);
	SLS_TEST(fedvr);
	SLS_TEST(file);
	SLS_TEST(global);
	SLS_TEST(graph);
	SLS_TEST(GSL);
	SLS_TEST(heap);
	SLS_TEST(huffman);
	SLS_TEST(hungarian);
	SLS_TEST(hydrogen);
	SLS_TEST(hypergeom);
	SLS_TEST(Imag);
	SLS_TEST(interp1);
	SLS_TEST(json);
	SLS_TEST(lanczos);
	SLS_TEST(legendreP);
	SLS_TEST(linbcg);
	SLS_TEST(linux);
	SLS_TEST(lin_eq);
	SLS_TEST(matfile);
	SLS_TEST(matt);
	SLS_TEST(matb);
	SLS_TEST(mat_fun);
	SLS_TEST(Mcoo);
	SLS_TEST(odeint);
	SLS_TEST(quad_math);
	SLS_TEST(queue);
	SLS_TEST(random);
	SLS_TEST(SafeInt);
	SLS_TEST(scalar_arith);
	SLS_TEST(Scmat);
	SLS_TEST(Scmat3);
	SLS_TEST(search);
	SLS_TEST(sha1sum);
	SLS_TEST(sing_list);
	SLS_TEST(sort);
	SLS_TEST(sqlite);
	SLS_TEST(string);
	SLS_TEST(Svec);
	SLS_TEST(time);
	SLS_TEST(unicode);
	SLS_TEST(Vbase);
	SLS_TEST(Vec);
	SLS_TEST(ylm);
	
	if (test_name.empty()) {
		cout << "do optional tests? (y/[n])" << endl;
		if (getchar() == 'y') {
			SLS_TEST(disp);
			SLS_TEST(input);
		}
		else
			cout << "optional tests skipped." << endl;
	}
	cout << "end of testing!" << endl;
}
