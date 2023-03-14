// tree utility
#pragma once
#include "search.h"

namespace slisc {

struct Node
{
	vecLong last; // last nodes
	vecLong next; // next nodes
};

// links[2n] -> links[2n+1]
inline void tree_gen(vector<Node> &tree, vecStr32_I entries, vecLong_I links)
{
	Long Nlink = links.size();
	tree.resize(entries.size());
	for (Long i = 0; i < Nlink; i += 2) {
		Long ind1 = links[i], ind2 = links[i + 1];
		tree[ind1].next.push_back(ind2);
		tree[ind2].last.push_back(ind1);
	}
}

// recursives implementation of tree_all_dep()
// return -1-ind if too many levels (probably circular dependency), tree[ind] is the deepest level
inline Long tree_all_dep_imp(vecLong_O deps, const vector<Node> &tree, Long_I ind, vecStr32_I vector, Long Niter = 0)
{
	++Niter;
	// cout << "tree debug: ind = " << ind << ", level = " << Niter << endl;
	if (Niter > 300) {
		SLS_WARN("too many levels of dependencies! returning...");
		return -1-ind;
	}
	for (Long i = 0; i < size(tree[ind].last); ++i) {
		Long ind0 = tree[ind].last[i];
		deps.push_back(ind0);
		Long ret = tree_all_dep_imp(deps, tree, ind0, vector, Niter);
		if (ret < 0) {
			cout << "debug: Niter = " << Niter << "  vector[" << ind << "] = " << vector[ind] << endl; cout.flush();
			return ret;
		}
	}
	return 0;
}

// find all upstream nodes of a tree, and the distances
// return -1-ind if too many levels (probably circular dependency), tree[ind] is the deepest level
inline Long tree_all_dep(vecLong_O deps, const vector<Node> &tree, Long_I ind, vecStr32_I vector)
{
	deps.clear();
	Long ret = tree_all_dep_imp(deps, tree, ind, vector);
	if (ret < 0)
		return ret;
	while (true) {
		Long ret = find_repeat(deps);
		if (ret < 0) {
			return size(deps);
		}
		deps.erase(deps.begin() + ret);
	}
}

// find redundant i.e. if A->B->...C, then A->C is redundent
// return -1-ind if too many levels (probably circular dependency), tree[ind] is the deepest level
inline Long tree_redundant(vecLong_O links, const vector<Node> &tree, vecStr32_I vector)
{
	vecLong deps;
	for (Long i = 0; i < Long(tree.size()); ++i) {
		deps.clear();
		Long ret = tree_all_dep_imp(deps, tree, i, vector);
		if (ret < 0)
			return ret;
		for (Long j = 0; j < size(tree[i].last); ++j) {
			Long ind = search(tree[i].last[j], deps);
			if (ind >= 0) {
				deps.erase(deps.begin() + ind);
			}
		}
		for (Long j = 0; j < size(tree[i].last); ++j) {
			Long ind = search(tree[i].last[j], deps);
			if (ind >= 0) {
				links.push_back(deps[ind]);
				links.push_back(i);
			}
		}
	}
	return size(links) / 2;
}

} // namespace slisc
