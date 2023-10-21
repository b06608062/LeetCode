// 102. Binary Tree Level Order Traversal
#include <queue>
#include <vector>
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (root == nullptr)
      return ans;

    queue<pair<TreeNode *, int>> q1;
    queue<pair<TreeNode *, int>> q2;
    if (root != nullptr) {
      q1.push({root, 1});
      while (q1.size() > 0) {
        auto [node, level] = q1.front();
        q2.push({node, level});
        q1.pop();
        if (node->left != nullptr)
          q1.push({node->left, level + 1});
        if (node->right != nullptr)
          q1.push({node->right, level + 1});
      }
    }

    vector<int> *vp = new vector<int>();
    int l = 1;
    while (q2.size() > 0) {
      auto [node, level] = q2.front();
      q2.pop();
      if (l != level) {
        l = level;
        ans.push_back(*vp);
        vp = new vector<int>;
      }
      vp->push_back(node->val);
    }
    ans.push_back(*vp);

    return ans;
  }
};