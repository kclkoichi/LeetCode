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
  bool inorder(TreeNode* root, int& count, int& res) {
    if(root == nullptr) return false;

    if(inorder(root->left, count, res)) return true;

    count--;
    if(count == 0) {
      res = root->val;
      return true;
    }

    if(inorder(root->right, count, res)) return true;

    return false;
  }

  int kthSmallest(TreeNode* root, int k) {
    int res = -1;
    inorder(root, k, res);
    return res;
  }
};
