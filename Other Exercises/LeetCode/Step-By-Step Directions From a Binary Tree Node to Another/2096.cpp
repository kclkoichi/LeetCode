#include <string>
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
  string getPathFromRootBST(TreeNode* root, int target, string cur) {
    cur += to_string(root->val);
    if(root->val == target) return cur;
    if(target > root->val) 
      return getPathFromRoot(root->right, target, cur + 'R');
    else 
      return getPathFromRoot(root->left, target, cur + 'L');
  }

  string getPathFromRoot(TreeNode* root, int target, string cur) {
    queue<pair<TreeNode*, string>> q;
    q.push(make_pair(root, ""));
    string path = "";
    while(!q.empty()) {
      auto cur = q.front(); q.pop();
      path = cur.second + to_string(cur.first->val);
      if(cur.first->val == target) break;
      if(cur.first->right != nullptr) q.push(make_pair(cur.first->right, path + 'R'));
      if(cur.first->left != nullptr) q.push(make_pair(cur.first->left, path + 'L'));
    }
    return path;
  }

  string getDirections(TreeNode* root, int startValue, int destValue) {
    // bfs (because not a BST...)
    string sPath = getPathFromRoot(root, startValue, "");
    string dPath =  getPathFromRoot(root, destValue, "");

    // find right after latest common ancestor
    int i = 0, j = 0;
    while(sPath[i] == dPath[j]) {
      i++;
      j++;
    }

    string res = "";
    // Everytime we went R or L, we would go U till Latest Common Ancestor
    for(char c : sPath.substr(i, sPath.length()-i))
      if(c == 'R' || c == 'L') res += 'U';
    // From Latest Common Ancestor we go down till dest
    for(char c : dPath.substr(j, dPath.length() - j))
      if(c == 'R' || c == 'L') res += c;
    return res;
  }
};