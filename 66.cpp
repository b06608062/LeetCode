#include <vector>
using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int carry = 1;
    int l = digits.size() - 1;
    for (int i = l; i >= 0; i--) {
      int num = digits[i];
      int sum = num + carry;
      digits[i] = sum % 10;
      carry = sum / 10;
    }
    if (carry) {
      digits.insert(digits.begin(), 1);
    }

    return digits;
  }
};