#include <algorithm>

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
  int height(TreeNode* root) {
    if(root == nullptr) return 0;
    return std::max(height(root->left), height(root->right)) + 1;
  }
  bool isBalanced(TreeNode* root) {
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)) {
      return true;
    }
    int diff = height(root->left) - height(root->right);
    return (diff == -1 || diff == 0 || diff == 1) && isBalanced(root->left) && isBalanced(root->right);
  }
};