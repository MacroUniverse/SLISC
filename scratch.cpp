// === Build time on Mission with WSL1 ===
// [iostream] 4.2s [STL] 5.2s
// [STL+SLISC] 8.5s
// [GCH:STL+SLISC] 5.2s (GCH = gcc precompiled header)
// [GCH:STL+SLISC+test_arithmetic] 7.2s

// === Build time on Miranda with WSL2 ===
// [STL+SLISC] 4.6s
// [GCH:STL+SLISC] 1.7s
// #include <bits/stdc++.h>

// #include "SLISC/util/STL_util.h"
// #include "SLISC/algo/search.h"
// #include "SLISC/algo/heap.h"
// #include "SLISC/algo/sort.h"
// #include "SLISC/algo/sing_list.h"
// #include "SLISC/algo/bin_tree.h"
// #include "SLISC/algo/disjoint_sets.h"
// #include "SLISC/algo/graph.h"
// #include "SLISC/algo/queue.h"
// #include "SLISC/algo/disjoint_sets.h"
// #include "SLISC/algo/hungarian.h"
// #include "SLISC/algo/huffman.h"
// // #define SLS_RAND_SEED 0
// #include "SLISC/util/random.h"
// #include "SLISC/util/bit.h"
#include "SLISC/util/input.h"
// #include "SLISC/str/str.h"
// #include "SLISC/str/disp.h"
// #include "SLISC/file/file.h"

using namespace slisc;
// using namespace std;

// usage: `./scratch.x < scratch.inp`
int main() {
    vector<int> v_num, v_num1; vector<string> v_str;
    read_input2(v_num, v_str);
	printf("\n\nyour input:");
	for (size_t i = 0; i < v_num.size(); ++i)
		cout << v_num[i] << "  " << v_str[i] << endl; 
    return 0;
}
