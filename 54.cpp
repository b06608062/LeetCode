#include <vector>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size() - 1;
    int n = matrix[0].size() - 1;
    vector<int> ans;
    int l = 0, r = n, t = 0, b = m;
    while (l < r && t < b) {
      for (int i = 0; i < r - l; i++) {
        ans.push_back(matrix[t][l + i]);
      }
      for (int i = 0; i < b - t; i++) {
        ans.push_back(matrix[t + i][r]);
      }
      for (int i = 0; i < r - l; i++) {
        ans.push_back(matrix[b][r - i]);
      }
      for (int i = 0; i < b - t; i++) {
        ans.push_back(matrix[b - i][l]);
      }
      l++, r--, t++, b--;
    }

    if (l == r && t == b) {
      ans.push_back(matrix[t][l]);
    } else if (l == r) {
      for (int i = 0; i < b - t + 1; i++) {
        ans.push_back(matrix[t + i][l]);
      }
    } else if (t == b) {
      for (int i = 0; i < r - l + 1; i++) {
        ans.push_back(matrix[t][l + i]);
      }
    }

    return ans;
  }
};