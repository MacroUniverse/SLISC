#include "../SLISC/dense/Cmat.h"
#include "../SLISC/prec/quad_math.h"
#include "../SLISC/util/random.h"

void test_quad_math()
{
	using namespace slisc;
#ifdef SLS_USE_QUAD_MATH
	// cout << (3.5Q < 3.7Q) << endl;
	// cout << (3.5Q == 3.5Q) << endl;
	// cout << (3.5Q != 3.5Q) << endl;
	for (Long i = 0; i < 20; ++i) {
		Qdoub x = randQdoub(), y = randQdoub();
		SLS_ASSERT(sin(x) == sinq(x));
		SLS_ASSERT(std::atan2(x, y) == atan2q(x,y));

		Qcomp z_std = randQcomp(), c_std = randQcomp();
		__complex128 z_c = to_c(z_std);
		SLS_ASSERT(sin(z_std) == std::to_std(csinq(z_c)));
		SLS_ASSERT(to_c(pow(z_std, c_std)) == cpowq(to_c(z_std), to_c(c_std)));
	}

	auto old_prec = std::cout.precision();
	std::cout.precision(34);
	// test libquadmath
	// cout.precision(5);
	// cout << "FLT128_MAX = " << FLT128_MAX << endl;
	// cout << "FLT128_MIN = " << FLT128_MIN << endl;
	// cout << "FLT128_EPSILON = " << FLT128_EPSILON << endl;
	// cout << "FLT128_DENORM_MIN = " << FLT128_DENORM_MIN << endl;
	if (FLT128_MANT_DIG != 113)
		SLS_FAIL;
	if (FLT128_MAX_EXP != 16384)
		SLS_FAIL;
	if (FLT128_DIG != 33)
		SLS_FAIL;
	if (sqrt(3.Q) != 1.7320508075688772935274463415058724Q)
		SLS_FAIL;
	
	// CmatQdoub qmat(2, 2);
	// for (Long i = 0; i < 4; ++i) {
	// 	qmat[i] = i + PI;
	// 	cout << qmat[i] << endl;
	// }

	// Qcomp q2 = Qcomp(2, 3);
	// cout << q2 << endl;
	std::cout.precision(old_prec);
#else
	cout << "---------- disabled! ----------" << endl;
#endif
}
