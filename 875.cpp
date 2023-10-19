// 875. Koko Eating Bananas
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int min = 1, max = *max_element(piles.begin(), piles.end()), k;
    while (min <= max) {
      k = (min + max) / 2;
      double spandTime = 0;
      for (auto pile : piles) {
        spandTime += ceil((double)pile / k);
      }
      if (spandTime <= h) {
        max = k - 1;
      } else {
        min = k + 1;
      }
    }

    return min;
  }
};