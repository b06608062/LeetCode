#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
      for (auto word : wordDict) {
        int l = word.size();
        if (i - l >= 0 && dp[i - l] &&
            wordSet.find(s.substr(i - l, l)) != wordSet.end()) {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[n];
  }
};