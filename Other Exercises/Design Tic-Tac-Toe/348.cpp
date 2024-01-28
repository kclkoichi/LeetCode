#include <vector>
using namespace std;

// move in time O(1)
// Space O(n)
class TicTacToe {
public:
  int size = 0;
  vector<int> rows;
  vector<int> cols;
  int diag = 0;
  int antiDiag = 0;

  TicTacToe(int n) {
    size = n;
    rows = vector<int>(n);
    cols = vector<int>(n);
  }
  
  int move(int row, int col, int player) {
    int toAdd = player == 1 ? 1 : -1;

    rows[row] += toAdd;
    if(rows[row] == size || rows[row] == -size) return player;
    cols[col] += toAdd;
    if(cols[col] == size || cols[col] == -size) return player;

    if(row == col) {
      diag += toAdd;
      if(diag == size || diag == -size) return player;
    }

    if(size - 1 - col == row) {
      antiDiag += toAdd;
      if(antiDiag == size || antiDiag == -size) return player;
    }

    return 0;
  }
};

// Time complexity: O(n^2)
class TicTacToe {
public:
  vector<vector<int>> grid;

  TicTacToe(int n) {
    grid = vector<vector<int>>(n, vector<int>(n, -1));
  }

  bool check(int player) {
    // per row
    for(int i = 0; i < grid.size(); i++) {
      bool valid = true;
      for(int j = 0; j < grid[0].size(); j++) {
        if(grid[i][j] != player) {
          valid = false;
          break;
        }
      }
      if(valid) return true;
    }

    // per col
    for(int j = 0; j < grid[0].size(); j++) {
      bool valid = true;
      for(int i = 0; i < grid.size(); i++) {
        if(grid[i][j] != player) {
          valid = false;
          break;
        }
      }
      if(valid) return true;
    }

    // diagonal 1
    for(int i = 0; i < grid.size(); i++) {
      if(grid[i][i] != player) break;
      if(i == grid.size() - 1) return true;
    }

    // diagonal 2
    int j = 0;
    for(int i = grid.size() - 1; i >= 0; i--) {
      if(grid[i][j] != player) break;
      j++;
      if(i == 0) return true;
    }

    return false;
  }
  
  int move(int row, int col, int player) {
    grid[row][col] = player;
    if(check(player)) return player;
    return 0;
  }
};
