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
    int max = 0;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (this->grid[i][j] == 1) {
          int count = 0;
          dfs(i, j, count);
          max = max > count ? max : count;
        }
      }
    }

    return max;
  }

  bool check(int i, int j) { return 0 <= i && i < row && 0 <= j && j < col; }

  void dfs(int i, int j, int &count) {
    if (!check(i, j) || grid[i][j] != 1)
      return;

    count++;
    grid[i][j] = -1;
    dfs(i - 1, j, count);
    dfs(i + 1, j, count);
    dfs(i, j - 1, count);
    dfs(i, j + 1, count);
  }
};