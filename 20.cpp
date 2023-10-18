// 20. Valid Parentheses
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> m = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
    for (auto c : s) {
      if (c == '(' || c == '{' || c == '[') {
        st.push(c);
      } else {
        if (st.empty() || m[st.top()] != c)
          return false;
        st.pop();
      }
    }
    if (!st.empty())
      return false;
    return true;
  }
};