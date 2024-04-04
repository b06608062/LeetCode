#include <algorithm> // for make_heap, push_heap, pop_heap
#include <vector>
using namespace std;

class KthLargest {
public:
  vector<int> heap;
  int k;

  KthLargest(int k, vector<int> &nums) : k(k) {
    for (int num : nums) {
      heap.push_back(num);
      push_heap(heap.begin(), heap.end(), greater<int>());
      if (heap.size() > k) {
        pop_heap(heap.begin(), heap.end(), greater<int>());
        heap.pop_back();
      }
    }
  }

  int add(int val) {
    heap.push_back(val);
    push_heap(heap.begin(), heap.end(), greater<int>());
    if (heap.size() > k) {
      pop_heap(heap.begin(), heap.end(), greater<int>());
      heap.pop_back();
    }

    return heap.front();
  }
};
