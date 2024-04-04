#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    map<int, int> myMap;
    vector<int> noRepeatNums;
    for (auto num : nums)
      myMap[num]++;
    if (myMap.find(0) != myMap.end() && myMap[0] > 2)
      ans.push_back({0, 0, 0});
    for (auto it : myMap) {
      if (it.first != 0 && it.second > 1 &&
          myMap.find(-it.first * 2) != myMap.end())
        ans.push_back({it.first, it.first, -it.first * 2});
      noRepeatNums.push_back(it.first);
    }
    int n = noRepeatNums.size();
    for (int i = 0; i < n - 2; i++) {
      if (noRepeatNums[i] > 0)
        break;
      int target = -noRepeatNums[i];
      int left = i + 1, right = n - 1;
      while (left < right) {
        int towSum = noRepeatNums[left] + noRepeatNums[right];
        if (towSum == target)
          ans.push_back(
              {noRepeatNums[i], noRepeatNums[left++], noRepeatNums[right--]});
        else if (towSum < target)
          left++;
        else
          right--;
      }
    }

    return ans;
  }
};