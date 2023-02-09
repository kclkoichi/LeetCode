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

class Solution {
public:
    int height(TreeNode* root) {
        if(root == nullptr) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int diameterRoot = height(root->left) + height(root->right);
        
        return max(max(diameterRoot, diameterOfBinaryTree(root->left)), diameterOfBinaryTree((root->right)));
    }
};