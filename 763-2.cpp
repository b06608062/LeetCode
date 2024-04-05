#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string s) {
    int n = s.length();
    unordered_map<char, int> myMap;
    for (int i = 0; i < n; i++) {
      myMap[s[i]] = i;
    }
    vector<int> ans;
    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
      end = max(end, myMap[s[i]]);
      if (end == i) {
        ans.push_back(end - start + 1);
        start = i + 1;
        end = i + 1;
      }
    }

    return ans;
  }
};