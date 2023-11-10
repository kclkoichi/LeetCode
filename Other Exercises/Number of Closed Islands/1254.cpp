#include <vector>
using namespace std;

// destroying island
class Solution {
public:
  void dfs(int i, int j, vector<vector<int>>& grid, bool& valid) {
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
      valid = false;
      // cannot take shortcut, need to finish marking whole island as visited!!
      return;
    }
    if(grid[i][j] == 1) return;
    grid[i][j] = 1; // change visited island into water, so we won't come back to it
    dfs(i-1, j, grid, valid);
    dfs(i+1, j, grid, valid);
    dfs(i, j-1, grid, valid);
    dfs(i, j+1, grid, valid);
  }

  int closedIsland(vector<vector<int>>& grid) {
    int count = 0;
    for(int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[0].size(); j++) {
        if(grid[i][j] == 0) {
          // if it's land, dfs
          bool valid = true;
          dfs(i, j, grid, valid);
          if(valid) count++;
        }
      }
    }
    return count;
  }
};

class Solution {
public:
  void dfs(int i, int j, vector<vector<int>>& grid, bool& valid, vector<vector<bool>>& visited) {
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
      valid = false;
      // cannot take shortcut, need to finish marking whole island as visited!!
      return;
    }
    if(grid[i][j] == 1) return;
    if(visited[i][j]) return;
    visited[i][j] = true;
    dfs(i-1, j, grid, valid, visited);
    dfs(i+1, j, grid, valid, visited);
    dfs(i, j-1, grid, valid, visited);
    dfs(i, j+1, grid, valid, visited);
  }

  int closedIsland(vector<vector<int>>& grid) {
    int count = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
    for(int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[0].size(); j++) {
        if(!visited[i][j] && grid[i][j] == 0) {
          // if it's land, dfs
          bool valid = true;
          dfs(i, j, grid, valid, visited);
          if(valid) count++;
        }
      }
    }
    return count;
  }
};