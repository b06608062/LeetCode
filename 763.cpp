#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string s) {
    int l = s.length();
    vector<int> ans;
    int end = 0;
    int count = 0;
    for (int i = 0; i < l; i++) {
      if (count && i == end) {
        ans.push_back(count + 1);
        count = 0;
        end = i + 1;
        continue;
      }
      int right = l - 1;
      while (s[right] != s[i]) {
        right--;
      }
      if (right == i && i == end) {
        ans.push_back(1);
        count = 0;
        end = i + 1;
        continue;
      }
      end = max(end, right);
      count++;
    }

    return ans;
  }
};