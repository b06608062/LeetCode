// 746. Min Cost Climbing Stairs
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int height = cost.size();
    if (height == 0 || height == 1)
      return 0;
    vector<int> stairs(height + 1, 0);
    for (int i = 2; i <= height; ++i)
      stairs[i] = min(stairs[i - 1] + cost[i - 1], stairs[i - 2] + cost[i - 2]);

    return stairs[height];
  }
};