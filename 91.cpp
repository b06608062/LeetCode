// 91. Decode Ways
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool flag;
  int numDecodings(string s) {
    int n = s.length();
    if (n == 0 || s[0] == '0')
      return 0;

    vector<int> v(n + 1);
    v[0] = 1;
    v[1] = 1;
    for (int i = 2; i <= n; ++i) {
      char cur = s[i - 1];
      int res = isValid(s, i - 2);
      if (res == 0) {
        if (cur == '0')
          return 0;
        else
          v[i] = v[i - 1];
      } else {
        if (cur == '0')
          v[i] = v[i - 2];
        else
          v[i] = v[i - 1] + v[i - 2];
      }
    }

    return v[n];
  }

  int isValid(string &s, int i) {
    int dec = stoi(s.substr(i, 2));
    if (10 <= dec && dec <= 26)
      return 1;

    return 0;
  }
};