#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> totalSub;
    vector<int> sub;

    selectNextElement(nums, sub, 0, totalSub);

    return totalSub;
  }

  void selectNextElement(vector<int> &nums, vector<int> &sub, int begin,
                         vector<vector<int>> &totalSub) {
    totalSub.push_back(sub);

    for (int i = begin; i < nums.size(); i++) {
      sub.push_back(nums[i]);
      selectNextElement(nums, sub, i + 1, totalSub);
      sub.pop_back();
    }
  }
};