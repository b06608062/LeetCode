// 695. Max Area of Island
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> grid;
  int row;
  int col;
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    this->grid = grid;
    row = grid.size();
    col = grid[0].size();
    vector<vector<int>> visited(row, vector<int>(col, 0));
    int max = 0;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (!visited[i][j] && grid[i][j] != 0) {
          int count = 0;
          dfs(i, j, count, visited);
          max = max > count ? max : count;
        }
      }
    }

    return max;
  }

  bool check(int i, int j) { return 0 <= i && i < row && 0 <= j && j < col; }

  void dfs(int i, int j, int &count, vector<vector<int>> &visited) {
    if (!check(i, j) || grid[i][j] == 0 || visited[i][j] == 1)
      return;

    count++;
    visited[i][j] = 1;
    dfs(i - 1, j, count, visited);
    dfs(i + 1, j, count, visited);
    dfs(i, j - 1, count, visited);
    dfs(i, j + 1, count, visited);
  }
};