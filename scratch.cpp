// === Build time on Mission with WSL1 ===
// [iostream] 4.2s [STL] 5.2s
// [STL+SLISC] 8.5s
// [GCH:STL+SLISC] 5.2s (GCH = gcc precompiled header)
// [GCH:STL+SLISC+test_arithmetic] 7.2s

// === Build time on Miranda with WSL2 ===
// [STL+SLISC] 4.6s
// [GCH:STL+SLISC] 1.7s
// #include <bits/stdc++.h>

#include "SLISC/util/STL_util.h"
#include "SLISC/algo/search.h"
#include "SLISC/algo/heap.h"
#include "SLISC/algo/sort.h"
#include "SLISC/algo/sing_list.h"
#include "SLISC/algo/bin_tree.h"
#include "SLISC/algo/disjoint_sets.h"
#include "SLISC/algo/graph.h"
#include "SLISC/algo/queue.h"
#include "SLISC/algo/disjoint_sets.h"
#include "SLISC/algo/hungarian.h"
#include "SLISC/algo/huffman.h"
// #define SLS_RAND_SEED 0
#include "SLISC/util/random.h"
#include "SLISC/util/bit.h"
#include "SLISC/util/input.h"
#include "SLISC/str/str.h"
#include "SLISC/str/disp.h"
#include "SLISC/file/file.h"

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
    vector<int> v_num, v_num1; vector<string> v_str;
    read_input(v_num, v_str);
    disp(v_num);
    disp(v_str);
//----------------------------------------------
    cout << "done!" << endl;
    return 0;
}
