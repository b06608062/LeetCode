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
  bool flag = true;
  bool isBalanced(TreeNode *root) {
    if (root == nullptr)
      return true;
    maxDepth(root);

    return flag;
  }

  int maxDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    if (abs(leftDepth - rightDepth) > 1)
      flag = false;

    return max(leftDepth, rightDepth) + 1;
  }
};