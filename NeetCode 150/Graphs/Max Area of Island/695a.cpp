#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
  int dfs(int i, int j, vector<vector<int>>& grid) {
    int count = 0;
    stack<vector<int>> s; // i,j
    s.push({i,j});
    while(!s.empty()) {
      int x = s.top()[0];
      int y = s.top()[1];
      s.pop();
      if(grid[x][y] == 1) {
        count++;
        grid[x][y] = -1; // means we visited this cell of the island
        if(x+1 < grid.size()) s.push({x+1, y});
        if(x-1 >= 0) s.push({x-1, y});
        if(y-1 >= 0) s.push({x, y-1});
        if(y+1 < grid[x].size()) s.push({x, y+1});
      }
    }
    return count;
  }
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int area = 0;
    for(int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[i].size(); j++) {
        if(grid[i][j] == 1) area = max(area, dfs(i,j,grid));
      }
    }
    return area;
  }
};