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

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Trie {
public:
  TrieNode* dummyRoot;

  Trie() {
    dummyRoot = new TrieNode('?');
  }
  
  // O(length of word)
  void insert(string word) {
    TrieNode* cur = dummyRoot;
    for(int i = 0; i < word.size(); i++) {
      bool found = false;
      // O(26) = O(1), because it's the max size of children
      for(int j = 0; j < cur->children.size(); j++) {
        if(word[i] == cur->children[j]->character) {
          found = true;
          cur = cur->children[j];
          break;
        }
      }
      if(!found) {
        cur->children.push_back(new TrieNode(word[i]));
        cur = cur->children[cur->children.size()-1];
      }
      if(i+1==word.size()) cur->toggle();
    }
  }
  
  // O(length of word)
  bool search(string word) {
    TrieNode* cur = dummyRoot;
    for(int i = 0; i < word.size(); i++) {
      bool found = false;
      // O(26) = O(1), because it's the max size of children
      for(int j = 0; j < cur->children.size(); j++) {
        if(word[i] == cur->children[j]->character) {
          found = true;
          cur = cur->children[j];
          break;
        }
      }
      if(!found) return false;
      if(i+1==word.size()) return cur->isEnd;
    }
    cout << "Something wrong happened";
    return false; // should never happen
  }
  
  // O(length of prefix)
  bool startsWith(string prefix) {
    TrieNode* cur = dummyRoot;
    for(int i = 0; i < prefix.size(); i++) {
      bool found = false;
      // O(26) = O(1), because it's the max size of children
      for(int j = 0; j < cur->children.size(); j++) {
        if(prefix[i] == cur->children[j]->character) {
          found = true;
          cur = cur->children[j];
          break;
        }
      }
      if(!found) return false;
    }
    return true;
  }
};