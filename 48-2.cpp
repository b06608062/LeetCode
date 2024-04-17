#include <vector>
using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int l = 0, r = n - 1;
    while (l < r) {
      int t = l, b = r;
      for (int i = 0; i < r - l; i++) {
        int topTeft = matrix[t][l + i];
        matrix[t][l + i] = matrix[b - i][l];
        matrix[b - i][l] = matrix[b][r - i];
        matrix[b][r - i] = matrix[t + i][r];
        matrix[t + i][r] = topTeft;
      }
      l++;
      r--;
    }
  }
};