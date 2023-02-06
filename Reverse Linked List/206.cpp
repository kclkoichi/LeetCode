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
      ListNode* prev = nullptr;
      ListNode* act = head;
      ListNode* next;
      while(act != nullptr) {
        next = act->next;
        act->next = prev;
        prev = act;
        act = next;
      }

      return prev;
    }
};