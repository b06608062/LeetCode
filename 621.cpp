// 621. Task Scheduler
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int time;
  priority_queue<int> pq;
  queue<pair<int, int>> q;
  int leastInterval(vector<char> &tasks, int n) {
    time = 0;
    vector<int> v(26, 0);
    for (auto c : tasks) {
      v[c - 'A']++;
    }
    for (auto i : v) {
      if (i)
        pq.push(i);
    }

    while (!pq.empty() || !q.empty()) {
      time++;
      if (!q.empty()) {
        if (q.front().second == time) {
          pq.push(q.front().first);
          q.pop();
        }
      }
      if (!pq.empty()) {
        int task = pq.top() - 1;
        pq.pop();
        if (task) {
          q.push({task, time + n + 1});
        }
      }
    }

    return time;
  }
};