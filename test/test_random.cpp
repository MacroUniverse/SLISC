#include "../SLISC/random.h"
#include "../SLISC/search.h"

void test_random()
{
    using namespace slisc;
    using internal::Ran;
	{
		// same seed
		Ran rangen1(1234), rangen2(1234);
		Long i, N = 10;
		for (i = 0; i < 5; ++i)
			if (rangen1.doub() != rangen2.doub())
				SLS_FAIL;
		VecDoub vx(N), vx1(N);
		rand(vx); rand(vx1);
		if (vx == vx1)
			SLS_FAIL;
		if (max(vx) > 1.)
			SLS_FAIL;
		if (max(vx) < 0.)
			SLS_FAIL;
		VecComp vc(N), vc1(N);
		rand(vc); rand(vc1);
		if (vc == vc1)
			SLS_FAIL;
	}
    
	// randPerm
	{
		Long N = 20;
		VecInt v(N);
		randPerm(v);
		for (Long i = 0; i < N; ++i) {
			if (v[i] < 0 || v[i] >= N)
				SLS_FAIL;
		}
		if (find_repeat(v) >= 0)
			SLS_FAIL;
	}

#ifdef SLS_USE_QUAD_MATH
	{
		auto old_prec = cout.precision();
		cout.precision(35);
		Qdoub q;
		for (Long i = 0; i < 20; ++i) {
			q = randQdoub();
			if (q < 0 || q > 1)
				SLS_FAIL;
		}
		cout.precision(old_prec);
	}
#endif
}
