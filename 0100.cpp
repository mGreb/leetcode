/* 100. Same Tree
 * Easy
 * Given the roots of two binary trees p and q, write a function to check if they are the same or not.
 * Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.*/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  void traverse(TreeNode*p, TreeNode *q) {
    if (!same)
      return;
    
    if (q == nullptr && p == nullptr)
      return;
    
    if (p != nullptr && q != nullptr && p->val == q->val) {
      traverse(p->left, q->left);
      traverse(p->right, q->right);
    } else {
      same = false;
    }
  }
  bool same = true;
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    traverse(p, q);
    return same;
  }
};

int main() {
  TreeNode a(1), al(2), ar(3);
  a.left = &al; a.right = &ar;
  TreeNode b(1), bl(2), br(3);
  b.left = &bl; b.right = &br;
  Solution s;
  [[maybe_unused]] const bool res = s.isSameTree(&a,&b) == true;
  return 0;
}
