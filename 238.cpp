// 238. Product of Array Except Self
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int zeroCount = 0;
    int allProduct = 1;
    for (const auto &num : nums) {
      if (num == 0)
        zeroCount++;
      else
        allProduct *= num;
    }
    vector<int> ans;
    switch (zeroCount) {
    case 0:
      for (const auto &num : nums) {
        ans.push_back(allProduct / num);
      }
      break;
    case 1:
      for (const auto &num : nums) {
        if (num == 0)
          ans.push_back(allProduct);
        else
          ans.push_back(0);
      }
      break;
    default:
      return vector<int>(nums.size(), 0);
      break;
    }
    return ans;
  }
};