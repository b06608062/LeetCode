#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    if (s[0] == '0')
      return 0;
    int n = s.length();
    if (n == 1)
      return 1;
    vector<int> dp(n + 1, 1);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      bool canDecode = helper(s, i - 2);
      if (s[i - 1] == '0') {
        if (canDecode)
          dp[i] = dp[i - 2];
        else
          return 0;
      } else {
        if (canDecode)
          dp[i] = dp[i - 1] + dp[i - 2];
        else
          dp[i] = dp[i - 1];
      }
    }

    return dp[n];
  }
  bool helper(string &s, int begin) {
    int decode = stoi(s.substr(begin, 2));
    if (decode >= 10 && decode <= 26)
      return true;

    return false;
  }
};