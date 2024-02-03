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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    int curLevel = 0;

    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, 0));
    vector<int> curV;
    while(!q.empty()) {
      pair<TreeNode*, int> cur = q.front(); q.pop();
      if(cur.first == nullptr) continue;
      // We have node
      if(cur.second == curLevel + 1) {
        curLevel++;
        res.push_back(curV);
        curV = vector<int>();
      }
      curV.push_back(cur.first->val);
      q.push(make_pair(cur.first->left, curLevel+1));
      q.push(make_pair(cur.first->right, curLevel+1));
    }
    if(!curV.empty()) res.push_back(curV);
    return res;
  }
};
