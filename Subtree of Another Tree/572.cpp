#include <algorithm>
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
    bool sameTree(TreeNode* a, TreeNode* b) {
      if(a == nullptr || b == nullptr) {
        // Want both nullptr, cannot proceed if only one of them is nullptr
        return a == nullptr && b == nullptr;
      }
      if(a->val == b->val) {
        return sameTree(a->right, b->right) && sameTree(a->left, b->left);
      }
      return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      if(root == nullptr || subRoot == nullptr) return false;
      if(root->val != subRoot->val) {
        return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
      } else {
        if(sameTree(root, subRoot)) return true;
        return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
      }
    }
};