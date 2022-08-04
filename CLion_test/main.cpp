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

// Perform DFS on the graph and set the departure time of all vertices of the graph
int DFS(Graph const &graph, int v, vector<bool> &discovered, vector<int> &departure, int &time)
{
    // mark the current node as discovered
    discovered[v] = true;

    // do for every edge (v, u)
    for (int u: graph.adjList[v])
    {
        // if `u` is not yet discovered
        if (!discovered[u]) {
            DFS(graph, u, discovered, departure, time);
        }
    }

    // ready to backtrack
    // set departure time of vertex `v`
    departure[v] = time++;
}

// Returns true if given directed graph is DAG
bool isDAG(Graph const &graph, int n)
{
    // keep track of whether a vertex is discovered or not
    vector<bool> discovered(n);

    // keep track of the departure time of a vertex in DFS
    vector<int> departure(n);

    int time = 0;

    // Perform DFS traversal from all undiscovered vertices
    // to visit all connected components of a graph
    for (int i = 0; i < n; i++)
    {
        if (!discovered[i]) {
            DFS(graph, i, discovered, departure, time);
        }
    }

    // check if the given directed graph is DAG or not
    for (int u = 0; u < n; u++)
    {
        // check if (u, v) forms a back-edge.
        for (int v: graph.adjList[u])
        {
            // If the departure time of vertex `v` is greater than equal
            // to the departure time of `u`, they form a back edge.

            // Note that departure[u] will be equal to
            // departure[v] only if `u = v`, i.e., vertex
            // contain an edge to itself
            if (departure[u] <= departure[v]) {
                return false;
            }
        }
    }

    // no back edges
    return true;
}



int main() {
    vector<int> v_num, v_num1; vector<string> v_str;
    read_input(v_num, v_str);
    //----------------------------------------------
    // Create a graph given in the above diagram

//
//    cout << "Following is a Topological Sort of the given "
//            "graph \n";
//
//    // Function Call
//    g.topologicalSort();
    vector<DAGnode> dag;
    dag_examp1(dag);
    vector<Long> order;
    // dag_topo_sort(dag, order);
    Long N = dag.size();
    for (Long i = 0; i < N; ++i) {
        for (Long j = 0; j < N; ++j) {
            bool ret1 = dag_is_linked_DFS(dag, i, j);
            bool ret2 = dag_is_linked_BFS(dag, i, j);
            SLS_ASSERT(ret1 == ret2);
        }
    }
    SLS_ASSERT(false);
    return 0;
}
