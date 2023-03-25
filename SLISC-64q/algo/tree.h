// tree utility
#pragma once
#include "../algo/search.h"

namespace slisc {

// links[2n] -> links[2n+1]
inline void tree_gen(vector<Node> &tree, vecStr32_I entries, vecLong_I links)
{
	SLS_ERR("use graph.h instead!");
	// Long Nlink = links.size();
	// tree.resize(entries.size());
	// for (Long i = 0; i < Nlink; i += 2) {
	// 	Long ind1 = links[i], ind2 = links[i + 1];
	// 	tree[ind1].next.push_back(ind2);
	// 	tree[ind2].last.push_back(ind1);
	// }
}

// find all upstream nodes of a tree, and the distances
// return -1-ind if too many levels (probably circular dependency), tree[ind] is the deepest level
inline Long tree_all_dep(vecLong_O deps, const vector<Node> &tree, Long_I ind, vecStr32_I vector)
{ SLS_ERR("use dag_downstream() instead!");	return 0; }

// find redundant i.e. if A->B->...C, then A->C is redundent
// return -1-ind if too many levels (probably circular dependency), tree[ind] is the deepest level
inline Long tree_redundant(vecLong_O links, const vector<Node> &tree, vecStr32_I vector)
{ SLS_ERR("use dag_short_edges() instead!"); return 0; }

} // namespace slisc
