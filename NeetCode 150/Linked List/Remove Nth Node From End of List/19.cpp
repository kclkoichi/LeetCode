struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  int size(ListNode* head, int s) {
    if(head->next == nullptr) return s+1;
    return size(head->next, s+1);
  }

  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int length = size(head,0);
    int del = length-n;
    if(del == 0) return head->next;
    
    ListNode* prev = nullptr;
    ListNode* cur = head;
    for(int i = 0; i < del; i++) {
      prev = cur;
      cur = cur->next;
    }
    prev->next = cur->next;
    // cur->next = nullptr;

    return head;
  }
};