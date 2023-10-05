#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
  vector<vector<int>> getValid(int r, int c, int k, int step, int maxR, int maxC) {
    vector<vector<int>> res;
    if(r - 1 >= 0) res.push_back({r-1, c, k, step+1});
    if(r + 1 < maxR) res.push_back({r+1, c, k, step+1});
    if(c - 1 >= 0) res.push_back({r, c-1, k, step+1});
    if(c + 1 < maxC) res.push_back({r, c+1, k, step+1});
    return res;
  }

  int shortestPath(vector<vector<int>>& grid, int k) {
    int rNum = grid.size();
    int cNum = grid[0].size();

    unordered_map<int, unordered_map<int, int>> visited; // r,c,remaining k
    
    queue<vector<int>> q;
    q.push({0,0,k,0}); // r,c,remaining k, step
    while(!q.empty()) {
      vector<int> cur = q.front(); q.pop();
      // goal
      if(cur[0] == rNum - 1 && cur[1] == cNum - 1) return cur[3];
      // wall
      if(grid[cur[0]][cur[1]] == 1) {
        cur[2]--;
        if(cur[2] < 0) continue;
      }
      if(visited[cur[0]].find(cur[1]) == visited[cur[0]].end()) {
        // not visited yet
        visited[cur[0]][cur[1]] = cur[2];
      } else if(visited[cur[0]][cur[1]] >= cur[2]) {
        // visited already with more remaining steps
        continue;
      }
      // push valid neighbours
      for(vector<int> v : getValid(cur[0], cur[1], cur[2], cur[3], rNum, cNum)) q.push(v);
    }
    return -1;
  }
};