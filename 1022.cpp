/*
 * 1022. Sum of Root To Leaf Binary Numbers
 * You are given the root of a binary tree where each node has a value 0 or 1.
 * Each root-to-leaf path represents a binary number starting with the most significant bit.
 * For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
 * For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.
 * Return the sum of these numbers.
 * The test cases are generated so that the answer fits in a 32-bits integer.
 * */

#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
	int res = 0;
public:
	int sumRootToLeaf(TreeNode* root)
	{
		sumRootToLeaf(root, {});
		return res;
	}
	
	void sumRootToLeaf(TreeNode* node, int val)
	{
		val = 2 * val + node->val;
		if (!node->left && !node->right)
		{
			res += val;
			return;
		}
		if (node->left)
			sumRootToLeaf(node->left, val);
		if (node->right)
			sumRootToLeaf(node->right, val);
	}
};

int main()
{
    Solution s;
    TreeNode root(1);
    TreeNode l1(0), r1(1);
    TreeNode l1l(0), l1r(1), r1l(0), r1r(1);
    root.left = &l1; root.right = &r1;
    l1.left = &l1l; l1.right = &l1r;
    r1.left = &r1l; r1.right = &r1r;
    std::vector<bool> res;
    res.push_back(s.sumRootToLeaf(&root) == 22);
    return 0;
}
