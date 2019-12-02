#include "../SLISC/lin_eq.h"
#include "../SLISC/arithmetic.h"
#include "../SLISC/disp.h"

void test_lin_eq()
{
    using namespace slisc;
    CmatDoub a(3, 3), a_inv(3, 3), b(3, 3);
    copy(a, 1); a(0, 0) += 2; a(1, 1) += 2; a(2, 2) += 2;    
    copy(a_inv, a);
    inv_mat(a_inv);
    mul(b, a, a_inv);
    b(0, 0) -= 1; b(1, 1) -= 1; b(2, 2) -= 1;
    if (norm(b) > 2e-15)
        SLS_ERR("failed!");
}
