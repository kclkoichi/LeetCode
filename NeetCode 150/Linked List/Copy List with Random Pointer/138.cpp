#include <stdio.h>
#include <unordered_map>
using namespace std;

class Node {
public:
  int val;
  Node* next;
  Node* random;
  
  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node* copyRandomList(Node* head) {
    if(head == NULL) return NULL; // edge case
    Node* copyHead = new Node(head->val);
    unordered_map<Node*, Node*> mapping; // Mapping original address to copied address
    mapping[head] = copyHead;

    Node* cur = head->next;
    Node* curCopy = copyHead;
    // Filling the 'next'
    while(cur != NULL) {
      Node* newNode = new Node(cur->val);
      curCopy->next = newNode;
      curCopy = curCopy->next;
      mapping[cur] = newNode;
      cur = cur->next;
    }

    cur = head;
    curCopy = copyHead;
    // Filling the 'random'
    while(cur != NULL) {
      curCopy->random = mapping[cur->random];
      cur = cur->next;
      curCopy = curCopy->next;
    }

    return copyHead;
  }
};