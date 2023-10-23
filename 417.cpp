// 417. Pacific Atlantic Water Flow
// Time Limit Exceeded
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> heights;
  vector<vector<int>> ans;

  int row;
  int col;

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    this->heights = heights;
    row = heights.size();
    col = heights[0].size();
    set<pair<int, int>> records;

    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        vector<pair<int, int>> search(
            {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}});
        for (auto p : search) {
          auto [x, y] = p;
          if (check(x, y) && records.find(p) != records.end() &&
              heights[i][j] >= heights[x][y]) {
            records.insert({i, j});
            continue;
          }
        }
        bool P = false, A = false;
        vector<vector<int>> visited(row, vector<int>(col, 0));
        dfs(i, j, visited, P, A);
        if (P && A)
          records.insert({i, j});
      }
    }

    for (auto p : records) {
      auto [i, j] = p;
      ans.push_back(vector<int>({i, j}));
    }

    return ans;
  }

  bool check(int i, int j) { return 0 <= i && i < row && 0 <= j && j < col; }

  void dfs(int i, int j, vector<vector<int>> visited, bool &P, bool &A) {
    if (visited[i][j] == 1 || (P && A))
      return;

    if (i == 0 || j == 0)
      P = true;
    if (i == row - 1 || j == col - 1)
      A = true;

    visited[i][j] = 1;
    int height = heights[i][j];
    if (check(i - 1, j) && height >= heights[i - 1][j])
      dfs(i - 1, j, visited, P, A);

    if (check(i + 1, j) && height >= heights[i + 1][j])
      dfs(i + 1, j, visited, P, A);

    if (check(i, j - 1) && height >= heights[i][j - 1])
      dfs(i, j - 1, visited, P, A);

    if (check(i, j + 1) && height >= heights[i][j + 1])
      dfs(i, j + 1, visited, P, A);
  }
};