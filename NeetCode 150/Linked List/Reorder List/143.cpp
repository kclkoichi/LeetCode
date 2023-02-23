#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  void print(ListNode* head) {
    if(head->next == nullptr) {
      cout << to_string(head->val) << endl;
    } else {
      cout << to_string(head->val) << " ";
      print(head->next);
    }
  }
  int length(ListNode* head, int l) {
    if(head->next == nullptr) return l;
    return length(head->next, l+1);
  }

  void copyList(ListNode* copy, ListNode* head) {
    if(head->next == nullptr) {
      copy->val=head->val;
      return;
    } else {
      copy->next = new ListNode();
      copy->val=head->val;
      copyList(copy->next, head->next);
    }
  }

  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while(cur != nullptr) {
      ListNode* temp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = temp;
    }
    return prev;
  }

  void reorderList(ListNode* head) {
    ListNode* reverseHead = new ListNode(); 
    copyList(reverseHead, head); // works
    reverseHead = reverseList(reverseHead); // works

    // Creation of new list
    ListNode* cur = head;
    ListNode* orderedNext = head;
    ListNode* reverseNext = reverseHead;
    int l = length(head, 1);
    for(int i = 1; i < l; i++) {
      if(i%2==1) {
        // Act on inorder
        orderedNext = orderedNext->next;
        cur->next = reverseNext;
        cur = reverseNext;
      } else {
        // Act on reverse
        reverseNext = reverseNext->next;
        cur->next = orderedNext;
        cur = orderedNext;
      }
      if(i==l-1) cur->next = nullptr; // Last iteration
    }
  }
};

