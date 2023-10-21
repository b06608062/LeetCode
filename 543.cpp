// 543. Diameter of Binary Tree
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
  int diameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int maxDiameter = 0;

    maxDepth(root, maxDiameter);

    return maxDiameter;
  }

  int maxDepth(TreeNode *root, int &maxDiameter) {
    if (root == nullptr)
      return 0;
    int leftDepth = maxDepth(root->left, maxDiameter);
    int rightDepth = maxDepth(root->right, maxDiameter);
    maxDiameter = max(maxDiameter, leftDepth + rightDepth);
    return max(leftDepth, rightDepth) + 1;
  }
};