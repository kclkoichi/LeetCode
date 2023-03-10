#include <vector>
#include <algorithm>
#include <random>
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
  vector<int> v;
  int i = 0;
  int size = 0;
  // auto rd = std::random_device {}; 
  // auto rng = default_random_engine { rd() };

  Solution(ListNode* head) {
    ListNode* cur = head;
    while(cur != nullptr) {
      v.push_back(cur->val);
      cur = cur->next;
      size++;
    }
  }
  
  int getRandom() {
    int r = random() % size;
    return v[r];
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */