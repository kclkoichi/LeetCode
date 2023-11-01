#include <string>
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
  // stack, dfs(preorder), MLE
  string getPathFromRoot(TreeNode* root, int target, string cur) {
    stack<pair<TreeNode*, string>> s;
    s.push(make_pair(root, ""));
    string path = "";
    while(!s.empty()) {
      auto cur = s.top(); s.pop();
      path = cur.second;
      if(cur.first->val == target) break;
      if(cur.first->right != nullptr) s.push(make_pair(cur.first->right, path + 'R'));
      if(cur.first->left != nullptr) s.push(make_pair(cur.first->left, path + 'L'));
    }
    return path;
  }

  // recursion, dfs(preorder), pass
  bool makePathFromRoot(TreeNode* root, int target, string& cur) {
    if(root->val == target) return true;
    if(root->left) {
      cur += 'L';
      if(makePathFromRoot(root->left, target, cur)) return true;
      cur.pop_back();
    }
    if(root->right) {
      cur += 'R';
      if(makePathFromRoot(root->right, target, cur)) return true;
      cur.pop_back();
    }
    return false;
  }

  string getDirections(TreeNode* root, int startValue, int destValue) {
    string sPath, dPath;
    makePathFromRoot(root, startValue, sPath);
    makePathFromRoot(root, destValue, dPath);

    // find right after latest common ancestor
    int i = 0, j = 0;
    while(i < sPath.length() && j < dPath.length() && sPath[i] == dPath[j]) {
      i++;
      j++;
    }

    string res = "";
    // Everytime we went R or L, we would go U till Latest Common Ancestor
    for(char c : sPath.substr(i, sPath.length() - i))
      if(c == 'R' || c == 'L') res += 'U';
    // From Latest Common Ancestor we go down till dest
    for(char c : dPath.substr(j, dPath.length() - j))
      if(c == 'R' || c == 'L') res += c;
    return res;
  }
};