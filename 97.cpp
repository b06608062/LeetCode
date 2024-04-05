#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
    if (l1 + l2 != l3)
      return false;
    if (!l1 && !l2 && !l3)
      return true;
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= l1; i++) {
      if (s1.substr(0, i) != s3.substr(0, i))
        break;
      dp[i][0] = 1;
    }
    for (int j = 1; j <= l2; j++) {
      if (s2.substr(0, j) != s3.substr(0, j))
        break;
      dp[0][j] = 1;
    }
    for (int i = 1; i <= l1; i++) {
      for (int j = 1; j <= l2; j++) {
        if (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j])
          dp[i][j] = 1;
        if (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1])
          dp[i][j] = 1;
      }
    }

    return dp[l1][l2] == 1;
  }
};