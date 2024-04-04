#include <vector>
using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    int max = INT_MAX - 1;
    sort(coins.begin(), coins.end());
    vector<int> dp(amount + 1, max);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
      for (auto coin : coins) {
        int idx = i - coin;
        if (idx < 0)
          break;
        dp[i] = min(dp[i], dp[idx] + 1);
      }
    }

    return dp[amount] == max ? -1 : dp[amount];
  }
};