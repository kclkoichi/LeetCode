#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    int remaining = 0;
    queue<vector<int>> q; // x,y,current time
    for(int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[i].size(); j++) {
        if(grid[i][j] == 1) remaining++;
        if(grid[i][j] == 2) q.push({i,j,0});
      }
    }
    if(remaining == 0 && q.empty()) return 0; // no orange to rot

    // bfs
    while(!q.empty()) {
      int x = q.front()[0];
      int y = q.front()[1];
      int curTime = q.front()[2];
      q.pop();

      // check coordinate validity
      if(!(x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size())) continue;

      if(grid[x][y] == 0) continue;
      if(grid[x][y] == 2 && curTime != 0) continue;

      q.push({x-1, y, curTime + 1});
      q.push({x+1, y, curTime + 1});
      q.push({x, y-1, curTime + 1});
      q.push({x, y+1, curTime + 1});

      // Orange to rot
      if(curTime != 0) remaining--;
      if(remaining == 0) return curTime;
      grid[x][y] = 2;
    }

    return -1; // no solution
  }
};