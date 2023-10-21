// 98. Validate Binary Search Tree
#include <math.h>
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
  bool isValidBST(TreeNode *root) {
    return checkBST(root, -pow(2, 31) - 1, pow(2, 31) + 1);
  }
  bool checkBST(TreeNode *root, long min, long max) {
    if (root == nullptr)
      return true;
    if (root->val <= min || root->val >= max)
      return false;

    bool isValid = !root->left || checkBST(root->left, min, root->val);
    if (!isValid)
      return false;
    else
      return !root->right || checkBST(root->right, root->val, max);
  }
};