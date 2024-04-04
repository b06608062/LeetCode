#include <vector>
using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n == 0 || n == 1)
      return n;

    vector<int> stairs(n + 1);
    stairs[0] = 1;
    stairs[1] = 1;
    for (int i = 2; i <= n; i++)
      stairs[i] = stairs[i - 1] + stairs[i - 2];

    return stairs[n];
  }
};