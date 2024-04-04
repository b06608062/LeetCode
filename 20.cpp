#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> myStack;
    unordered_map<char, char> myMap = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
    for (auto c : s) {
      if (c == '(' || c == '{' || c == '[') {
        myStack.push(c);
      } else {
        if (myStack.empty() || myMap[myStack.top()] != c)
          return false;
        myStack.pop();
      }
    }
    if (!myStack.empty())
      return false;

    return true;
  }
};