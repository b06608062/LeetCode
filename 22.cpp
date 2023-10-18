// 22. Generate Parentheses
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
  vector<string> ans;
  int N;

public:
  vector<string> generateParenthesis(int n) {
    string s = "";
    N = n;
    tryParenthesis(0, 0, s);

    return ans;
  }

  void tryParenthesis(int n1, int n2, string s) {
    if (n1 == N && n2 == N) {
      ans.push_back(s);
    } else {
      if (n1 < N)
        tryParenthesis(n1 + 1, n2, s + "(");
      if (n2 < n1)
        tryParenthesis(n1, n2 + 1, s + ")");
    }
  }
};