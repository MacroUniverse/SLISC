#include "../SLISC/scalar_arith.h"
using namespace slisc;

template <class T1, class T2>
inline Bool is_equiv(const T1 &s1, const T2 &s2)
{
	return s1 == s2 && sizeof(T1) == sizeof(T2);
}

void test_scalar_arith()
{
    // to_num(s)
    if (!is_equiv(to_num(false), 0)) SLS_ERR("failed!");
    if (!is_equiv(to_num(true), 1)) SLS_ERR("failed!");
    if (!is_equiv(to_num(Char(-125)), -125)) SLS_ERR("failed!");
    if (!is_equiv(to_num(Uchar(253)), 253)) SLS_ERR("failed!");
    if (!is_equiv(to_num(2.3), 2.3)) SLS_ERR("failed!");
    if (!is_equiv(to_num(Comp(3.1,3.2)), Comp(3.1,3.2))) SLS_ERR("failed!");

    // test scalar functions
    if (!isodd(3) || !isodd(-3) || isodd(4) || isodd(-4))
        SLS_ERR("failed!");
    if (!ispow2(4) || !ispow2(32) || !ispow2(1024) || !ispow2(65536)
        || ispow2(12) || ispow2(48))
        SLS_ERR("failed!");
    // modulus (quotion truncated to 0)
    if (-5%3 != -2 || -1%3 != -1 || 1%3 != 1 || 5%3 != 2)
        SLS_ERR("failed!");
    if (-5%-3 != -2 || -1%-3 != -1 || 1%-3 != 1 || 5%-3 != 2)
        SLS_ERR("failed!");
    for (Doub s = -3; s <= 3; s += 0.5) {
        Long n1, n2;
        Doub d1 = 0.5, d2 = -0.5;
        Doub ret1 = mod(n1, s, d1), ret2 = mod(n2, s, d2);
        if (abs(n1 * d1) > abs(s) || abs(ret1 + n1 * d1 - s) > 2e-15)
            SLS_ERR("failed!");
        if (abs(n2 * d2) > abs(s) || abs(ret2 + n2 * d2 - s) > 2e-15)
            SLS_ERR("failed!");
    }
    // modulus (quotion floored)
    if (mod_fl(-5,3) != 1 || mod_fl(-1,3) != 2 || mod_fl(1,3) != 1 || mod_fl(5,3) != 2)
        SLS_ERR("failed!");
    if (mod_fl(-5,-3) != -2 || mod_fl(-1,-3) != -1 || mod_fl(1,-3) != -2 || mod_fl(5,-3) != -1)
        SLS_ERR("failed!");
    for (Doub s = -3; s <= 3; s += 0.5) {
        Long n1, n2;
        Doub d1 = 0.5, d2 = -0.5;
        Doub ret1 = mod_fl(n1, s, d1), ret2 = mod_fl(n2, s, d2);
        if (ret1 < 0 || abs(ret1 + n1 * d1 - s) > 2e-15)
            SLS_ERR("failed!");
        if (ret2 > 0 || abs(ret2 + n2 * d2 - s) > 2e-15)
            SLS_ERR("failed!");
    }
    // modulus (positive modulus, or euclidean)
    if (mod_eu(-5,3) != 1 || mod_eu(-1,3) != 2 || mod_eu(1,3) != 1 || mod_eu(5,3) != 2)
        SLS_ERR("failed!");
    if (mod_eu(-5,-3) != 1 || mod_eu(-1,-3) != 2 || mod_eu(1,-3) != 1 || mod_eu(5,-3) != 2)
        SLS_ERR("failed!");
    for (Doub s = -3; s <= 3; s += 0.5) {
        Long n1, n2;
        Doub d1 = 0.5, d2 = -0.5;
        Doub ret1 = mod_eu(n1, s, d1), ret2 = mod_eu(n2, s, d2);
        if (ret1 < 0 || abs(ret1 + n1 * d1 - s) > 2e-15)
            SLS_ERR("failed!");
        if (ret2 < 0 || abs(ret2 + n2 * d2 - s) > 2e-15)
            SLS_ERR("failed!");
    }

    // operator== involving floating point complex<>
    if (Fcomp(3, 4) != Comp(3, 4)) SLS_ERR("failed!");

    // if (Comp(1,0) == 1.f) SLS_ERR("failed!");

    // operator+,-,*,/ between floatig point complex<> and intrinsic types
    if (!is_equiv(Comp(1.1,2.2) + 3, Comp(4.1, 2.2))) SLS_ERR("failed!");
    if (!is_equiv(Comp(1.1, 2.2) + Char(3), Comp(4.1, 2.2))) SLS_ERR("failed!");
    if (!is_equiv(Comp(1.1, 2.2) + 3.f, Comp(4.1, 2.2))) SLS_ERR("failed!");
    if (!is_equiv(Comp(1.1, 2.2) + 3., Comp(4.1, 2.2))) SLS_ERR("failed!");
    if (!is_equiv(-2 + Comp(1., 2.2), Comp(-1, 2.2))) SLS_ERR("failed!");
    if (!is_equiv(Char(-2) + Comp(1., 2.2), Comp(-1, 2.2))) SLS_ERR("failed!");

    if (!is_equiv(Comp(1.1, 2.2) - 3, Comp(-1.9, 2.2))) SLS_ERR("failed!");
    if (!is_equiv(Comp(1.1, 2.2) - 3.f, Comp(-1.9, 2.2))) SLS_ERR("failed!");
    if (!is_equiv(Comp(1.1, 2.2) - 3., Comp(-1.9, 2.2))) SLS_ERR("failed!");
    if (!is_equiv(1 - Comp(1.5, 2.2), Comp(-0.5, -2.2))) SLS_ERR("failed!");
    if (!is_equiv(true - Comp(1.5, 2.2), Comp(-0.5, -2.2))) SLS_ERR("failed!");
    if (!is_equiv(1.f - Comp(1.5, 2.2), Comp(-0.5, -2.2))) SLS_ERR("failed!");
    if (!is_equiv(1. - Comp(1.5, 2.2), Comp(-0.5, -2.2))) SLS_ERR("failed!");

    if (!is_equiv(Comp(1.5, 2.5) * Char(3), Comp(4.5, 7.5))) SLS_ERR("failed!");
    if (!is_equiv(Comp(1.5, 2.5) * 3.f, Comp(4.5, 7.5))) SLS_ERR("failed!");
    if (!is_equiv(Comp(1.5, 2.5) * 3., Comp(4.5, 7.5))) SLS_ERR("failed!");
    if (!is_equiv(Char(3) * Comp(1.5, 2.5), Comp(4.5, 7.5))) SLS_ERR("failed!");

    if (!is_equiv(Comp(4.5, 7.5) / 3, Comp(1.5, 2.5))) SLS_ERR("failed!");
    if (!is_equiv(Comp(1.5, 4.5) / 3.f, Comp(0.5, 1.5))) SLS_ERR("failed!");
    if (!is_equiv(Comp(1.5, 4.5) / 3., Comp(0.5, 1.5))) SLS_ERR("failed!");
    if (!is_equiv(6 / Comp(1, 1), Comp(3, -3))) SLS_ERR("failed!");
    if (!is_equiv(6.f / Comp(1, 1), Comp(3, -3))) SLS_ERR("failed!");
    if (!is_equiv(6. / Comp(1, 1), Comp(3, -3))) SLS_ERR("failed!");
    if (!is_equiv(6. / Fcomp(1, 1), Comp(3, -3))) SLS_ERR("failed!");

    // operator+,-,*,/ between two floatig point std::complex<>    
    if (!is_equiv(Fcomp(1.25, 3.75) + Fcomp(0.75, -1.75), std::complex<float>(2, 2)))
        SLS_ERR("failed!");
    if (!is_equiv(Fcomp(1.25, 3.75) - Comp(-0.75, 0.75), Comp(2, 3)))
        SLS_ERR("failed!");
    if (!is_equiv(Fcomp(1., 2.) / Comp(1., 2.), Comp(1, 0)))
        SLS_ERR("failed!");

    // test factorial()
    if (factorial(5) != 120)
        SLS_ERR("failed!");
    if (factorial(17) != 355687428096000)
        SLS_ERR("failed!");
    if (abs(factorial(100) - 9.33262154439441526e157)/9.33262154439441526e157 > 1e-14)
        SLS_ERR("failed!");
    if (abs(factorial(150) - 5.71338395644585459e262) / 5.71338395644585459e262 > 1e-14)
        SLS_ERR("failed!");
}
