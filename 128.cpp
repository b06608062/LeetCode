#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> mySet;
    for (const int &num : nums) {
      mySet.insert(num);
    }
    int max = 0;
    for (const int &num : mySet) {
      if (mySet.find(num - 1) == mySet.end()) {
        int count = 1;
        while (mySet.find(num + count) != mySet.end()) {
          count++;
        }
        max = max > count ? max : count;
      }
    }

    return max;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {100, 4, 200, 1, 3, 2};
  cout << solution.longestConsecutive(nums) << endl;

  return 0;
}