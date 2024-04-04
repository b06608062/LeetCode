#include <vector>
using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int length = nums.size();
    if (nums[0] <= nums[length - 1])
      return nums[0];
    int left = 0, right = length - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      int current = nums[mid];
      if (current > nums[mid + 1]) {
        return nums[mid + 1];
      } else {
        if (current >= nums[0]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }

    return -1;
  }
};