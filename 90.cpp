// 90. Subsets II
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  set<vector<int>> s;
  vector<int> nums;

  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    this->nums = nums;
    vector<int> subset;
    build(subset, 0);
    vector<vector<int>> ans(s.begin(), s.end());

    return ans;
  }

  void build(vector<int> &subset, int i) {
    if (i == nums.size()) {
      s.insert(subset);
      return;
    }

    int num = nums[i];
    build(subset, i + 1);
    subset.push_back(num);
    build(subset, i + 1);
    subset.pop_back();
  }
};
