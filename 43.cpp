#include <string>
using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    vector<int> res(n1 + n2, 0);

    for (int i = n1 - 1; i >= 0; i--) {
      for (int j = n2 - 1; j >= 0; j--) {
        int mul1 = num1[i] - '0', mul2 = num2[j] - '0';
        int mul = mul1 * mul2;
        int pos1 = res[i + j], pos2 = res[i + j + 1];
        int sum = pos2 + mul;
        res[i + j] += sum / 10;
        res[i + j + 1] = sum % 10;
      }
    }

    string s;
    for (auto x : res) {
      if (x == 0 && s.length() > 0)
        s += "0";
      else if (x != 0)
        s += (x + '0');
    }

    return s.length() ? s : "0";
  }
};