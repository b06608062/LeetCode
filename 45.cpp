#include <vector>
using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
      int min_steps = INT_MAX;
      for (int j = 0; j < i; j++) {
        int dist = i - j;
        if (dp[j] && nums[j] >= dist) {
          min_steps = min(min_steps, dp[j] + 1);
        }
      }
      dp[i] = min_steps == INT_MAX ? 0 : min_steps;
    }

    return dp[n - 1] - 1;
  }
};