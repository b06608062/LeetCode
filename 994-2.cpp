// 994. Rotting Oranges
#include <queue>
#include <set>
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
    set<pair<int, int>> seen;
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (grid[i][j] == 1)
          fresh++;
        else if (grid[i][j] == 2)
          q.push(make_tuple(i, j, 0));
      }
    }
    if (fresh == 0)
      return 0;

    while (!q.empty()) {
      auto [i, j, current] = q.front();
      q.pop();
      vector<pair<int, int>> directions(
          {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}});
      for (auto d : directions) {
        auto [r, c] = d;
        if (check(r, c) && grid[r][c] == 1 && seen.insert({r, c}).second) {
          fresh--;
          if (!fresh)
            return current + 1;
          else
            q.push(make_tuple(r, c, current + 1));
        }
      }
    }

    return -1;
  }

  bool check(int i, int j) { return 0 <= i && i < row && 0 <= j && j < col; }
};