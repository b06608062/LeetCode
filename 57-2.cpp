#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    vector<vector<int>> l;
    vector<vector<int>> r;
    int start = newInterval[0];
    int end = newInterval[1];
    for (auto interval : intervals) {
      if (interval[1] < start) {
        l.push_back(interval);
      } else if (interval[0] > end) {
        r.push_back(interval);
      } else {
        start = min(start, interval[0]);
        end = max(end, interval[1]);
      }
    }

    l.push_back({start, end});
    l.insert(l.end(), r.begin(), r.end());
    return l;
  }
};