// 621. Task Scheduler
#include <vector>
using namespace std;

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    vector<int> v(26, 0);
    int max = 0;
    int maxTaskCounts = 0;
    for (auto &c : tasks) {
      int index = c - 'A';
      v[index]++;
      if (v[index] > max) {
        max = v[index];
        maxTaskCounts = 1;
      } else if (v[index] == max) {
        maxTaskCounts++;
      }
    }
    int spand = (max - 1) * (n + 1) + maxTaskCounts;

    return spand > tasks.size() ? spand : tasks.size();
  }
};