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
    unordered_map<Node *, Node *> myMap;
    Node *p = head;
    while (p != NULL) {
      myMap[p] = new Node(p->val);
      p = p->next;
    }
    myMap[NULL] = NULL;

    p = head;
    while (p != NULL) {
      myMap[p]->next = myMap[p->next];
      myMap[p]->random = myMap[p->random];
      p = p->next;
    }

    return myMap[head];
  }
};