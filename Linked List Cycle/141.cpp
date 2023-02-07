#include <unordered_set>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // bool hasCycle(ListNode *head) {
    //     unordered_set<ListNode*> seen;
    //     while(head != nullptr) {
    //       if(seen.find(head) != seen.end()) return true;
    //       seen.insert(head);
    //       head = head->next;
    //     }
    //     return false;
    // }

    bool hasCycle(ListNode *head) {
      ListNode* fast = head;
      ListNode* slow = head;
      while(fast != nullptr) {
        fast = fast->next;
        if(fast == slow) return true;
        if(fast == nullptr) return false;
        fast = fast->next;
        if(fast == slow) return true;
        slow = slow->next;
        if(fast == slow) return true;
      }
      return false;
    }
};