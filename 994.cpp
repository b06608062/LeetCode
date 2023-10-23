// 994. Rotting Oranges
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> grid;
  int row;
  int col;
  int orangesRotting(vector<vector<int>> &grid) {
    this->grid = grid;
    row = grid.size();
    col = grid[0].size();
    int max = row * col;
    int count = 0;
    while (!done() && count < max) {
      nextRound();
      count++;
    }

    return count == max ? -1 : count;
  }

  bool check(int i, int j) { return 0 <= i && i < row && 0 <= j && j < col; }

  void nextRound() {
    vector<vector<int>> visited(row, vector<int>(col, 0));
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (grid[i][j] == 2 && !visited[i][j]) {
          grid[i][j] = -1;
          vector<pair<int, int>> search(
              {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}});
          for (auto p : search) {
            auto [ii, jj] = p;
            if (check(ii, jj) && grid[ii][jj] == 1) {
              grid[ii][jj] = 2;
              visited[ii][jj] = 1;
            }
          }
        }
      }
    }
  }

  bool done() {
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (grid[i][j] == 1)
          return false;
      }
    }

    return true;
  }
};