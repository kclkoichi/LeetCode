struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int size = 0;
    ListNode* counting = head;
    while(counting != nullptr) {
      size++;
      counting = counting->next;
    }

    int toGet = size-n;
    if(toGet == 0) return head->next;
    
    ListNode* prev;
    ListNode* cur = head;
    for(int i = 0; i < toGet; i++) {
      prev = cur;
      cur = cur->next;
    }
    prev->next = cur->next;
    cur = nullptr;
    return head;
  }
};
