#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> graph;
  vector<int> states;
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    this->graph = vector<vector<int>>(numCourses);
    for (auto p : prerequisites) {
      graph[p[1]].push_back(p[0]);
    }

    // states: 0 = unkown, 1 = visiting, 2 = visited
    this->states = vector<int>(numCourses);
    for (int i = 0; i < numCourses; i++) {
      if (dfs(i))
        return false;
    }

    return true;
  }

  bool dfs(int i) {
    if (states[i] == 2)
      return false;
    else if (states[i] == 1)
      return true;

    states[i] = 1;
    for (auto j : graph[i]) {
      if (dfs(j))
        return true;
    }
    states[i] = 2;

    return false;
  }
};