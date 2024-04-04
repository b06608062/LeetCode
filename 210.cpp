#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> graph;
  vector<int> states;
  vector<int> ans;
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    this->graph = vector<vector<int>>(numCourses);
    for (auto p : prerequisites) {
      graph[p[1]].push_back(p[0]);
    }
    // states: 0 = unkown, 1 = visiting, 2 = visited
    this->states = vector<int>(numCourses);

    for (int i = 0; i < numCourses; i++) {
      if (dfs(i))
        return vector<int>();
    }
    reverse(ans.begin(), ans.end());

    return ans;
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
    ans.push_back(i);

    return false;
  }
};