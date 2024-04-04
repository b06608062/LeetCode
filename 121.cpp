#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int profit = 0;
    int buy = prices[0];
    for (int i = 1; i < prices.size(); i++) {
      int current = prices[i];
      buy = buy < current ? buy : current;
      profit = profit > current - buy ? profit : current - buy;
    }

    return profit;
  }
};