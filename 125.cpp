// 125. Valid Palindrome
#include <string>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    string t = "";
    for (char c : s) {
      if (isalpha(c) || isdigit(c))
        t += towlower(c);
    }
    int length = t.length();
    int half = length / 2;
    for (int i = 0; i < half; ++i) {
      if (t[i] != t[length - i - 1]) {
        return false;
      }
    }
    return true;
  }
};