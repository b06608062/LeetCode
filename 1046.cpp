// 1046. Last Stone Weight
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  priority_queue<int> pq;
  int lastStoneWeight(vector<int> &stones) {
    pq = priority_queue<int>(stones.begin(), stones.end());
    while (pq.size() > 1) {
      int y = pq.top();
      pq.pop();
      int x = pq.top();
      pq.pop();
      if (x != y)
        pq.push(y - x);
    }

    return pq.empty() ? 0 : pq.top();
  }
};