// 49. Group Anagrams
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ans;
    map<string, vector<string>> m;
    for (auto &str : strs) {
      m[sortString(str)].push_back(str);
    }
    for (auto &it : m) {
      ans.push_back(it.second);
    }
    return ans;
  }
  string &sortString(string str) {
    sort(str.begin(), str.end());
    return str;
  }
};