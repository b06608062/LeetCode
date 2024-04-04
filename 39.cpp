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
    build(subset, 0, 0);

    return ans;
  }

  void build(vector<int> &subset, int i, int sum) {
    if (sum > target || i == candidates.size()) {
      return;
    } else if (sum == target) {
      ans.push_back(subset);
    } else {
      int candidate = candidates[i];
      subset.push_back(candidate);
      build(subset, i, sum + candidate);
      subset.pop_back();
      build(subset, i + 1, sum);
    }
  }
};