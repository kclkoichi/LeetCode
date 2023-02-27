#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  // N, E, S, W
  void dfs(vector<vector<char>>& board, string& word, int i, int j, int indexWord, vector<vector<bool>>& visited, bool& found) {
    if(word[indexWord] != board[i][j]) return;
    if(indexWord == word.size() - 1) { found = true; return; }
    visited[i][j] = true;
    if(j > 0 && !visited[i][j-1]) dfs(board, word, i, j-1, indexWord+1, visited, found); // N
    if(i < board.size() - 1 && !visited[i+1][j]) dfs(board, word, i+1, j, indexWord+1, visited, found); // E
    if(j < board[i].size() - 1 && !visited[i][j+1]) dfs(board, word, i, j+1, indexWord+1, visited, found); // S
    if(i > 0 && !visited[i-1][j]) dfs(board, word, i-1, j, indexWord+1, visited, found); // W
    visited[i][j] = false;
  }

  bool exist(vector<vector<char>>& board, string word) {
    vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size()));
    bool found = false;
    for(int i = 0; i < board.size(); i++) {
      for(int j = 0; j < board[i].size(); j++) {
        // if(word[0] == board[i][j]) 
        visited[i][j] = true;
        dfs(board, word, i, j, 0, visited, found);
        visited[i][j] = false;
        if(found) return true;
      }
    }
    return found;
  }
};