// 743. Network Delay Time
// Bellman-Ford
#include <climits>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    int max = 99 * 100 + 1;
    vector<int> dist(n + 1, max);
    dist[k] = 0;
    for (int i = 1; i < n; i++) {
      for (auto t : times) {
        int u = t[0], v = t[1], d = t[2];
        dist[v] = min(dist[v], dist[u] + d);
      }
    }
    int maxDist = *max_element(dist.begin() + 1, dist.end());

    return maxDist == max ? -1 : maxDist;
  }
};