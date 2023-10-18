// 128. Longest Consecutive Sequence
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    set<int> s;
    for (const int &num : nums) {
      s.insert(num);
    }
    int max = 0;
    for (const int &num : s) {
      if (s.find(num - 1) == s.end()) {
        int count = 1;
        while (s.find(num + count) != s.end()) {
          count++;
        }
        max = max > count ? max : count;
      }
    }
    return max;
  }
};