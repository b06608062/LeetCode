#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int size = nums.size();
    if (size == 0)
      return 0;
    else if (size == 1)
      return nums[0];

    vector<int> moneys(size + 1);
    moneys[0] = 0;
    moneys[1] = nums[0];
    for (int i = 2; i <= size; i++) {
      moneys[i] = max(moneys[i - 1], moneys[i - 2] + nums[i - 1]);
    }

    return moneys[size];
  }
};