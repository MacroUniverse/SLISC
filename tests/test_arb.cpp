#include <iostream>
#ifdef SLS_USE_ARB
#include <gmp.h>
#include <flint/flint.h>
// #include <flint/fmpz.h>
#include <arb_hypgeom.h>
#include "../SLISC/prec/arb_extension.h"
#endif

int main()
{
#ifdef SLS_USE_ARB
	using namespace slisc;
	SLS_ASSERT(sizeof(slong) == sizeof(Llong)); // test compatibility

	// test arb_t: arf_t with rigorous error bound
	arb_t a; arb_init(a);
	slong prec = 100; // precision digits (in binary)
	arb_set_str(a, "1.23456789022345678903234567890423456789e12345678", prec);
	char *cs;
	Str str = cs = arb_get_str(a, 50, ARB_STR_MORE);
	SLS_ASSERT(str == Str("[1.2345678902234567890323456789042238629443408769906e+12345678 +/- 1.05e+12345648]"));
	free(cs); arb_clear(a);

	// arf_t f;
	// arf_set(f, &a[0].mid);

	{
		arb_t a; arb_init(a);
		arb_const_pi(a, 32);
		char *cs;
		Str str = cs = arb_get_str(a, 11, ARB_STR_MORE);
        SLS_ASSERT(str.substr(0, 13) == "[3.1415926535");
		free(cs); arb_clear(a);
	}

#ifdef SLS_USE_QUAD_MATH
	// test my arf_get_q() fun
	arb_init(a); prec = 150;
	arb_set_str(a, "1.23456789022345678903234567890423456789e123", prec);
	Qdoub v = arf_get_q(arb_midref(a), ARF_RND_NEAR);
	SLS_ASSERT(std::quad2str(v, 36) == Str("1.23456789022345678903234567890423455e+123"));
	arb_clear(a);

	arf_t af; arf_init(af);
	arf_set_q(af, 1.23456789022345678903234567890423455e+123Q);
	arf_clear(af);
#endif

	// test fmpz_t wrapper
	{
		// test fmpz_t: arbitrary length integer from flint library, with performance for small number
		Bint a("1234567890223456789032"), b("2345678902234567890323"), c;
		SLS_ASSERT(a == "1234567890223456789032");
		SLS_ASSERT(b == "2345678902234567890323");
		SLS_ASSERT(b != "2345678902234567890324");
		add(c, a, b);
		SLS_ASSERT(to_string(c) == "3580246792458024679355");
		SLS_ASSERT(c == "3580246792458024679355");
		a += a;
		SLS_ASSERT(to_string(a) == "2469135780446913578064");
		SLS_ASSERT(a == "2469135780446913578064");
		mul(c, a, b);
		SLS_ASSERT(to_string(c) == "5791799706946809282022521437831175850674672");
		SLS_ASSERT(c == "5791799706946809282022521437831175850674672");
		c *= c;
		SLS_ASSERT(c == "33544943845389145879408669314542605675909324086440898342615643360632092646597582307584");
		SLS_ASSERT(to_string(c) == "33544943845389145879408669314542605675909324086440898342615643360632092646597582307584");

		SLS_ASSERT(Bint("123456789") == Bint("123456789"));
		SLS_ASSERT(Bint("123456789") != Bint("123456788"));
		SLS_ASSERT(Bint("123456789") > Bint("123456788"));
		SLS_ASSERT(Bint("123456788") < Bint("123456789"));
		neg(a);
		SLS_ASSERT(a == "-2469135780446913578064");
	}

	// test arf_t wrapper
	{
		arb_prec(200);
		Breal x(PI), y("1.23456789022345678903234567890423456789e-2"), z;
        SLS_ASSERT(to_string(y, 42) == "0.0123456789022345678903234567890423456789000" || // newer version
			to_string(y, 42) == "[0.0123456789022345678903234567890423456789000 +/- 3e-48]"); // older version
		add(z, x, y);
		// cout << to_string(z) << endl;
		add(z, z, y);
		// cout << to_string(z) << endl;
	}

	// test arb_t wrapper
	{
		Areal x(PI), y("1.2345678902234567890323456789"), z;
		// cout << to_string(y) << endl;
		add(z, x, y);
		// cout << to_string(z) << endl;
		sin(z, y);
		// cout << to_string(z) << endl;
		exp(z, y);
		pow(y, x, x);
		// cout << to_string(z) << endl;
	}

	// test arb_spec_fun
	{
		// Areal x, y, z;
		// arb_digits(300);
		// x = "1.23";
		// cout << x << endl;

		// arb_pi(x);
		// arb_digits(300);
		// arb_pi(y);
		// add(z, x, y);
		// cout << "z = " << z << endl;
		// cout << get_digits(x) << endl;
		// cout << get_digits(y) << endl;
		// cout << get_digits(z) << endl;

		// cout << to_string(x, 100) << endl;

		// Breal x("123.4567890223456789032345678904234567");
		// cout << to_string(x, 100) << endl;
	}

	flint_cleanup(); // prevent memory leak
#else
	std::cout << "---------- disabled! ----------" << std::endl;
#endif
}
