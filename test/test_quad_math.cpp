#include "../SLISC/quad_math.h"

void test_quad_math()
{
	using namespace slisc;
	// test Ldoub
	Ldoub x = 3.1415926535897932384626433832795028841971693993751058209749445L;
	cout.precision(10);
	cout << "pi = " << x << endl;
	cout << "sizeof(Doub) = " << sizeof(Doub) << endl;
	cout << "sizeof(Ldoub) = " << sizeof(Ldoub) << endl;
	cout << "std::numeric_limits<Doub>::denorm_min() = " << std::numeric_limits<Doub>::denorm_min() << endl;
	cout << "std::numeric_limits<Ldoub>::denorm_min() = " << std::numeric_limits<Ldoub>::denorm_min() << endl;
	cout << "std::numeric_limits<Doub>::max() = " << std::numeric_limits<Doub>::max() << endl;
	cout << "std::numeric_limits<Ldoub>::max() = " << std::numeric_limits<Ldoub>::max() << endl;
	cout << "std::numeric_limits<Doub>::min() = " << std::numeric_limits<Doub>::min() << endl;
	cout << "std::numeric_limits<Ldoub>::min() = " << std::numeric_limits<Ldoub>::min() << endl;
	cout << "std::numeric_limits<Doub>::epsilon() = " << std::numeric_limits<Doub>::epsilon() << endl;
	cout << "std::numeric_limits<Ldoub>::epsilon() = " << std::numeric_limits<Ldoub>::epsilon() << endl;
	cout << "std::numeric_limits<Doub>::digits10 = " << std::numeric_limits<Doub>::digits10 << endl;
	cout << "std::numeric_limits<Ldoub>::digits10 = " << std::numeric_limits<Ldoub>::digits10 << endl;
	cout << "std::numeric_limits<__float128>::digits10 = " << std::numeric_limits<__float128>::digits10 << endl;

	cout.precision(30);
	cout << "sqrt(2.)       = " << sqrt(2.) << endl;
	cout << "sqrt(Ldoub(2)) = " << sqrt(Ldoub(2.L)) << endl;
	cout << "sqrt(sym(2))   = " << "1.41421356237309504880168872421" << endl;
	// ====================
	// test libquadmath
	cout.precision(5);
	cout << "FLT128_MAX = " << FLT128_MAX << endl;
	cout << "FLT128_MIN = " << FLT128_MIN << endl;
	cout << "FLT128_EPSILON = " << FLT128_EPSILON << endl;
	cout << "FLT128_DENORM_MIN = " << FLT128_DENORM_MIN << endl;
	cout << "FLT128_MANT_DIG = " << FLT128_MANT_DIG << endl;
	cout << "FLT128_MAX_EXP = " << FLT128_MAX_EXP << endl;
	cout << "FLT128_DIG = " << FLT128_DIG << endl;
	cout.precision(34);
	cout << "M_PIq = " << M_PIq + 2*M_PIq << endl;
	cout << "sqrtq(3) = " << sqrtq(3) << endl;
	// 
}
