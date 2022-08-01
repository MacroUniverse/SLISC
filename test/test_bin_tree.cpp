#include "../SLISC/bin_tree.h"

int test_bin_tree() {
    using namespace slisc;
    // 4-level binary tree with 15 nodes, val 1~15
    // 3 and 10 switched to test error
    string tree_str = "8 4 2 1 NULL NULL 10 NULL NULL 6 5 NULL NULL 7 NULL NULL 12 3 9 NULL NULL 11 NULL NULL 14 "
                      "13 NULL NULL 15 NULL NULL";

    // === test text2Btree() and Btree2text() ===
    BtreeNode *root = text2Btree(tree_str);
    string tree_str1 = Btree2text(root);
    cout << tree_str << endl;
    cout << tree_str1 << endl;
    if (tree_str1 != tree_str) SLS_ERR("failed!");

    // === test bin_tree_check() ===
    vector<pair<BtreeNode*, BtreeNode*>> err_pair;
    bin_tree_check(err_pair, root);
    if (err_pair.size() != 2) SLS_ERR("failed!");
    if (err_pair[0].first->val != 10 || err_pair[0].second->val != 4) SLS_ERR("failed!");
    if (err_pair[1].first->val != 9 || err_pair[1].second->val != 3) SLS_ERR("failed!");
    return 0;
}
