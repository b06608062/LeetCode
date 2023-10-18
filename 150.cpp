// 150. Evaluate Reverse Polish Notation
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isOperator(string &token) {
    if (token == "+" || token == "-" || token == "*" || token == "/")
      return true;
    return false;
  }

  int evalRPN(vector<string> &tokens) {
    stack<int> st;
    for (auto &token : tokens) {
      if (isOperator(token)) {
        int op2 = st.top();
        st.pop();
        int op1 = st.top();
        st.pop();

        if (token == "+")
          st.push(op1 + op2);
        else if (token == "-")
          st.push(op1 - op2);
        else if (token == "*")
          st.push(op1 * op2);
        else
          st.push(op1 / op2);
      } else {
        st.push(stoi(token.c_str()));
      }
    }

    return st.top();
  }
};