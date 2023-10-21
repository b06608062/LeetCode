// 110. Balanced Binary Tree
#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (root == nullptr)
      return true;
    bool flag = true;
    maxDepth(root, flag);

    return flag;
  }

  int maxDepth(TreeNode *root, bool &flag) {
    if (root == nullptr)
      return 0;
    int leftDepth = maxDepth(root->left, flag);
    int rightDepth = maxDepth(root->right, flag);
    if (abs(leftDepth - rightDepth) > 1)
      flag = false;
    return max(leftDepth, rightDepth) + 1;
  }
};