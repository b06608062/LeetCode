// 5. Longest Palindromic Substring
#include <math.h>
#include <string>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.length();
    auto getLen = [&](int l, int r) {
      while (l >= 0 && r < n && s[l] == s[r]) {
        --l;
        ++r;
      }
      return r - l - 1;
    };
    int start = 0;
    int maxLen = 0;
    for (int i = 0; i < n; ++i) {
      int cur = max(getLen(i, i), getLen(i, i + 1));
      if (cur > maxLen) {
        maxLen = cur;
        start = i - (cur - 1) / 2;
      }
    }

    return s.substr(start, maxLen);
  }
};