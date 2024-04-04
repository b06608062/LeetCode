#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph = vector(numCourses, vector<int>());
    vector<int> inDegree = vector(numCourses, 0);
    for (auto p : prerequisites) {
      graph[p[1]].push_back(p[0]);
      inDegree[p[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (inDegree[i] == 0)
        q.push(i);
    }
    vector<int> ans;
    int count = 0;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      ans.push_back(cur);
      count++;
      for (auto nxt : graph[cur]) {
        if (--inDegree[nxt] == 0)
          q.push(nxt);
      }
    }

    return count == numCourses ? ans : vector<int>{};
  }
};