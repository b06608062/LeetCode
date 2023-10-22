// 46. Permutations
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> ans;
  int length;
  vector<vector<int>> permute(vector<int> &nums) {
    this->length = nums.size();
    run(nums, 0);

    return ans;
  }
  void run(vector<int> &nums, int i) {
    if (i == length - 1) {
      ans.push_back(nums);
      return;
    }

    for (int j = i; j < length; ++j) {
      swap(nums[i], nums[j]);
      run(nums, i + 1);
      swap(nums[i], nums[j]);
    }
  }
};