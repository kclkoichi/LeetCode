struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode* head = new ListNode();
      ListNode* making = head;
      ListNode* ptr1 = list1;
      ListNode* ptr2 = list2;
      while(ptr1 != nullptr && ptr2 != nullptr){
        if(ptr1->val < ptr2->val) {
          making->next = ptr1;
          ptr1 = ptr1->next;
          making = making->next;
        } else {
          // ptr2 > or ==
          making->next = ptr2;
          ptr2 = ptr2->next;
          making = making->next;
        }
      }
      if(ptr1 == nullptr) making->next = ptr2;
      if(ptr2 == nullptr) making->next = ptr1;

      return head->next;
    }
};