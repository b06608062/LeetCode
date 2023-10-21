// 208. Implement Trie (Prefix Tree)
#include <string>
using namespace std;

class Trie {
public:
  class TrieNode {
  public:
    bool isWord;

    TrieNode *children[26];
    TrieNode() {
      isWord = false;
      for (int i = 0; i < 26; ++i) {
        children[i] = nullptr;
      }
    }
  };

  TrieNode *root;

  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode *p = root;
    for (auto c : word) {
      int next = c - 'a';
      if (p->children[next] == nullptr) {
        p->children[next] = new TrieNode();
      }
      p = p->children[next];
    }
    p->isWord = true;
  }

  bool search(string word) {
    TrieNode *p = root;
    for (auto c : word) {
      int next = c - 'a';
      if (p->children[next] == nullptr)
        return false;
      p = p->children[next];
    }

    return p->isWord;
  }

  bool startsWith(string prefix) {
    TrieNode *p = root;
    for (auto c : prefix) {
      int next = c - 'a';
      if (p->children[next] == nullptr)
        return false;
      p = p->children[next];
    }

    return true;
  }
};
