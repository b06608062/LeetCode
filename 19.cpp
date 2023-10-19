// 19. Remove Nth Node From End of List
#include <stack>
#include <vector>
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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    vector<ListNode *> v;
    ListNode *p = head;
    while (p != nullptr) {
      v.push_back(p);
      p = p->next;
    }

    int len = v.size();
    if (n == len)
      head = head->next;
    else if (n == 1)
      v[len - 2]->next = nullptr;
    else
      v[v.size() - n - 1]->next = v[v.size() - n + 1];

    return head;
  }
};