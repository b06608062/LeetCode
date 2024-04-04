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
  int count = 0;

  int goodNodes(TreeNode *root) {
    countGoodNodes(root, -10001);

    return count;
  }

  void countGoodNodes(TreeNode *root, int max) {
    if (root->val >= max) {
      count++;
      max = root->val;
    }
    if (root->left != nullptr)
      countGoodNodes(root->left, max);
    if (root->right != nullptr)
      countGoodNodes(root->right, max);
  }
};