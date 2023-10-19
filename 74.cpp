// 74. Search a 2D Matrix
#include <vector>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int r = findRow(matrix, target);
    if (r == -2) {
      return true;
    } else if (r >= 0) {
      vector<int> &row = matrix[r];
      int left = 0, right = row.size() - 1, mid;
      while (left <= right) {
        mid = (left + right) / 2;
        if (row[mid] == target) {
          return true;
        } else if (row[mid] < target) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }

    return false;
  }
  int findRow(vector<vector<int>> &matrix, int target) {
    int rowSize = matrix.size();
    int top = 0, bottom = matrix.size() - 1, mid;
    while (top <= bottom) {
      mid = (top + bottom) / 2;
      int current = matrix[mid][0];
      if (current == target) {
        return -2;
      } else if (current < target) {
        top = mid + 1;
      } else {
        bottom = mid - 1;
      }
    }
    int colSize = matrix[0].size();
    if (target > matrix[mid][0] && target <= matrix[mid][colSize - 1]) {
      return mid;
    }
    if (mid - 1 >= 0) {
      if (target > matrix[mid - 1][0] &&
          target <= matrix[mid - 1][colSize - 1]) {
        return mid - 1;
      }
    }
    if (mid + 1 < rowSize) {
      if (target > matrix[mid + 1][0] &&
          target <= matrix[mid + 1][colSize + 1]) {
        return mid + 1;
      }
    }

    return -1;
  }
};