#pragma once
#include "global.h"

namespace slisc {

// Definition for a binary tree node.
struct BTNode {
    int val;
    BTNode *left, *right;
    BTNode() = default;
    BTNode(int x) : val(x), left(NULL), right(NULL) {}
};

// generate btree with exactly Nlevel
// total # of nodes is (2^Nlevel - 1)
inline BTNode *btree_gen(Long_I Nlevel)
{
    if (Nlevel == 0) return NULL;
    BTNode *node = new BTNode;
    if (Nlevel == 1) {
        node->left = NULL; node->right = NULL;
        return node;
    }
    node->left = btree_gen(Nlevel-1);
    node->right = btree_gen(Nlevel-1);
    return node;
}

// deallocate a btree or subtree (assuming every node is created with `new`)
inline void btree_delete(BTNode* node)
{
    if (node == NULL) return;
    btree_delete(node->left);
    btree_delete(node->right);
    delete node;
};

// assign order traversal index to each node value
inline BTNode *btree_assign(BTNode *node, BTNode *last = NULL)
{
    if (node->left != NULL) {
        last = btree_assign(node->left, last);
        if (last == NULL)
            return NULL;
    }
    /* cout << node->val << endl; */
    if (last == NULL) {
        if (node != NULL) node->val = 0;
    }
    else {
        node->val = last->val + 1;
    }
    if (node->right != NULL)
        return btree_assign(node->right, node);
    return node;
}

// traverse binary tree and check if values are in order
// `err_pair` will be empty if values are correct
// if not, `err_pair[i]` will be neighboring node pairs with wrong values
// argument `last` is the previous node checked before calling this function, use NULL if `node` is head
// return last node checked for `node` (can't be NULL) subtree, return NULL to exit everything
inline BTNode *btree_check(vector<pair<BTNode*, BTNode*>> &err_pair, BTNode *node, BTNode *last = NULL)
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

// Function to print binary tree in 2D
// It does reverse inorder traversal
inline void btree_print(BTNode *root, int space = 0)
{
    const int COUNT = 7;
    if (root == NULL)
        return;
    space += COUNT;
    // Process right child first
    btree_print(root->right, space);
    // Print current node after space
    cout << string(space-COUNT, ' ');
    cout << root->val << endl;
    // Process left child
    btree_print(root->left, space);
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

inline BTNode *text2btree(const string &str) {
    stringstream ss(str);
	BTNode *root;
    text2btree_helper(root, ss);
	return root;
}

// compare 2 (sub) binary trees
inline bool btree_cmp(BTNode *node1, BTNode *node2) {
    if (node1 == NULL || node2 == NULL) {
        if (node1 != NULL || node2 != NULL)
            return false;
        return true;
    }
    if (node1->val != node2->val) return false;
    if (!btree_cmp(node1->left, node2->left)) return false;
    if(!btree_cmp(node1->right, node2->right)) return false;
    return true;
}

} // namespace slisc
