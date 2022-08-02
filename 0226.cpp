/*
 * 226. Invert Binary Tree
 * Given the root of a binary tree, invert the tree, and return its root.
 * */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
	static void swap_children(TreeNode *a) {
		TreeNode *temp = a->left;
		a->left = a->right;
		a->right = temp;
	}
	void invert(TreeNode* node) {
		swap_children(node);
		
		if (node->left  != nullptr)
			invert( node->left);
		if (node->right != nullptr)
			invert(node->right);
	}
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr)
			return root;
		invert(root);
		return root;
	}
};

int main() {
  return 0;
}