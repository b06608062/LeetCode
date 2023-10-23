// 133. Clone Graph
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  unordered_map<Node *, Node *> m;
  unordered_set<Node *> s;

  Node *cloneGraph(Node *node) {
    if (!node)
      return nullptr;

    copyNode(node);

    for (auto nodei : s) {
      connectNode(nodei);
    }

    return m[node];
  }

  void copyNode(Node *node) {
    if (!s.insert(node).second)
      return;
    Node *cNode = new Node(node->val);
    m[node] = cNode;
    vector<Node *> neighbors = node->neighbors;
    for (auto neighbor : neighbors) {
      copyNode(neighbor);
    }
  }

  void connectNode(Node *node) {
    vector<Node *> neighbors = node->neighbors;
    Node *cNode = m[node];

    for (auto neighbor : neighbors) {
      cNode->neighbors.push_back(m[neighbor]);
    }
  }
};