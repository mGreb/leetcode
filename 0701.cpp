/*
 * 701. Insert into a Binary Search Tree
 * You are given the root node of a binary search tree (BST) and
 * a value to insert into the tree. Return the root node of the BST
 * after the insertion. It is guaranteed that the new value does not exist in the original BST.
 * Notice that there may exist multiple valid ways for the insertion,
 * as long as the tree remains a BST after insertion. You can return any of them.
 * */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <iostream>

class Solution {
private:
	void traverse (TreeNode *node, int val)
	{
		if (val < node->val)
		{
			if (!node->left)
			{
				TreeNode* new_node = new TreeNode(val);
				node->left = new_node;
				return;
			}
			traverse(node->left, val);
		}
		if (val > node->val)
		{
			if (!node->right)
			{
				TreeNode* new_node = new TreeNode(val);
				node->right = new_node;
				return;
			}
			traverse(node->right, val);
		}
	}
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (!root)
			root = new TreeNode(val);
		else
			traverse(root, val);
		return root;
	}
};

int main()
{
    Solution s;
    TreeNode root(4);
    TreeNode l1(2), r1(7);
    TreeNode l1l(1), l1r(3);
    root.left = &l1; root.right = &r1;
    l1.left = &l1l; l1.right = &l1r;
    [[maybe_unused]] TreeNode* res = s.insertIntoBST(&root, 5);
    return 0;
}
