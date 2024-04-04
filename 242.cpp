#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> myMap;
    if (s.size() != t.size())
      return false;
    for (int i = 0; i < s.size(); i++) {
      myMap[s[i]]++;
      myMap[t[i]]--;
    }
    for (auto &pair : myMap) {
      if (pair.second != 0)
        return false;
    }

    return true;
  }
};