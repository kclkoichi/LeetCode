#include <vector>
#include <queue>
using namespace std;

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
  // BFS from right to left
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    int height = -1;
    queue<pair<int, TreeNode*>> q;
    q.push(make_pair(0, root));
    while(!q.empty()) {
      int curHeight = q.front().first;
      TreeNode* curNode = q.front().second;
      q.pop();

      if(curNode == nullptr) continue;

      if(height < curHeight) {
        height = curHeight;
        res.push_back(curNode->val);
      }

      q.push(make_pair(curHeight+1, curNode->right));
      q.push(make_pair(curHeight+1, curNode->left));
    }

    return res;
  }
};
