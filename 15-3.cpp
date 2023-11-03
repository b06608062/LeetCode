// 15. 3Sum
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    map<int, int> mp;
    vector<int> noRepeatNums;
    for (auto num : nums)
      ++mp[num];
    if (mp[0] > 2)
      ans.push_back({0, 0, 0});
    for (auto m : mp) {
      if (m.first != 0 && m.second > 1 && mp.find(-m.first * 2) != mp.end())
        ans.push_back({m.first, m.first, -m.first * 2});
      noRepeatNums.push_back(m.first);
    }

    int n = noRepeatNums.size();
    for (int i = 0; i < n - 2; ++i) {
      if (noRepeatNums[i] > 0)
        break;
      int t = -noRepeatNums[i];
      int left = i + 1, right = n - 1;
      while (left < right) {
        int tmp = noRepeatNums[left] + noRepeatNums[right];
        if (tmp == t)
          ans.push_back(
              {noRepeatNums[i], noRepeatNums[left++], noRepeatNums[right--]});
        else if (tmp < t)
          left++;
        else
          right--;
      }
    }

    return ans;
  }
};