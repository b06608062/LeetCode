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
  int goodNodes(TreeNode *root) {
    if (root == nullptr)
      return 0;

    int count = 0;
    stack<pair<TreeNode *, int>> s;
    s.push({root, root->val});
    while (!s.empty()) {
      auto [node, max] = s.top();
      s.pop();
      if (node->val >= max) {
        count++;
        max = node->val;
      }
      if (node->left != nullptr)
        s.push({node->left, max});
      if (node->right != nullptr)
        s.push({node->right, max});
    }

    return count;
  }
};