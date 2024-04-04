#include <stack>
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
  void reorderList(ListNode *head) {
    stack<ListNode *> myStack;
    ListNode *p = head;
    int count = 0;
    while (p != nullptr) {
      myStack.push(p);
      count++;
      p = p->next;
    }
    ListNode *next;
    p = head;
    for (int i = 1; i <= count / 2; i++) {
      next = p->next;
      p->next = myStack.top();
      myStack.pop();
      p->next->next = next;
      p = next;
    }
    p->next = nullptr;
  }
};