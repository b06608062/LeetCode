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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return buildSubTree(preorder, inorder);
  }

  TreeNode *buildSubTree(vector<int> &preorder, vector<int> &inorder) {
    if (inorder.empty())
      return NULL;
    auto it = find(inorder.begin(), inorder.end(), preorder.front());

    TreeNode *node = new TreeNode();
    vector<int> leftInorder(inorder.begin(), it);
    vector<int> rightInorder(it + 1, inorder.end());

    node->val = preorder.front();
    preorder.erase(preorder.begin());

    node->left = buildSubTree(preorder, leftInorder);
    node->right = buildSubTree(preorder, rightInorder);

    return node;
  }
};