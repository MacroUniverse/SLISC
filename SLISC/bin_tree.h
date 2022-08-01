#pragma once
#include "global.h"

namespace slisc {

// Definition for a binary tree node.
struct BtreeNode {
    int val;
    BtreeNode *left, *right;
    BtreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// deallocate a Btree or subtree (assuming every node is created with `new`)
inline void Btree_delete(BtreeNode* node)
{
    if (node == NULL) return;
    Btree_delete(node->left);
    Btree_delete(node->right);
    delete node;
};

// traverse binary tree and check if values are in order
// `err_pair` will be empty if values are correct
// if not, `err_pair[i]` will be neighboring node pairs with wrong values
// argument `last` is the previous node checked before calling this function, use NULL if `node` is head
// return last node checked for `node` (can't be NULL) subtree, return NULL to exit everything
inline BtreeNode* Btree_check(vector<pair<BtreeNode*, BtreeNode*>> &err_pair, BtreeNode *node, BtreeNode *last = NULL)
{
    if (node->left != NULL) {
        last = Btree_check(err_pair, node->left, last);
        if (last == NULL)
            return NULL;
    }
    /* cout << node->val << endl; */
    if (last != NULL && last->val > node->val) {
        err_pair.emplace_back(last, node);
    }
    if (node->right != NULL)
        return Btree_check(err_pair, node->right, node);
    return node;
}

// Encodes a tree to a text string.
// node->left->right order traverse
inline void Btree2text_helper(string &str, BtreeNode *node) {
    if (!str.empty()) str += ' ';
    if (node == NULL) {
        str += "NULL"; return;
    }
    str += to_string(node->val);
    Btree2text_helper(str, node->left);
    Btree2text_helper(str, node->right);
}

inline string Btree2text(BtreeNode* root) {
	string str;
    Btree2text_helper(str, root);
	return str;
}

// Decodes text string to binary tree.
inline void text2Btree_helper(BtreeNode* &node, stringstream &ss) {
    string sval;
    ss >> sval;
    if (sval == "NULL" || sval.empty()) {
        node = NULL; return;
    }
    int val = stoi(sval);
    node = new BtreeNode(val);
    text2Btree_helper(node->left, ss);
    text2Btree_helper(node->right, ss);
}

inline BtreeNode* text2Btree(const string &str) {
    stringstream ss(str);
	BtreeNode *root;
    text2Btree_helper(root, ss);
	return root;
}

} // namespace slisc
