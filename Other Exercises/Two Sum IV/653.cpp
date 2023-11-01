#include <unordered_set>
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
  bool findTarget(TreeNode* root, int k) {
    unordered_set<int> hashSet;
    // bfs
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while(!nodeQueue.empty()) {
      int cur = nodeQueue.front()->val;
      if(hashSet.find(k - cur) != hashSet.end()) return true; // first check if counterpart exists, then insert. Otherwise target 2 with just one 1 fails...
      hashSet.insert(cur);
      if(nodeQueue.front()->left != nullptr) nodeQueue.push(nodeQueue.front()->left);
      if(nodeQueue.front()->right != nullptr) nodeQueue.push(nodeQueue.front()->right);
      nodeQueue.pop();
    }
    return false;
  }
};