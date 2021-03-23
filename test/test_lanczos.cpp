#include "../SLISC/disp.h"
#include "../SLISC/lanczos.h"
#include "../SLISC/random.h"

void test_lanczos()
{
	using namespace slisc;
	Long N = 5;
	VecComp x(N), y(N); rand(x); x /= norm(x);
	CmatDoub H(N, N);
	for (Long i = 0; i < N; ++i)
		H(i,i) = 1;
	for (Long i = 1; i < N; ++i) {
		H(i,i-1) = 0.5; H(i-1,i) = 0.5;
	}
	Doub err = expv(y, H, x, 0, N-1);
	cout << "err = " << err << endl;
	disp(x);
	disp(y);
}
