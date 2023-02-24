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
      vector<vector<int>> sol;
      if(root == nullptr) return sol; // edge case 
      int lvl = 0;
      queue<pair<TreeNode*, int>> q; // Node and depth lvl
      q.push(make_pair(root, lvl));
      while(!q.empty()) {
        pair<TreeNode*, int> cur = q.front(); q.pop();
        if(cur.second >= sol.size()) {
          sol.push_back(vector<int> { cur.first->val });
        } else {
          sol[cur.second].push_back(cur.first->val);
        }
        // push children to q
        if(cur.first->left) q.push(make_pair(cur.first->left, cur.second+1));
        if(cur.first->right) q.push(make_pair(cur.first->right, cur.second+1));
      }
      return sol;
    }
};