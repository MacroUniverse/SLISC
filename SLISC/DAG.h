// Directed Acyclic Graph
#pragma once
#include "global.h"
namespace slisc {

    // node[i] are the next connected nodes
    // node.prev is the last connected node
    struct DAGnode : vector<Long> {
        Long val;
        Long prev;
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
    inline bool dag_topo_sort1(const vector<DAGnode> &dag, vector<Long> &order, vector<bool> &visited, Long_I node)
    {
        visited[node] = true;
        for (auto &next : dag[node]) {
            if (visited[next]) continue;
            dag_topo_sort1(dag, order, visited, next);
        }
        order.push_back(node);
    }

    // topological sort for DAG (algo: DFS backtrack)
    inline bool dag_topo_sort(const vector<DAGnode> &dag, vector<Long> &order)
    {
        Long N = dag.size();
        vector<bool> visited(N, false);
        for (Long node = 0; node < N; ++node) {
            if (!visited[node])
                dag_topo_sort1(dag, order, visited, node);
        }
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

    // check cycle in DAG
//    inline bool dag_check_DFS(const vector<DAGnode> &dag, vector<bool> visited, Long_I start)
//    {
//        for (auto &next : dag[start]) {
//            if (visited[next] && dag_is_downstream_DFS(dag, vector<bool> visited, start, next))
//            if (dag_is_downstream_DFS(dag, visited, node, next))
//                return true;
//        }
//    }

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
