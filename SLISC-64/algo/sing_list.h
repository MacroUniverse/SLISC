// singly linked list utilities
#pragma once
#include "../util/random.h"

namespace slisc {

// single linked list node
// each one must be created by `new`
struct SNode {
	int val;
	SNode *next;
	SNode() = default;
	SNode(int val): val(val) {};
	SNode(int val, SNode *next): val(val), next(next) {};
};

// === create, set, destroy list ===
SNode *slist_gen(Long_I N);
void slist_rand_perm(SNode *head, Long_I N);
// delete node and all nodes after
void slist_delete(SNode *node);

// === query ===
void slist_print(SNode* node);
// check loop in singly linked list for loop, return number of nodes
// throw last node (node->next = old node) if there is a loop
Long slist_check(SNode *node);
Long slist_size(SNode *head); // # of nodes
SNode *slist_end(SNode *node); // end node
SNode *slist_end_size(Long_O N, SNode *node); // both size and end node
// return node+i node, return NULL if out of bound
SNode *slist_locate(SNode *node, Long_I ind);
// return node-i node, return NULL if out of bound
// node = NULL means one pass the end node
SNode *slist_rlocate(SNode *beg, Long_I ind, SNode *node = NULL);

// === edit ===
// insert a node at the beginning of the linked list
SNode *slist_push_front(SNode* head, int val);
void slist_insert_after(SNode* node, int val);
void slist_insert_after(SNode* node, SNode* new_node);
void slist_insert_after(SNode* node, SNode* first, SNode* last);
// erase 1 node after `node`
void slist_erase_after(SNode* node);
// erase N nodes after `node`, out of bound allowed
void slist_erase_N_after(SNode* node, Long N);
void slist_erase_all_after(SNode* node);
// split into half and return the second head
// if the length is odd, the extra node should go in the front list
SNode *slist_split_half(SNode* head);
// merge 2 sorted lists
SNode *slist_merge_sorted(SNode* a, SNode* b);
// sorts the linked list by changing links
SNode *slist_mergesort(SNode *head);
// ----------------------------------------

// allocate singly linked list with values [0,1,...,N-1]
// each node is allocated separately
inline SNode *slist_gen(Long_I N)
{
	if (N == 0) return NULL;
	SNode *head = new SNode(0), *node = head;
	for (Long i = 1; i < N; ++i)
		node = (node->next = new SNode(i));
	node->next = NULL;
	return head;
}

inline void slist_delete(SNode *head)
{
	while (head != NULL) {
		SNode *next = head->next;
		delete head;
		head = next;
	}
}

inline Long slist_size(SNode *head)
{
	Long N = 0;
	while (head != NULL)
		head = head->next, ++N;
	return N;
}

inline SNode *slist_end(SNode *node)
{
	if (node == NULL) return NULL;
	while (node->next != NULL)
		node = node->next;
	return node;
}

// return the last node and size of singly linked list
inline SNode *slist_end_size(Long_O N, SNode *node)
{
	if (node == NULL) { N = 0; return NULL; }
	N = 1;
	while (node->next != NULL) {
		node = node->next; ++N;
	}
	return node;
}

inline SNode *slist_locate(SNode *node, Long_I ind)
{
	for (Long i = 0; i < ind; ++i) {
		if (node == NULL) return NULL;
		node = node->next;
	}
	return node;
}

// reverse locate
// ind = 1 for the last node
// return NULL if out of bound
// (verified with leetcode 19)
inline SNode *slist_rlocate(SNode *beg, Long_I ind, SNode *node)
{
	SNode *node0 = beg;
	for (Long i = 0; i < ind; ++i) {
		if (beg == node) return NULL;
		beg = beg->next;
	}
	while (beg != node)
		beg = beg->next, node0 = node0->next;
	return node0;
}

inline void slist_rand_perm(SNode *head, Long_I N)
{
	vecLong perm(N);
	randPerm(perm);
	for (Long i = 0; i < N; ++i) {
#ifdef SLS_CHECK_BOUNDS
		if (head == NULL) SLS_ERR("unknown!");
#endif
		head->val = perm[i]; head = head->next;
	}
}

// print singly linked list, will detect loop
inline void slist_print(SNode* node)
{
	unordered_set<SNode*> uset;
	while (node != NULL) {
		if (uset.count(node) > 0) {
			cout << " cyclic link to " << node->val; return;
		}
		uset.insert(node);
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;
}

inline Long slist_check(SNode *node)
{
	unordered_set<SNode*> uset;
	if (node == NULL) return 0;
	uset.insert(node);
	SNode* next = node->next;
	while (next != NULL) {
		if (uset.count(next) > 0)
			throw node;
		uset.insert(next);
		node = next; next = node->next;
	}
	return uset.size();
}

inline SNode *slist_push_front(SNode* head, int val)
{
	SNode* new_node = new SNode;
	new_node->val = val; new_node->next = head;
	return new_node;
}

// insert a singly linked list after a node in another singly linked list
inline void slist_insert_after(SNode* node, SNode* new_node)
{
	new_node->next = node->next; node->next = new_node;
}

// insert a singly linked list after a node in another singly linked list
inline void slist_insert_after(SNode* node, SNode* first, SNode* last)
{
	last->next = node->next; node->next = first;
}

inline void slist_insert_after(SNode* node, int val)
{
	SNode* new_node = new SNode; new_node->val = val;
	slist_insert_after(node, new_node);
}

inline void slist_erase_after(SNode* node)
{
	if (node == NULL) return;
	SNode *node0 = node; node = node->next;
	if (node == NULL) return;
	node0->next = node->next;
	delete node;
}

inline void slist_erase_N_after(SNode* node, Long N)
{
	if (N == 0) return;
	SNode *node0 = node; node = node->next;
	for (Long i = 0; i < N; ++i) {
		if (node == NULL) break;
		SNode *next = node->next;
		delete node;
		node = next;
	}
	node0->next = node;
}

inline void slist_erase_all_after(SNode* node)
{
	if (node == NULL) return;
	SNode *node0 = node; node = node->next;
	slist_delete(node); node0->next = NULL;
}

inline SNode* slist_split_half(SNode* head)
{
	SNode* slow = head;
	SNode* fast = head->next;
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	SNode *head1 = slow->next;
	slow->next = NULL;
	return head1;
}

// merge 2 sorted singly linked list
// verified in leetcode 148
inline SNode *slist_merge_sorted(SNode* a, SNode* b)
{
	if (a == NULL) return b;
	if (b == NULL) return a;
	SNode *head, *node;
	if (a->val < b->val)
		head = node = a, a = a->next;
	else
		head = node = b, b = b->next;
	while (1) {
		if (a == NULL) {
			node->next = b; break;
		}
		if (b == NULL) {
			node->next = a; break;
		}
		if (a->val < b->val)
			node = (node->next = a), a = a->next;
		else
			node = (node->next = b), b = b->next;
	}
	return head;
}

inline SNode* slist_mergesort(SNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	SNode* head1 = slist_split_half(head);
	head = slist_mergesort(head);
	head1 = slist_mergesort(head1);
	return slist_merge_sorted(head, head1);
}

} // namespace slisc
