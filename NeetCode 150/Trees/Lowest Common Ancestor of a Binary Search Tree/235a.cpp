#include <list>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  // It's in BST not any tree!
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* lca = root;

    TreeNode* cur = root;
    while(cur != nullptr && 
      ((p->val < cur->val && q->val < cur->val) 
      || (p->val > cur->val && q->val > cur->val)) 
    ) {
      if(p->val < cur->val && q->val < cur->val) {
        cur = cur->left;
      } else {
        cur = cur->right;
      }
      lca = cur;
    }

    return lca;
  }
};
