#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    int length = s.length();
    unordered_map<char, int> myMap;
    int l = 0, r = 0;
    int windowSize = 0;
    for (; r < length; r++) {
      myMap[s[r]]++;
      auto it =
          max_element(myMap.begin(), myMap.end(),
                      [](const pair<char, int> &a, const pair<char, int> &b) {
                        return a.second < b.second;
                      });
      while (it->second + k < r - l + 1) {
        myMap[s[l++]]--;
        it =
            max_element(myMap.begin(), myMap.end(),
                        [](const pair<char, int> &a, const pair<char, int> &b) {
                          return a.second < b.second;
                        });
      }
      windowSize = windowSize < r - l + 1 ? r - l + 1 : windowSize;
    }

    return windowSize;
  }
};