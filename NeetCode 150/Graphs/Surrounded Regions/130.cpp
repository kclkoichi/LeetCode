#include <vector>
using namespace std;

class Solution {
public:
  void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>> vis, bool& touchBorder) {
    vector<vector<int>> dir {vector<int> {-1, 0}, vector<int> {1, 0}, vector<int> {0, -1}, vector<int> {0, 1}};
    if(touchBorder) return;
    if(i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1) {
      touchBorder = true;
      return;
    }
    if(vis[i][j]) return;
    vis[i][j] = true;
    if(board[i][j] == 'O') {
      for(vector<int> d : dir) {
        dfs(i+d[0], j+d[1], board, vis, touchBorder);
        if(touchBorder) return;
      }
    }
    // if(!touchBorder) board[i][j] = 'X';
  }

  void solve(vector<vector<char>>& board) {
    vector<vector<bool>> vis;
    for(int i = 0; i < board.size(); i++) {
      for(int j = 0; j < board[0].size(); j++) {
        vis = vector(board.size(), vector<bool>(board[0].size()));
        bool touchBorder = false;
        dfs(i, j, board, vis, touchBorder);
        if(touchBorder) board[i][j] = 'O'; else board[i][j] = 'X';
      }
    }
  }
};