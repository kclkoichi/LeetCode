#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // 3x3 square
  bool validSquare(vector<vector<char>>& board, int i, int j) {
    unordered_map<char, int> counter;
    for(int x = i; x < i+3; x++) {
      for(int y = j; y < j+3; y++) {
        char c = board[x][y];
        if(c != '.') counter[c]++;
        if(counter[c] > 1) return false; // more than once same number in row
      }
    }
    return true;
  }

  bool isValidSudoku(vector<vector<char>>& board) {
    // col validation
    for(int i = 0; i < 9; i++) {
      vector<char> row = board[i];
      unordered_map<char, int> counter;
      for(char c : row) {
        if(c != '.') counter[c]++;
        if(counter[c] > 1) return false; // more than once same number in col
      }
    }

    // row validation
    for(int j = 0; j < 9; j++) {
      unordered_map<char, int> counter;
      for(int i = 0; i < 9; i++) {
        char c = board[i][j];
        if(c != '.') counter[c]++;
        if(counter[c] > 1) return false; // more than once same number in row
      }
    }

    // square validation
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
        if(i%3 == 0 && j%3 == 0) {
          if(!validSquare(board, i, j)) return false;
        }
      }
    }

    return true;
  }
};