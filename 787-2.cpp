// 787. Cheapest Flights Within K Stops
#include <math.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    int max = (k + 1) * 10000 + 1;
    vector<vector<pair<int, int>>> G(n);
    for (auto f : flights)
      G[f[0]].push_back({f[1], f[2]});
    vector<int> costs(n, max);
    queue<pair<int, int>> q;

    q.push({src, 0});
    for (int i = 0; i <= k; ++i) {
      if (q.empty())
        break;
      int qSize = q.size();
      while (qSize-- > 0) {
        auto [node, cost] = q.front();
        q.pop();
        for (auto [neighbour, price] : G[node]) {
          if (cost + price < costs[neighbour]) {
            costs[neighbour] = cost + price;
            q.push({neighbour, costs[neighbour]});
          }
        }
      }
    }

    return costs[dst] == max ? -1 : costs[dst];
  }
};