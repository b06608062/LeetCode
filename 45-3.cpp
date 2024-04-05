#include <vector>
using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return 0;
    int curEnd = 0, curFarthest = 0, jumps = 0;
    for (int i = 0; i < n; i++) {
      curFarthest = max(curFarthest, i + nums[i]);
      if (curFarthest >= n - 1)
        return jumps + 1;
      if (i == curEnd) {
        jumps++;
        curEnd = curFarthest;
      }
    }

    return -1;
  }
};