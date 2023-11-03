// 15. 3Sum
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            if(nums[i] > 0) break;
            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                if(left > i + 1 && nums[left] == nums[left - 1]) {
                    left++;
                    continue;
                }
                if(right < n - 1 && nums[right] == nums[right + 1]) {
                    right--;
                    continue;
                }
                int tmp = nums[left] + nums[right];
                if (tmp == target) 
                    res.push_back({nums[i], nums[left++], nums[right--]});
                else if (tmp < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return res;
    }
};