// Bellman-Ford
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    int max = 99 * 100 + 1;
    vector<int> dist(n + 1, max);
    dist[k] = 0;
    for (int i = 1; i < n; i++) {
      for (auto a : times) {
        int u = a[0], v = a[1], t = a[2];
        dist[v] = min(dist[v], dist[u] + t);
      }
    }
    int maxDist = *max_element(dist.begin() + 1, dist.end());

    return maxDist == max ? -1 : maxDist;
  }
};