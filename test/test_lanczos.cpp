#include "../SLISC/lanczos.h"
#include "../SLISC/random.h"

void test_lanczos()
{
	using namespace slisc;
	Long N = 5;
	VecComp x(N), y(N); rand(x);
	CmatDoub H(N, N);
	for (Long i = 0; i < N; ++i)
		H(i,i) = 1;
	for (Long i = 1; i < N; ++i) {
		H(i,i-1) = 0.5; H(i-1,i) = 0.5;
	}
	expv(y, H, x, 1, N);
}
