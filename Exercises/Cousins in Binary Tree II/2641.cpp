#include <unordered_map>
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
  TreeNode* replaceValueInTree(TreeNode* root) {
    unordered_map<int, int> depthSum;

    queue<pair<int, TreeNode*>> q;
    q.push(make_pair(0, root));

    while(!q.empty()) {
      int depth = q.front().first;
      TreeNode* cur = q.front().second;
      q.pop();

      depthSum[depth] += cur->val;

      if(cur->left) q.push(make_pair(depth + 1, cur->left));
      if(cur->right) q.push(make_pair(depth + 1, cur->right));
    }

    q.push(make_pair(0, root));
    while(!q.empty()) {
      int depth = q.front().first;
      TreeNode* cur = q.front().second;
      q.pop();

      if(!(cur->left || cur->right)) continue;

      int childrenValues = 0;
      if(cur->left) childrenValues += cur->left->val;
      if(cur->right) childrenValues += cur->right->val;
      if(cur->left) cur->left->val = depthSum[depth+1] - childrenValues;
      if(cur->right) cur->right->val = depthSum[depth+1] - childrenValues;
      if(cur->left) q.push(make_pair(depth + 1, cur->left));
      if(cur->right) q.push(make_pair(depth + 1, cur->right));
    }

    root->val = 0; // no cousins
    return root;
  }
};
