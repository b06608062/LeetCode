#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string s;
  int stringLength;
  vector<vector<string>> ans;
  vector<vector<string>> partition(string s) {
    this->s = s;
    stringLength = s.size();
    vector<string> subset;
    helper(subset, 0);

    return ans;
  }

  bool isPalindrome(int start, int end) {
    int length = end - start + 1;
    for (int i = 0; i < length / 2; i++) {
      if (s[start + i] != s[end - i])
        return false;
    }
    return true;
  }

  void helper(vector<string> &subset, int start) {
    if (start == stringLength) {
      ans.push_back(subset);
      return;
    }

    for (int i = start; i < stringLength; i++) {
      if (isPalindrome(start, i)) {
        subset.push_back(s.substr(start, i - start + 1));
        helper(subset, i + 1);
        subset.pop_back();
      }
    }
  }
};