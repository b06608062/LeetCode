#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> ans;
  vector<int> nums;

  vector<vector<int>> subsets(vector<int> &nums) {
    this->nums = nums;
    vector<int> subset;
    build(subset, 0);

    return ans;
  }

  void build(vector<int> &subset, int i) {
    if (i == nums.size()) {
      ans.push_back(subset);
      return;
    }

    int num = nums[i];
    subset.push_back(num);
    build(subset, i + 1);
    subset.pop_back();
    build(subset, i + 1);
  }
};
