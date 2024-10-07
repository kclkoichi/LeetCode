#include <vector>
#include <queue>
using namespace std;

// One DFS, one big BFS
class Solution {
public:
  // color island of 1s to 2s
  void colorDfs(vector<vector<int>>& grid, int i, int j, queue<vector<int>>& q) {
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return; // out of bound
    if(grid[i][j] != 1) return;
    q.push({i, j, -1});
    grid[i][j] = 2;
    colorDfs(grid, i-1, j, q);
    colorDfs(grid, i+1, j, q);
    colorDfs(grid, i, j-1, q);
    colorDfs(grid, i, j+1, q);
  }

  int shortestBridge(vector<vector<int>>& grid) {
    bool finish = false;
    queue<vector<int>> q; // i, j, distance
    // Color first island to 2s
    for(int i = 0; i < grid.size() && !finish; i++) {
      for(int j = 0; j < grid[0].size() && !finish; j++) {
        if(grid[i][j] == 1) {
          colorDfs(grid, i, j, q);
          finish = true;
          break;
        }
      }
    }

    // BFS
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    while(!q.empty()) {
      int x = q.front()[0];
      int y = q.front()[1];
      int dist = q.front()[2];
      q.pop();

      // out of bound
      if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) continue;
      // same island, will just get worse than if started form here (except start position)
      if(dist != -1 && grid[x][y] == 2) continue;
      // already visited
      if(visited[x][y] == true) continue;

      if(grid[x][y] == 1) {
        // found other island
        return dist;
      }
      visited[x][y] = true;
      q.push({x-1, y, dist+1});
      q.push({x+1, y, dist+1});
      q.push({x, y-1, dist+1});
      q.push({x, y+1, dist+1});
    }

    return -1; // couldn't find path...
  }
};

// One DFS, BFS from every cell of island
class Solution {
public:
  // color island of 1s to 2s
  void colorDfs(vector<vector<int>>& grid, int i, int j, vector<pair<int, int>>& island2positions) {
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return; // out of bound
    if(grid[i][j] != 1) return;
    island2positions.push_back(make_pair(i, j));
    grid[i][j] = 2;
    colorDfs(grid, i-1, j, island2positions);
    colorDfs(grid, i+1, j, island2positions);
    colorDfs(grid, i, j-1, island2positions);
    colorDfs(grid, i, j+1, island2positions);
  }

  int shortestBridge(vector<vector<int>>& grid) {
    bool finish = false;
    vector<pair<int, int>> island2positions;
    // Color first island to 2s
    for(int i = 0; i < grid.size() && !finish; i++) {
      for(int j = 0; j < grid[0].size() && !finish; j++) {
        if(grid[i][j] == 1) {
          colorDfs(grid, i, j, island2positions);
          finish = true;
          break;
        }
      }
    }

    int minDist = INT_MAX;
    // find shortest distance from island of 2s to island of 1s
    for(auto [i, j]: island2positions) {
      if(minDist == 1) return minDist;
      // BFS
      bool stop = false;
      vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
      // { x, y, distance from where we started }
      queue<vector<int>> q;
      q.push({i, j, -1});
      while(!q.empty() && !stop) {
        int x = q.front()[0];
        int y = q.front()[1];
        int dist = q.front()[2];
        q.pop();
        if(dist >= minDist) continue; // we already found better
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) continue; // out of bound
        if(dist != -1 && grid[x][y] == 2) continue; // same island, will just get worse than if started form here (except start position)
        if(visited[x][y] == true) continue; // already visited

        if(grid[x][y] == 1) {
          // found other island
          stop = true;
          minDist = min(minDist, dist);
        }
        visited[x][y] = true;
        q.push({x-1, y, dist+1});
        q.push({x+1, y, dist+1});
        q.push({x, y-1, dist+1});
        q.push({x, y+1, dist+1});
      }
    }

    return minDist;
  }
};