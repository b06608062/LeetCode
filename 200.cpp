// 200. Number of Islands
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<char>> grid;
  int row;
  int col;

  int numIslands(vector<vector<char>> &grid) {
    this->grid = grid;
    row = grid.size();
    col = grid[0].size();
    vector<vector<int>> visited(row, vector<int>(col, 0));
    int ans = 0;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (!visited[i][j] && grid[i][j] != '0') {
          dfs(i, j, visited);
          ans++;
        }
      }
    }

    return ans;
  }

  bool check(int i, int j) { return 0 <= i && i < row && 0 <= j && j < col; }

  void dfs(int i, int j, vector<vector<int>> &visited) {
    if (!check(i, j) || grid[i][j] == '0' || visited[i][j] == 1)
      return;

    visited[i][j] = 1;
    dfs(i - 1, j, visited);
    dfs(i + 1, j, visited);
    dfs(i, j - 1, visited);
    dfs(i, j + 1, visited);
  }
};