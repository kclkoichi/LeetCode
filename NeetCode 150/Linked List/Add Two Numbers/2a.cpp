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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* tmp = res;
        bool carry = false;
        while(l1 || l2 || carry) {
            tmp->next = new ListNode();
            tmp = tmp->next;
            int sum = 0;
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            if(carry) sum++;
            
            tmp->val = sum % 10;
            carry = sum / 10; // new carry
        }
        return res->next;
    }
};
