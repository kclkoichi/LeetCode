#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int, pair<int, int>>> q; // current time, <x, y>
    int orangeCount = 0; // rotten and fresh
    for(int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[0].size(); j++) {
        if(grid[i][j] == 0) continue;
        orangeCount++;
        if(grid[i][j] == 2) q.push(make_pair(0, make_pair(i, j)));
      }
    }

    int time = 0;
    while(!q.empty() && orangeCount != 0) {
      time = q.front().first;
      int x = q.front().second.first;
      int y = q.front().second.second;
      q.pop();

      if(grid[x][y] == 1 || time == 0) {
        // Make orange rotten
        grid[x][y] = 2;
        orangeCount--;

        // Put into queue next fresh oranges 
        if(x-1 >= 0 && grid[x-1][y] == 1) q.push(make_pair(time+1, make_pair(x-1, y)));
        if(y-1 >= 0 && grid[x][y-1] == 1) q.push(make_pair(time+1, make_pair(x, y-1)));
        if(x+1 <= grid.size()-1 && grid[x+1][y] == 1) q.push(make_pair(time+1, make_pair(x+1, y)));
        if(y+1 <= grid[0].size()-1 && grid[x][y+1] == 1) q.push(make_pair(time+1, make_pair(x, y+1)));
      }
    }

    return orangeCount != 0 ? -1 : time;
  }
};
