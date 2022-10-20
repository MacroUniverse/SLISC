// === Build time on Mission with WSL1 ===
// [iostream] 4.2s [STL] 5.2s
// [STL+SLISC] 8.5s
// [GCH:STL+SLISC] 5.2s (GCH = gcc precompiled header)
// [GCH:STL+SLISC+test_arithmetic] 7.2s

// === Build time on Miranda with WSL2 ===
// [STL+SLISC] 4.6s
// [GCH:STL+SLISC] 1.7s
//#include <bits/stdc++.h>
//#define SLS_USE_INT_AS_LONG
//#include "../SLISC/global.h"
//#include "../SLISC/STL_util.h"
//#include "../SLISC/search.h"
//#include "../SLISC/heap.h"
//#include "../SLISC/sort.h"
// #define SLS_RAND_SEED 0
//#include "../SLISC/random.h"
//#include "../SLISC/sing_list.h"
//#include "../SLISC/bin_tree.h"
//#include "../SLISC/disjoint_sets.h"
//#include "../SLISC/graph.h"
//#include "../SLISC/string.h"
//#include "../SLISC/Bit.h"
//#include "../SLISC/disp.h"
//#include "../SLISC/input.h"
//#include "../SLISC/file.h"
//#include "../SLISC/queue.h"
//#include "../SLISC/disjoint_sets.h"
//#include "../SLISC/hungarian.h"
//#include "../SLISC/huffman.h"
#include "../SLISC/matb.h"

#include "../SLISC/odeint.h"
using namespace slisc;

// a functor for derivative
struct Dfun
{
    void operator() (Doub_I t, VecDoub_I yy, VecDoub_O dyydt) {
        dyydt[0] = yy[1];
        dyydt[1] = -yy[0];
    }
};

int main() {
//    vector<int> v_num, v_num1; vector<string> v_str;
//    read_input(v_num, v_str);
//----------------------------------------------

    // SHO
    VecDoub ystartt(2); ystartt[0] = 1; ystartt[1] = 0;
    Doub xx1 = 0, xx2 = 10, atol = 1e-14, rtol = 1e-14, h1 = 0.1, hminn = 0;
    Output outt;
    Dfun dfun;

    Odeint<StepperDopr853<Dfun>> ode(ystartt, xx1, xx2, atol, rtol, h1,
        hminn, outt, dfun);
    ode.integrate();
    Matb matb("test.matb", "w");
    save(outt.xsave, "xsave", matb);
    save(outt.ysave, "ysave", matb);
    return 0;
}
