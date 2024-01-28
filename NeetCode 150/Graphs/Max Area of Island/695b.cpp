#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return 0; // out of bounds
    if(grid[i][j] == 0) return 0;
    if(visited[i][j]) return 0;

    // Unvisited part of island
    int size = 1;
    visited[i][j] = true;
    size += dfs(i-1, j, grid, visited);
    size += dfs(i, j-1, grid, visited);
    size += dfs(i+1, j, grid, visited);
    size += dfs(i, j+1, grid, visited);
    return size;
  }

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxSize = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));

    for(int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[0].size(); j++) {
        if(grid[i][j] == 1) {
          maxSize = max(maxSize, dfs(i, j, grid, visited));
        }
      }
    }

    return maxSize;
  }
};