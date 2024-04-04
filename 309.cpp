#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int buy = INT_MIN, sell = 0, cool = 0;
    for (auto a : prices) {
      int prev_sell = sell;
      sell = buy + a;
      buy = max(buy, cool - a);
      cool = max(cool, prev_sell);
    }

    return max(sell, cool);
  }
};