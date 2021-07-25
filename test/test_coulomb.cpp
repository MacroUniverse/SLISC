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

    Long Nr = 20;
    VecDoub r(Nr); linspace(r, 0, 200);
    Doub k = 0.5, F_exp = 0; //  = 3.1415; // F_exp = 0;
    VecDoub F(Nr);
    for (Long l = 50; l < 52; ++l) {
        // ret = gsl_sf_coulomb_wave_F_array(l, 0, eta, k*r[i], &F, &F_exp);
        // cout << "l = " << l << endl;
        coulombF(F, l, k, r);
        for (Long i = 0; i < r.size(); ++i) {
            if (slisc::isnan(F[i])) {
                cout << "(ret, l, i, F_exp) = " << ret << ", " << l << ", " << i << ", " << F_exp << endl;
                SLS_ERR("failed!");
            }
            if (isinf(F[i])) {
                cout << "(ret, l, i, F_exp) = " << ret << ", " << l << ", " << i << ", " << F_exp << endl;
                SLS_ERR("failed!");
            }
        }
    }
#endif
#ifdef SLS_USE_ARB
    Doub val = 4.5882301380287637784e-286;
    if (abs((arb_coulombF(203, -0.1, 6) - val)/val) > 1e-14)
        SLS_ERR("failed!");
#endif
}
