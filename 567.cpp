// 567. Permutation in String
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int s1Length = s1.length(), s2Length = s2.length();
    if (s1Length > s2Length)
      return false;
    unordered_map<char, int> m1, m2;
    unordered_set<char> s;
    int s1Hash = 0, s2Hash = 0;
    for (int i = 0; i < s1Length; ++i) {
      char c1 = s1[i];
      char c2 = s2[i];
      m1[c1]++;
      s1Hash = (s1Hash + c1) % 11;
      s.insert(c1);
      m2[c2]++;
      s2Hash = (s2Hash + c2) % 11;
    }
    int start = 0;
    while (start <= s2Length - s1Length) {
      if (s1Hash == s2Hash) {
        bool flag = true;
        for (auto c : s) {
          if (m1[c] != m2[c]) {
            flag = false;
            break;
          }
        }
        if (flag)
          return true;
      }

      m2[s2[start]]--;
      s2Hash = (s2Hash - (s2[start] % 11) + s2[start + s1Length]) % 11;
      m2[s2[start + s1Length]]++;
      start++;
    }
    return false;
  }
};