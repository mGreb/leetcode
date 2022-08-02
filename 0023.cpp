/* 23. Merge k Sorted Lists
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 * Example 1:
 *  Input: lists = [[1,4,5],[1,3,4],[2,6]]
 *  Output: [1,1,2,3,4,4,5,6]
 *  Explanation: The linked-lists are:
 *  [1->4->5, 1->3->4, 2->6]
 *  merging them into one sorted list:
 *  1->1->2->3->4->4->5->6
 * Example 2:
 *  Input: lists = []
 *  Output: []
 * Example 3:
 *  Input: lists = [[]]
 *  Output: []
 * Constraints:
 *  k == lists.length
 *  0 <= k <= 10^4
 *  0 <= lists[i].length <= 500
 *  -10^4 <= lists[i][j] <= 10^4
 *  lists[i] is sorted in ascending order.
 *  The sum of lists[i].length will not exceed 10^4*/

#include <vector>
#include <set>
#include <queue>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     explicit ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// just cram everything into vector and sort it!
// such wow, so much faster
// although not memory friendly
class Solution {
public:
  static ListNode* mergeKLists(const std::vector<ListNode*>& lists) {
    std::vector<std::pair<int, ListNode*>> v;
    
    for (auto item: lists) {
      while (item != nullptr) {
        v.push_back({item->val, item});
        item = item->next;
      }
    }
    
    if (v.empty())
      return nullptr;
    
    std::sort(v.begin(), v.end(), [](const std::pair<int, ListNode*>& a,
                                     const std::pair<int, ListNode*>& b)
                                     {return a.first < b.first;});
    
    for (size_t i = 0; i < v.size() - 1; ++i) {
      v[i].second->next = v[i+1].second;
    }
    v.back().second->next = nullptr;
    
    return v[0].second;
  }
};

// priority queue, still slow
class Solution2 {
  struct comp {
    bool operator()(const std::pair<int, ListNode*>& a, const std::pair<int, ListNode*>& b) const {
      return a.first > b.first;
    }
  };
public:
  static ListNode* mergeKLists(const std::vector<ListNode*>& lists) {
    std::priority_queue<std::pair<int, ListNode*>, std::vector<std::pair<int, ListNode*>>, comp> my_pr_queue;
    for (auto l : lists)
      if (l != nullptr)
        my_pr_queue.push({l->val, l});
    auto temp_head = new ListNode(0);
    ListNode* curr = temp_head;
    while (!my_pr_queue.empty()) {
      ListNode* smallest = my_pr_queue.top().second;
      
      curr->next = smallest;
      curr = curr->next;
      
      my_pr_queue.pop();
      if (smallest->next != nullptr)
        my_pr_queue.push({smallest->next->val, smallest->next});
    }
    curr = temp_head->next;
    delete temp_head;
    return curr;
  }
};

// based on multiset, pretty slow but short
class Solution1 {
  struct comp {
    bool operator()(const std::pair<int, ListNode*>& a, const std::pair<int, ListNode*>& b) const {
      return a.first < b.first;
    }
  };
public:
  static ListNode* mergeKLists(const std::vector<ListNode*>& lists) {
    std::multiset<std::pair<int, ListNode*>, comp> my_set;
    for (auto l : lists)
      if (l != nullptr)
        my_set.insert({l->val, l});
    auto temp_head = new ListNode(0);
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

// old, complicated and slow
class Solution0 {
	static int getMinListNodePos(const std::vector<ListNode*>& lists) {
		
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
  
  ListNode  a(1);
  ListNode a1(1);
  ListNode a2(5);
  ListNode a3(7);
   a.next = &a1;
  a1.next = &a2;
  a2.next = &a3;
  
  ListNode  b(2);
  ListNode b1(4);
  ListNode b2(6);
  ListNode b3(8);
   b.next = &b1;
  b1.next = &b2;
  b2.next = &b3;
  
  std::vector<ListNode*> v = {&a, &b};
  [[maybe_unused]] ListNode* res = s.mergeKLists(v);
  return 0;
}
