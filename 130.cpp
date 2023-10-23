// 130. Surrounded Regions
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<char>> board;
  int row;
  int col;
  void solve(vector<vector<char>> &board) {
    this->board = board;
    row = board.size();
    col = board[0].size();
    vector<vector<int>> visited(row, vector<int>(col, 0));
    for (int i = 0; i < row; ++i) {
      dfs(i, 0, visited);
      dfs(i, col - 1, visited);
    }
    for (int j = 0; j < col; ++j) {
      dfs(0, j, visited);
      dfs(row - 1, j, visited);
    }

    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        char c = this->board[i][j];
        if (c == 'O')
          board[i][j] = 'X';
        else if (c == '#')
          board[i][j] = 'O';
      }
    }
  }

  bool check(int i, int j) { return 0 <= i && i < row && 0 <= j && j < col; }

  void dfs(int i, int j, vector<vector<int>> &visited) {
    if (!check(i, j) || visited[i][j] == 1 || board[i][j] == 'X')
      return;
    visited[i][j] = 1;
    board[i][j] = '#';
    dfs(i - 1, j, visited);
    dfs(i + 1, j, visited);
    dfs(i, j - 1, visited);
    dfs(i, j + 1, visited);
  }
};