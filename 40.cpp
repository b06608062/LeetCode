#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> candidates;
  int length;
  vector<vector<int>> ans;

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    this->candidates = candidates;
    length = candidates.size();
    vector<int> subset;
    helper(subset, 0, target);

    return ans;
  }

  void helper(vector<int> &subset, int begin, int target) {
    if (target < 0) {
      return;
    } else if (target == 0) {
      ans.push_back(subset);
    } else {
      for (int i = begin; i < length; i++) {
        int num = candidates[i];
        if (i != begin && num == candidates[i - 1])
          continue;
        subset.push_back(num);
        helper(subset, i + 1, target - num);
        subset.pop_back();
      }
    }
  }
};