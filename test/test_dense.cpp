// test dense containers here
#include "../SLISC/arithmetic.h"
#include "../SLISC/cut.h"
#include "../SLISC/random.h"
#include "../SLISC/disp.h"

void test_dense()
{
    using namespace slisc;

    // size initialize
    {
        VecDoub vDoub(3);
        if (vDoub.size() != 3) SLS_ERR("failed!");
        if (vDoub.p() != &vDoub[0]) SLS_ERR("failed!");
        MatDoub aDoub(3, 3);
        if (aDoub.size() != 9) SLS_ERR("failed!");
        if (aDoub.n1() != 3) SLS_ERR("failed!");
        if (aDoub.n2() != 3) SLS_ERR("failed!");
        if (aDoub.p() != &aDoub(0, 0)) SLS_ERR("failed!");
        Mat3Doub a3Doub(3, 3, 3);
        if (a3Doub.size() != 27) SLS_ERR("failed!");
        if (a3Doub.n1() != 3) SLS_ERR("failed!");
        if (a3Doub.n2() != 3) SLS_ERR("failed!");
        if (a3Doub.n3() != 3) SLS_ERR("failed!");
        if (a3Doub.p() != &a3Doub(0,0,0)) SLS_ERR("failed!");
        Cmat3Doub c3Doub(3, 3, 3);
        if (c3Doub.size() != 27) SLS_ERR("failed!");
        if (c3Doub.n1() != 3) SLS_ERR("failed!");
        if (c3Doub.n2() != 3) SLS_ERR("failed!");
        if (c3Doub.n3() != 3) SLS_ERR("failed!");
        if (c3Doub.p() != &c3Doub(0, 0, 0)) SLS_ERR("failed!");
    }

    // const initialize
    VecDoub vDoub(3); copy(vDoub, 1);
    if (vDoub != 1.) SLS_ERR("failed!");
    MatDoub aDoub(3, 3); copy(aDoub, 1);
    if (aDoub != 1.) SLS_ERR("failed!");
    Mat3Doub a3Doub(3, 3, 3); copy(a3Doub, 1);
    if (a3Doub != 1.) SLS_ERR("failed!");
    Cmat3Doub c3Doub(3, 3, 3); copy(c3Doub, 1);
    if (c3Doub != 1.) SLS_ERR("failed!");

    // resize
    vDoub.resize(0);
    if (vDoub.size() != 0) SLS_ERR("failed!");
    vDoub.resize(4);
    if (vDoub.size() != 4) SLS_ERR("failed!");
    if (vDoub.p() != &vDoub[0]) SLS_ERR("failed!");
    aDoub.resize(0, 3);
    if (aDoub.size() != 0) SLS_ERR("failed!");
    aDoub.resize(3, 0);
    if (aDoub.size() != 0) SLS_ERR("failed!");
    aDoub.resize(4, 4);
    if (aDoub.size() != 16) SLS_ERR("failed!");
    if (aDoub.n1() != 4) SLS_ERR("failed!");
    if (aDoub.n2() != 4) SLS_ERR("failed!");
    if (aDoub.p() != &aDoub(0,0)) SLS_ERR("failed!");
    a3Doub.resize(0, 0, 4);
    if (a3Doub.size() != 0) SLS_ERR("failed!");
    a3Doub.resize(0, 4, 0);
    if (a3Doub.size() != 0) SLS_ERR("failed!");
    a3Doub.resize(4, 0, 0);
    if (a3Doub.size() != 0) SLS_ERR("failed!");
    a3Doub.resize(4, 4, 4);
    if (a3Doub.size() != 64) SLS_ERR("failed!");
    if (a3Doub.n1() != 4) SLS_ERR("failed!");
    if (a3Doub.n2() != 4) SLS_ERR("failed!");
    if (a3Doub.n3() != 4) SLS_ERR("failed!");
    if (a3Doub.p() != &a3Doub(0,0,0)) SLS_ERR("failed!");
    c3Doub.resize(0, 0, 4);
    if (c3Doub.size() != 0) SLS_ERR("failed!");
    c3Doub.resize(0, 4, 0);
    if (c3Doub.size() != 0) SLS_ERR("failed!");
    c3Doub.resize(4, 0, 0);
    if (c3Doub.size() != 0) SLS_ERR("failed!");
    c3Doub.resize(4, 4, 4);
    if (c3Doub.size() != 64) SLS_ERR("failed!");
    if (c3Doub.n1() != 4) SLS_ERR("failed!");
    if (c3Doub.n2() != 4) SLS_ERR("failed!");
    if (c3Doub.n3() != 4) SLS_ERR("failed!");
    if (c3Doub.p() != &c3Doub(0, 0, 0)) SLS_ERR("failed!");

    // resize and copy old data
    {
        VecInt v(3);
        v[0] = 100; v[1] = 101; v[2] = 102;
        resize_cpy(v, 5);
        if (v[0] != 100 || v[1] != 101 || v[2] != 102 || v[3] != 0 || v[4] != 0)
            SLS_ERR("failed!");
        resize_cpy(v, 2);
        if (v[0] != 100 || v[1] != 101)
            SLS_ERR("failed!");

        CmatDoub a2(4, 5), b2(4, 5);
        linspace(a2, 1, 20); copy(b2, a2);
        resize_cpy(b2, 7, 9);
        if (cut(b2, 0, 4, 0, 5) != a2)
            SLS_ERR("failed!");
        resize_cpy(b2, 4, 5);
        if (b2 != a2)
            SLS_ERR("failed!");

        Cmat3Doub a3(2, 3, 4), b3(2, 3, 4);
        rand(a3); copy(b3, a3);
        resize_cpy(b3, 3, 4, 5);
        if (cut(b3, 0, 2, 0, 3, 0, 4) != a3)
            SLS_ERR("failed!");
        resize_cpy(b3, 2, 3, 4);
        if (b3 != a3)
            SLS_ERR("failed!");
    }

    // assignment operator
    copy(vDoub, 1); if (vDoub != 1.) SLS_ERR("failed!");
    copy(aDoub, 1); if (aDoub != 1.) SLS_ERR("failed!");
    copy(a3Doub, 1); if (a3Doub != 1.) SLS_ERR("failed!");
    VecDoub vDoub1(4);
    copy(vDoub1, 2);
    copy(vDoub, vDoub1);
    if (vDoub != vDoub1) SLS_ERR("failed!");
    MatDoub aDoub1(4, 4);
    copy(aDoub1, 2);
    copy(aDoub, aDoub1);
    if (aDoub != aDoub1) SLS_ERR("failed!");
    Mat3Doub a3Doub1(4, 4, 4);
    copy(a3Doub1, 2);
    copy(a3Doub, a3Doub1);
    if (a3Doub != a3Doub1) SLS_ERR("failed!");
    Cmat3Doub c3Doub1(4, 4, 4);
    copy(c3Doub1, 2);
    copy(c3Doub, c3Doub1);
    if (c3Doub != c3Doub1) SLS_ERR("failed!");

    // move operator
    VecDoub vDoub2;
    MatDoub aDoub2;
    Mat3Doub a3Doub2;
    Cmat3Doub c3Doub2;
    vDoub2 << vDoub;
    if (vDoub2 != vDoub1) SLS_ERR("failed!");
    if (vDoub.size() != 0) SLS_ERR("failed!");
    aDoub2 << aDoub;
    if (aDoub2 != aDoub1)  SLS_ERR("failed!");
    if (aDoub.size() != 0) SLS_ERR("failed!");
    if (aDoub.n1() != 0) SLS_ERR("failed!");
    if (aDoub.n2() != 0) SLS_ERR("failed!");
    a3Doub2 << a3Doub;
    if (a3Doub2 != a3Doub1) SLS_ERR("failed!");
    if (a3Doub.size() != 0) SLS_ERR("failed!");
    if (a3Doub.n1() != 0) SLS_ERR("failed!");
    if (a3Doub.n2() != 0) SLS_ERR("failed!");
    if (a3Doub.n3() != 0) SLS_ERR("failed!");
    c3Doub2 << c3Doub;
    if (c3Doub2 != c3Doub1) SLS_ERR("failed!");
    if (a3Doub.size() != 0) SLS_ERR("failed!");
    if (a3Doub.n1() != 0) SLS_ERR("failed!");
    if (a3Doub.n2() != 0) SLS_ERR("failed!");
    if (a3Doub.n3() != 0) SLS_ERR("failed!");

    // end()
    vDoub1[vDoub1.size()-1] = 3.1;
    if (vDoub1.end() != 3.1)  SLS_ERR("failed!");
    if (vDoub1.end(1) != 3.1)  SLS_ERR("failed!");
    aDoub1[aDoub1.size()-1] = 3.1;
    if (aDoub1.end() != 3.1)  SLS_ERR("failed!");
    if (aDoub1.end(1) != 3.1)  SLS_ERR("failed!");
    a3Doub1[a3Doub1.size()-1] = 3.1;
    if (a3Doub1.end() != 3.1)  SLS_ERR("failed!");
    if (a3Doub1.end(1) != 3.1)  SLS_ERR("failed!");
    c3Doub1[c3Doub1.size() - 1] = 3.1;
    if (c3Doub1.end() != 3.1)  SLS_ERR("failed!");
    if (c3Doub1.end(1) != 3.1)  SLS_ERR("failed!");
    vDoub1[vDoub1.size()-2] = 3.2;
    if (vDoub1.end(2) != 3.2)  SLS_ERR("failed!");
    aDoub1[aDoub1.size()-2] = 3.2;
    if (aDoub1.end(2) != 3.2)  SLS_ERR("failed!");
    a3Doub1[a3Doub1.size()-2] = 3.2;
    if (a3Doub1.end(2) != 3.2)  SLS_ERR("failed!");
    c3Doub1[c3Doub1.size() - 2] = 3.2;
    if (c3Doub1.end(2) != 3.2)  SLS_ERR("failed!");

    // operator()
    vDoub1[vDoub1.size()-1] = 5.5;
    if (vDoub1[vDoub1.size()-1] != 5.5 ) SLS_ERR("failed!");
    if (vDoub1.end() != 5.5)  SLS_ERR("failed!");
    aDoub1(aDoub1.n1()-1, aDoub1.n2()-1) = 5.5;
    if (aDoub1(aDoub1.n1()-1, aDoub1.n2()-1) != 5.5 ) SLS_ERR("failed!");
    if (aDoub1.end() != 5.5)  SLS_ERR("failed!");
    a3Doub1(a3Doub1.n1()-1, a3Doub1.n2()-1, a3Doub1.n3()-1) = 5.5;
    if (a3Doub1(a3Doub1.n1()-1, a3Doub1.n2()-1, a3Doub1.n3()-1) != 5.5 ) SLS_ERR("failed!");
    if (a3Doub1.end() != 5.5)  SLS_ERR("failed!");

    Cmat3Doub c3d(2, 3, 4);
    linspace(c3d, 1, 24);
    if (c3d(0, 0, 0) != 1 || c3d(1,0,0) != 2)
        SLS_ERR("failed!");
    if (c3d(0, 1, 0) != 3 || c3d(0, 2, 0) != 5)
        SLS_ERR("failed!");
    if (c3d(0, 0, 1) != 7 || c3d(0, 0, 2) != 13)
        SLS_ERR("failed!");

    // operator()
    // TODO:
}
