#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> inDegree(numCourses, 0);

    for (auto &p : prerequisites) {
      graph[p[1]].push_back(p[0]);
      inDegree[p[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (inDegree[i] == 0)
        q.push(i);
    }

    int count = 0;
    while (!q.empty()) {
      int current = q.front();
      q.pop();
      ++count;

      for (int next : graph[current]) {
        if (--inDegree[next] == 0)
          q.push(next);
      }
    }

    return count == numCourses;
  }
};
