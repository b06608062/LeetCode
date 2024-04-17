#include <cstdint>

#include <vector>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int ret = 0;
    int n = nums.size();
    for (int i = 0; i <= n; i++) {
      ret ^= i;
    }
    for (auto x : nums) {
      ret ^= x;
    }

    return ret;
  }
};