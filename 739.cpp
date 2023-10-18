// 739. Daily Temperatures
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int length = temperatures.size();
    vector<int> ans(length, 0);
    stack<pair<int, int>> st;
    for (int i = 0; i < length; i++) {
      int current = temperatures[i];
      while (!st.empty() && current > st.top().second) {
        pair<int, int> past = st.top();
        st.pop();
        ans[past.first] = i - past.first;
      }
      st.push({i, current});
    }
    return ans;
  }
};