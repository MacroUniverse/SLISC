#include "../SLISC/arithmetic.h"
#include "../SLISC/coulomb.h"
#include "../SLISC/time.h"
#include "../SLISC/disp.h"

void test_coulomb()
{
    using std::cout; using std::endl;
    using namespace slisc;

    // coulomb phase shift
#ifdef SLS_USE_GSL
    Doub ret = coulomb_sigma(3, -2./5);
    if (abs(ret + 0.503297642943251313) > 1e-15)
        SLS_ERR("failed!");
    ret = coulomb_sigma(4, -2. / 9);
    if (abs(ret + 0.3347819876751476) > 1e-15)
        SLS_ERR("failed!");
#endif
}
