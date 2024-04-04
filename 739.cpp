#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int length = temperatures.size();
    vector<int> ans(length, 0);
    stack<pair<int, int>> myStack;
    for (int i = 0; i < length; i++) {
      int current = temperatures[i];
      while (!myStack.empty() && current > myStack.top().second) {
        pair<int, int> past = myStack.top();
        myStack.pop();
        ans[past.first] = i - past.first;
      }
      myStack.push({i, current});
    }

    return ans;
  }
};