#include <stack>
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
  ListNode* reverseListIterative(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while(cur != nullptr) {
      ListNode* after = cur->next;
      cur->next = prev;
      prev = cur;
      cur = after;
    }
    return prev;
  }

  // propagating original last node because it's new head :o
  ListNode* reverseList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
  }
};