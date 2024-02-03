#include <stack>
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
  bool isGoodNode(TreeNode* root) {
    int nodeCount = 0;
    int sum = 0;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
      TreeNode* cur = st.top(); st.pop();
      if(cur == nullptr) continue;
      nodeCount++;
      sum+=cur->val;
      st.push(cur->right);
      st.push(cur->left);
    }
    return (int)(sum / nodeCount) == root->val;
  }

  int averageOfSubtree(TreeNode* root) {
    if(root == nullptr) return 0;
    return averageOfSubtree(root->left) + averageOfSubtree(root->right) + isGoodNode(root);
  }
};
