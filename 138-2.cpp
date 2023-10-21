// 138. Copy List with Random Pointer
#include <unordered_map>
using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (head == NULL)
      return NULL;
    unordered_map<Node *, Node *> m;
    Node *p = head;
    while (p != NULL) {
      m[p] = new Node(p->val);
      p = p->next;
    }
    m[NULL] = NULL;

    p = head;
    while (p != NULL) {
      m[p]->next = m[p->next];
      m[p]->random = m[p->random];
      p = p->next;
    }

    return m[head];
  }
};