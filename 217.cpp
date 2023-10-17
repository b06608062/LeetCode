// 217. Contains Duplicate
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> numSet;
    for (const int &num : nums) {
      if (!numSet.insert(num).second) {
        return true;
      }
    }
    return false;
  }
};