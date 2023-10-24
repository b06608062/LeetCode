// 743. Network Delay Time
// Floyd–Warshall
#include <climits>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    int max = 99 * 100 + 1;
    vector<vector<int>> D(n + 1, vector<int>(n + 1, max));
    for (auto t : times)
      D[t[0]][t[1]] = t[2];
    for (int i = 1; i <= n; ++i)
      D[i][i] = 0;

    for (int k = 1; k <= n; ++k)
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
          D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

    int ans = 0;
    for (int j = 1; j <= n; ++j)
      ans = ans > D[k][j] ? ans : D[k][j];

    return ans == max ? -1 : ans;
  }
};