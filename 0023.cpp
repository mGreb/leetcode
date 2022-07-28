/*
 * 23. Merge k Sorted Lists
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 */

#include <vector>
#include <set>
#include <queue>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
  struct comp {
    bool operator()(const std::pair<int, ListNode*>& a, const std::pair<int, ListNode*>& b) const {
      return a.first > b.first;
    }
  };
public:
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    std::priority_queue<std::pair<int, ListNode*>, std::vector<std::pair<int, ListNode*>>, comp> my_pr_queue;
    for (auto l : lists)
      if (l != nullptr)
        my_pr_queue.push({l->val, l});
    ListNode* temp_head = new ListNode(0);
    ListNode* curr = temp_head;
    while (!my_pr_queue.empty()) {
      ListNode* smallest = my_pr_queue.top().second;
      
      curr->next = smallest;
      curr = curr->next;
      
      my_pr_queue.pop();  // my_pr_queue.begin());
      if (smallest->next != nullptr)
        my_pr_queue.push({smallest->next->val, smallest->next});
    }
    curr = temp_head->next;
    delete temp_head;
    return curr;
  }
};

class Solution0 {
  struct comp {
    bool operator()(const std::pair<int, ListNode*>& a, const std::pair<int, ListNode*>& b) const {
      return a.first < b.first;
    }
  };
public:
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    std::multiset<std::pair<int, ListNode*>, comp> my_set;
    for (auto l : lists)
      if (l != nullptr)
        my_set.insert({l->val, l});
    ListNode* temp_head = new ListNode(0);
    ListNode* curr = temp_head;
    while (!my_set.empty()) {
      ListNode* smallest = my_set.begin()->second;
      
      curr->next = smallest;
      curr = curr->next;
      
      my_set.erase(my_set.begin());
      if (smallest->next != nullptr)
        my_set.insert({smallest->next->val, smallest->next});
    }
    curr = temp_head->next;
    delete temp_head;
    return curr;
  }
};

class Solution1 {
	int getMinListNodePos(std::vector<ListNode*>& lists) {
		
		// find first non-null element
		int minVal = 0;
    size_t null_cnt = 0;
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
		for (size_t i = 0; i < lists.size(); ++i)
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
  Solution s;
  ListNode* a = new ListNode(1);
  {
    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(5);
    ListNode* a3 = new ListNode(7);
    a->next = a1;
    a1->next = a2;
    a2->next = a3;
  }
  ListNode* b = new ListNode(2);
  {
    ListNode* b1 = new ListNode(4);
    ListNode* b2 = new ListNode(6);
    ListNode* b3 = new ListNode(8);
    b->next = b1;
    b1->next = b2;
    b2->next = b3;
  }
  std::vector<ListNode*> v = {a, b};
  ListNode* res = s.mergeKLists(v);
  return 0;
}
