#include "../../Arpack_test/include/arssym.h"
// #include "../../Arpack_test/examples/product/sym/symsol.h"
#include "../SLISC/arithmetic.h"
#include "../SLISC/disp.h"
using namespace slisc;

class MyMatrix {

private:
	Long m_N;
	Long m_count;

public:
	MyMatrix(Long N): m_N(N), m_count(0) {}

	void mul(Doub *v, Doub* w) {
		// matrix-vector mul with matrix A: subdiagonal = 1, other = 0
		for (Long i = 0; i < m_N-1; ++i)
			w[i] = v[i+1];
		w[m_N-1] = 0;
		for (Long i = 0; i < m_N-1; ++i)
			w[i+1] += v[i];

		// report
		++m_count;
		if (m_count % 100 == 0) {
            // cout << "mul count: " << m_count << ", err = " << err(v, w) << endl;
        }
	}

	// mean value / eigen value
    Doub mean(const Doub *v, const Doub *w) const
    {
        SvecDoub_c sv(v, m_N), sw(w, m_N);
        return dot(sv, sw)/dot(sv, sv);
    }

	Doub err(const Doub *v, const Doub *w) const
	{
		Doub val = mean(v, w);
		Doub nrm2 = 0;
		for (Long i = 0; i < m_N; ++i)
			nrm2 += sqr(abs(w[i] - val * v[i]));
		return sqrt(nrm2);
	}
};

void test_arpack()
{
	Long N = 10, Nsol = 3;
	MyMatrix a(N);
  	ARSymStdEig<Doub, MyMatrix> dprob(N, Nsol, &a, &MyMatrix::mul, "SM");
	dprob.ChangeMaxit(1000000);
	dprob.ChangeTol(1e-2); // ||Av - lambda v|| is usually 10-100 times smaller thant Tol
	dprob.FindEigenvectors();
	// cout << "\n\n============ done ===============\n\n" << endl;

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

	VecDoub av(N);
	for (Long j = 0; j < Nconv; ++j) {
		SvecDoub v(dprob.RawEigenvector(j), N);
		if (abs(norm(v) - 1) > 1e-10)
			SLS_ERR("failed!");
		a.mul(v.p(), av.p());
		Doub err = a.err(v.p(), av.p());
		// cout << "err = " << err << endl;
		if (err > 1e-2)
			SLS_ERR("failed!");
	}
}
