#include "../SLISC/Ddoub.h"

// >> and << operating on signed integer is "undefined"!
// Char and Uchar reinterpret cast conserves bit, but static cast might not (for older architecture)

void test_Ddoub()
{
	using std::sin;
    using namespace slisc;
	Ddoub x(1.1Q), y(3.1Q);
	x += y;
	cout << x.x << endl;
	y = sin(x);
	cout << y.x << endl;
}
