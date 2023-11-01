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

  bool notHaveChildren(TreeNode* root) {
    return root->left == nullptr && root->right == nullptr;
  }

  // dfs
  vector<int> removeLeaves(TreeNode*& root) {
    vector<int> leaves = vector<int>();
    if(notHaveChildren(root)) {
      leaves.push_back(root->val);
      root = nullptr;
    } else {
      vector<int> toAdd;
      if(root->left != nullptr) {
        vector<int> leftLeaves = removeLeaves(root->left);
        toAdd.insert(toAdd.end(), leftLeaves.begin(), leftLeaves.end());
      }
      if(root->right != nullptr) {
        vector<int> rightLeaves = removeLeaves(root->right);
        toAdd.insert(toAdd.end(), rightLeaves.begin(), rightLeaves.end());
      }
      return toAdd;
    }
    return leaves;
  }

  vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> res;
    while(root != nullptr) {
      res.push_back(removeLeaves(root));
    }
    return res;
  }
};