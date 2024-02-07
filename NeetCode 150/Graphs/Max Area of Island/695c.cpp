#include <vector>
using namespace std;

class Solution {
public:
  int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return 0;
    if(vis[i][j]) return 0;
    if(grid[i][j] == 0) return 0;
    vis[i][j] = true;
    return 1 + dfs(i+1, j, grid, vis) + dfs(i-1, j, grid, vis) + dfs(i, j-1, grid, vis) + dfs(i, j+1, grid, vis);
  }

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;
    vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
    for(int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[0].size(); j++) {
        if(!vis[i][j] && grid[i][j] == 1) {
          maxArea = max(maxArea, dfs(i,j,grid,vis));
        }
      }
    }
    return maxArea;
  }
};