#include <vector>
using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < grid.size(); i++) grid[i][grid[i].size()-1] = 1;
    for(int i = 0; i < grid[0].size(); i++) grid[grid.size()-1][i] = 1;
    for(int i = grid.size()-2; i >= 0; i--) {
      for(int j = grid[i].size() - 2; j >= 0; j--) {
        grid[i][j] = grid[i+1][j] + grid[i][j+1];
      }
    }
    return grid[0][0];
  }
};
