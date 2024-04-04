#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ans;
    map<string, vector<string>> myMap;
    for (auto &str : strs) {
      myMap[sortString(str)].push_back(str);
    }
    for (auto &it : myMap) {
      ans.push_back(it.second);
    }

    return ans;
  }
  string sortString(string str) {
    sort(str.begin(), str.end());

    return str;
  }
};