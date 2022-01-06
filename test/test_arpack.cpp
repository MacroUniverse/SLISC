#include "../../Arpack_test/include/arssym.h"
// #include "../../Arpack_test/examples/product/sym/symsol.h"
#include "../SLISC/arithmetic.h"
#include "../SLISC/disp.h"
using namespace slisc;

class MyMatrix {

private:
		CmatDoub a;
public:
	MyMatrix(Long N) {
		a.resize(N, N); copy(a, 0);
		for (Long i = 0; i < N-1; ++i) {
			a(i, i+1) = a(i+1, i) = 1;
		}
	}

	void mul(Doub *v, Doub* w) {
		SvecDoub sv(v, a.n1());
		SvecDoub sw(w, a.n0());
		slisc::mul(sw, a, sv);
	}
};

void test_arpack()
{
	Long N = 5;
	MyMatrix a(N);
  	ARSymStdEig<Doub, MyMatrix> dprob(N, 3, &a, &MyMatrix::mul, "SM");
	dprob.FindEigenvectors();

	// print solution:
	// Long n = dprob.GetN(); // # dim
	// Long mode  = dprob.GetMode(); // 1:regular 3:shift
	// Long Nreq = dprob.GetNev(); // # of requested eigenvalues
	// Long Narnl = dprob.GetNcv(); // # of Arnoldi vectors generated
	// Long Niter = dprob.GetIter(); // # of iterations taken
	// Long Nfound = dprob.EigenvaluesFound(); // # of eigenvalues found
	// Long Nev = dprob.EigenvectorsFound(); // # of eigenvectors found

	Long Nconv = dprob.ConvergedEigenvalues(); // # of converged eigenvalues
	VecDoub eval(N);
	for (Long i = 0; i < Nconv; ++i)
		eval[i] = dprob.Eigenvalue(i);

	if (abs(eval[0] + 1) > 1e-10)
		SLS_ERR("failed!");
	if (abs(eval[1]) > 1e-10)
		SLS_ERR("failed!");
	if (abs(eval[2] - 1) > 1e-10)
		SLS_ERR("failed!");

	VecDoub av(N);
	for (Long j = 0; j < Nconv; ++j) {
		SvecDoub v(dprob.RawEigenvector(j), N);
		if (abs(norm(v) - 1) > 1e-10)
			SLS_ERR("failed!");
		a.mul(v.p(), av.p());
		for (Long i = 0; i < N; ++i)
			av[i] -= eval[j] * v[i];
		// cout << j << ": " << abs(norm(av)) << endl;
		if (abs(norm(av)) > 1e-10)
			SLS_ERR("failed!");
	}
}
