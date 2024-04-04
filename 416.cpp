#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
      return false;
    int target = sum / 2;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (auto num : nums) {
      for (int curSum = target; curSum - num >= 0; curSum--) {
        if (dp[curSum - num])
          dp[curSum] = 1;
      }
    }

    return dp[target] == 1;
  }
};