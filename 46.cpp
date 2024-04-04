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
  void run(vector<int> &nums, int begin) {
    if (begin == length - 1) {
      ans.push_back(nums);
      return;
    }

    for (int i = begin; i < length; i++) {
      swap(nums[begin], nums[i]);
      run(nums, begin + 1);
      swap(nums[begin], nums[i]);
    }
  }
};