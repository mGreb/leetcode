/*
 * 23. Merge k Sorted Lists
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 */

#include <vector>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
	int getMinListNodePos(std::vector<ListNode*>& lists) {
		
		// find first non-null element
		int minVal = 0, null_cnt = 0;
		for (const auto& node : lists)
			if (node != nullptr) {
				minVal = node->val;
				break;
			} else
				++null_cnt;
		
		int ind = -1;
		if (null_cnt == lists.size())
			return ind;
		
		// find min element among non-null elements in all lists
		for (int i = 0; i < lists.size(); ++i)
			if (lists[i] != nullptr)
				if (minVal >= lists[i]->val) {
					minVal = lists[i]->val;
					ind = i;
				}
		
		return ind;
	}
public:
	ListNode* mergeKLists(std::vector<ListNode*>& lists) {
		
		int minNodePos = getMinListNodePos(lists);
		if (minNodePos == -1)
			return nullptr;
		
		auto res = lists[minNodePos];
		auto resHead = res;
		
		while (true) {
			res = lists[minNodePos];
			
			lists[minNodePos] = lists[minNodePos]->next;
			
			minNodePos = getMinListNodePos(lists);
			if (minNodePos == -1)
				break;
			
			res->next = lists[minNodePos];
			res = res->next;
		}
		
		return resHead;
	}
};

int main() {
	return 0;
}