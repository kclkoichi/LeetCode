#include <vector>
using namespace std;

class Solution {
public:
  void dfs(int i, int j, vector<vector<char>>& board) {
    if(i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1) return; // out of bounds
    if(board[i][j] == '#' || board[i][j] == 'X') return; 
    if(board[i][j] == 'O') board[i][j] = '#';
    vector<vector<int>> dir {vector<int> {-1, 0}, vector<int> {1, 0}, vector<int> {0, -1}, vector<int> {0, 1}};
    for(vector<int> d : dir) dfs(i+d[0], j+d[1], board);
  }

  // Again, only need to do from the borders (N,E,S,W)...
  void solve(vector<vector<char>>& board) {
    vector<vector<int>> toDFS; // Create vector of all regions to dfs from
    for(int i = 0; i < board.size(); i++) {
      toDFS.push_back(vector<int> { i, 0 }); // W
      toDFS.push_back(vector<int> { i, (int)board[0].size()-1 }); // E
    }
    for(int i = 0; i < board[0].size(); i++) {
      toDFS.push_back(vector<int> { 0, i }); // N
      toDFS.push_back(vector<int> { (int)board.size()-1, i }); // S
    }

    for(vector<int> v : toDFS) {
      dfs(v[0], v[1], board);
    }
    
    // Replace all # with O and all O with X
    for(int i = 0; i < board.size(); i++) {
      for(int j = 0; j < board[0].size(); j++) {
        if(board[i][j] == '#') {
          board[i][j] = 'O';
        } else if(board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }
};