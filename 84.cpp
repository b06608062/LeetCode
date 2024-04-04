#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    stack<int> stk;
    vector<int> nextSmaller(n, n);
    vector<int> prevSmaller(n, -1);
    for (int i = 0; i < heights.size(); i++) {
      while (!stk.empty() && heights[stk.top()] > heights[i]) {
        nextSmaller[stk.top()] = i;
        stk.pop();
      }
      if (!stk.empty())
        prevSmaller[i] = stk.top();
      stk.push(i);
    }
    int ret = 0;
    for (int i = 0; i < n; i++)
      ret = max(ret, heights[i] * (nextSmaller[i] - prevSmaller[i] - 1));

    return ret;
  }
};
