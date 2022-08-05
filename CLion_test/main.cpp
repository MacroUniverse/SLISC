// Build time: [iostream] 4.2s [STL] 5.2s [SLISC] 8.5s
#include <bits/stdc++.h>
#include "../SLISC/STL_util.h"
#include "../SLISC/search.h"
#include "../SLISC/sort.h"
#include "../SLISC/random.h"
#include "../SLISC/sing_list.h"
#include "../SLISC/bin_tree.h"
#include "../SLISC/DAG.h"
#include "../SLISC/string.h"
#include "../SLISC/Bit.h"
#include "../SLISC/disp.h"
#include "../SLISC/input.h"
#include "../SLISC/file.h"
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
    cout << "hello!" << endl;
    return 0;
}
