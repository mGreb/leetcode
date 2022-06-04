/*
 * 21. Merge Two Sorted Lists
 * You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists in a one sorted list.
 * The list should be made by splicing together the nodes of the first two lists.
 * Return the head of the merged linked list.
 * */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		
		// deal with empty lists
		if (l1 && !l2 || !l1 && !l2)
			return l1;
		if (!l1 && l2)
			return l2;
		
		ListNode *res;
		// first, choose smallest element
		if (l1->val < l2->val) {
			res = l1;
			l1 = l1->next;
		} else {
			res = l2;
			l2 = l2->next;
		}
		ListNode *tmp = res;
		
		while (l1 && l2) {
			
			if (l1->val <  l2->val) {
				tmp->next = l1;
				l1 = l1->next;
			} else {
				tmp->next = l2;
				l2 = l2->next;
			}
			
			tmp = tmp->next;
		}
		
		while (l1) {
			tmp->next = l1;
			l1 = l1->next;
			tmp = tmp->next;
		}
		
		while (l2) {
			tmp->next = l2;
			l2 = l2->next;
			tmp = tmp->next;
		}
		
		return res;
	}
};

int main() {
	return 0;
}