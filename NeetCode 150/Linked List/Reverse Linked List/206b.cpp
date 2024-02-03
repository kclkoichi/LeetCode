struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    // edge case
    if(head == nullptr) return head;
    ListNode* prev = nullptr;
    while(head != nullptr) {
      ListNode* tmpNext = head->next;
      // reversing
      head->next = prev;
      // moving
      prev = head;
      head = tmpNext;
    }
    return prev;
  }
};
