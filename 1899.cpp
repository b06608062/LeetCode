#include <vector>
using namespace std;

class Solution {
public:
  bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
    int a = target[0], b = target[1], c = target[2];
    vector<int> flags(3, 0);
    for (auto triplet : triplets) {
      int aa = triplet[0], bb = triplet[1], cc = triplet[2];
      if (aa == a && bb <= b && cc <= c)
        flags[0] = 1;
      if (aa <= a && bb == b && cc <= c)
        flags[1] = 1;
      if (aa <= a && bb <= b && cc == c)
        flags[2] = 1;
    }

    return flags[0] == 1 && flags[1] == 1 && flags[2] == 1;
  }
};