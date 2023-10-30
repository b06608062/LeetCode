// 322. Coin Change
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      int minCount = INT_MAX;
      for (auto coin : coins) {
        if (i - coin >= 0 && dp[i - coin] != -1)
          minCount = min(minCount, 1 + dp[i - coin]);
      }
      dp[i] = minCount == INT_MAX ? -1 : minCount;
    }

    return dp[amount];
  }
};