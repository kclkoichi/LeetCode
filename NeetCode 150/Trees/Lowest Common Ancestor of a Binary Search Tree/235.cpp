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
  void search(int v, TreeNode* root, unordered_set<TreeNode*> &path) {
    path.insert(root);
    if(v == root->val) return;
    if(v > root->val) {
      search(v, root->right, path);
    } else {
      search(v, root->left, path);
    }
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    unordered_set<TreeNode*> path;
    search(p->val, root, path);
    if(q->val == root->val) return root;
    TreeNode* prevAncestor = nullptr;
    TreeNode* cur = root;
    while(true) {
      if(path.find(cur) != path.end()) {
        if(q->val == cur->val) return cur;
        prevAncestor = cur;
        if(q->val > cur->val) {
          cur = cur-> right;
        } else {
          cur = cur-> left;
        }
      } else {
        return prevAncestor;
      }
    }
    return prevAncestor;
  }
};