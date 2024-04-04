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
    int count = 0;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (this->grid[i][j] == '1') {
          dfs(i, j);
          count++;
        }
      }
    }

    return count;
  }

  bool check(int i, int j) { return 0 <= i && i < row && 0 <= j && j < col; }

  void dfs(int i, int j) {
    if (!check(i, j) || grid[i][j] != '1')
      return;
    grid[i][j] = 'x';
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
  }
};