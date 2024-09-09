#include <vector>
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
  int length = -1;
  int width = -1;
  vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};

  vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    length = m; 
    width = n;

    vector<vector<int>> res = vector<vector<int>>(m, vector<int>(n, -1));

    int i = 0;
    int j = 0;
    int curDir = 0;
    while(true) {
      if(head == nullptr) break;
      int cur = head->val;

      res[i][j] = cur;
      i += dir[curDir][0];
      j += dir[curDir][1];

      // This works as long as input is correct (listnode length <= size of grid)
      if(i == -1 || i == length || j == -1 || j == width || res[i][j] != -1) {
        // Move back in bound
        i -= dir[curDir][0];
        j -= dir[curDir][1];
        // Change direction
        curDir = (curDir+1) % 4;
        // Move to next slot
        i += dir[curDir][0];
        j += dir[curDir][1];
      }

      head = head->next;
    }

    return res;
  }
};
