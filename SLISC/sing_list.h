// singly linked list utilities
#pragma once
#include "global.h"

namespace slisc {

// single linked list
struct SingNode {
    int val;
    SingNode *next;
    SingNode(int val1): val(val1) {};
};

struct SingList {
	SingNode *root;
	void insert_after(SingNode *node);
	void push_back(int val);
	void resize(Long_I N);
};

/* function prototypes */
SingNode* SortedMerge(SingNode* a, SingNode* b);
void FrontBackSplit(SingNode* source,
                    SingNode** frontRef, SingNode** backRef);

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(SingNode** headRef)
{
    SingNode* head = *headRef;
    SingNode* a;
    SingNode* b;

    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);

    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);

    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}

/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
SingNode* sing_list_mergesort(SingNode* a, SingNode* b)
{
    SingNode* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->val <= b->val) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
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

/* Function to print nodes in a given linked list */
void sing_list_print(SingNode* node)
{
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
}

/* Function to insert a node at the beginning of the linked list */
inline SingNode *sing_list_push(SingNode* head, int val)
{
    SingNode* new_node = new SingNode(val);
    new_node->next = head;
    return new_node;
}

} // namespace slisc
