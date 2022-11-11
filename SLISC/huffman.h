// C++(STL) program for Huffman Coding with STL
// from https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
#pragma once
#include "global.h"

namespace slisc {

// A Huffman tree node
struct MinHeapNode {
	char data;
	unsigned freq; // Frequency of `data`
	MinHeapNode *left, *right; // Left and right child
	MinHeapNode(char data, unsigned freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

inline void huffman_tree_delete(MinHeapNode* node)
{
	if (node == NULL) return;
	huffman_tree_delete(node->left);
	huffman_tree_delete(node->right);
	delete node;
};

// comparison of two heap nodes (needed in min heap)
struct compare {
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{ return (l->freq > r->freq); }
};

// Prints huffman codes from
// the root of Huffman Tree.
void printCodes(unordered_map<char,string> &dict, struct MinHeapNode* root, string &str)
{
	if (!root) {
	    str.pop_back(); return;
	}
	if (root->data != '$')
	    dict[root->data] = str;
	str += '0'; printCodes(dict, root->left, str);
	str += '1'; printCodes(dict, root->right, str);
	str.pop_back();
}

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void huffman_code(unordered_map<char,string> &dict, Str_I data, vecLong freq)
{
	Long size = data.size();
	MinHeapNode *left, *right, *top;
	// Create a min heap & inserts all characters of data[]
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
	for (int i = 0; i < size; ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));
	while (minHeap.size() != 1) {
		// Extract the two minimum freq items
		left = minHeap.top(); minHeap.pop();
		right = minHeap.top(); minHeap.pop();
		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left; top->right = right;
		minHeap.push(top);
	}
	// Print Huffman codes using
	// the Huffman tree built above
	string str;
	SLS_WARN("something is wrong! str shouldn't be empty!");
	printCodes(dict, minHeap.top(), str);
	huffman_tree_delete(top);
}

} // namespace slisc
