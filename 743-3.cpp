// 743. Network Delay Time
// Dijkstra
#include <queue>
#include <vector>
using namespace std;

auto camp = [](vector<int> &e1, vector<int> &e2) { return e1[1] > e2[1]; };

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    int max = 99 * 100 + 1;
    vector<vector<pair<int, int>>> G(n + 1);
    for (auto t : times)
      G[t[0]].push_back({t[1], t[2]});
    vector<int> dist(n + 1, max);
    vector<int> done(n + 1, 0);
    priority_queue<vector<int>, vector<vector<int>>, decltype(camp)> minQ;

    minQ.push({k, 0});
    while (!minQ.empty()) {
      int i = minQ.top()[0];
      int t = minQ.top()[1];
      minQ.pop();
      if (done[i])
        continue;
      done[i] = 1;
      dist[i] = t;
      for (auto edge : G[i]) {
        auto [j, d] = edge;
        if (!done[j])
          minQ.push({j, t + d});
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
      ans = ans > dist[i] ? ans : dist[i];

    return ans == max ? -1 : ans;
  }
};