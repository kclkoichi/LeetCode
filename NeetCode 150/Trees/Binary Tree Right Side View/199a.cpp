#include <vector>
#include <unordered_set>
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
  void dfs(vector<int>& res, unordered_set<int>& visitedDepth, int depth, TreeNode* root) {
    if(root == nullptr) return;
    // preorder dfs on right first
    if(visitedDepth.find(depth) == visitedDepth.end()) {
        visitedDepth.insert(depth);
        res.push_back(root->val);
    }
    dfs(res, visitedDepth, depth+1, root->right);
    dfs(res, visitedDepth, depth+1, root->left);
  }
  
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    unordered_set<int> visitedDepth;
    dfs(res, visitedDepth, 0, root);
    return res;
  }
};