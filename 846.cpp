#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  bool isNStraightHand(vector<int> &hand, int groupSize) {
    if (hand.size() % groupSize != 0)
      return false;
    map<int, int> myMap;
    for (auto a : hand) {
      myMap[a]++;
    }
    while (!myMap.empty()) {
      int minCard = (*myMap.begin()).first;
      for (int i = minCard; i < minCard + groupSize; i++) {
        if (myMap.find(i) == myMap.end())
          return false;
        if (--myMap[i] == 0) {
          myMap.erase(i);
        };
      }
    }

    return true;
  }
};