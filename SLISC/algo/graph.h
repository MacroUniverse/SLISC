// Directed Graph (Acyclic or/and Weighted)
#pragma once
#include "../util/random.h"
#include "../algo/disjoint_sets.h"
#include "../algo/search.h"

namespace slisc {

	// ==== DAG (directed acyclic graph) ====
	
	// node for directed graph (including DAG)
	// node[i] are the next connected nodes
	typedef vector<Long> DGnode;

	void dag_examp(vector<DGnode> &dag, Long_I ind);
	void dag_add_edge(vector<DGnode> &dag, Long_I i, Long_I j);
	bool dag_exist_edge(const vector<DGnode> &dag, Long_I i, Long_I j);
	void dag_inv(vector<DGnode> &dag);
	void dag_inv(vector<DGnode> &idag, const vector<DGnode> &dag);
	// BFS
	Long dag_BFS(const vector<DGnode> &dag, Long_I source, Long_I target);
	void dag_shortest_path(vector<Long> &path, const vector<DGnode> &dag, Long_I source, Long_I target);
	void dag_short_edges(vector<pair<Long,Long>> &short_edges, const vector<DGnode> &dag);
	// DFS
	bool dag_is_linked_DFS(const vector<DGnode> &dag, Long_I source, Long_I target);
	bool dag_check(const vector<DGnode> &dag);
	bool dag_check(vector<Long> &cycle, const vector<DGnode> &dag);
	void dag_downstream(unordered_set<Long> &nodes, const vector<DGnode> &dag, Long_I node);
	void dag_upstream(unordered_set<Long> &nodes, vector<DGnode> &dag, Long_I node);
	void dag_topo_sort(const vector<DGnode> &dag, vector<Long> &order);
	Long dag_num_paths(const vector<DGnode> &dag, Long_I source, Long_I target);
	void dag_all_paths(vector<vector<Long>> &paths, const vector<DGnode> &dag, Long_I source, Long_I target);

	// ==== DWG (directed weighted graph) ====

	// edge of directed weighted graph, [0]:from, [1]:to [2]:weight
	typedef array<Long, 3> DWGedge;
	// node for directed weighted graph (including DAG)
	// node[i] are the next connected nodes (.first) and weights (.second)
	// node.last are the last connected nodes (.first) and weights (.second)
	typedef vector<pair<Long,Long>> DWGnode;

	void dwg_add_edge(vector<DWGedge> &dwg, Long_I from, Long_I to, Long_I weight);
	void edges2dwg(vector<DWGnode> &dwg, const vector<DWGedge> &edges);
	void dwg2edges(vector<DWGedge> &edges, const vector<DWGnode> &dwg);
	string dwg_edges2text(const vector<DWGedge> &edges);
	void dwg_text2edges(vector<DWGedge> &edges, const string &str);
	void dwg_SPFA(vector<Long> &dists, const vector<DWGnode> &dwg, Long_I source);
	void dwg_SPFA2(vector<Long> &dists, const vector<DWGnode> &dwg, Long_I source);
	void dwg_examp(vector<DWGedge> &edges);
	void dwg_rand_unsafe(vector<DWGedge> &edges, Long_I Nnode, Long_I Nedge, const pair<Long,Long> &weight_range, Long_I max_fork = 3);
	void dwg_rand(vector<DWGedge> &edges, Long_I Nnode, Long_I Nedge, const pair<Long,Long> &weight_range, Long_I max_fork = 3);

	// ==== WG (weighted graph) ====
	Long wg_MST_kruskal(vector<Long> &min_edges, vector<DWGedge> &edges, Long_I Nnode);


	// ==================== DAG ========================

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
	// dag[order[i]] will never be in upstream of dag[order[i+1]]
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

	// if two nodes of a link has other connection, then it is a "short link"
	// get a list of all short links
	// algo: temporarily unlink every edge, then try dag_BFS
	void dag_short_edges(vector<pair<Long,Long>> &short_edges, const vector<DGnode> &dag)
	{
		short_edges.clear();
		Long N = dag.size();
		for (Long node = 0; node < N; ++node) {
			for (auto &targ : dag[node]) {
				for (auto &next : dag[node]) {
					if (next == targ) continue;
					if (dag_BFS(dag, next, targ) > 0)
						short_edges.push_back(make_pair(node, targ));
				}
			}
		}
	}

	// `throw false` if cycle found
	inline void dag_check_helper(const vector<DGnode> &dag, vector<char> &states, Long_I node)
	{
	    states[node] = 'c';
	    for (auto &next : dag[node]) {
	        if (states[next] == 'u')
	            dag_check_helper(dag, states, next);
	        else if (states[next] == 'v')
	            continue;
	        else // states[next] == 'c'
	            throw false;
	    }
	    states[node] = 'v';
	}

	// check if a graph is DAG
	// algo: DFS, distinguish nodes along current path, visited and unvisited nodes [u]:unvisited, [v]:visited, [c]:current
	inline bool dag_check(const vector<DGnode> &dag)
	{
	    Long N = dag.size();
	    vector<char> states(N, 'u');
	    for (Long i = 0; i < N; ++i) {
	        if (states[i] == 'u') {
				try { dag_check_helper(dag, states, i); }
				catch (bool) { return false; }
			}
		}
	    return true;
	}

	// `throw false` if cycle found
	inline void dag_check_helper(vector<Long> &cycle, const vector<DGnode> &dag, vector<char> &states, Long_I node)
	{
	    states[node] = 'c'; cycle.push_back(node);
	    for (auto &next : dag[node]) {
	        if (states[next] == 'u')
	            dag_check_helper(dag, states, next);
	        else if (states[next] == 'v')
	            continue;
	        else { // states[next] == 'c'
				Long start = search(next, cycle);
				if (start != 0) {
					Long N = cycle.size();
					for (Long i = start; i < N; ++i)
						cycle[i-start] = cycle[i];
					cycle.resize(N - start);
				}
	            throw false;
			}
	    }
	    states[node] = 'v'; cycle.pop_back();
	}

	// check if a graph is DAG, and output 1 cycle
	// algo: DFS, same as dag_check 
	inline bool dag_check(vector<Long> &cycle, const vector<DGnode> &dag)
	{
	    Long N = dag.size(); cycle.clear();
	    vector<char> states(N, 'u');
	    for (Long i = 0; i < N; ++i) {
	        if (states[i] == 'u') {
				try { dag_check_helper(cycle, dag, states, i); }
				catch (bool) { return false; }
			}
		}
	    return true;
	}

	inline void dag_downstream_helper(unordered_set<Long> &nodes, const vector<DGnode> &dag, Long_I node)
	{
	    for (auto &next : dag[node]) {
	        if (nodes.count(next)) continue;
			nodes.insert(next);
	        dag_downstream_helper(nodes, dag, next);
	    }
	}

	// find all downstream nodes (not including `node`)
	// algo: DFS
	inline void dag_downstream(unordered_set<Long> &nodes, const vector<DGnode> &dag, Long_I node)
	{
		nodes.clear();
		dag_downstream_helper(nodes, dag, node);
	}

	// find all downstream nodes (not including `node`)
	// `dag` will only be changed temporarily
	// algo: DFS
	inline void dag_upstream(unordered_set<Long> &nodes, vector<DGnode> &dag, Long_I node)
	{
		vector<DGnode> idag;
		dag_inv(idag, dag);
		dag_downstream(nodes, idag, node);
	}

	inline void dag_inv_helper(vector<DGnode> &dag, vector<bool> &done, Long_I node) {
	    for (auto &next : dag[node]) {
	        if (!done[next])
	            dag_inv_helper(dag, done, next);
	        dag[next].push_back(node);
	    }
	    dag[node].clear(); done[node] = true;
	}

	// inverse every edge of a (singly linked) sub DAG
	// index of dag will not change
	// done[node] == true means all it's original links are erased
	inline void dag_inv(vector<DGnode> &dag) {
	    Long N = dag.size();
	    vector<bool> done(N, false);
	    for (Long node = 0; node < N; ++node)
	        if (!done[node])
	            dag_inv_helper(dag, done, node);
	}

	// create an inverse DAG, idag[i] and dag[i] are the same node
	inline void dag_inv(vector<DGnode> &idag, const vector<DGnode> &dag) {
		for (auto &node : idag) node.clear();
		idag.resize(dag.size());
	    Long N = dag.size();
	    for (Long node = 0; node < N; ++node)
	        for (auto &next : dag[node])
				idag[next].push_back(node);
	}

	// calculate count[node]
	// source != target
	inline void dag_num_paths_helper(unordered_map<Long,Long> &count, const vector<DGnode> &dag, Long_I node, Long_I target)
	{
	    Long N = 0;
	    for (auto &next : dag[node]) {
	        if (!count.count(next))
	            dag_num_paths_helper(count, dag, next, target);
	        N += count[next];
	    }
	    count[node] = N;
	}

	// find # of paths from source to target node
	// algo: DFS, record count from each node to target
	inline Long dag_num_paths(const vector<DGnode> &dag, Long_I source, Long_I target) {
	    if (source == target) return 1;
	    unordered_map<Long, Long> count; // # of paths from each node to target
	    count[target] = 1;
	    dag_num_paths_helper(count, dag, source, target);
	    return count[source];
	}

	inline void dag_all_paths_helper(vector<vector<Long>> &paths, vector<Long> &path, vector<bool> &dead,
	                                 const vector<DGnode> &dag, Long_I node, Long_I target)
	{
	    path.push_back(node);
	    if (node == target) {
	        paths.push_back(path); path.pop_back();
	        return;
	    }
	    bool found = false;
	    for (auto &next : dag[node]) {
	        if (dead[next])
	            continue;
	        dag_all_paths_helper(paths, path, dead, dag, next, target);
	        if (!found && !dead[next])
	            found = true;
	    }
	    dead[node] = !found;
	    path.pop_back();
	}

	// find all possible paths from source to target node
	// algo: DFS, but path to target remains unvisited to allow visiting again
	inline void dag_all_paths(vector<vector<Long>> &paths, const vector<DGnode> &dag, Long_I source, Long_I target) {
	    paths.clear();
	    vector<bool> dead(dag.size(), false); // visited node with no way to target
	    vector<Long> path;
	    dag_all_paths_helper(paths, path, dead, dag, source, target);
	}

	inline void dag_examp(vector<DGnode> &dag, Long_I ind)
	{
	    if (ind == 0) {
	        dag.resize(7);
	        dag[0].assign({2,3,4});
	        dag[1].assign({4,5});
	        dag[2].assign({6,3});
	        dag[4].assign({3,5});
	    }
	    else if (ind == 1) {
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
	    else if (ind == 2) {
	        dag.resize(10);
	        dag[0].assign({1, 2});
	        dag[1].assign({7, 3});
	        dag[2].assign({3});
	        dag[3].assign({4, 5});
	        dag[4].assign({6});
	        dag[5].assign({6});
	        dag[7].assign({8, 9});
	    }
	}

	// =============== DWG ===================

	inline void dwg_add_edge(vector<DWGedge> &dwg, Long_I from, Long_I to, Long_I weight)
	{
	    dwg.emplace_back(); DWGedge &b = dwg.back();
	    b[0] = from; b[1] = to; b[2] = weight;
	}

	// generate DWG from edges (edges[i] = {from, to, weight})
	inline void edges2dwg(vector<DWGnode> &dwg, const vector<DWGedge> &edges)
	{
	    dwg.clear();
	    for (auto &edge : edges) {
	        dwg.resize(max((Long)dwg.size(), max(edge[0], edge[1]) + 1));
	        dwg[edge[0]].emplace_back(edge[1], edge[2]);
	    }
	}

	// from DWG to edges (edges[i] = {from, to, weight})
	inline void dwg2edges(vector<DWGedge> &edges, const vector<DWGnode> &dwg)
	{
	    edges.clear();
	    for (Long node = 0; node < (Long)dwg.size(); ++node)
	        for (auto &next : dwg[node])
	            edges.emplace_back(DWGedge{node, next.first, next.second});
	}

	// convert edges to text
	inline string dwg_edges2text(const vector<DWGedge> &edges)
	{
	    stringstream ss;
	    for (auto &edge : edges)
	        ss << edge[0] << " " << edge[1] << " " << edge[2] << endl;
	    return ss.str();
	}

	// convert text to edges
	inline void dwg_text2edges(vector<DWGedge> &edges, const string &str)
	{
	    stringstream ss(str);
	    Long from, to, weight;
	    while (ss >> from >> to >> weight)
	        edges.push_back({from, to, weight});
	}

	// BFS algo to find the shortest dists from source node
	// (Shortest Path Faster Algorithm)
	// supports negative edge weight
	// out of reach distance is numeric_limits<Long>::max()
	inline void dwg_SPFA(vector<Long> &dists, const vector<DWGnode> &dwg, Long_I source)
	{
	    queue<Long> q; q.push(source);
	    vector<bool> in_q(dwg.size(), false);
	    dists.assign(dwg.size(), numeric_limits<Long>::max());
	    dists[source] = 0;
	    while (!q.empty()) {
	        Long node = q.front(); q.pop(); in_q[node] = false;
	        Long d = dists[node];
	        for (auto &pair : dwg[node]) {
	            Long next = pair.first, weight = pair.second;
	            if (d + weight >= dists[next])
	                continue;
	            dists[next] = d + weight;
	            if (dists[next] < -1e-4) throw "-infinity distance?";
	            if (!in_q[next])
	                q.push(next), in_q[next] = true;
	        }
	    }
	}

	// improved BFS algo to find the shortest dists from source node (algo: que is sorted by distance)
	// supports negative edge weight
	// out of reach distance is numeric_limits<Long>::max()
	inline void dwg_SPFA2(vector<Long> &dists, const vector<DWGnode> &dwg, Long_I source)
	{
	    set<pair<Long,Long>> q; // (dist, node)
	    q.insert(pair<Long,Long>(0, source));
	    vector<bool> in_q(dwg.size(), false);
	    dists.assign(dwg.size(), numeric_limits<Long>::max());
	    dists[source] = 0;
	    while (!q.empty()) {
	        Long node = (*q.begin()).second;
	        q.erase(q.begin()); in_q[node] = false;
	        Long d = dists[node];
	        for (auto &tmp : dwg[node]) {
	            Long next = tmp.first, weight = tmp.second;
	            if (d + weight >= dists[next])
	                continue;
	            if (in_q[next])
	                q.erase(pair<Long, Long>(dists[next], next));
	            dists[next] = d + weight;
	            if (dists[next] < -1e-4) throw "-infinity distance?";
	            q.insert(pair<Long, Long>(dists[next], next)); in_q[next] = true;
	        }
	    }
	}

	inline void dwg_examp(vector<DWGedge> &edges) {
	    edges.clear();
	    edges.push_back({0, 1, 1});
	    edges.push_back({0, 2, 4});
	    edges.push_back({1, 4, 2});
	    edges.push_back({2, 3, -1});
	    edges.push_back({2, 6, 2});
	    edges.push_back({3, 4, -1});
	    edges.push_back({4, 5, 2});
	    edges.push_back({4, 6, 1});
	}

	// generate random DWG (might have -inf cyclic)
	inline void dwg_rand_unsafe(vector<DWGedge> &edges, Long_I Nnode, Long_I Nedge, const pair<Long,Long> &weight_range, Long_I max_fork)
	{
	    edges.clear();
	    vector<Long> fork_count(Nnode, 0);
	    Long Nloop = 0, max_loop = 100*Nedge;
	    while ((Long)edges.size() < Nedge) {
	        if (++Nloop > max_loop) SLS_ERR("dwg_rand: max_loop reached, impossible input?");
	        Long from = randLong(Nnode);
	        while (fork_count[from] > max_fork) {
	            if (++Nloop > max_loop) SLS_ERR("dwg_rand: max_loop reached, impossible input?");
	            from = randLong(Nnode);
	        }
	        Long to = randLong(Nnode);
	        while (to == from) {
	            if (++Nloop > max_loop) SLS_ERR("dwg_rand: max_loop reached, impossible input?");
	            to = randLong(Nnode);
	        }
	        Long i; // check repetition
	        for (i = 0; i < (Long)edges.size(); ++i)
	            if ((edges[i][0] == from && edges[i][1] == to) || (edges[i][0] == to && edges[i][1] == from))
	                break;
	        if (i == (Long)edges.size()) {
	            Long weight = weight_range.first + randLong(weight_range.second-weight_range.first);
	            edges.push_back({from, to, weight});
	            ++fork_count[from];
	        }
	    }
	}

	// generate random DWG (prevent -inf cyclic)
	inline void dwg_rand(vector<DWGedge> &edges, Long_I Nnode, Long_I Nedge, const pair<Long,Long> &weight_range, Long_I max_fork)
	{
	    vector<DWGnode> dwg;
	    vector<Long> dists;
	    for (Long i = 0; i < 4000; ++i) {
	        dwg_rand_unsafe(edges, Nnode, Nedge, weight_range, max_fork);
	        edges2dwg(dwg, edges);
	        Long source;
	        for (source = 0; source < size(dwg); ++source) {
	            try { dwg_SPFA(dists, dwg, source); }
	            catch (...) { break; }
	        }
	        // got a good DWG
	        if (source == size(dwg)) return;
	    }
	    SLS_ERR("dwg_rand(): always got -inf loops, impossible params?");
	}



	// =============== weighted graph ================
	// Kruskal's algorithm to find Minimum Spanning Tree (MST) of a given connected, undirected and weighted graph
	// return total weight of the MST
	// return -1 if the graph is not connected
	// (tested with leetcode 1135)
	inline Long wg_MST_kruskal(vector<Long> &min_edges, vector<DWGedge> &edges, Long_I Nnode)
	{
	    Long tot_wt = 0; // total weight
	    min_edges.clear();
	    auto comp = [](const DWGedge &u, const DWGedge&v)
	    { return u[2] < v[2]; };
	    sort(edges.begin(), edges.end(), comp); // sort by weight
	    disjoint_sets ds(Nnode);
	    Long Nedge = edges.size();
	    for (Long i = 0; i < Nedge; ++i)
	    {
	        auto &edge = edges[i];
	        Long u = edge[0];
	        Long v = edge[1];
	        if (!ds.check(u, v)) // not connected
	        {
	            min_edges.push_back(i);
	            tot_wt += edge[2];
	            ds.merge(u, v);
	        }
	    }
	    return ds.num_set() == 1 ? tot_wt : -1;
	}
} // namespace
