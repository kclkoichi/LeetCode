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
  // Total number of nodes, sum, good nodes
  vector<int> recursion(TreeNode* root) {
    if(root == nullptr) return {0, 0, 0};

    vector<int> leftData = recursion(root->left);
    vector<int> rightData = recursion(root->right);

    int nodeCount = leftData[0]+rightData[0]+1;
    int sum = leftData[1]+rightData[1]+root->val;

    int isGoodNode = (int)(sum/nodeCount) == root->val;
    int goodNodeCount = leftData[2]+rightData[2]+isGoodNode;
    return {nodeCount, sum, goodNodeCount};
  }

  int averageOfSubtree(TreeNode* root) {
    return recursion(root)[2];
  }
};
