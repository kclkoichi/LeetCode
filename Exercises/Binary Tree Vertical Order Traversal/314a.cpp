#include <vector>
#include <queue>
#include <unordered_map>
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
        unordered_map<int, vector<int>> levelToVals;
        int minLevel = INT_MAX;
        int maxLevel = INT_MIN;
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0, root));
        while(!q.empty()) {
            int level = q.front().first;
            TreeNode* node = q.front().second;
            q.pop();
            if(!node) continue;

            minLevel = min(minLevel, level);
            maxLevel = max(maxLevel, level);
            levelToVals[level].push_back(node->val);
            q.push(make_pair(level-1, node->left));
            q.push(make_pair(level+1, node->right));
        }

        vector<vector<int>> res(abs(minLevel) + maxLevel + 1, vector<int>());
        for(int i = minLevel; i <= maxLevel; i++) {
            res[i+abs(minLevel)] = levelToVals[i];
        }
        return res;
    }
};
