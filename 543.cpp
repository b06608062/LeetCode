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
  int maxDiameter = 0;
  int diameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr)
      return 0;
    maxDepth(root);

    return maxDiameter;
  }

  int maxDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    maxDiameter = max(maxDiameter, leftDepth + rightDepth);

    return max(leftDepth, rightDepth) + 1;
  }
};