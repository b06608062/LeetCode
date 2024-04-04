#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  unordered_map<char, string> m;
  string digits;
  int length;
  vector<string> ans;
  vector<string> letterCombinations(string digits) {
    this->digits = digits;
    length = digits.length();
    if (length != 0) {
      m['2'] = "abc";
      m['3'] = "def";
      m['4'] = "ghi";
      m['5'] = "jkl";
      m['6'] = "mno";
      m['7'] = "pqrs";
      m['8'] = "tuv";
      m['9'] = "wxyz";
      helper("", 0);
    }

    return ans;
  }

  void helper(string subset, int begin) {
    if (begin == length) {
      ans.push_back(subset);
      return;
    }
    string str = m[digits[begin]];
    for (int i = 0; i < str.length(); i++) {
      helper(subset + str[i], begin + 1);
    }
  }
};