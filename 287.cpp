#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    sort(nums.begin(), nums.end(), [](int &a, int &b) { return a < b; });
    int length = nums.size();
    for (int i = 1; i < length; i++) {
      if (nums[i] == nums[i - 1])
        return nums[i];
    }

    return -1;
  }
};