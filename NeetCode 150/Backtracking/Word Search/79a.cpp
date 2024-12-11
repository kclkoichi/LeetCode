#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// Just easier with recursion (backtracking)...
// Seems like no solution does it iteratively
class Solution {
public:
    vector<vector<bool>> vis;

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        if(word[index] != board[i][j]) return false;
        if(vis[i][j]) return false;
        vis[i][j] = true;
        if(index == word.size() - 1) return true;
        for(auto [dx, dy]: dirs) {
            if(!(i+dx >= 0 && i+dx < board.size() && j+dy >= 0 && j+dy < board[0].size())) continue;
            if(dfs(board, word, i+dx, j+dy, index+1)) return true;
        }
        vis[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {       
        vis = vector<vector<bool>>(board.size(), vector<bool>(board[0].size()));
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] != word[0]) continue;
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};
