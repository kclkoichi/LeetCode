#include <limits.h>
#include <vector>
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
  void inorder(TreeNode* root, vector<int>& ordering) {
    if(root == nullptr) return;
    inorder(root->left, ordering);
    ordering.push_back(root->val);
    inorder(root->right, ordering);
  }

  bool isValidBST(TreeNode* root) {
    vector<int> ordering;
    inorder(root, ordering); // make vector of vals visited in order

    // check values in vector are in order (we want strictly positive)
    int prev = ordering[0];
    for(int i = 1; i < ordering.size(); i++) {
      int cur = ordering[i];
      if(cur > prev) {
        prev = cur;
      } else {
        return false;
      }
    }

    return true;
  }
};