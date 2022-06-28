#include "../SLISC/Imag.h"

void test_Imag()
{
    using namespace slisc;
    
    // constructors
    {
        Imag x;
        if (real(x) != 0 || x.real() != 0)
            SLS_ERR("failed!");
        Imag x1(0.25);
        if (real(x1) != 0 || x1.real() != 0)
            SLS_ERR("failed!");
        if (imag(x1) != 0.25 || x1.imag() != 0.25)
            SLS_ERR("failed!");
    }
    {
        Imag x1(1);
        if (real(x1) != 0 || x1.real() != 0)
            SLS_ERR("failed!");
        if (imag(x1) != 1 || x1.imag() != 1)
            SLS_ERR("failed!");
    }

    // operator +
    {
        // Imag + Imag
        Imag x, x1(0.25), x2(0.75);
        x = x1 + x2;
        if (imag(x) != 1)
            SLS_ERR("failed!");
    }

    // Imag * Imag
    {
        
        Doub x;
        Imag x1(0.25), x2(4);
        x = x1 * x2;
        if (x != -1)
            SLS_ERR("failed!");
    }

    // complex<T> = imag<T>
    {
        Comp x; Imag x1(1.25);
        x = x1;
        if (real(x) != 0 || imag(x) != 1.25)
            SLS_ERR("failed!");
        x = I;
        if (real(x) != 0 || imag(x) != 1)
            SLS_ERR("failed!");
        x = -I;
        if (real(x) != 0 || imag(x) != -1)
            SLS_ERR("failed!");
    }

    // Imag +-*/ Doub,  Doub +-*/ Imag
    {
        Doub a = 2.;
        Imag b(3.);
        if (a + b != Comp(2,3)) SLS_ERR("failed!");
        if (b + a != Comp(2,3)) SLS_ERR("failed!");
        if (a - b != Comp(2,-3)) SLS_ERR("failed!");
        if (b - a != Comp(-2,3)) SLS_ERR("failed!");
        if (a * b != Imag(6.)) SLS_ERR("failed!");
        if (b * a != Imag(6.)) SLS_ERR("failed!");
        if (a / b != Imag(-2./3.)) SLS_ERR("failed!");
        if (b / a != Imag(3./2.)) SLS_ERR("failed!");
    }

    // Imag +-*/ Comp,  Comp +-*/ Imag
    {
        Comp a(1, -2), c;
        Imag b(   2.);
        c = a + b;
        if (real(c) != 1. || imag(c) != 0.) SLS_ERR("failed!");
        c = b + a;
        if (b + a != a + b) SLS_ERR("failed!");
        c = a - b;
        if (real(c) != 1. || imag(c) != -4.) SLS_ERR("failed!");
        if (b - a != -(a-b)) SLS_ERR("failed!");
        c = a * b;
        if (real(c) != 4. || imag(c) != 2.) SLS_ERR("failed!");
        if (a*b != b*a) SLS_ERR("failed!");
        c = a / b;
        if (real(c) != -1. || imag(c) != -.5) SLS_ERR("failed!");
    }
}
