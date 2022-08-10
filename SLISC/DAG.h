// Directed Acyclic Graph
#pragma once
#include "global.h"
namespace slisc {

    // node[i] are the next connected nodes
    // node.prev is the last connected node
    struct DGnode : vector<Long> {
        Long val;
        vector<Long> last;
    };

    // add edge to DAG
    inline void dag_add_edge(vector<DGnode> &dag, Long_I i, Long_I j)
    { dag[i].push_back(j); }

    // check if edge exist in DAG
    inline bool dag_exist_edge(const vector<DGnode> &dag, Long_I i, Long_I j)
    {
        for (auto &e : dag[i])
            if (j == e) // repeated edge
                return true;
        return false;
    }

    // topological sort for a sub DAG (algo: DFS backtrack)
    inline void dag_topo_sort1(const vector<DGnode> &dag, vector<Long> &order, vector<bool> &visited, Long_I node)
    {
        visited[node] = true;
        for (auto &next : dag[node]) {
            if (visited[next]) continue;
            dag_topo_sort1(dag, order, visited, next);
        }
        order.push_back(node);
    }

    // topological sort for DAG (algo: DFS backtrack)
    inline void dag_topo_sort(const vector<DGnode> &dag, vector<Long> &order)
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
    inline bool dag_is_linked_DFS_helper(const vector<DGnode> &dag, vector<bool> &visited, Long_I source, Long_I target)
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

    inline bool dag_is_linked_DFS(const vector<DGnode> &dag, Long_I source, Long_I target)
    {
        vector<bool> visited(dag.size(), false);
        return dag_is_linked_DFS_helper(dag, visited, source, target);
    }

    // breadth first search from dag[i] for dag[j] (including i == j)
    // return mininum steps needed, return -1 if not found
    inline Long dag_BFS(const vector<DGnode> &dag, Long_I source, Long_I target)
    {
        if (source == target) return 0;
        vector<bool> visited(dag.size(), false);
        vector<Long> nodes = {source}, nodes1;
        Long Nstep = 1;
        while (!nodes.empty()) {
            ++Nstep;
            for (auto &node : nodes) {
                for (auto &next : dag[node]) {
                    if (next == target)
                        return Nstep;
                    if (visited[next]) continue;
                    nodes1.push_back(next); visited[next] = true;
                }
            }
            swap(nodes, nodes1); nodes1.clear();
        }
        return -1;
    }

    // get shortest path between source and target
    // algo: BFS, add reverse link for each seached edge
    inline void dag_shortest_path(vector<Long> &path, const vector<DGnode> &dag, Long_I source, Long_I target)
    {
        path.clear(); path.push_back(target);
        if (source == target) return;
        unordered_map<Long, Long> iedge; // all searched edge in reverse
        vector<Long> nodes = {source}, nodes1;
        while (!nodes.empty()) {
            for (auto &node : nodes) {
                for (auto &next : dag[node]) {
                    if (iedge.count(next)) continue;
                    iedge[next] = node;
                    if (next == target) goto abc;
                    nodes1.push_back(next);
                }
            }
            swap(nodes, nodes1); nodes1.clear();
        }
        abc:
        Long node = target;
        while (node != source) {
            node = iedge[node];
            path.push_back(node);
        }
        reverse(path.begin(), path.end());
    }

    inline bool dag_check_helper(const vector<DGnode> &dag, vector<char> &states, Long_I node)
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
    inline bool dag_check(const vector<DGnode> &dag)
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
    inline void dag_inverse1(vector<DGnode> &dag, vector<bool> &done, Long_I node) {
        for (auto &next : dag[node]) {
            if (!done[next])
                dag_inverse1(dag, done, next);
            dag[next].push_back(node);
        }
        dag[node].clear(); done[node] = true;
    }

    inline void dag_inverse(vector<DGnode> &dag) {
        Long N = dag.size();
        vector<bool> done(N, false);
        for (Long node = 0; node < N; ++node)
            if (!done[node])
                dag_inverse1(dag, done, node);
    }

    inline void dag_all_paths_helper(vector<vector<Long>> &paths, vector<Long> &path, vector<bool> &visited, const vector<DGnode> &dag, Long_I node, Long_I target) {
        path.push_back(node);
        if (node == target) {
            paths.push_back(path); path.pop_back();
            return;
        }
        bool found = false;
        for (auto &next : dag[node]) {
            if (!visited[next]) {
                dag_all_paths_helper(paths, path, visited, dag, next, target);
                if (!visited[next])
                    found = true;
            }
            else // states[next] == 'v'
                continue;
        }
        visited[node] = !found;
        path.pop_back();
    }

    // find all possible paths from source to target node
    // algo: deep first search (DFS), but path to target remains unvisited to allow visiting again
    inline void dag_all_paths(vector<vector<Long>> &paths, const vector<DGnode> &dag, Long_I source, Long_I target) {
        paths.clear();
        vector<bool> visited(dag.size(), false);
        vector<Long> path;
        dag_all_paths_helper(paths, path, visited, dag, source, target);
    }

    inline void dag_examp0(vector<DGnode> &dag) {
        dag.resize(7);
        dag[0].assign({2,3,4});
        dag[1].assign({4,5});
        dag[2].assign({6,3});
        // dag[3];
        dag[4].assign({3,5});
        // dag[5]
        // dag[6]
    }

    inline void dag_examp1(vector<DGnode> &dag) {
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
