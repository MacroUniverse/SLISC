#include "../SLISC/algo/sing_list.h"

void test_sing_list()
{
	// ==== test merge sort ===
	using namespace slisc;
	Long N = 20;
	SNode *head = slist_gen(N);
	slist_rand_perm(head, N);
	// slist_print(head);
	head = slist_mergesort(head);
	SNode *node = head;
	while (node->next != NULL) {
		if (node->next->val < node->val)
			SLS_FAIL;
		node = node->next;
	}
	// slist_print(head);
	// cout << slist_check(head) << endl;
	SLS_ASSERT(slist_check(head) == N);
	// slist_print(head);
	SLS_ASSERT(slist_size(head) == N);
	SNode *node3 = slist_locate(head, 3);
	slist_insert_after(node3, 333);
	// slist_print(head);
	slist_delete(head);
}
