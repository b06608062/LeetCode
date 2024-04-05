#include <vector>
using namespace std;

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    if (amount == 0)
      return 1;
    sort(coins.begin(), coins.end());
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (auto c : coins) {
      auto dp_tmp = dp;
      for (int a = 1; a <= amount; a++) {
        dp[a] = 0;
        for (int k = 0; k <= a / c; k++) {
          dp[a] += dp_tmp[a - k * c];
        }
      }
    }

    return dp[amount];
  }
};