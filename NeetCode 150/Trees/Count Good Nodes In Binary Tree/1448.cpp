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
  void dfs(TreeNode* root, int& count, int maxUpToNow) {
    if(root == nullptr) return;
    if(root->val >= maxUpToNow) {
      count++;
      maxUpToNow = root->val;
    }
    dfs(root->left, count, maxUpToNow);
    dfs(root->right, count, maxUpToNow);
  }

  int goodNodes(TreeNode* root) {
    int maxUpToNow = root->val;
    int count = 0;
    dfs(root, count, maxUpToNow);
    return count;
  }
};