/*
 * 2. Add Two Numbers
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * */

#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void Print(ListNode* l)
{
	ListNode* temp = l;
	while (temp != nullptr)
	{
		std::cout << temp->val << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

class Solution2
{
public:
	static ListNode* addTwoNumbers(ListNode* l1_, ListNode* l2_) {
		ListNode* l1 = l1_, * l2 = l2_;
		ListNode* head = new ListNode(0);
		ListNode* cur = head;
		int carry = 0;
		while (l1 != nullptr || l2 != nullptr)
		{
			const int x = l1 != nullptr ? l1->val : 0;
			const int y = l2 != nullptr ? l2->val : 0;
			const int sum = carry + x + y;
			carry = sum / 10;
			cur->next = new ListNode(sum % 10);
			cur = cur->next;
			if (l1 != nullptr) l1 = l1->next;
			if (l2 != nullptr) l2 = l2->next;
		}
		if (carry > 0)
			cur->next = new ListNode(carry);
		ListNode* res = head->next;
		delete head;
		return res;
	}
};

int main()
{
	// 2-4-3
	ListNode l1(2), l2(4), l3(3);
	l1.next = &l2;
	l2.next = &l3;
	Print(&l1);
	// 5-6-4
	ListNode l4(5), l5(6), l6(4);
	l4.next = &l5;
	// l5.next = &l6;
	Print(&l4);
	// add
	ListNode* l_res = Solution2::addTwoNumbers(&l1, &l4);
	Print(l_res);
	return 0;
}
