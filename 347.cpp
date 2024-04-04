#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> myMap;
    for (const int &val : nums) {
      myMap[val]++;
    }
    vector<pair<int, int>> myVector(myMap.begin(), myMap.end());
    auto compare = [](const pair<int, int> &a, const pair<int, int> &b) {
      return a.second < b.second;
    };
    make_heap(myVector.begin(), myVector.end(), compare);
    vector<int> topK;
    for (int i = 0; i < k; i++) {
      pop_heap(myVector.begin(), myVector.end(), compare);
      topK.push_back(myVector[myVector.size() - 1].first);
      myVector.pop_back();
    }

    return topK;
  }
};