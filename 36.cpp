#include <vector>
using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    for (vector<char> row : board) {
      vector<int> record(10, 1);
      for (char c : row) {
        if (c == '.')
          continue;
        int num = c - '0';
        if (--record[num] < 0)
          return false;
      }
    }
    for (int j = 0; j < 9; j++) {
      vector<int> record(10, 1);
      for (vector<char> row : board) {
        char c = row[j];
        if (c == '.')
          continue;
        int num = c - '0';
        if (--record[num] < 0)
          return false;
      }
    }
    for (int r = 0; r < 3; r++) {
      for (int c = 0; c < 3; c++) {
        vector<int> record(10, 1);
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            char ch = board[r * 3 + i][c * 3 + j];
            if (ch == '.')
              continue;
            int num = ch - '0';
            if (--record[num] < 0)
              return false;
          }
        }
      }
    }

    return true;
  }
};