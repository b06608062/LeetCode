#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    int a = newInterval[0];
    auto it = intervals.begin();
    while (it != intervals.end() && a >= (*it)[0])
      it++;
    intervals.insert(it, newInterval);

    vector<vector<int>> ret;
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
