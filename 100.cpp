// 100. Same Tree
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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr)
      return true;

    bool res = true;
    if (p != nullptr && q != nullptr) {
      if (p->val != q->val) {
        res = false;
      } else {
        res = isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
      }
    } else {
      res = false;
    }

    return res;
  }
};