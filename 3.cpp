// 3. Longest Substring Without Repeating Characters
#include <set>
#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int max = 0;
    set<char> seen;
    int start = 0;
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (!seen.insert(c).second) {
        max = max > seen.size() ? max : seen.size();
        char t;
        while ((t = s[start++]) != c) {
          seen.erase(t);
        }
      }
    }
    max = max > seen.size() ? max : seen.size();

    return max;
  }
};