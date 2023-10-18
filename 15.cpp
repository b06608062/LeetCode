// 15. 3Sum
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    set<vector<int>> s;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
      int target = -nums[i];
      if (target < 0)
        break;
      int left = i + 1, right = nums.size() - 1;
      while (left < right) {
        int towSum = nums[left] + nums[right];
        if (towSum == target) {
          vector<int> tmp = {nums[i], nums[left], nums[right]};
          s.insert(tmp);
          left++;
          right--;
        } else if (towSum < target) {
          left++;
        } else {
          right--;
        }
      }
    }
    for (auto t : s) {
      ans.push_back(t);
    }

    return ans;
  }
};