// 213. House Robber II
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int l = nums.size();
    if (l == 0)
      return 0;
    else if (l == 1)
      return nums[0];

    vector<int> in1(l + 1);
    in1[0] = 0;
    in1[1] = nums[0];
    in1[2] = nums[0];
    vector<int> ex1(l + 1);
    ex1[0] = 0;
    ex1[1] = 0;
    for (int i = 3; i < l; ++i)
      in1[i] = max(in1[i - 1], in1[i - 2] + nums[i - 1]);

    for (int i = 2; i <= l; ++i)
      ex1[i] = max(ex1[i - 1], ex1[i - 2] + nums[i - 1]);

    return max(in1[l - 1], ex1[l]);
  }
};