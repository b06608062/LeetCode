#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<char>> board;
  string word;
  int row;
  int col;

  bool exist(vector<vector<char>> &board, string word) {
    this->board = board;
    this->word = word;
    row = board.size();
    col = board[0].size();
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        vector<vector<int>> visited(row, vector<int>(col, 0));
        if (dfs(i, j, visited, 0))
          return true;
      }
    }

    return false;
  }

  bool check(int i, int j) { return 0 <= i && i < row && 0 <= j && j < col; }

  bool dfs(int i, int j, vector<vector<int>> &visited, int match) {
    if (match == word.size())
      return true;
    if (!check(i, j) || visited[i][j] == 1 || word[match] != board[i][j])
      return false;
    visited[i][j] = 1;
    if (dfs(i - 1, j, visited, match + 1) ||
        dfs(i + 1, j, visited, match + 1) ||
        dfs(i, j - 1, visited, match + 1) || dfs(i, j + 1, visited, match + 1))
      return true;
    visited[i][j] = 0;

    return false;
  }
};