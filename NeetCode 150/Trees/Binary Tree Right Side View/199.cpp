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
  void dfsRight(TreeNode* root, int depth, vector<int>& sol) {
    if(root == nullptr) return;
    if(depth > (int) sol.size() - 1) sol.push_back(root->val);
    dfsRight(root->right, depth+1, sol);
    dfsRight(root->left, depth+1, sol);
  }

  // Use recursive stack instead of real stack
  vector<int> rightSideView(TreeNode* root) {
    vector<int> sol;
    dfsRight(root, 0, sol);
    return sol;
  }
};