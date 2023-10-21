// 146. LRU Cache
#include <unordered_map>
using namespace std;

class LRUCache {
public:
  class Node {
  public:
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int key, int val) {
      this->key = key;
      this->val = val;
    }
  };

  Node *head;
  Node *tail;
  unordered_map<int, Node *> cache;
  int cacheSize;

  LRUCache(int capacity) {
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
    cacheSize = capacity;
  }

  void pushFront(int key, int val) {
    Node *tmp = head->next;
    Node *newNode = new Node(key, val);
    newNode->prev = head;
    newNode->next = tmp;
    head->next = newNode;
    tmp->prev = newNode;
  }

  void delNode(Node *target) {
    target->prev->next = target->next;
    target->next->prev = target->prev;
    delete (target);
  }

  int get(int key) {
    auto it = cache.find(key);
    if (it != cache.end()) {
      int val = it->second->val;
      delNode(it->second);
      pushFront(key, val);
      it->second = head->next;
      return val;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    auto it = cache.find(key);
    if (it != cache.end()) {
      delNode(it->second);
      pushFront(key, value);
      it->second = head->next;
    } else {
      if (cache.size() == cacheSize) {
        Node *tmp = tail->prev;
        cache.erase(tmp->key);
        delNode(tmp);
        pushFront(key, value);
        cache[key] = head->next;
      } else {
        pushFront(key, value);
        cache[key] = head->next;
      }
    }
  }
};