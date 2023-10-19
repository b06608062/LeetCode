// 33. Search in Rotated Sorted Array
#include <vector>
using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int length = nums.size();
    if (nums[0] < nums[length - 1])
      return binarySearch(nums, 0, length - 1, target);

    int minIndex = findMinIndex(nums);
    if (target >= nums[0] && target <= nums[minIndex - 1])
      return binarySearch(nums, 0, minIndex - 1, target);
    if (target >= nums[minIndex] && target <= nums[length - 1])
      return binarySearch(nums, minIndex, length - 1, target);

    return -1;
  }

  int binarySearch(vector<int> &nums, int left, int right, int target) {
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] > target)
        right = mid - 1;
      else
        left = mid + 1;
    }

    return -1;
  }

  int findMinIndex(vector<int> &nums) {
    int length = nums.size();
    int left = 0, right = length - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      int current = nums[mid];
      if (current > nums[mid + 1]) {
        return mid + 1;
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