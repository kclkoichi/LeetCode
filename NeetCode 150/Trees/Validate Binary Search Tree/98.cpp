#include <limits.h>

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
  bool inorderTraversal(TreeNode* root, long long& maxUpToNow) {
    if(root == nullptr) return true; // if leaf
    bool ret = true;
    ret &= inorderTraversal(root->left, maxUpToNow);
    if(root->val > maxUpToNow) {
      maxUpToNow = root->val;
    } else {
      ret = false;
    }
    ret &= inorderTraversal(root->right, maxUpToNow);
    return ret;
  }

  // A tree is a BST iff its inorder traversal is in order
  bool isValidBST(TreeNode* root) {
    long long maxUpToNow = LLONG_MIN;
    return inorderTraversal(root, maxUpToNow);
  }
};