#include "nr3.h"

struct SVD {
    Int m,n;
    MatDoub u,v;
    VecDoub w;
    Doub eps, tsh;
    SVD(MatDoub_I &a) : m(a.nrows()), n(a.ncols()), u(a), v(n,n), w(n) {
        eps = std::numeric_limits<Doub>::epsilon();
        decompose();
        reorder();
        tsh = 0.5*sqrt(m+n+1.)*w[0]*eps;
    }

    void solve(VecDoub_I &b, VecDoub_O &x, Doub thresh = -1.);
    void solve(MatDoub_I &b, MatDoub_O &x, Doub thresh = -1.);

    Int rank(Doub thresh = -1.);
    Int nullity(Doub thresh = -1.);
    MatDoub range(Doub thresh = -1.);
    MatDoub nullspace(Doub thresh = -1.);

    Doub inv_condition() {
        return (w[0] <= 0. || w[n-1] <= 0.) ? 0. : w[n-1]/w[0];
    }

    void decompose();
    void reorder();
    Doub pythag(const Doub a, const Doub b);
};

