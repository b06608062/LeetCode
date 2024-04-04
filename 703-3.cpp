#include <set>
using namespace std;

class KthLargest {
public:
  multiset<int> mySet;
  int K;
  KthLargest(int k, vector<int> nums) {
    for (int num : nums) {
      mySet.insert(num);
      if (mySet.size() > k)
        mySet.erase(mySet.begin());
    }
    K = k;
  }

  int add(int val) {
    mySet.insert(val);
    if (mySet.size() > K)
      mySet.erase(mySet.begin());

    return *mySet.begin();
  }
};