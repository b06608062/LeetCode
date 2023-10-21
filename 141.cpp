// 141. Linked List Cycle
#include <unordered_set>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head) {
      ListNode *p = head;
      unordered_set<ListNode *> visited;
      while (p) {
        visited.insert(p);
        if (visited.find(p->next) != visited.end()) {
          return true;
        }
        p = p->next;
      }
    }

    return false;
  }
};