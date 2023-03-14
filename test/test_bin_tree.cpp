#include "../SLISC/algo/bin_tree.h"

void test_bin_tree() {
	using namespace slisc;
	// 4-level binary tree with 15 nodes, val 1~15
	// 3 and 10 switched to test error
	string tree_str = "8 4 2 1 NULL NULL 10 NULL NULL 6 5 NULL NULL 7 NULL NULL 12 3 9 NULL NULL 11 NULL NULL 14 "
					  "13 NULL NULL 15 NULL NULL";

	// === test text2btree() and btree2text() ===
	BTnode *root = text2btree(tree_str);
	string tree_str1 = btree2text(root);
	if (tree_str1 != tree_str) SLS_FAIL;

	// === test btree_check() ===
	vector<pair<BTnode*, BTnode*>> err_pair;
	btree_check(err_pair, root);
	if (err_pair.size() != 2) SLS_FAIL;
	if (err_pair[0].first->val != 10 || err_pair[0].second->val != 4) SLS_FAIL;
	if (err_pair[1].first->val != 9 || err_pair[1].second->val != 3) SLS_FAIL;
	btree_delete(root);

	// gen
	BTnode *root1 = btree_gen(4);
	btree_assign(root1);
	
	// btree_print(root1);
	BTnode *root2 = btree_gen(4);
	btree_assign(root2);
	// btree_print(root2);
	SLS_ASSERT(btree_cmp(root1, root2));
	btree_delete(root1); btree_delete(root2);

	// btree_search()
	root = btree_gen(5);
	btree_assign(root, 2);
	// btree_print(root);
	for (Long key = 0; key <= 60; key += 2)
		SLS_ASSERT(btree_search(root, key)->val == key);
	btree_delete(root);
}
