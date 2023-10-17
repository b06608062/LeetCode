// 242. Valid Anagram
#include <map>
#include <string>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return false;

    map<char, int> countMap;
    for (char c : s) {
      countMap[c]++;
    }
    for (char c : t) {
      int count = --countMap[c];
      if (count < 0)
        return false;
      else if (count = 0)
        countMap.erase(c);
    }
    return true;
  }
};