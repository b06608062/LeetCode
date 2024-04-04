#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  priority_queue<int, vector<int>, greater<int>> pq;
  int findKthLargest(vector<int> &nums, int k) {
    pq = priority_queue<int, vector<int>, greater<int>>(nums.begin(),
                                                        nums.end());
    while (pq.size() > k)
      pq.pop();

    return pq.top();
  }
};