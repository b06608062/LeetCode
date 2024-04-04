#include <vector>
using namespace std;

class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int length = nums.size();
    for (int i = 0; i < length; i++) {
      int idx = abs(nums[i]);
      if (nums[idx] < 0)
        return idx;
      nums[idx] *= -1;
    }

    return -1;
  }
};