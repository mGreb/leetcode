/*206. Reverse Linked List
 * Easy
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 * Constraints:
 *  The number of nodes in the list is the range [0, 5000].
 *  -5000 <= Node.val <= 5000*/

#include <memory>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    
    ListNode* temp = head;
    ListNode* next = nullptr;
    ListNode* prev = nullptr;
    
    while (temp != nullptr) {
      next = temp->next;
      temp->next = prev;
      prev = temp;
      temp = next;
    }
    
    return prev;
  }
};

int main() {
  ListNode* a = new ListNode(1);
  {
    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(5);
    ListNode* a3 = new ListNode(7);
    a->next = a1;
    a1->next = a2;
    a2->next = a3;
  }
  ListNode* b = new ListNode(1);
  {
    ListNode* b1 = new ListNode(1);
    b->next = b1;
  }
  Solution s;
  ListNode* a_rev = s.reverseList(a);
  ListNode* b_rev = s.reverseList(b);
  
  return 0;
}
