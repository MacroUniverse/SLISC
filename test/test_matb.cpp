#include "../SLISC/matt.h"
#include "../SLISC/matb.h"
#include "../SLISC/random.h"

void test_matb()
{
    using namespace slisc;

    // write to file
    Matb matb;
    if (file_exist("test.matb"))
        remove("test.matb");
    matb.open("test.matb", 'w');

    // scalars
    Char s8 = 88;
    save(s8, "s8", matb);

    Int si = 99;
    save(si, "si", matb);

    Doub s(3.14159265358979323);
    save(s, "s", matb);

    Comp sc(s, -s);
    save(sc, "sc", matb);

    // vectors
    VecChar v8(3);
    v8[0] = 1; v8[1] = 2; v8[2] = 3;
    save(v8, "v8", matb);
    VecInt vi(3);
    vi[0] = 1; vi[1] = 2; vi[2] = 3;
    save(vi, "vi", matb);
    VecDoub v(3);
    v[0] = 1.; v[1] = 2.; v[2] = 3.;
    save(v, "v", matb);
    VecComp vc(3);
    for (Int i = 0; i < 3; ++i)
        vc[i] = 1 + (Doub)i - I * (Doub)i;
    save(vc, "vc", matb);

    // matrices

    MatInt AI(2, 3); copy(AI, 0);
    AI(0, 0) = 1; AI(0, 1) = 3; AI(0, 2) = 5; AI(1, 2) = 11;
    save(AI, "AI", matb);

    MatDoub A(2, 3); copy(A, 0);
    A(0, 0) = 1; A(0, 1) = 3; A(0, 2) = 5; A(1, 2) = 11;
    save(A, "A", matb);

    MatComp C(3, 3);
    Comp *pC{ &C(0, 0) };
    for (Int i = 0; i < 9; ++i) {
        pC[i] = 1 + (Doub)i + I * (Doub)i;
    }
    save(C, "C", matb);

    // 3d arrays
    Mat3Doub A3(2, 2, 2);
    for (Int i = 0; i < 8; ++i)
        A3[i] = 1. + (Doub)i;
    save(A3, "A3", matb);

    Mat3Comp C3(2, 2, 2);
    for (Int i = 0; i < 8; ++i)
        C3[i] = Comp(1. + (Doub)i, (Doub)i);
    save(C3, "C3", matb);

    Cmat3Comp CC3(10, 12, 15);
    for (Int i = 0; i < CC3.size(); ++i)
        CC3[i] = Comp(randDoub(), randDoub());
    save(CC3, "CC3", matb);

    matb.close();

    // read test

    // scalars
    matb.open("test.matb", 'r');


    Int r_si;
    load(r_si, "si", matb);
    if (r_si != si) SLS_ERR("failed!");

    Doub r_s;
    load(r_s, "s", matb);
    if (abs(r_s-s) != 0) SLS_ERR("failed!");

    Comp r_sc;
    load(r_sc, "sc", matb);
    if (abs(r_sc-sc) != 0) SLS_ERR("failed!");

    // vectors
    // TODO: Char

    VecInt r_vi(0);
    load(r_vi, "vi", matb);
    if (r_vi != vi) SLS_ERR("failed!");

    VecDoub r_v(0);
    load(r_v, "v", matb);
    r_v -= v;
    if (norm(r_v) != 0) SLS_ERR("failed!");

    VecComp r_vc(0);
    load(r_vc, "vc", matb);
    r_vc -= vc;
    if (norm(r_v) != 0) SLS_ERR("failed!");

    // matrices
    // TODO: Char

    MatInt r_AI(0,0);
    load(r_AI, "AI", matb);
    if (r_AI != AI) SLS_ERR("failed!");

    MatDoub r_A(0,0);
    load(r_A, "A", matb);
    r_A -= A;
    if (norm(r_A) != 0) SLS_ERR("failed!");

    MatComp r_C(0,0);
    load(r_C, "C", matb);
    r_C -= C;
    if (norm(r_C) != 0) SLS_ERR("failed!");

    // 3D arrays
    // Mat3Doub r_A3(0,0,0);
    // load(r_A3, "A3", matb);
    // r_A3 -= A3;
    // if (norm(r_A3) != 0) SLS_ERR("failed!");

    // Mat3Comp r_C3(0,0,0);
    // load(r_C3, "C3", matb);
    // r_C3 -= C3;
    // if (norm(r_C3) != 0) SLS_ERR("failed!");

    Cmat3Comp r_CC3(0, 0, 0);
    load(r_CC3, "CC3", matb);
    r_CC3 -= CC3;
    if (norm(r_CC3) != 0) SLS_ERR("failed!");

    // matb to matt
    {
        matb2matt("test.matb");
        Cmat3Comp r_CC3(0, 0, 0);
        load_matt(r_CC3, "CC3", "test.matt");
        r_CC3 -= CC3;
        if (max_abs(r_CC3) > 1e-14) SLS_ERR("failed!");
    }

    matb.close();
}
