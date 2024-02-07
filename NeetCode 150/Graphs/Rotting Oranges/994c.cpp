#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    int maxTime = 0;
    int toRot = 0;
    queue<pair<pair<int, int>, int>> q; // <<x,y>, time>
    // Add to queue rotten oranges
    for(int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[0].size(); j++) {
        if(grid[i][j] == 2) q.push(make_pair(make_pair(i,j), 0));
        if(grid[i][j] == 1) toRot++;
      }
    }

    // BFS
    while(!q.empty()) {
      int x = q.front().first.first;
      int y = q.front().first.second;
      int curTime = q.front().second;
      q.pop();
      if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) continue; // Out of bounds
      if(curTime > 0 && grid[x][y] == 2) continue; // Already rotten, but not the original ones
      if(grid[x][y] == 0) continue; // Empty cell
      // Here, we must have fresh orange
      if(curTime > 0) toRot--; // The if condition is to avoid counting the original rotten oranges
      grid[x][y] = 2; // So we rot it
      maxTime = max(maxTime, curTime);
      q.push(make_pair(make_pair(x-1,y), curTime+1));
      q.push(make_pair(make_pair(x,y-1), curTime+1));
      q.push(make_pair(make_pair(x+1,y), curTime+1));
      q.push(make_pair(make_pair(x,y+1), curTime+1));
    }

    return toRot == 0 ? maxTime : -1;
  }
};