#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    int max = (k + 1) * 10000 + 1;
    vector<int> dist1(n, max);
    vector<int> dist2(n, max);
    dist1[src] = 0;

    for (int i = 0; i <= k; i++) {
      for (auto f : flights)
        dist2[f[1]] = min(dist2[f[1]], dist1[f[0]] + f[2]);
      dist1 = dist2;
    }

    return dist2[dst] == max ? -1 : dist2[dst];
  }
};