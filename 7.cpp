#include <climits> // For INT_MAX and INT_MIN

class Solution {
public:
  int reverse(int x) {
    int res = 0;
    while (x != 0) {
      int tail = x % 10;
      // Check for overflow before updating `res`
      if (res > INT_MAX / 10 || (res == INT_MAX / 10 && tail > 7))
        return 0; // Overflow if res is going to be greater than INT_MAX
      if (res < INT_MIN / 10 || (res == INT_MIN / 10 && tail < -8))
        return 0; // Underflow if res is going to be less than INT_MIN
      res = res * 10 + tail;
      x /= 10;
    }
    return res;
  }
};
