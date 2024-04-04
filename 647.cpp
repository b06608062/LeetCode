#include <string>
using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    int n = s.length();
    int count = 0;
    auto countPal = [&](int l, int r) {
      while (l >= 0 && r < n && s[l] == s[r]) {
        --l;
        ++r;
        count++;
      }
    };

    for (int i = 0; i < n; i++) {
      countPal(i, i);
      countPal(i, i + 1);
    }

    return count;
  }
};