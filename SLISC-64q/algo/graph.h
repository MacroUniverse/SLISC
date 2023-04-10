// Directed Graph (Acyclic or/and Weighted)
#pragma once
#include "../util/random.h"
#include "../algo/disjoint_sets.h"
#include "../algo/search.h"
#include "../util/STL_util.h"

namespace slisc {

	// ==== DG (directed graph) ====
	// node for directed graph (including DAG)
	// node[i] are the next connected nodes
	typedef vector<Long> DGnode;
	void dg_rand(vector<DGnode> &dg, Long_I Nnode, Long_I Nedge, Long max_fork);
	void dg_add_edges(vector<DGnode> &dg, const vector<pair<Long,Long>> &edges);
	void dg_rm_edges(vector<DGnode> &dg, const vector<pair<Long,Long>> &edges);
	Long dg_Nedges(const vector<DGnode> &dg);
	void dg_sort(vector<DGnode> &dg);
	std::ostream &operator<<(std::ostream &os, const vector<DGnode> &dg);

	// ==== DAG (directed acyclic graph) ====
	void dag_rand(vector<DGnode> &dag, Long_I Nnode, Long_I Nedge, Long_I max_fork);
	void dag_examp(vector<DGnode> &dag, Long_I ind);
	void dag_inv(vector<DGnode> &dag);
	void dag_inv(vector<DGnode> &idag, const vector<DGnode> &dag);
	// BFS
	Long dag_BFS(const vector<DGnode> &dag, Long_I source, Long_I target);
	void dag_BFS(vector<Long> &path, const vector<DGnode> &dag, Long_I source, Long_I target);
	void dag_reduce(vector<pair<Long,Long>> &short_edges, const vector<DGnode> &dag);
	Long dag_reduce(vector<DGnode> &dag);
	// DFS
	bool dag_DFS(const vector<DGnode> &dag, Long_I source, Long_I target);
	void dag_topo_sort(const vector<DGnode> &dag, vector<Long> &order);
	bool dag_check(const vector<DGnode> &dag);
	bool dag_check(vector<Long> &cycle, const vector<DGnode> &dag);
	void dg2dag(vector<DGnode> &dag);
	void dag_downstream(unordered_set<Long> &nodes, const vector<DGnode> &dag, Long_I node);
	void dag_upstream(unordered_set<Long> &nodes, vector<DGnode> &dag, Long_I node);
	Long dag_num_paths(const vector<DGnode> &dag, Long_I source, Long_I target);
	void dag_all_paths(vector<vector<Long>> &paths, const vector<DGnode> &dag, Long_I source, Long_I target);

	// ==== DWG (directed weighted graph) ====

	// edge of directed weighted graph, [0]:from, [1]:to, [2]:weight
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

	// generate random directed graph (might have cycle, might not be all connected)
	inline void dg_rand(vector<DGnode> &dg, Long_I Nnode, Long_I Nedge, Long max_fork)
	{
		max_fork = min(max_fork, Nnode-1);
		assert(Nedge <= Nnode*max_fork);
		dg.clear(); dg.resize(Nnode);
		for (Long i = 0; i < Nedge; ++i) {
			Long from, to;
			do
				from = randLong(Nnode);
			while (size(dg[from]) == max_fork);
			do
				to = randLong(Nnode);
			while (to == from || search(to, dg[from]) >= 0);
			dg[from].push_back(to);
		}
	}

	// generate random DAG
	inline void dag_rand(vector<DGnode> &dag, Long_I Nnode, Long_I Nedge, Long max_fork)
	{
		max_fork = min(max_fork, Nnode-1);
		assert(Nedge <= Nnode*max_fork);
		assert(Nedge <= Nnode*(Nnode-1)/2);
		dag.clear(); dag.resize(Nnode);
		unordered_set<Long> froms, tos;
		for (Long i = 0; i < Nnode; ++i) froms.insert(i);
		for (Long i = 0; i < Nedge; ++i) {
			Long from;
			label: ;
			auto p_from = rand_iter(froms);
			from = *p_from;
			tos.clear();
			for (Long j = 0; j < Nnode; ++j) {
				if (j == from) continue;
				tos.insert(j);
			}
			auto p_to = rand_iter(tos);
			while (search(*p_to, dag[from]) >= 0 || dag_BFS(dag, *p_to, from) > 0) {
				tos.erase(p_to);
				if (tos.empty()) {
					froms.erase(p_from);
					if (froms.empty())
						throw "can't satisfy Nedge!";
					goto label;
				}
				p_to = rand_iter(tos);
			}
			dag[from].push_back(*p_to);
			if (size(dag[from]) == max_fork) {
				froms.erase(p_from);
				if (froms.empty()) throw "can't satisfy Nedge!";
			}
		}
	}

	// topological sort for a sub DAG (algo: DFS backtrack)
	inline void dag_topo_sort_helper(const vector<DGnode> &dag, vector<Long> &order, vector<bool> &visited, Long_I node)
	{
		visited[node] = true;
		for (auto &next : dag[node]) {
			if (visited[next]) continue;
			dag_topo_sort_helper(dag, order, visited, next);
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
				dag_topo_sort_helper(dag, order, visited, node);
		}
		reverse(order.begin(), order.end());
	}

	// deep first search a node: if node[i] can go to node[j] (including i == j)
	inline bool dag_DFS_helper(const vector<DGnode> &dag, vector<bool> &visited, Long_I source, Long_I target)
	{
		visited[source] = true;
		if (source == target)
			return true;
		for (auto &next : dag[source]) {
			if (visited[next]) continue;
			if (dag_DFS_helper(dag, visited, next, target))
				return true;
		}
		return false;
	}

	inline bool dag_DFS(const vector<DGnode> &dag, Long_I source, Long_I target)
	{
		vector<bool> visited(dag.size(), false);
		return dag_DFS_helper(dag, visited, source, target);
	}

	// breadth first search from dag[i] for dag[j] (including i == j)
	// return mininum steps needed, return -1 if not found
	// return 0 iff source == target
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

	// shortest path from multiple sources to target
	inline Long dag_BFS(const vector<DGnode> &dag, vecLong_I sources, Long_I target)
	{
		if (search(target, sources) >= 0) return 0;
		vector<bool> visited(dag.size(), false);
		vector<Long> nodes(sources), nodes1;
		Long Nstep = 1;
		while (!nodes.empty()) {
			++Nstep;
			for (auto &node : nodes) {
				for (auto &next : dag[node]) {
					if (visited[next]) continue;
					if (next == target)
						return Nstep;
					nodes1.push_back(next); visited[next] = true;
				}
			}
			swap(nodes, nodes1); nodes1.clear();
		}
		return -1;
	}

	// get shortest path between source and target
	// algo: BFS, store reverse edge for each searched edge
	inline void dag_BFS(vector<Long> &path, const vector<DGnode> &dag, Long_I source, Long_I target)
	{
		path.clear();
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
		if (nodes.empty()) return; // not counnected
		Long node = target;
		path.push_back(target);
		while (node != source) {
			node = iedge[node];
			path.push_back(node);
		}
		reverse(path.begin(), path.end());
	}

	// shortest path from multiple sources to target
	inline void dag_BFS(vector<Long> &path, const vector<DGnode> &dag, vecLong_I sources, Long_I target)
	{
		path.clear();
		if (search(target, sources) >= 0) return;
		unordered_map<Long, Long> iedge; // all searched edge in reverse
		vector<Long> nodes(sources), nodes1;
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
		if (nodes.empty()) return; // not counnected
		Long node = target;
		path.push_back(target);
		while (search(node, sources) < 0) {
			node = iedge[node];
			path.push_back(node);
		}
		reverse(path.begin(), path.end());
	}

	// Transitive Reduction
	// if two nodes of an edge has other connection, then it is redundant
	// get a list of all redundant edges
	// algo: temporarily remove every edge, then try dag_BFS
	inline void dag_reduce(vector<pair<Long,Long>> &short_edges, const vector<DGnode> &dag)
	{
		short_edges.clear();
		Long N = dag.size();
		vecLong sources;
		for (Long node = 0; node < N; ++node) {
			for (auto &targ : dag[node]) {
				sources.clear();
				for (auto &next: dag[node]) {
					if (next == targ) continue;
					sources.push_back(next);
				}
				if (dag_BFS(dag, sources, targ) >= 0)
					short_edges.push_back(make_pair(node, targ));
			}
		}
	}

	// find all children of dag[node] are redundant, and the alternative paths
	// paths[i] is the shortest alternative path from `node` to the i-th redundant child
	inline void dag_reduce(vector<vecLong> &paths, const vector<DGnode> &dag, Long_I node)
	{
		paths.clear();
		vecLong path; vecLong sources;
		for (auto &targ : dag[node]) {
			sources.clear();
			for (auto &next: dag[node]) {
				if (next == targ) continue;
				sources.push_back(next);
			}
			dag_BFS(path, dag, sources, targ);
			if (!path.empty()) {
				path.insert(path.begin(), node);
				paths.push_back(path);
			}
		}
	}

	// return # of deleted edges
	inline Long dag_reduce(vector<DGnode> &dag)
	{
		vector<pair<Long,Long>> short_edges;
		dag_reduce(short_edges, dag);
		dg_rm_edges(dag, short_edges);
		return short_edges.size();
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
				dag_check_helper(cycle, dag, states, next);
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

	inline void dg2dag_helper(vector<DGnode> &dag, vector<char> &states, Long_I node)
	{
		states[node] = 'c';
		DGnode &cur = dag[node]; // current node
		for (Long i = size(cur)-1; i >= 0; --i) {
			Long next = cur[i];
			if (states[next] == 'u')
				dg2dag_helper(dag, states, next);
			else if (states[next] == 'v')
				continue;
			else // states[next] == 'c'
				erase(cur, i);
		}
		states[node] = 'v';
	}

	// remove cycles from dg, making dag
	inline void dg2dag(vector<DGnode> &dag)
	{
		Long N = dag.size();
		vector<char> states(N, 'u');
		for (Long i = 0; i < N; ++i)
			if (states[i] == 'u')
				dg2dag_helper(dag, states, i);
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

	// inverse every edge of a sub DAG
	// index of dag will not change
	// `done[node]` == true means all it's original edges are erased
	inline void dag_inv(vector<DGnode> &dag)
	{
		Long N = dag.size();
		vector<bool> done(N, false);
		for (Long node = 0; node < N; ++node)
			if (!done[node])
				dag_inv_helper(dag, done, node);
	}

	// create an inverse DAG, idag[i] and dag[i] are the same node
	inline void dag_inv(vector<DGnode> &idag, const vector<DGnode> &dag)
	{
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
	inline Long dag_num_paths(const vector<DGnode> &dag, Long_I source, Long_I target)
	{
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
	inline void dag_all_paths(vector<vector<Long>> &paths, const vector<DGnode> &dag, Long_I source, Long_I target)
	{
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

	// will not repeat
	inline void dg_add_edges(vector<DGnode> &dg, const vector<pair<Long,Long>> &edges)
	{
		for (auto &edge : edges) {
			if (edge.first == edge.second)
				SLS_ERR("illegal edge:" + to_string(edge.first) + "->" + to_string(edge.second));
			Long sz = max(edge.first,edge.second)+1;
			if (size(dg) < sz)
				dg.resize(sz);
			auto &node = dg[edge.first];
			if (search(edge.second, node) < 0)
				node.push_back(edge.second);
		}
	}

	// doesn't have to exist
	inline void dg_rm_edges(vector<DGnode> &dg, const vector<pair<Long,Long>> &edges)
	{
		for (auto &edge : edges) {
			if (edge.first >= size(dg))
				continue;
			auto &node = dg[edge.first];
			Long i = search(edge.second, node);
			if (i >= 0)
				node.erase(node.begin() + i);
		}
	}

	// count edges
	inline Long dg_Nedges(const vector<DGnode> &dg)
	{
		Long N = 0;
		for (auto &node : dg)
			N += node.size();
		return N;
	}

	// sort every DGnode by "next"
	inline void dg_sort(vector<DGnode> &dg)
	{
		for (auto &node : dg)
			if (node.size())
				sort(node.begin(), node.end());
	}

	inline std::ostream &operator<<(std::ostream &os, const vector<DGnode> &dg)
	{
		cout << "directed graph with " << size(dg) << " nodes and "
			<< dg_Nedges(dg) << " edges:" << endl;
		for (Long i = 0; i < size(dg); ++i) {
			cout << i << " -> ";
			for (auto &next : dg[i])
				cout << next << " ";
			cout << endl;
		}
		return os;
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

	// BFS algo to find the shortest dists from `source` node to all nodes
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
				if (dists[next] < -1e4)
					throw "cycle with negative total weight? not allowed.";
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
		set<pair<Long,Long>> q; // (dist, node), ordered by dist
		dists.assign(dwg.size(), numeric_limits<Long>::max());
		dists[source] = 0;
		q.insert(make_pair(Long(0), source));
		while (!q.empty()) {
			Long node = (*q.begin()).second, d = (*q.begin()).first;
			q.erase(q.begin());
			for (auto &tmp : dwg[node]) {
				Long next = tmp.first, weight = tmp.second;
				if (d + weight >= dists[next])
					continue;
				q.erase(make_pair(dists[next], next));
				dists[next] = d + weight;
				if (dists[next] < -1e4)
					throw "cycle with negative total weight? not allowed.";
				q.insert(make_pair(dists[next], next));
			}
		}
	}

	inline void dwg_examp(vector<DWGedge> &edges)
	{
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

	// generate random DWG (might have cyclic with negative total weight)
	inline void dwg_rand_unsafe(vector<DWGedge> &edges, Long_I Nnode, Long_I Nedge,
								const pair<Long,Long> &weight_range, Long_I max_fork)
	{
		edges.clear();
		vector<Long> fork_count(Nnode, 0);
		Long Niter = 0, max_iter = 100*Nedge;
		while ((Long)edges.size() < Nedge) {
			if (++Niter > max_iter) SLS_ERR("dwg_rand: max_iter reached, impossible input?");
			Long from = randLong(Nnode);
			while (fork_count[from] > max_fork) {
				if (++Niter > max_iter) SLS_ERR("dwg_rand: max_iter reached, impossible input?");
				from = randLong(Nnode);
			}
			Long to = randLong(Nnode);
			while (to == from) {
				if (++Niter > max_iter) SLS_ERR("dwg_rand: max_iter reached, impossible input?");
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

	// generate random DWG (prevent cycle with negative total weight)
	inline void dwg_rand(vector<DWGedge> &edges, Long_I Nnode, Long_I Nedge,
						 const pair<Long,Long> &weight_range, Long_I max_fork)
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
		SLS_ERR("dwg_rand(): always got cycles with negative weight, impossible params?");
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
