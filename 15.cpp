#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    set<vector<int>> mySet;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
      int target = -nums[i];
      if (target < 0)
        break;
      int left = i + 1, right = nums.size() - 1;
      while (left < right) {
        int towSum = nums[left] + nums[right];
        if (towSum == target) {
          mySet.insert({nums[i], nums[left], nums[right]});
          left++;
          right--;
        } else if (towSum < target) {
          left++;
        } else {
          right--;
        }
      }
    }
    for (auto it : mySet) {
      ans.push_back(it);
    }

    return ans;
  }
};