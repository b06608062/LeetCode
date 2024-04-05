#include <vector>
using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        int dist = i - j;
        if (dp[j] && nums[j] >= dist) {
          dp[i] = 1;
          break;
        }
      }
    }

    return dp[n - 1];
  }
};