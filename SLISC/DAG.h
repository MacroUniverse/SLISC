// Directed Acyclic Graph
#pragma once
#include "global.h"
namespace slisc {

    // node[i] are the next connected nodes
    // node.prev is the last connected node
    struct DAGnode : vector<Long> {
        Long val;
        vector<Long> last;
    };

    // add edge to DAG
    inline void dag_add_edge(vector<DAGnode> &dag, Long_I i, Long_I j)
    { dag[i].push_back(j); }

    // check if edge exist in DAG
    inline bool dag_exist_edge(const vector<DAGnode> &dag, Long_I i, Long_I j)
    {
        for (auto &e : dag[i])
            if (j == e) // repeated edge
                return true;
        return false;
    }

    // topological sort for a sub DAG (algo: DFS backtrack)
    inline void dag_topo_sort1(const vector<DAGnode> &dag, vector<Long> &order, vector<bool> &visited, Long_I node)
    {
        visited[node] = true;
        for (auto &next : dag[node]) {
            if (visited[next]) continue;
            dag_topo_sort1(dag, order, visited, next);
        }
        order.push_back(node);
    }

    // topological sort for DAG (algo: DFS backtrack)
    inline void dag_topo_sort(const vector<DAGnode> &dag, vector<Long> &order)
    {
        Long N = dag.size();
        vector<bool> visited(N, false);
        for (Long node = 0; node < N; ++node) {
            if (!visited[node])
                dag_topo_sort1(dag, order, visited, node);
        }
        reverse(order.begin(), order.end());
    }

    // deep first search a node: if node[i] can go to node[j] (including i == j)
    inline bool dag_is_linked_DFS_helper(const vector<DAGnode> &dag, vector<bool> &visited, Long_I source, Long_I target)
    {
        visited[source] = true;
        if (source == target)
            return true;
        for (auto &next : dag[source]) {
            if (visited[next]) continue;
            if (dag_is_linked_DFS_helper(dag, visited, next, target))
                return true;
        }
        return false;
    }

    inline bool dag_is_linked_DFS(const vector<DAGnode> &dag, Long_I source, Long_I target)
    {
        vector<bool> visited(dag.size(), false);
        return dag_is_linked_DFS_helper(dag, visited, source, target);
    }

    // breadth first search a node: if node[i] can go to node[j] (including i == j)
    inline bool dag_is_linked_BFS(const vector<DAGnode> &dag, Long_I source, Long_I target)
    {
        if (source == target) return true;
        vector<bool> visited(dag.size(), false);
        vector<Long> nodes = {source}, nodes1;
        while (!nodes.empty()) {
            for (auto &node : nodes) {
                for (auto &next : dag[node]) {
                    if (next == target)
                        return true;
                    if (visited[next]) continue;
                    nodes1.push_back(next); visited[next] = true;
                }
            }
            swap(nodes, nodes1); nodes1.clear();
        }
        return false;
    }

    inline bool dag_check_helper(const vector<DAGnode> &dag, vector<char> &states, Long_I node)
    {
        states[node] = 'c';
        for (auto &next : dag[node]) {
            if (states[next] == 'u') {
                if (!dag_check_helper(dag, states, next))
                    return false;
            }
            else if (states[next] == 'v')
                continue;
            else // states[next] == 'c'
                return false;
        }
        states[node] = 'v';
        return true;
    }

    // check if a graph is DAG
    // algo: DFS, distinguish nodes along current path, visited and unvisited nodes [u] unvisited [v] visited [c] current
    inline bool dag_check(const vector<DAGnode> &dag)
    {
        Long N = dag.size();
        vector<char> states(N, 'u');
        for (Long i = 0; i < N; ++i)
            if (states[i] == 'u' && !dag_check_helper(dag, states, i))
                return false;
        return true;
    }

    // reverse every edge of a (singly linked) sub DAG
    // done[node] == true means all it's original links are erased
    inline void dag_inverse1(vector<DAGnode> &dag, vector<bool> &done, Long_I node) {
        for (auto &next : dag[node]) {
            if (!done[next])
                dag_inverse1(dag, done, next);
            dag[next].push_back(node);
        }
        dag[node].clear(); done[node] = true;
    }

    inline void dag_inverse(vector<DAGnode> &dag) {
        Long N = dag.size();
        vector<bool> done(N, false);
        for (Long node = 0; node < N; ++node)
            if (!done[node])
                dag_inverse1(dag, done, node);
    }

    inline void dag_examp0(vector<DAGnode> &dag) {
        dag.resize(7);
        dag[0].assign({2,3,4});
        dag[1].assign({4,5});
        dag[2].assign({6,3});
        // dag[3];
        dag[4].assign({3,5});
        // dag[5]
        // dag[6]
    }

    inline void dag_examp1(vector<DAGnode> &dag) {
        dag.resize(12);
        dag[0].assign({1, 7});
        dag[1].assign({3, 4});
        dag[2].assign({4, 5, 11});
        dag[3].assign({7, 8});
        dag[4].assign({6});
        dag[5].assign({6});
        dag[6].assign({10, 11});
        dag[7].assign({9});
        dag[8].assign({9});
        dag[9].assign({10});
    }

} // namespace
