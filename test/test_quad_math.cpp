#ifdef SLS_USE_QUAD_MATH
#include "../SLISC/quad_math.h"
#endif
#include "../SLISC/Cmat.h"

void test_quad_math()
{
#ifdef SLS_USE_QUAD_MATH
	using namespace slisc;
	// test libquadmath
	// cout.precision(5);
	// cout << "FLT128_MAX = " << FLT128_MAX << endl;
	// cout << "FLT128_MIN = " << FLT128_MIN << endl;
	// cout << "FLT128_EPSILON = " << FLT128_EPSILON << endl;
	// cout << "FLT128_DENORM_MIN = " << FLT128_DENORM_MIN << endl;
	if (FLT128_MANT_DIG != 113)
		SLS_ERR("failed!");
	if (FLT128_MAX_EXP != 16384)
		SLS_ERR("failed!");
	if (FLT128_DIG != 33)
		SLS_ERR("failed!");
	cout.precision(34);
	if (sqrt(3.Q) != 1.7320508075688772935274463415058724Q)
		SLS_ERR("failed!");
	
	// CmatQdoub qmat(2, 2);
	// for (Long i = 0; i < 4; ++i) {
	// 	qmat[i] = i + PI;
	// 	cout << qmat[i] << endl;
	// }

	// Qcomp q2 = Qcomp(2, 3);
	// cout << q2 << endl;
#endif
}
