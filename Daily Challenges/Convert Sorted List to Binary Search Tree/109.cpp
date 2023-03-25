#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode* sortedListToBST(ListNode* head) {
    if(head == nullptr) return nullptr;
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    TreeNode* ret = new TreeNode(slow->val);
    ret->right = sortedListToBST(slow);
    slow->next = nullptr;
    ret->left = sortedListToBST(head);
    return ret;
  }
};