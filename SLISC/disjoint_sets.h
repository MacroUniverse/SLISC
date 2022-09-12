// disjoint sets
#pragma once
#include "global.h"

namespace slisc {
	struct disjoint_sets
	{
	// private:
	    Long Nset; // # of sets
	    // parent of a node that leads to the set leader
	    vector<Long> parent;
		// map set leaders to total # of children (must not be 0)
	    unordered_map<Long, Long> Nchild;

	// public:
	    disjoint_sets() = default;

	    disjoint_sets(Long N): parent(N), Nset(N)
	    {
	        for (Long i = 0; i < N; i++)
	            parent[i] = i;
	    }

	    // update and return the set leader of a node
	    Long find(Long node)
	    {
	        Long &p = parent[node];
	        if (p != parent[p])
	            p = find(p);
	        return p;
	    }

	    // check if two nodes are in the same set
	    bool check(Long_I x, Long_I y)
	    { return find(x) == find(y); }

	    // merge two sets. x, y are elements from each set
	    // x, y can be in the same group
	    void merge(Long_I node1, Long_I node2)
	    {
	        Long l1 = find(node1), l2 = find(node2);
	        if (l1 == l2) return; // same set
	        Long N1 = set_size(l1), N2 = set_size(l2);
	        if (N1 > N2) // set 2 join set 1
	            parent[l2] = l1, Nchild[l1] += N2, Nchild.erase(l2);
	        else // set 1 join set 2
	            parent[l1] = l2, Nchild[l2] += N1, Nchild.erase(l1);
	        --Nset;
	    }

	    // total # of nodes
	    Long size() { return parent.size(); }

	    // # of sets
	    Long num_set() { return Nset; }

	    // # of sets with more than 1 node
	    Long num_set2() { return Nchild.size(); }

	    // # of nodes in each set
	    Long set_size(Long_I leader)
	    { return Nchild.count(leader) ? Nchild[leader]+1 : 1; }

	    // add isolated nodes, or add nodes to the set of `node`
	    void resize(Long_I N, Long_I node = -1)
	    {
	        Long old_size = size();
	        assert(N > old_size);
	        if (node < 0) {
	            parent.resize(N);
	            for (Long i = old_size; i < N; ++i)
	                parent[i] = i;
	            Nset += N - old_size;
	        }
	        else
	            parent.resize(N, find(node));
	    }

	    // update the parens of all nodes to set leaders
	    // for debug purpose only
	    void update()
	    {
	        Long N = size();
	        for (Long i = 0; i < N; ++i)
	            find(i);
	    }
	};
} // namespace slisc
