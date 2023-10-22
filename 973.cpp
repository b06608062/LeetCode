// 973. K Closest Points to Origin
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

auto calculate = [](int x, int y) -> double {
  return sqrt((double)(x * x + y * y));
};

auto comp = [](pair<int, int> &a, pair<int, int> &b) -> bool {
  auto [x1, y1] = a;
  auto [x2, y2] = b;
  return calculate(x1, y1) > calculate(x2, y2);
};

class Solution {
public:
  priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq;
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    vector<vector<int>> ans;
    for (auto &point : points) {
      pq.push({point[0], point[1]});
    }
    while (k > 0) {
      auto [x, y] = pq.top();
      pq.pop();
      ans.push_back(vector<int>({x, y}));
      k--;
    }

    return ans;
  }
};