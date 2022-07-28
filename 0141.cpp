/*141. Linked List Cycle
 * Easy
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 * There is a cycle in a linked list if there is some node in the list that can be
 * reached again by continuously following the next pointer. Internally, pos is used to
 * denote the index of the node that tail's next pointer is connected to.
 * Note that pos is not passed as a parameter.
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 * Constraints:
 *  The number of the nodes in the list is in the range [0, 10^4].
 *  -10^5 <= Node.val <= 10^5
 *  pos is -1 or a valid index in the linked-list.*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    
    if (head == nullptr || head->next == nullptr)
      return false;
    
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while (slow != fast) {
      if (slow != nullptr)
        slow = slow->next;
      if (fast != nullptr)
        fast = fast->next;
      if (fast != nullptr)
        fast = fast->next;
    }
    
    if (slow != nullptr)
      return true;
    
    return false;
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
    ListNode* b4 = new ListNode(9);
    b->next = b1;
    b1->next = b2;
    b2->next = b3;
    b3->next = b4;
    b4->next = b2;
  }
  ListNode* c = new ListNode(0);
  ListNode* d = nullptr;
  const bool res1 = s.hasCycle(a) == false;
  const bool res2 = s.hasCycle(b) == true;
  const bool res3 = s.hasCycle(c) == false;
  const bool res4 = s.hasCycle(d) == false;
  return 0;
}
