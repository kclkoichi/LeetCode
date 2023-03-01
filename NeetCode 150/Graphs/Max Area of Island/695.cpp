#include <vector>
using namespace std;

class Solution {
public:
  void visit(vector<vector<int>>& grid, int i, int j, int& count) {
    if(i < 0 || i > grid.size() - 1 || j < 0 || j > grid[i].size() - 1) return; // out of bounds
    if(grid[i][j] == 0) return; // not island
    grid[i][j] = 0;
    count++;
    visit(grid, i, j-1, count);
    visit(grid, i+1, j, count);
    visit(grid, i, j+1, count);
    visit(grid, i-1, j, count);
  }

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxSize = 0; 
    for(int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[i].size(); j++) {
        int count = 0;
        visit(grid, i, j, count);
        if(maxSize < count) maxSize = count;
      }
    }
    return maxSize;
  }
};