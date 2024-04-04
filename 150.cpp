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
    stack<int> myStack;
    for (auto &token : tokens) {
      if (isOperator(token)) {
        int op2 = myStack.top();
        myStack.pop();
        int op1 = myStack.top();
        myStack.pop();
        if (token == "+")
          myStack.push(op1 + op2);
        else if (token == "-")
          myStack.push(op1 - op2);
        else if (token == "*")
          myStack.push(op1 * op2);
        else
          myStack.push(op1 / op2);
      } else {
        myStack.push(stoi(token.c_str()));
      }
    }

    return myStack.top();
  }
};