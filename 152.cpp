// 152. Maximum Product Subarray
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;

    vector<int> dpMin(n);
    vector<int> dpMax(n);
    dpMin[0] = nums[0];
    dpMax[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      int cur = nums[i];
      int a = cur * dpMin[i - 1];
      int b = cur * dpMax[i - 1];
      dpMin[i] = min(min(a, b), cur);
      dpMax[i] = max(max(a, b), cur);
    }

    return *max_element(dpMax.begin(), dpMax.end());
  }
};