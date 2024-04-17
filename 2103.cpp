#include <map>
#include <vector>
using namespace std;

class DetectSquares {
public:
  map<vector<int>, int> myMap;
  DetectSquares() {}

  void add(vector<int> point) { myMap[point] += 1; }

  int count(vector<int> point) {
    int x = point[0], y = point[1];
    int count = 0;
    for (auto pp : myMap) {
      if (pp.first[0] != x && pp.first[1] != y) {
        int xx = pp.first[0], yy = pp.first[1];
        if (abs(x - xx) == abs(y - yy)) {
          if (myMap.find({xx, y}) != myMap.end() &&
              myMap.find({x, yy}) != myMap.end()) {
            count += myMap[{xx, yy}] * myMap[{xx, y}] * myMap[{x, yy}];
          }
        }
      }
    }

    return count;
  }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */