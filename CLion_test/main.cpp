#include <bits/stdc++.h>
#include "../SLISC/STL_util.h"
#include "../SLISC/arithmetic.h"
#include "../SLISC/sort.h"
#include "../SLISC/search.h"
#include "../SLISC/random.h"
#include "../SLISC/string.h"
#include "../SLISC/Bit.h"
#include "../SLISC/disp.h"
#include "../SLISC/file.h"
#include "../SLISC/input.h"
#include "../SLISC/sing_list.h"

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
    vector<int> v_num, v_num1; vector<string> v_str;
    read_input(v_num, v_str);
    //----------------------------------------------
    Long N = 5;
    SNode *head = sing_list_gen(N);
    sing_list_rand_perm(head, N);
    sing_list_print(head);
    sing_list_mergesort(head);
    SLS_ASSERT(sing_list_check(head) == N);
    sing_list_print(head);
    Long sz = sing_list_size(head);
    SNode *node3 = sing_list_locate(head, 3);
    sing_list_insert_after(node3, 333);
    sing_list_print(head);
    return 0;
}
