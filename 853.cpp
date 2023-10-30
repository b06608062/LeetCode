// 853. Car Fleet
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    vector<pair<int, int>> cars;
    int length = position.size();
    for (int i = 0; i < length; ++i) {
      cars.push_back({position[i], speed[i]});
    }
    sort(cars.begin(), cars.end(), [](pair<int, int> &a, pair<int, int> &b) {
      return a.first < b.first;
    });
    vector<double> times;
    for (auto &car : cars) {
      times.push_back((double)(target - car.first) / (double)car.second);
    }
    int count = 1;
    double fleet = times[length - 1];
    for (int i = length - 2; i >= 0; --i) {
      if (times[i] > fleet) {
        count++;
        fleet = times[i];
      }
    }

    return count;
  }
};