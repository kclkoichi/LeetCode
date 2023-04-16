#include <string>
#include <vector>
#include <iostream>
using namespace std;

class TrieNode {
public:
  vector<TrieNode*> children; // max size 26 (alphabet length)
  char character;
  bool isEnd;

  TrieNode(char c) {
    character = c;
    isEnd = false;
  }

  void toggle() {
    isEnd = true;
  }

  void setChar(char c) {
    character = c;
  }

  TrieNode* addChild(char c) {
    children.push_back(new TrieNode(c));
    return children[children.size()-1];
  }

  TrieNode* findChild(char c) {
    for(TrieNode* tn : children) {
      if(tn->character == c) return tn;
    }
    return nullptr; // not found
  }

};

class WordDictionary {
public:
  TrieNode* dummyRoot;
  WordDictionary() {
    dummyRoot = new TrieNode('?');
  }
  
  void addWord(string word) {
    TrieNode* cur = dummyRoot;
    for(int i = 0; i < word.size(); i++) {
      if(cur->findChild(word[i]) != nullptr) {
        cur = cur->findChild(word[i]);
      } else {
        cur = cur->addChild(word[i]);
      }
      if(i+1==word.size()) cur->toggle();
    }
  }

  bool searchRec(string word, int i, TrieNode* cur) {
    // base case
    if(cur == nullptr) return false;
    if(i+1 == word.size()) {
      if(word[i] == '.') {
        bool found = false;
        for(auto a : cur->children) if(a->isEnd) found = true;
        return found;
      } else {
        return (cur->findChild(word[i]) != nullptr) && cur->findChild(word[i])->isEnd;
      }
    }

    if(word[i] == '.') {
      for(auto a : cur->children) {
        if(searchRec(word, i+1, a)) return true;
      }
    } else {
      cur = cur->findChild(word[i]);
      return searchRec(word, i+1, cur);
    }

    return false;
  }
  
  bool search(string word) {
    TrieNode* cur = dummyRoot;
    return searchRec(word, 0, cur);
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */