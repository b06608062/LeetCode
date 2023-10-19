// 33. Search in Rotated Sorted Array
#include <vector>
using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int length = nums.size();
    int leftN = nums[0], rightN = nums[length - 1];
    int left = 0, right = length - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      int current = nums[mid];
      if (current == target) {
        return mid;
      } else if (current > target) {
        if (current <= rightN || target >= leftN)
          right = mid - 1;
        else
          left = mid + 1;
      } else {
        if (current >= leftN || target <= rightN)
          left = mid + 1;
        else
          right = mid - 1;
      }
    }

    return -1;
  }
};