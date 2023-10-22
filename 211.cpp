#include <string>
#include <vector>
using namespace std;

class WordDictionary {
public:
  class DicNode {
  public:
    bool isWord;
    vector<DicNode *> children = vector<DicNode *>(26, nullptr);
    DicNode() { isWord = false; }
  };
  DicNode *root;

  WordDictionary() { root = new DicNode(); }

  void addWord(string word) {
    DicNode *p = root;
    for (auto c : word) {
      int next = c - 'a';
      if (p->children[next] == nullptr) {
        p->children[next] = new DicNode();
      }
      p = p->children[next];
    }
    p->isWord = true;
  }

  bool search(string word) { return searchDot(word, this->root); }

  bool searchDot(string word, DicNode *root) {
    if (word.size() == 0)
      return root->isWord;

    DicNode *p = root;
    char c = word[0];
    bool found = false;
    if (c == '.') {
      for (auto child : p->children) {
        if (child == nullptr)
          continue;
        if ((found = searchDot(word.substr(1), child)))
          break;
      }
    } else {
      int next = c - 'a';
      if (p->children[next] == nullptr)
        return false;

      found = searchDot(word.substr(1), p->children[next]);
      p = p->children[next];
    }

    return found;
  }
};