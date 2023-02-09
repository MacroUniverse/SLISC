// === Build time on Mission with WSL1 ===
// [iostream] 4.2s [STL] 5.2s
// [STL+SLISC] 8.5s
// [GCH:STL+SLISC] 5.2s (GCH = gcc precompiled header)
// [GCH:STL+SLISC+test_arithmetic] 7.2s

// === Build time on Miranda with WSL2 ===
// [STL+SLISC] 4.6s
// [GCH:STL+SLISC] 1.7s
#include <bits/stdc++.h>
// #define SLS_USE_INT_AS_LONG
#include "../SLISC/global.h"
#include "../SLISC/STL_util.h"
#include <climits>
#include "../SLISC/search.h"
#include "../SLISC/heap.h"
#include "../SLISC/sort.h"
// #define SLS_RAND_SEED 0
#include "../SLISC/random.h"
#include "../SLISC/sing_list.h"
#include "../SLISC/bin_tree.h"
#include "../SLISC/disjoint_sets.h"
#include "../SLISC/graph.h"
#include "../SLISC/string.h"
#include "../SLISC/Bit.h"
#include "../SLISC/disp.h"
#include "../SLISC/input.h"
#include "../SLISC/file.h"
#include "../SLISC/queue.h"
#include "../SLISC/disjoint_sets.h"
#include "../SLISC/hungarian.h"
#include "../SLISC/huffman.h"
using namespace slisc;

using namespace std;

inline void read_input(vector<int> &v_num, vector<string> &v_str) {
    int num; string str;
    while (cin >> num >> str) {
        v_num.push_back(num);
        v_str.push_back(move(str));
        cin.ignore(ULLONG_MAX, '\n');
    }
}

int main() {
//    vector<int> v_num, v_num1; vector<string> v_str;
//    read_input(v_num, v_str);
//----------------------------------------------
    return 0;
}
