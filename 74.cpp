#include <vector>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int r = findRow(matrix, target);
    if (r == -1) {
      return true;
    } else {
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
        return -1;
      } else if (current < target) {
        top = mid + 1;
      } else {
        bottom = mid - 1;
      }
    }

    return top == 0 ? 0 : top - 1;
  }
};