#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> nums;
  vector<vector<int>> totalSub;
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    this->nums = nums;
    vector<int> sub;
    selectNextElement(sub, 0);

    return totalSub;
  }

  void selectNextElement(vector<int> &sub, int begin) {
    totalSub.push_back(sub);

    for (int i = begin; i < nums.size(); i++) {
      if (i != begin && nums[i] == nums[i - 1]) {
        continue;
      }
      sub.push_back(nums[i]);
      selectNextElement(sub, i + 1);
      sub.pop_back();
    }
  }
};
