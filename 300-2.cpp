#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n1 = nums.size();
    vector<int> s1 = nums;
    set<int> mySet(nums.begin(), nums.end());
    vector<int> s2(mySet.begin(), mySet.end());
    int n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n1; i++) {
      for (int j = 1; j <= n2; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[n1][n2];
  }
};