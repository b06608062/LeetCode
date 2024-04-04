#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<char>> board;
  int row;
  int col;

  bool exist(vector<vector<char>> &board, string word) {
    this->board = board;
    row = board.size();
    col = board[0].size();
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (dfs(i, j, word))
          return true;
      }
    }

    return false;
  }

  bool check(int i, int j) { return 0 <= i && i < row && 0 <= j && j < col; }
  bool matchChar(int i, int j, char c) { return c == board[i][j]; }

  bool dfs(int i, int j, string word) {
    if (word.empty())
      return true;
    char tmp = word[0];
    if (!check(i, j) || !matchChar(i, j, tmp))
      return false;
    string subWord = word.substr(1);
    board[i][j] = '*';
    if (dfs(i - 1, j, subWord) || dfs(i + 1, j, subWord) ||
        dfs(i, j - 1, subWord) || dfs(i, j + 1, subWord))
      return true;
    board[i][j] = tmp;

    return false;
  }
};