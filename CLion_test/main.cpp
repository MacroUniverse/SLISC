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
// #define SLS_RAND_SEED 0
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
//    vector<int> v_num, v_num1; vector<string> v_str;
//    read_input(v_num, v_str);
//----------------------------------------------
//    priority_queue<int, vector<int>, greater<int>> heap;   // 定义小根堆的方式
//    heap.push(5); heap.push(8); heap.push(3); heap.push(1); heap.push(2); heap.push(9); heap.push(6);
//    while (!heap.empty())
//    {
//        cout << heap.top() << endl;     // 输出最小值，即队头
//        heap.pop();     // 删除最小值，即删除队头
//    }
    return 0;
}
