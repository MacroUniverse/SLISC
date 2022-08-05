#include <iostream>
#ifdef SLS_USE_ARB
#include <gmp.h>
#include <flint.h>
#include <flint/fmpz.h>
#include "arb_hypgeom.h"
#include "../SLISC/arb_extension.h"
#endif

void test_arb()
{
#ifdef SLS_USE_ARB
    using namespace slisc;
	// test fmpz_t: arbitrary length integer from flint library, with performance for small number
    fmpz_t f, g, h;
    fmpz_init(f); fmpz_init(g); fmpz_init(h);
    fmpz_set_str(g, "12345678901234567890123456789012345678901234567890", 10);
    fmpz_set_str(h, "98765432109876543210987654321098765432109876543210", 10);
    fmpz_add(f, g, h);
    char *cs; cs = fmpz_get_str(NULL, 10, f);
    Str s = cs;
    free(cs);
    SLS_ASSERT(s == "111111111011111111101111111110111111111011111111100")
    fmpz_sub(f, g, h);
    s = cs = fmpz_get_str(NULL, 10, f);
    SLS_ASSERT(s == "-86419753208641975320864197532086419753208641975320")
    free(cs);
    fmpz_mul(f, g, h);
    s = cs = fmpz_get_str(NULL, 10, f);
    SLS_ASSERT(s == "1219326311370217952261850327338667885945115073915611949397448712086533622923332237463801111263526900")
    free(cs);
    fmpz_mod(f, g, h); // always positive
    s = cs = fmpz_get_str(NULL, 10, f);
    SLS_ASSERT(s == "12345678901234567890123456789012345678901234567890")
    free(cs);
    fmpz_clear(f); fmpz_clear(g); fmpz_clear(h);

    // test arf_t: arbitrary precision floating point numbers
    // https://arblib.org/arf.html
    arf_t x; arf_init(x); // init to 0, arf_t is a pointer (array of size 1)
    arf_set_d(x, PI); // set from double
    // arf_allocated_bytes(x); // check size in heap
    arf_clear(x); // free memory

    // test arb_t: arf_t with rigorous error bound
    arb_t a; arb_init(a);
    slong prec = 100; // precision digits (in binary)
    arb_set_str(a, "1.23456789022345678903234567890423456789e12345678", prec);
    Str str = cs = arb_get_str(a, 50, ARB_STR_MORE);
    SLS_ASSERT(str == Str("[1.2345678902234567890323456789042238629443408769906e+12345678 +/- 1.05e+12345648]"))
    free(cs); arb_clear(a);

#ifdef SLS_USE_QUAD_MATH
    // test my arf_get_q() fun
    arb_init(a); prec = 150;
    arb_set_str(a, "1.23456789022345678903234567890423456789e123", prec);
    Qdoub v;
    arf_get_q(v, arb_midref(a), ARF_RND_NEAR);
    SLS_ASSERT(std::quad2str(v, 36) == Str("1.23456789022345678903234567890423455e+123"))
    arb_clear(a);
    arf_t af; arf_init(af);
    arf_set_q(af, 1.23456789022345678903234567890423455e+123Q);
    arf_clear(af);
#endif
    flint_cleanup();
#else
    std::cout << "---------- disabled! ----------" << std::endl;
#endif
}
