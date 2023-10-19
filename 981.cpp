// 981. Time Based Key-Value Store
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TimeMap {
private:
  unordered_map<string, vector<pair<int, int>>> m;
  vector<string> valueBox;
  int count;

public:
  TimeMap() { count = 0; }

  void set(string key, string value, int timestamp) {
    m[key].push_back({timestamp, count++});
    valueBox.push_back(value);
  }

  string get(string key, int timestamp) {
    int index = matcher(m[key], timestamp);
    return index == -1 ? "" : valueBox[index];
  }

  int matcher(vector<pair<int, int>> &v, int &timestamp) {
    int length = v.size();
    int left = 0, right = length - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
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
      return -1;
    return v[left - 1].second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */