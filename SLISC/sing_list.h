// singly linked list utilities
#pragma once
#include "global.h"

namespace slisc {

// single linked list
struct SingNode {
    int val;
    SingNode *next;
    SingNode() = default;
    SingNode(int val1): val(val1) {};
};

//struct SingList {
//    Long m_N;
//	SingNode *m_root;
//    SingList(int N): m_N(N), m_root(new SingNode [N]) {};
//    Long size() { return m_N; }
//	void insert_after(SingNode *node);
//	void push_back(int val);
//	void resize(Long_I N);
//};

inline SingNode *sing_list_gen(Long_I N)
{
    SingNode *head = new SingNode [N];
    for (Long i = 1; i < N; ++i)
        head[i-1].next = head + i;
    head[N-1].next = NULL;
    return head;
}

inline void sing_list_rand_perm(SingNode *head, Long_I N)
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

/* Function to print nodes in a given linked list */
inline void sing_list_print(SingNode* node)
{
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
}

// insert a node at the beginning of the linked list
inline SingNode *sing_list_push(SingNode* head, int val)
{
    SingNode* new_node = new SingNode(val);
    new_node->next = head;
    return new_node;
}

// insert a new node after a node in singly linked list
inline void sing_list_insert_after(SingNode* node, SingNode* new_node)
{
    new_node->next = node->next;
    node->next = new_node;
}

inline void sing_list_insert_after(SingNode* node, int val)
{
    SingNode* new_node = new SingNode(val);
    sing_list_insert_after(node, new_node);
}

/* Split the nodes of the given list into front and back halves,
and return the head of the second list.
If the length is odd, the extra node should go in the front list.
Uses the fast/slow pointer strategy. */
SingNode* sing_list_split(SingNode* head)
{
    SingNode* slow = head;
    SingNode* fast = head->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    SingNode *head1 = slow->next;
    slow->next = NULL;
    return head1;
}

// merge 2 sorted singly linked list
SingNode* sing_list_merge_sorted(SingNode* a, SingNode* b)
{
    if (a == NULL) return (b);
    if (b == NULL) return (a);
    SingNode *head, *node;
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
void sing_list_mergesort(SingNode *&headRef)
{
    SingNode* head = headRef;
    if (head == NULL || head->next == NULL)
        return;
    SingNode* head1 = sing_list_split(head);
    sing_list_mergesort(head);
    sing_list_mergesort(head1);
    headRef = sing_list_merge_sorted(head, head1);
}

} // namespace slisc
