#include <string>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int length = s.length();
    int start = 0;
    int max = 1;
    for (int i = 0; i < length; i++) {
      for (int j = i + max; j < length; j++) {
        if (isPalindrome(s, i, j)) {
          start = i;
          max = j - i + 1;
        }
      }
    }

    return s.substr(start, max);
  }

  bool isPalindrome(string &s, int start, int end) {
    int length = end - start + 1;
    for (int i = 0; i < length / 2; i++)
      if (s[start + i] != s[end - i])
        return false;

    return true;
  }
};