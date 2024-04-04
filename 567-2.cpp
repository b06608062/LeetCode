#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int l1 = s1.length(), l2 = s2.length();
    if (l1 > l2) {
      return false;
    }
    for (int i = 0; i <= l2 - l1; i++) {
      if (isAnagram(s1, s2.substr(i, l1)))
        return true;
    }

    return false;
  }
  bool isAnagram(string s1, string s2) {
    int n = s1.length();
    unordered_map<char, int> myMap;
    for (auto &c : s1) {
      myMap[c]++;
    }
    for (auto &c : s2) {
      if (myMap[c]-- == 0) {
        return false;
      }
    }

    return true;
  }
};