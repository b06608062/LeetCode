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

  bool search(string word) { return searchDot(word, root, 0); }

  bool searchDot(const string &word, DicNode *p, int index) {
    if (index == word.size())
      return p->isWord;

    char c = word[index];
    if (c == '.') {
      for (auto child : p->children) {
        if (child != nullptr && searchDot(word, child, index + 1))
          return true;
      }
      return false;
    } else {
      int next = c - 'a';
      return p->children[next] != nullptr &&
             searchDot(word, p->children[next], index + 1);
    }
  }
};