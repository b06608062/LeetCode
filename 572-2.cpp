#include <string>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  string convertString(TreeNode *root, string rootStr = "") {
    if (root == nullptr)
      return rootStr;

    rootStr += to_string(root->val);
    rootStr = convertString(root->left, rootStr);
    rootStr += to_string(root->val);
    rootStr = convertString(root->right, rootStr);
    rootStr += to_string(root->val);

    return rootStr;
  }

  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    string subRootStr = convertString(subRoot);
    string rootStr = convertString(root);

    return rootStr.find(subRootStr) != string::npos;
  }
};
