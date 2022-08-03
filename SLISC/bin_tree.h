#pragma once
#include "global.h"

namespace slisc {

// Definition for a binary tree node.
struct BTNode {
    int val;
    BTNode *left, *right;
    BTNode(int x) : val(x), left(NULL), right(NULL) {}
};

// deallocate a btree or subtree (assuming every node is created with `new`)
inline void btree_delete(BTNode* node)
{
    if (node == NULL) return;
    btree_delete(node->left);
    btree_delete(node->right);
    delete node;
};

// traverse binary tree and check if values are in order
// `err_pair` will be empty if values are correct
// if not, `err_pair[i]` will be neighboring node pairs with wrong values
// argument `last` is the previous node checked before calling this function, use NULL if `node` is head
// return last node checked for `node` (can't be NULL) subtree, return NULL to exit everything
inline BTNode* btree_check(vector<pair<BTNode*, BTNode*>> &err_pair, BTNode *node, BTNode *last = NULL)
{
    if (node->left != NULL) {
        last = btree_check(err_pair, node->left, last);
        if (last == NULL)
            return NULL;
    }
    /* cout << node->val << endl; */
    if (last != NULL && last->val > node->val) {
        err_pair.emplace_back(last, node);
    }
    if (node->right != NULL)
        return btree_check(err_pair, node->right, node);
    return node;
}

// Encodes a tree to a text string.
// node->left->right order traverse
inline void btree2text_helper(string &str, BTNode *node) {
    if (!str.empty()) str += ' ';
    if (node == NULL) {
        str += "NULL"; return;
    }
    str += to_string(node->val);
    btree2text_helper(str, node->left);
    btree2text_helper(str, node->right);
}

inline string btree2text(BTNode* root) {
	string str;
    btree2text_helper(str, root);
	return str;
}

// Decodes text string to binary tree.
inline void text2btree_helper(BTNode* &node, stringstream &ss) {
    string sval;
    ss >> sval;
    if (sval == "NULL" || sval.empty()) {
        node = NULL; return;
    }
    int val = stoi(sval);
    node = new BTNode(val);
    text2btree_helper(node->left, ss);
    text2btree_helper(node->right, ss);
}

inline BTNode* text2btree(const string &str) {
    stringstream ss(str);
	BTNode *root;
    text2btree_helper(root, ss);
	return root;
}

} // namespace slisc
