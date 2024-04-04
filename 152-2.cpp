#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int n = nums.size();
    int n0 = nums[0];
    if (n == 1)
      return n0;
    int ans = INT_MIN;
    int myMin = n0, myMax = n0;
    ans = myMax;

    for (int i = 1; i < n; i++) {
      int ni = nums[i];
      int a = myMin * ni;
      int b = myMax * ni;
      myMin = min(min(a, b), ni);
      myMax = max(max(a, b), ni);
      ans = ans > myMax ? ans : myMax;
    }

    return ans;
  }
};