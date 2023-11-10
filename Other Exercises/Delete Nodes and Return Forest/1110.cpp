#include <vector>
#include <list>
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
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    list<TreeNode*> forest;
    forest.push_back(root);

    for(int searching: to_delete) {
      bool found = false;
      for(auto it = forest.begin(); it != forest.end(); ++it){
        if(found) break;
        TreeNode* cur = (*it);
        // edge case: the top of cur tree is the val we want to delete
        if(cur->val == searching) {
          if(cur->right != nullptr) forest.push_back(cur->right);
          if(cur->left != nullptr) forest.push_back(cur->left);
          forest.erase(it);
          break;
        }

        // dfs
        stack<TreeNode*> s;
        s.push(cur);
        while(!s.empty()) {
          TreeNode* cur = s.top();
          s.pop();
          if(cur->right != nullptr){
            if(cur->right->val == searching) {
              if(cur->right->left != nullptr) forest.push_back(cur->right->left);
              if(cur->right->right != nullptr) forest.push_back(cur->right->right);
              delete cur->right;
              cur->right = nullptr;
              found = true; // exit the for(iterator) loop
              break; // exit the while
            } else {
              s.push(cur->right);
            }
          }
          if(cur->left != nullptr) {
            if(cur->left->val == searching) {
              if(cur->left->left != nullptr) forest.push_back(cur->left->left);
              if(cur->left->right != nullptr) forest.push_back(cur->left->right);
              delete cur->left;
              cur->left = nullptr;
              found = true; // exit the for(iterator) loop
              break; // exit the while
            } else {
              s.push(cur->left);
            }
          }
        }
      }
    }

    vector<TreeNode*> toReturn;
    for(TreeNode* node: forest) {
      if(node != nullptr) toReturn.push_back(node);
    }

    return toReturn;
  }
};