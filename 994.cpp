#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int row;
  int col;
  int orangesRotting(vector<vector<int>> &grid) {
    row = grid.size();
    col = grid[0].size();
    int fresh = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        int k = grid[i][j];
        if (k == 2)
          q.push({i, j});
        else if (k == 1)
          fresh++;
      }
    }
    if (fresh == 0)
      return 0;

    int run = 0;
    while (!q.empty()) {
      run++;
      int n = q.size();
      for (int k = 0; k < n; k++) {
        auto [i, j] = q.front();
        q.pop();
        vector<pair<int, int>> directions(
            {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}});
        for (auto d : directions) {
          auto [ii, jj] = d;
          if (check(ii, jj) && grid[ii][jj] == 1) {
            fresh--;
            if (fresh == 0)
              return run;
            grid[ii][jj] = 2;
            q.push({ii, jj});
          }
        }
      }
    }

    return -1;
  }

  bool check(int i, int j) { return i >= 0 && i < row && j >= 0 && j < col; }
};