#include <flint/fmpz.h>
#include "../SLISC/global.h"

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
    Str s = fmpz_get_str(NULL, 10, f);
    if (s != "111111111011111111101111111110111111111011111111100")
        SLS_ERR("failed!");
    fmpz_sub(f, g, h);
    s = fmpz_get_str(NULL, 10, f);
    if (s != "-86419753208641975320864197532086419753208641975320")
        SLS_ERR("failed!");
    fmpz_mul(f, g, h);
    s = fmpz_get_str(NULL, 10, f);
    if (s != "1219326311370217952261850327338667885945115073915611949397448712086533622923332237463801111263526900")
        SLS_ERR("failed!");
    fmpz_mod(f, g, h); // always positive
    s = fmpz_get_str(NULL, 10, f);
    if (s != "12345678901234567890123456789012345678901234567890")
        SLS_ERR("failed!");
#endif
}
