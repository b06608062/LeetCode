// 105. Construct Binary Tree from Preorder and Inorder Traversal
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
    return buildDNode(preorder, inorder, 0, 0, inorder.size() - 1);
  }

  TreeNode *buildDNode(vector<int> &preorder, vector<int> &inorder, int l1,
                       int l2, int r2) {
    if (l2 > r2)
      return nullptr;

    int dValue = preorder[l1];
    TreeNode *newNode = new TreeNode(dValue);

    if (l2 == r2) {
      newNode->left = nullptr;
      newNode->right = nullptr;
      return newNode;
    }

    int dIndex =
        distance(inorder.begin(), find(inorder.begin(), inorder.end(), dValue));
    int leftCount = dIndex - l2;
    newNode->left = buildDNode(preorder, inorder, l1 + 1, l2, dIndex - 1);
    newNode->right =
        buildDNode(preorder, inorder, l1 + leftCount + 1, dIndex + 1, r2);

    return newNode;
  }
};