#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> ret;
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
    for (auto interval : intervals) {
      if (ret.empty() || interval[0] > ret.back()[1]) {
        ret.push_back(interval);
      } else {
        ret.back()[1] = max(ret.back()[1], interval[1]);
      }
    }

    return ret;
  }
};