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
  int kth;
  int flag = false;

  int kthSmallest(TreeNode *root, int k) {
    inOrderTraversal(root, k);

    return kth;
  }

  void inOrderTraversal(TreeNode *root, int &k) {
    if (flag)
      return;

    if (root != nullptr) {
      inOrderTraversal(root->left, k);
      if (--k == 0) {
        kth = root->val;
        flag = true;
      }
      inOrderTraversal(root->right, k);
    }
  }
};