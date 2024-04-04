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
    for (int i = 0; i < row; i++) {
      dfs(i, 0);
      dfs(i, col - 1);
    }
    for (int j = 0; j < col; j++) {
      dfs(0, j);
      dfs(row - 1, j);
    }

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        char c = this->board[i][j];
        if (c == 'O')
          board[i][j] = 'X';
        else if (c == '#')
          board[i][j] = 'O';
      }
    }
  }

  bool check(int i, int j) { return 0 <= i && i < row && 0 <= j && j < col; }

  void dfs(int i, int j) {
    if (!check(i, j) || board[i][j] != 'O')
      return;
    board[i][j] = '#';
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
  }
};