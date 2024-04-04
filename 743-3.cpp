// Dijkstra
#include <queue>
#include <vector>
using namespace std;

auto comp = [](pair<int, int> &p1, pair<int, int> &p2) {
  return p1.second >= p2.second;
};

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    int max = (n - 1) * 100 + 1;
    vector<int> done(n + 1, 0);
    vector<int> dist(n + 1, max);
    vector<vector<pair<int, int>>> graph(n + 1);
    for (auto a : times) {
      graph[a[0]].push_back({a[1], a[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q;
    q.push({k, 0});
    while (!q.empty()) {
      auto [i, d] = q.top();
      q.pop();
      if (done[i])
        continue;
      dist[i] = d;
      done[i] = 1;
      for (auto a : graph[i]) {
        auto [j, t] = a;
        if (done[j])
          continue;
        q.push({j, d + t});
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
      ans = ans > dist[i] ? ans : dist[i];
    return ans == max ? -1 : ans;
  }
};