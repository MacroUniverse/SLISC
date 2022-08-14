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

template <class T>
inline void minN(vector<T> &vals, vector<Long> &inds, T *v, Long_I N, Long_I Nmin)
{
#ifdef SLS_CHECK_SHAPES
    if (N < Nmin)
        SLS_ERR("wrong shape!");
#endif
    typedef pair<T,Long> P; // (val, ind)
    vals.resize(Nmin); inds.resize(Nmin);
    priority_queue<P> q;
    for (Long i = 0; i < Nmin; ++i)
        q.push(P(v[i], i));
    for (Long i = Nmin; i < N; ++i) {
        T &val = v[i];
        if (val < q.top().first) {
            q.pop();
            q.push(P(val, i));
        }
    }
    for (Long i = 0; i < Nmin; ++i) {
        Long j = Nmin-i-1;
        vals[j] = q.top().first;
        inds[j] = q.top().second;
        q.pop();
    }
}

template <class T>
inline void maxN(vector<T> &vals, vector<Long> &inds, T *v, Long_I N, Long_I Nmax)
{
#ifdef SLS_CHECK_SHAPES
    if (N < Nmax)
        SLS_ERR("wrong shape!");
#endif
    typedef pair<T,Long> P; // (val, ind)
    vals.resize(Nmax); inds.resize(Nmax);
    priority_queue<P, vector<P>, std::greater<P>> q;
    for (Long i = 0; i < Nmax; ++i)
        q.push(P(v[i], i));
    for (Long i = Nmax; i < N; ++i) {
        T &val = v[i];
        if (val > q.top().first) {
            q.pop();
            q.push(P(val, i));
        }
    }
    for (Long i = 0; i < Nmax; ++i) {
        Long j = Nmax-i-1;
        vals[j] = q.top().first;
        inds[j] = q.top().second;
        q.pop();
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

    Long N = 1000, Nmax = 50;
    vector<Long> v(N), vals(Nmax), inds(Nmax);
    randPerm(v);
    maxN(vals, inds, &v[0], N, Nmax);
    for (Long i = 0; i < Nmax; ++i) {
        SLS_ASSERT(vals[i] == N-1-i);
        SLS_ASSERT(vals[i] == v[inds[i]]);
    }
    minN(vals, inds, &v[0], N, Nmax);
    for (Long i = 0; i < Nmax; ++i) {
        SLS_ASSERT(vals[i] == i);
        SLS_ASSERT(vals[i] == v[inds[i]]);
    }
    max(VecInt(5));
    return 0;
}
