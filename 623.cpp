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
  int aimDepth;

public:
  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    if (depth == 1) {
      TreeNode *newRoot = new TreeNode(val, root, nullptr);
      return newRoot;
    }
    aimDepth = depth;
    helper(root, val, 1);

    return root;
  }
  void helper(TreeNode *root, int val, int depth) {
    if (depth == aimDepth - 1) {
      TreeNode *newLeftNode = new TreeNode(val, root->left, nullptr);
      TreeNode *newRightNode = new TreeNode(val, nullptr, root->right);
      root->left = newLeftNode;
      root->right = newRightNode;
    } else {
      if (root->left)
        helper(root->left, val, depth + 1);
      if (root->right)
        helper(root->right, val, depth + 1);
    }
  }
};