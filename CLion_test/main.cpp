// === Build time on Mission with WSL1 ===
// [iostream] 4.2s [STL] 5.2s
// [STL+SLISC] 8.5s
// [GCH:STL+SLISC] 5.2s (GCH = gcc precompiled header)
// [GCH:STL+SLISC+test_arithmetic] 7.2s

// === Build time on Miranda with WSL2 ===
// [STL+SLISC] 4.6s
// [GCH:STL+SLISC] 1.7s

#include <bits/stdc++.h>
#include "../SLISC/STL_util.h"
#include "../SLISC/search.h"
#include "../SLISC/sort.h"
#include "../SLISC/random.h"
#include "../SLISC/sing_list.h"
#include "../SLISC/bin_tree.h"
#include "../SLISC/graph.h"
#include "../SLISC/string.h"
#include "../SLISC/Bit.h"
#include "../SLISC/disp.h"
#include "../SLISC/input.h"
#include "../SLISC/file.h"
#include "../SLISC/queue.h"
using namespace slisc;

using namespace std;

inline void read_input(vector<int> &v_num, vector<string> &v_str) {
    int num; string str;
    while (cin >> num >> str) {
        v_num.push_back(num);
        v_str.push_back(move(str));
        cin.ignore(ULONG_LONG_MAX, '\n');
    }
}

int main() {
    vector<int> v_num, v_num1; vector<string> v_str;
    read_input(v_num, v_str);
//----------------------------------------------

    vector<vector<Long>> edges, edges2;
    dwg_examp0(edges);
    vector<DWGnode> dwg, dwg2;
    edges2dwg(dwg, edges);
    vector<Long> dists, dists2;
    dwg_SPFA(dists, dwg, 0);
    dwg_SPFA2(dists2, dwg, 0);
    SLS_ASSERT(dists == dists2);

    dwg_rand(edges2, 20, 50, {-2,5}, 3);
    edges2dwg(dwg2, edges2);
    for (Long source = 0; source < (Long)dwg2.size(); ++source) {
        dwg_SPFA(dists, dwg2, 0);
        dwg_SPFA2(dists2, dwg2, 0);
        SLS_ASSERT(dists == dists2);
    }
    return 0;
}
