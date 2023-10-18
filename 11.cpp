// 11. Container With Most Water
#include <vector>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int max = 0;
    int left = 0, right = height.size() - 1;
    while (left < right) {
      int area = min(height[left], height[right]) * (right - left);
      max = max > area ? max : area;
      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }

    return max;
  }
};