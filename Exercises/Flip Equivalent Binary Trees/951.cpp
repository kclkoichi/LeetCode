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
  bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    // tree 1 node, tree 2 node
    queue<pair<TreeNode*, TreeNode*>> q;
    q.push(make_pair(root1, root2));
    while(!q.empty()) {
      TreeNode* cur1 = q.front().first;
      TreeNode* cur2 = q.front().second;
      q.pop();

      if((cur1 == nullptr) ^ (cur2 == nullptr)) return false;
      if(cur1 == nullptr && cur2 == nullptr) continue;
      if(cur1->val != cur2->val) return false;

      // If both lefts are nodes
      if(cur1->left && cur2->left) {
        if(cur1->left->val != cur2->left->val) {
          TreeNode* tmp = cur2->left;
          cur2->left = cur2->right;
          cur2->right = tmp;
        }
      } else if((cur1->left == nullptr) ^ (cur2->left == nullptr)) {
        // Only one is a node
        TreeNode* tmp = cur2->left;
        cur2->left = cur2->right;
        cur2->right = tmp;
      }

      q.push(make_pair(cur1->left, cur2->left));
      q.push(make_pair(cur1->right, cur2->right));
    }

    return true;
  }
};
