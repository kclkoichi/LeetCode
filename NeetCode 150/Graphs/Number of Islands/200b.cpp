#include <vector>
using namespace std;

class Solution {
public:
  void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
    if(vis[i][j]) return;
    if(grid[i][j] == '0') return;
    vis[i][j] = true;
    dfs(i+1, j, grid, vis);
    dfs(i-1, j, grid, vis);
    dfs(i, j-1, grid, vis);
    dfs(i, j+1, grid, vis);
  }

  int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
    for(int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[0].size(); j++) {
        if(grid[i][j] == '1' && !vis[i][j]) {
          count++;
          dfs(i, j, grid, vis);
        }
      }
    }
    return count;
  }
};