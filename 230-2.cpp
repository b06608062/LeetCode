#include <stack>
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
  int kthSmallest(TreeNode *root, int k) {
    int cnt = 0;
    stack<TreeNode *> s;
    TreeNode *p = root;
    while (p || !s.empty()) {
      while (p) {
        s.push(p);
        p = p->left;
      }
      p = s.top();
      s.pop();
      ++cnt;
      if (cnt == k)
        return p->val;
      p = p->right;
    }

    return -1;
  }
};