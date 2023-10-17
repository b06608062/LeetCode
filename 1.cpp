// 1. Two Sum
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<pair<int, int>> pairs;
    for (int i = 0; i < nums.size(); ++i) {
      pairs.push_back({nums[i], i});
    }

    sort(pairs.begin(), pairs.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           return a.first < b.first;
         });

    int left = 0, right = pairs.size() - 1;
    while (left < right) {
      int sum = pairs[left].first + pairs[right].first;
      if (sum == target) {
        break;
      } else if (sum < target) {
        ++left;
      } else {
        --right;
      }
    }
    return vector<int>({pairs[left].second, pairs[right].second});
  }
};