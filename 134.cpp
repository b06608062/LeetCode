#include <vector>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    int total = 0;
    int start = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
      cur += (gas[i] - cost[i]);
      if (cur < 0) {
        cur = 0;
        start = i + 1;
      }
      total += (gas[i] - cost[i]);
    }

    return total < 0 ? -1 : start;
  }
};