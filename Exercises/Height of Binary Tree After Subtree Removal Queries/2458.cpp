#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// // we are guaranteed the node to delete is not the root
  // void deleteSubtree(TreeNode*& root, int toDelete) {
  //   if(root->left != nullptr) {
  //     if(root->left->val == toDelete) {
  //       root->left = nullptr; // memory leak. should delete subtree recursively
  //       return;
  //     } else {
  //       deleteSubtree(root->left, toDelete);
  //     }
  //   }
  //   if(root->right != nullptr) {
  //     if(root->right->val == toDelete) {
  //       root->right = nullptr; // memory leak. should delete subtree recursively
  //       return;
  //     } else {
  //       deleteSubtree(root->right, toDelete);
  //     }
  //   }
  // }

// class Solution {
// public:
  // void depth(TreeNode* root, int curDepth, vector<int>& depths, int& nodeCount) {
  //   if(root == nullptr) return;
  //   nodeCount++;
  //   depths[root->val] = curDepth;
  //   depth(root->left, curDepth+1, depths, nodeCount);
  //   depth(root->right, curDepth+1, depths, nodeCount);
  //   return;
  // }

//   unordered_set<int> getChildrens(TreeNode* root, unordered_map<int, unordered_set<int>>& childrens) {
//     if(root == nullptr) return unordered_set<int>();
//     if(root->left == nullptr && root->right == nullptr) {
//       childrens[root->val] = unordered_set<int>();
//     } else {
//       for(int children : getChildrens(root->left, childrens)) childrens[root->val].insert(children);
//       for(int children : getChildrens(root->right, childrens)) childrens[root->val].insert(children);
//     }
//     childrens[root->val].insert(root->val); // Add so when deleted, we also not consider itself
//     return childrens[root->val];
//   }

//   vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
//     int nodeCount = 0;
//     // Map nodes to its depth
//     vector<int> depths(100001); // given constraint
//     depth(root, 0, depths, nodeCount);

//     // Map nodes to its children
//     unordered_map<int, unordered_set<int>> childrens;
//     getChildrens(root, childrens);

//     // BST ordered by depth
//     set<pair<int, int>> bst; // <depth, node>
//      for(int i = 1; i <= nodeCount; i++) {
//       bst.insert(make_pair(depths[i], i));
//     }

//     // Reverse inorder on bst
//     // first node we didn't need to remove has deepest depth, so add to res
//     vector<int> res;
//     for(int query: queries) {
//       unordered_set<int> deleted = childrens[query];
//       for(auto it = bst.rbegin(); it != bst.rend(); ++it) {
//         auto [depth, node] = *it;
//         // if we didn't delete node, we can take its depth
//         if(deleted.find(node) == deleted.end()) {
//           res.push_back(depth);
//           break;
//         }
//       }
//     }
//     return res;
//   }
// };

class Solution {
public:
  int getHeight(TreeNode* root, unordered_map<int, int>& heights) {
    if(root == nullptr) return 0;
    if(root->left == nullptr && root->right == nullptr) {
      heights[root->val] = 0;
      return 0; // height of a leaf is 0
    }
    heights[root->val] = 1 + max(getHeight(root->left, heights), getHeight(root->right, heights)); // any non leaf
    return heights[root->val];
  }

  void getDepths(TreeNode* root, int curDepth, unordered_map<int, int>& depths) {
    if(root == nullptr) return;
    depths[root->val] = curDepth;
    getDepths(root->left, curDepth+1, depths);
    getDepths(root->right, curDepth+1, depths);
    return;
  }
  
  vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
    unordered_map<int, int> heights;
    getHeight(root, heights);

    unordered_map<int, int> depths;
    getDepths(root, 0, depths);

    // for e
    unordered_map<int, set<pair<int,int>>> depthToNodes; // nodes are sorted by height
    for(auto [node, depth] : depths) {
      depthToNodes[depth].insert(make_pair(heights[node], node));
      // We only need to maintain top 2 height nodes
      if(depthToNodes[depth].size() == 3) depthToNodes[depth].erase(depthToNodes[depth].begin()); 
    }

    vector<int> res;

    for(int toDel: queries) {
      int depth = depths[toDel];
      set<pair<int,int>> cousins = depthToNodes[depth];
      if(cousins.size() == 1) {
        // We delete the only one at this depth. 
        // It means we must not have deeper (we would have had cousins otherwise), 
        // So depth-1 is deepest
        res.push_back(depth-1);
        continue;
      }
      // DESC order of height
      for(auto it = cousins.rbegin(); it != cousins.rend(); ++it) {
        auto [height, node] = *it;
        if(node != toDel) {
          res.push_back(depth + height);
          break;
        }
      }
    }

    return res;
  }
};