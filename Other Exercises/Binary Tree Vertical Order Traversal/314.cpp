#include <vector>
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
  vector<vector<int>> verticalOrder(TreeNode* root) {
    int extremeL = 0;
    unordered_map<int, vector<int>> mapper;

    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, 0));

    // BFS
    while(!q.empty()) {
      TreeNode* cur = q.front().first;
      int curLR = q.front().second;
      q.pop();

      if(cur == nullptr) continue;
      extremeL = min(extremeL, curLR);
      q.push(make_pair(cur->left, curLR-1));
      mapper[curLR].push_back(cur->val);
      q.push(make_pair(cur->right, curLR+1));
    }

    vector<vector<int>> res;
    while(mapper.find(extremeL) != mapper.end()) {
      res.push_back(mapper[extremeL++]);
    }
    return res;
  }
};