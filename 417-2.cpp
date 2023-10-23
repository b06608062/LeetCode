// 417. Pacific Atlantic Water Flow
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> heights;
  int row;
  int col;
  vector<vector<int>> ans;
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    this->heights = heights;
    row = heights.size();
    col = heights[0].size();
    vector<vector<int>> A(row, vector<int>(col, 0));
    vector<vector<int>> P(row, vector<int>(col, 0));
    for (int i = 0; i < row; ++i) {
      dfs(i, 0, 0, P);
      dfs(i, col - 1, 0, A);
    }

    for (int j = 0; j < col; ++j) {
      dfs(0, j, 0, P);
      dfs(row - 1, j, 0, A);
    }

    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j)
        if (A[i][j] && P[i][j])
          ans.push_back(vector<int>({i, j}));

    return ans;
  }

  bool check(int i, int j) { return 0 <= i && i < row && 0 <= j && j < col; }

  void dfs(int i, int j, int h, vector<vector<int>> &visited) {
    if (!check(i, j) || visited[i][j] == 1 || heights[i][j] < h)
      return;

    visited[i][j] = 1;
    int height = heights[i][j];
    vector<pair<int, int>> neighbors(
        {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}});
    for (auto neighbor : neighbors) {
      auto [ii, jj] = neighbor;
      if (check(ii, jj))
        dfs(ii, jj, height, visited);
    }
  }
};