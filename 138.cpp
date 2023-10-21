// 138. Copy List with Random Pointer
#include <vector>
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
    Node *p = head;
    Node *q;
    vector<Node *> v1;
    vector<Node *> v2;
    while (p != NULL) {
      v1.push_back(p);
      q = new Node(p->val);
      v2.push_back(q);
      p = p->next;
    }
    v1.push_back(NULL);
    v2.push_back(NULL);

    int size = v1.size();
    for (int i = 0; i < size - 1; ++i) {
      int rIndex =
          distance(v1.begin(), find(v1.begin(), v1.end(), v1[i]->random));
      v2[i]->random = v2[rIndex];
      v2[i]->next = v2[i + 1];
    }
    head = v2[0];

    return head;
  }
};