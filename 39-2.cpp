#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> ans;
  vector<int> candidates;
  int target;

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    this->candidates = candidates;
    this->target = target;
    vector<int> subset;
    helper(subset, 0, 0);

    return ans;
  }

  void helper(vector<int> &subset, int begin, int sum) {
    if (sum > target || begin == candidates.size()) {
      return;
    } else if (sum == target) {
      ans.push_back(subset);
    } else {
      for (int i = begin; i < candidates.size(); i++) {
        subset.push_back(candidates[i]);
        helper(subset, i, sum + candidates[i]);
        subset.pop_back();
      }
    }
  }
};