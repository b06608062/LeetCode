// 300. Longest Increasing Subsequence
#include <vector>
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;

    vector<int> dp(n);
    dp[0] = 1;
    int maxLen = 1;
    for (int i = 1; i < n; ++i) {
      int max = 1;
      int cur = nums[i];
      for (int j = 0; j < i; ++j) {
        if (cur > nums[j])
          max = max > 1 + dp[j] ? max : 1 + dp[j];
      }
      dp[i] = max;
      maxLen = maxLen > max ? maxLen : max;
    }

    return maxLen;
  }
};