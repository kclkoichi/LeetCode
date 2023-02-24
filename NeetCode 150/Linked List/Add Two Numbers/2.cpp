struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* sol = new ListNode(-1); // dummy node
    ListNode* curSol = sol;
    ListNode* cur1 = l1;
    ListNode* cur2 = l2;
    int carryOver = 0;
    while(cur1 != nullptr && cur2 != nullptr) {
      int sum = carryOver + cur1->val + cur2->val;
      carryOver = sum / 10; 
      sum = sum % 10;
      curSol->next = new ListNode(sum);
      curSol = curSol->next;
      cur1 = cur1->next;
      cur2 = cur2->next;
    }
    // Need to add the remaining one
    // Only one of the below while loop can be executed
    ListNode* curRemaining = (cur1 == nullptr ? cur2 : cur1);
    while(curRemaining != nullptr) {
      int sum = carryOver + curRemaining->val;
      carryOver = sum / 10; 
      sum = sum % 10;
      curSol->next = new ListNode(sum);
      curSol = curSol->next;
      curRemaining = curRemaining->next;
    }
    if(carryOver != 0) {
      curSol->next = new ListNode(carryOver);
    }
    return sol->next;
  }
};