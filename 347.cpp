// 347. Top K Frequent Elements
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> m;
    for (const int &val : nums) {
      m[val]++;
    }

    vector<pair<int, int>> v(m.begin(), m.end());
    auto compare = [](const pair<int, int> &a, const pair<int, int> &b) {
      return a.second < b.second;
    };
    make_heap(v.begin(), v.end(), compare);

    vector<int> topK;
    for (int i = 0; i < k; ++i) {
      pop_heap(v.begin(), v.end(), compare);
      topK.push_back(v[v.size() - 1].first);
      v.pop_back();
    }

    return topK;
  }
};