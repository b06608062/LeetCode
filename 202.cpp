#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> mySet;
    while (1) {
      mySet.insert(n);
      string s = to_string(n);
      n = 0;
      for (int i = 0; i < s.length(); i++) {
        n += pow(s[i] - '0', 2);
      }
      if (n == 1) {
        return true;
      } else if (mySet.find(n) != mySet.end()) {
        return false;
      }
    }
  }
};