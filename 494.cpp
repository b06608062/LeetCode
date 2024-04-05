#include <vector>
using namespace std;

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int n = nums.size();
    int sum = 0;
    for (auto a : nums) {
      sum += a;
    }
    if (target > sum || target < -sum)
      return 0;
    vector<vector<int>> dp(n + 1, vector<int>(sum * 2 + 1, 0));
    dp[0][sum] = 1;
    for (int i = 0; i < n; i++) {
      int a = nums[i];
      for (int j = a; j < sum * 2 + 1 - a; j++) {
        dp[i + 1][j - a] += dp[i][j];
        dp[i + 1][j + a] += dp[i][j];
      }
    }

    return dp[n][sum + target];
  }
};