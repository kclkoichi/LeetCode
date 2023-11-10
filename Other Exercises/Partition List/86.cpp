#include <queue>
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
  ListNode* partition(ListNode* head, int x) {
    queue<int> smaller;
    queue<int> biggerOrEqual;
    while(head != nullptr) {
      int val = head->val;
      if(val < x) smaller.push(val);
      if(val >= x) biggerOrEqual.push(val);
      head = head->next;
    }

    ListNode* modifying = new ListNode(-1); // dummy head
    ListNode* res = modifying;
    while(!smaller.empty()) {
      modifying->next = new ListNode(smaller.front());
      smaller.pop();
      modifying = modifying->next;
    }
    while(!biggerOrEqual.empty()) {
      modifying->next = new ListNode(biggerOrEqual.front());
      biggerOrEqual.pop();
      modifying = modifying->next;
    }
    return res->next;
  }
};