// singly linked list utilities
#pragma once
#include "random.h"

namespace slisc {

// single linked list node
struct SNode {
	int val;
	SNode *next;
	SNode() = default;
	SNode(int val): val(val) {};
	SNode(int val, SNode *next): val(val), next(next) {};
};

// create, set, destroy
SNode *slist_gen(Long_I N);
void slist_rand_perm(SNode *head, Long_I N);
void slist_delete(SNode *node);
// query
void slist_print(SNode* node);
Long slist_check(SNode *node);
Long slist_size(SNode *head);
SNode *slist_end(SNode *node);
SNode *slist_locate(SNode *node, Long_I ind);
// edit
SNode *slist_push(SNode* head, int val);
void slist_insert_after(SNode* node, int val);
void slist_insert_after(SNode* node, SNode* new_node);
void slist_insert_after(SNode* node, SNode* first, SNode* last);
void slist_erase_after(SNode* node, Long N = -1);
SNode *slist_split(SNode* head);
// sort
SNode *slist_merge_sorted(SNode* a, SNode* b);
void slist_mergesort(SNode *&headRef);
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

// delete singly linked list
inline void slist_delete(SNode *node)
{
	while (node != NULL) {
		SNode *next = node->next;
		delete node;
		node = next;
	}
}

// check size of singly linked list
inline Long slist_size(SNode *head)
{
	Long N = 0;
	while (head != NULL)
		head = head->next, ++N;
	return N;
}

// return the last node of singly linked list
inline SNode *slist_end(SNode *node)
{
	if (node == NULL) return NULL;
	while (node->next != NULL)
		node = node->next;
	return node;
}

// return node + i node of singly linked list
inline SNode *slist_locate(SNode *node, Long_I ind)
{
	for (Long i = 0; i < ind; ++i)
		node = node->next;
	return node;
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

// check loop in singly linked list, return number of nodes
// throw last node (node->next = old node) if there is a loop
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

// insert a node at the beginning of the linked list
inline SNode *slist_push(SNode* head, int val)
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

inline void slist_erase_after(SNode* node, Long N)
{
	if (N == 0) return;
	SNode *node0 = node; node = node->next;
	if (N < 0) { // erase all nodes after
		slist_delete(node); node0->next = NULL;
		return;
	}
	for (Long i = 0; i < N; ++i) {
		SNode *next = node->next;
		delete node;
		node = next;
	}
	node0->next = node;
}

/* Split the nodes of the given list into front and back halves,
and return the head of the second list.
If the length is odd, the extra node should go in the front list.
Uses the fast/slow pointer strategy. */
inline SNode* slist_split(SNode* head)
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
inline SNode* slist_merge_sorted(SNode* a, SNode* b)
{
	if (a == NULL) return (b);
	if (b == NULL) return (a);
	SNode *head, *node;
	if (a->val < b->val) {
		head = node = a; a = a->next;
	}
	else {
		head = node = b; b = b->next;
	}
	while (1) {
		if (a == NULL) {
			node->next = b; break;
		}
		if (b == NULL) {
			node->next = a; break;
		}
		if (a->val < b->val) {
			node = (node->next = a); a = a->next;
		}
		else {
			node = (node->next = b); b = b->next;
		}
	}
	return head;
}

/* sorts the linked list by changing next pointers (not data) */
inline void slist_mergesort(SNode *&headRef)
{
	SNode* head = headRef;
	if (head == NULL || head->next == NULL)
		return;
	SNode* head1 = slist_split(head);
	slist_mergesort(head);
	slist_mergesort(head1);
	headRef = slist_merge_sorted(head, head1);
}

} // namespace slisc
