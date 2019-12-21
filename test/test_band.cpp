#include "../SLISC/band_arith.h"
#include "../SLISC/random.h"

using namespace slisc;
void test_band()
{
	// test band diagonal conversion
    {
        Long N1 = 5, N2 = 6, kl = 2, ku = 1;
        CmatDoub matrix(N1, N2), matrix1(N1, N2);
        linspace(matrix, 1, N1*N2); linspace(matrix1, 1, N1*N2);
        CbandDoub a(N1, N2, ku, kl);
        copy(a, matrix);
        copy(matrix1, a);
        if (matrix != matrix1)
            SLS_ERR("failed!");
    }

    {
        // Long N1 = 5, N2 = 6, kl = 2, ku = 1;
        // Long lda = kl + ku + 1;
        // MatDoub matrix(N1, N2), matrix1(N1, N2);
        // linspace(matrix, 1, N1*N2); linspace(matrix1, 1, N1*N2);
        // MatDoub a(N1, lda); copy(a, 0);
        // copy(a, matrix, ku, kl);
        // copy(matrix1, a, ku, kl);
        // if (matrix != matrix1)
        //     SLS_ERR("failed!");
    }

    // test band matrix-vector multiplication
    {
        Long N1 = 5, N2 = 6, Nlow = 2, Nup = 1;
        CmatDoub den(N1, N2);
        rand(den);
        CbandDoub ban(N1, N2, Nup, Nlow);
		copy(ban, den);
        copy(den, 0);
        copy(den, ban);

        VecDoub x(N2); rand(x);
        VecDoub y(N1), y1(N1);
        mul(y, den, x);
        mul(y1, ban, x);
        y1 -= y;
        if (max_abs(y1) > 1e-13)
            SLS_ERR("failed");
    }

    {
        Long N1 = 5, N2 = 6, Nlow = 2, Nup = 1;
        CmatComp den(N1, N2);
        rand(den);
        CbandComp ban(N1, N2, Nup, Nlow);
		copy(ban, den);
        copy(den, 0);
        copy(den, ban);
        
        VecComp x(N2); rand(x);
        VecComp y(N1), y1(N1);
        mul(y, den, x);
        mul(y1, ban, x);
        y1 -= y;
        if (max_abs(y1) > 1e-13)
            SLS_ERR("failed");
    }
}
