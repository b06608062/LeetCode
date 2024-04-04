#include <math.h>
#include <queue>
#include <vector>
using namespace std;

class DisjoinSet {
public:
  vector<int> parent;
  vector<int> rank;

  DisjoinSet(int size) {
    parent.resize(size);
    rank.resize(size, 1);
    for (int i = 0; i < size; i++) {
      parent[i] = i;
    }
  };

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }

    return parent[x];
  }

  bool unionSet(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py)
      return false;
    if (rank[px] >= rank[py]) {
      parent[py] = px;
      rank[px] += rank[py];
    } else {
      parent[px] = py;
      rank[py] += rank[px];
    }

    return true;
  }
};

auto comp = [](vector<int> &e1, vector<int> &e2) { return e1[2] > e2[2]; };

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    int size = points.size();
    DisjoinSet ds(size);
    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq;
    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        int dist =
            abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        pq.push({i, j, dist});
      }
    }

    int count = 0;
    int minCost = 0;
    while (count < size - 1) {
      vector<int> edge = pq.top();
      pq.pop();
      if (ds.unionSet(edge[0], edge[1])) {
        count++;
        minCost += edge[2];
      }
    }

    return minCost;
  }
};