#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TimeMap {
private:
  unordered_map<string, vector<pair<int, string>>> myMap;

public:
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    myMap[key].push_back({timestamp, value});
  }

  string get(string key, int timestamp) {

    return matcher(myMap[key], timestamp);
  }

  string matcher(vector<pair<int, string>> &v, int &timestamp) {
    int length = v.size();
    int left = 0, right = length - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      int current = v[mid].first;
      if (current == timestamp) {
        return v[mid].second;
      } else if (current < timestamp) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (right == -1)
      return "";

    return v[left - 1].second;
  }
};