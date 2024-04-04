#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      if (nums[i] > 0)
        break;
      int l = i + 1, r = n - 1, target = -nums[i];
      while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum == target) {
          ans.push_back({-target, nums[l], nums[r]});
          while (l < r && nums[l] == nums[l + 1])
            l++;
          while (l < r && nums[r] == nums[r - 1])
            r--;
          l++, r--;
        } else if (sum < target) {
          l++;
        } else {
          r--;
        }
      }
    }

    return ans;
  }
};