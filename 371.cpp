class Solution {
public:
  int getSum(int a, int b) {
    if (!a)
      return b;
    if (!b)
      return a;
    while (b != 0) {
      int carry = a & b;
      a = a ^ b;
      b = carry << 1;
    }

    return a;
  }
};