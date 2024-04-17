#include <queue>
#include <string>
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

auto comp = [](string &s1, string &s2) {
  // int res = s1.compare(s2);
  // if(res==1)
  //     return true;
  // return false;
  int l1 = s1.length();
  int l2 = s2.length();
  int l = min(l1, l2);
  int i = 0;
  while (i < l) {
    if (s1[i] != s2[i])
      break;
    i++;
  }
  if (i < l)
    return s1[i] > s2[i];

  return l1 > l2;
};
class Solution {
public:
  priority_queue<string, vector<string>, decltype(comp)> pq;
  string smallestFromLeaf(TreeNode *root) {
    helper(root, "");

    return pq.top();
  }
  void helper(TreeNode *root, string s) {
    s += (root->val + 'a');
    if (!root->left && !root->right) {
      string str = "";
      for (auto a : s) {
        str = a + str;
      }
      pq.push(str);

      return;
    }
    if (root->left) {
      helper(root->left, s);
    }
    if (root->right) {
      helper(root->right, s);
    }
  }
};