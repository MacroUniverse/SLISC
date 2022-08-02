#include <bits/stdc++.h>
#include "../SLISC/sort.h"
#include "../SLISC/search.h"
#include "../SLISC/random.h"
#include "../SLISC/STL_util.h"
#include "../SLISC/arithmetic.h"
#include "../SLISC/file.h"
#include "../SLISC/input.h"

using namespace slisc;
using namespace std;

inline void read_input(vector<int> &v_num, vector<string> &v_str) {
    int num; string str;
    while (cin >> num >> str) {
        v_num.push_back(num);
        v_str.push_back(move(str));
        cin_ignore_line();
    }
}

int main() {
    vector<int> v_num; vector<string> v_str;
    read_input(v_num, v_str);

    forward_list<int> flist, flist1;
    for (int i = 0; i < 10; ++i) {
        flist.push_front(randInt(100));
        flist1.push_front(randInt(100));
    }
    flist.sort(); flist1.sort();
    flist.merge(flist1);
    for (auto &e : flist)
        cout << e << endl;
    cout << *(flist.begin()) << endl;
    flist.insert_after(flist.begin(), 300);
    return 0;
}
