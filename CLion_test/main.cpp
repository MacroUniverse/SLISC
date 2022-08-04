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
#include "../SLISC/bin_tree.h"
#include "../SLISC/DAG.h"

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

// Data structure to store a graph edge
struct Edge {
    int src, dest;
};

// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;

    // Graph Constructor
    Graph(const vector<Edge> &edges, int n)
    {
        // resize the vector to hold `n` elements of type `vector<int>`
        adjList.resize(n);

        // add edges to the directed graph
        for (auto &edge: edges) {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};

int main() {
    vector<int> v_num, v_num1; vector<string> v_str;
    read_input(v_num, v_str);
    //----------------------------------------------
    vector<DAGnode> dag;
    dag_examp1(dag);
    vector<Long> order;
    // dag_topo_sort(dag, order);
    bool ret = dag_check(dag);
    return 0;
}
