#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    unordered_map<char, int> myMap;
    for (auto ch : tasks)
      myMap[ch]++;

    int maxFreq = 0;
    for (auto a : myMap)
      maxFreq = max(maxFreq, a.second);

    int result = (maxFreq - 1) * (n + 1);
    int count = 0;
    for (auto a : myMap) {
      if (a.second == maxFreq)
        count++;
    }

    return max(result + count, (int)tasks.size());
  }
};