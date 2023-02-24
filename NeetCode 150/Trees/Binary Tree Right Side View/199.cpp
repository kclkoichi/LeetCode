#include <vector>
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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> sol;
    if(root == nullptr) return sol; // edge case
    stack<pair<int,TreeNode*>> s; // depth,node
    s.push(make_pair(0, root));
    while(!s.empty()) {
      int curDepth = s.top().first;
      TreeNode* curNode = s.top().second;
      s.pop();
      // need to cast to int because CANNOT COMPARE SIGNED and UNSIGNED in C++
      if(curDepth > (int) sol.size() - 1) sol.push_back(curNode->val);
      if(curNode->left != nullptr) s.push(make_pair(curDepth+1, curNode->left));
      if(curNode->right != nullptr) s.push(make_pair(curDepth+1, curNode->right)); // we push right later because we want right to be treated first
    }
    return sol;
  }
};