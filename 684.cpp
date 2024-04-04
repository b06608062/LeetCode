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

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    // nodes labeled from 1 to n
    int size = edges.size() + 1;
    DisjoinSet ds(size);
    for (auto edge : edges) {
      int x = edge[0];
      int y = edge[1];
      if (!ds.unionSet(x, y))
        return {x, y};
    }

    return {-1, -1};
  }
};