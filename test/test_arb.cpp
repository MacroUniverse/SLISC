#include <iostream>
#ifdef SLS_USE_ARB
#include <gmp.h>
#include <flint.h>
#include <flint/fmpz.h>
#include "arb_hypgeom.h"
#include "../SLISC/arb_extension.h"
#endif

// void test_fun(int a[1])
// {
//     ++a[0];
// }

void test_arb()
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

#ifdef SLS_USE_QUAD_MATH
    // test my arf_get_q() fun
    arb_init(a); prec = 150;
    arb_set_str(a, "1.23456789022345678903234567890423456789e123", prec);
    Qdoub v;
    arf_get_q(v, arb_midref(a), ARF_RND_NEAR);
    SLS_ASSERT(std::quad2str(v, 36) == Str("1.23456789022345678903234567890423455e+123"));
    arb_clear(a);
    arf_t af; arf_init(af);
    arf_set_q(af, 1.23456789022345678903234567890423455e+123Q);
    arf_clear(af);
#endif

    // test Bint wrapper
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

    flint_cleanup(); // prevent memory leak
#else
    std::cout << "---------- disabled! ----------" << std::endl;
#endif
}
