#include <vector>
using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return 0;
    int start = 0, end = 0;
    int step = 0;
    while (start <= end) {
      int new_end = end;
      for (int i = start; i <= end; i++) {
        new_end = max(new_end, i + nums[i]);
        if (new_end >= n - 1)
          return step + 1;
      }
      step++;
      start = end + 1;
      end = new_end;
    }

    return -1;
  }
};