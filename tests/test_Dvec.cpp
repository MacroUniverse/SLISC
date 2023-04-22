#include "../SLISC/arith/arith2.h"

int main()
{
	using namespace slisc;
	DvecDoub cut;
	Long N = 6;
	VecDoub v(N); linspace(v, 1, N);
    cut.set(v.p(), N/2, 2);
	for (Long i = 0; i < N/2; ++i) {
		if (cut[i] != v[2*i])
			SLS_FAIL;
	}
}
