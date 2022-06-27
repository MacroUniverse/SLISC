#include "../SLISC/file.h"
#include "../SLISC/matfile.h"
#include "../SLISC/random.h"
#include "../SLISC/disp.h"

void test_matfile()
{
    using namespace slisc;

    // write to file
    if (file_exist("test.mat"))
        remove("test.mat");
    Mat mat = matOpen("test.mat", "w");
    
    // scalars
    Char c8 = 56;
    save(c8, "c8", mat);

    Uchar s8 = 88;
    save(s8, "s8", mat);

    Int si = 99;
    save(si, "si", mat);

    Llong sl = 123456;
    save(sl, "sl", mat);

    Doub s(3.14159265358979323);
    save(s, "s", mat);

    Comp sc(s, -s);
    save(sc, "sc", mat);

    // vectors
    VecChar v8(3);
    v8[0] = 1; v8[1] = 2; v8[2] = 3;
    save(v8, "v8", mat);

    VecInt vi(3);
    vi[0] = 1; vi[1] = 2; vi[2] = 3;
    save(vi, "vi", mat);

    VecLlong vl(3);
    vl[0] = 1; vl[1] = 2; vl[2] = 3;
    save(vl, "vl", mat);

    VecDoub v(3);
    v[0] = 1.; v[1] = 2.; v[2] = 3.;
    save(v, "v", mat);

    VecComp vc(3);
    for (Int i = 0; i < 3; ++i)
        vc[i] = 1 + (Doub)i - I * (Doub)i;
    save(vc, "vc", mat);

    // vecDoub vd(3); vd[0] = 1.1; vd[1] = 2.2; vd[2] = 3.3;
    // save(vd, "vd", mat);

    // matrices

    CmatInt AI(2, 3); copy(AI, 0);
    AI(0, 0) = 1; AI(0, 1) = 3; AI(0, 2) = 5; AI(1, 2) = 11;
    save(AI, "AI", mat);

    CmatLlong AL(2, 3); copy(AL, 0);
    AL(0, 0) = 1; AL(0, 1) = 3; AL(0, 2) = 5; AL(1, 2) = 11;
    save(AL, "AL", mat);

    CmatDoub A(2, 3); copy(A, 0);
    A(0, 0) = 1; A(0, 1) = 3; A(0, 2) = 5; A(1, 2) = 11;
    save(A, "A", mat);

    CmatComp C(3, 3);
    for (Int i = 0; i < 9; ++i)
        C[i] = 1 + (Doub)i + I * (Doub)i;
    save(C, "C", mat);

    // 3d arrays
    Cmat3Llong A3L(2, 2, 2);
    for (Int i = 0; i < 8; ++i)
        A3L[i] = 1. + (Doub)i;
    save(A3L, "A3L", mat);

    Cmat3Doub A3(2, 2, 2);
    for (Int i = 0; i < 8; ++i)
        A3[i] = 1. + (Doub)i;
    save(A3, "A3", mat);

    Cmat3Comp CC3(10, 12, 15);
    for (Int i = 0; i < CC3.size(); ++i)
        CC3[i] = Comp(randDoub(), randDoub());
    save(CC3, "CC3", mat);

    // // -----------  read test -------------

    // // scalars
    // matb.open("test1.matb", 'r');

    // Int r_si;
    // load(r_si, "si", matb);
    // if (r_si != si) SLS_ERR("failed!");

    // Doub r_s;
    // load(r_s, "s", matb);
    // if (abs(r_s-s) != 0) SLS_ERR("failed!");

    // Comp r_sc;
    // load(r_sc, "sc", matb);
    // if (abs(r_sc-sc) != 0) SLS_ERR("failed!");

    // // vectors
    // // TODO: Char

    // VecInt r_vi(0);
    // load(r_vi, "vi", matb);
    // if (r_vi != vi)
    //     SLS_ERR("failed!");

    // VecDoub r_v(0);
    // load(r_v, "v", matb);
    // r_v -= v;
    // if (norm(r_v) != 0)
    //     SLS_ERR("failed!");

    // VecComp r_vc(0);
    // load(r_vc, "vc", matb);
    // r_vc -= vc;
    // if (norm(r_v) != 0)
    //     SLS_ERR("failed!");

    // VecDoub r_vd(0);
    // load(r_vd, "vd", matb);
    // if (r_vd[0] != 1.1 || r_vd[1] != 2.2 || r_vd[2] != 3.3)
    //     SLS_ERR("failed!");

    // // matrices
    // // TODO: Char

    // MatInt r_AI(0,0);
    // load(r_AI, "AI", matb);
    // if (r_AI != AI) SLS_ERR("failed!");

    // MatDoub r_A(0,0);
    // load(r_A, "A", matb);
    // r_A -= A;
    // if (norm(r_A) != 0) SLS_ERR("failed!");

    // MatComp r_C(0,0);
    // load(r_C, "C", matb);
    // r_C -= C;
    // if (norm(r_C) != 0) SLS_ERR("failed!");

    // // 3D arrays
    // Mat3Doub r_A3(0,0,0);
    // load(r_A3, "A3", matb);
    // r_A3 -= A3;
    // if (norm(r_A3) != 0) SLS_ERR("failed!");

    // Mat3Comp r_C3(0,0,0);
    // load(r_C3, "C3", matb);
    // r_C3 -= C3;
    // if (norm(r_C3) != 0) SLS_ERR("failed!");

    // Cmat3Comp r_CC3(0, 0, 0);
    // load(r_CC3, "CC3", matb);
    // r_CC3 -= CC3;
    // if (norm(r_CC3) != 0) SLS_ERR("failed!");

    // // matb2matt: convert matb to matt
    // {
    //     remove("test.matt");
    //     matb2matt("test.matb");

    //     Matt matt("test.matt", "r");

    //     Int r_si;
    //     load(r_si, "si", matt);
    //     if (r_si != si) SLS_ERR("failed!");

    //     Doub r_s;
    //     load(r_s, "s", matt);
    //     if (abs(r_s-s) > 1e-15) SLS_ERR("failed!");

    //     Comp r_sc;
    //     load(r_sc, "sc", matt);
    //     if (abs(r_sc-sc) > 1e-15) SLS_ERR("failed!");

    //     // vectors
    //     // TODO: Char
        
    //     VecInt r_vi(0);
    //     load(r_vi, "vi", matt);
    //     if (r_vi != vi) SLS_ERR("failed!");

    //     VecDoub r_v(0);
    //     load(r_v, "v", matt);
    //     r_v -= v;
    //     if (norm(r_v) > 1e-15) SLS_ERR("failed!");

    //     VecComp r_vc(0);
    //     load(r_vc, "vc", matt);
    //     r_vc -= vc;
    //     if (norm(r_v) > 1e-15) SLS_ERR("failed!");

    //     // matrices
    //     // TODO: Char

    //     MatInt r_AI(0,0);
    //     load(r_AI, "AI", matt);
    //     if (r_AI != AI) SLS_ERR("failed!");

    //     MatDoub r_A(0,0);
    //     load(r_A, "A", matt);
    //     r_A -= A;
    //     if (norm(r_A) > 1e-15) SLS_ERR("failed!");

    //     MatComp r_C(0,0);
    //     load(r_C, "C", matt);
    //     r_C -= C;
    //     if (norm(r_C) > 1e-15) SLS_ERR("failed!");

    //     // 3D arrays
    //     // Mat3Doub r_A3(0,0,0);
    //     // load(r_A3, "A3", matt);
    //     // r_A3 -= A3;
    //     // if (norm(r_A3) > 1e-15) SLS_ERR("failed!");

    //     // Mat3Comp r_C3(0,0,0);
    //     // load(r_C3, "C3", matt);
    //     // r_C3 -= C3;
    //     // if (norm(r_C3) > 1e-15) SLS_ERR("failed!");

    //     Cmat3Comp r_CC3(0, 0, 0);
    //     load(r_CC3, "CC3", matt);
    //     r_CC3 -= CC3;
    //     if (norm(r_CC3) > 1e-15) SLS_ERR("failed!");

    //     matt.close();
    // }

    // // matt2matb: convert matt to matb
    // {
    //     remove("test.matb");
    //     matt2matb("test.matt");

    //     Matb matb("test.matb", 'r');

    //     Int r_si;
    //     load(r_si, "si", matb);
    //     if (r_si != si) SLS_ERR("failed!");

    //     Doub r_s;
    //     load(r_s, "s", matb);
    //     if (abs(r_s-s) > 1e-15) SLS_ERR("failed!");

    //     Comp r_sc;
    //     load(r_sc, "sc", matb);
    //     if (abs(r_sc-sc) > 1e-15) SLS_ERR("failed!");

    //     // vectors
    //     // TODO: Char
        
    //     VecInt r_vi(0);
    //     load(r_vi, "vi", matb);
    //     if (r_vi != vi) SLS_ERR("failed!");

    //     VecDoub r_v(0);
    //     load(r_v, "v", matb);
    //     r_v -= v;
    //     if (norm(r_v) > 1e-15) SLS_ERR("failed!");

    //     VecComp r_vc(0);
    //     load(r_vc, "vc", matb);
    //     r_vc -= vc;
    //     if (norm(r_v) > 1e-15) SLS_ERR("failed!");

    //     // matrices
    //     // TODO: Char

    //     MatInt r_AI(0,0);
    //     load(r_AI, "AI", matb);
    //     if (r_AI != AI) SLS_ERR("failed!");

    //     MatDoub r_A(0,0);
    //     load(r_A, "A", matb);
    //     r_A -= A;
    //     if (norm(r_A) > 1e-15) SLS_ERR("failed!");

    //     MatComp r_C(0,0);
    //     load(r_C, "C", matb);
    //     r_C -= C;
    //     if (norm(r_C) > 1e-15) SLS_ERR("failed!");

    //     // 3D arrays
    //     // Mat3Doub r_A3(0,0,0);
    //     // load(r_A3, "A3", matb);
    //     // r_A3 -= A3;
    //     // if (norm(r_A3) > 1e-15) SLS_ERR("failed!");

    //     // Mat3Comp r_C3(0,0,0);
    //     // load(r_C3, "C3", matb);
    //     // r_C3 -= C3;
    //     // if (norm(r_C3) > 1e-15) SLS_ERR("failed!");

    //     Cmat3Comp r_CC3(0, 0, 0);
    //     load(r_CC3, "CC3", matb);
    //     r_CC3 -= CC3;
    //     if (norm(r_CC3) > 1e-15) SLS_ERR("failed!");

    //     matb.close();
    // }
}
