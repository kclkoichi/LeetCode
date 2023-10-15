#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  // bfs would also work, we end up visiting same 
  void dfs(int i, int j, int prevHeight, vector<vector<int>>& heights, vector<vector<bool>>& reachable) {
    // out of bounds
    if(i < 0 || i >= heights.size()) return;
    if(j < 0 || j >= heights[i].size()) return;

    // if reachable, we already ran dfs from it
    if(reachable[i][j]) return;

    int cur = heights[i][j];
    // we want to go strictly increasing
    if(cur < prevHeight) return;
    reachable[i][j] = true;

    // dfs
    dfs(i+1, j, cur, heights, reachable);
    dfs(i-1, j, cur, heights, reachable);
    dfs(i, j+1, cur, heights, reachable);
    dfs(i, j-1, cur, heights, reachable);
  }

  // Need to reset visited grid for every run of dfs. 
  // Depending of where visiting from, reachable varies.
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<bool>> atlanticReachable = vector<vector<bool>>(heights.size(), vector<bool>(heights[0].size()));
    vector<vector<bool>> pacificReachable = vector<vector<bool>>(heights.size(), vector<bool>(heights[0].size()));

    // left to right = Pacific
    for(int i = 0; i < heights.size(); i++) {
      dfs(i, 0, -1, heights, pacificReachable);
    }

    // top to bottom = Pacific
    for(int i = 0; i < heights[0].size(); i++) {
      dfs(0, i, -1, heights, pacificReachable);
    }

    // right to left = Atlantic
    for(int i = 0; i < heights.size(); i++) {
      dfs(i, heights[i].size() - 1, -1, heights, atlanticReachable);
    }

    // bottom to top = Pacific
    for(int i = 0; i < heights[heights.size() - 1].size(); i++) {
      dfs(heights.size() - 1, i, -1, heights, atlanticReachable);
    }

    // Get correct answers
    vector<vector<int>> ans;
    for(int i = 0; i < heights.size(); i++) {
      for(int j = 0; j < heights[i].size(); j++) {
        if(pacificReachable[i][j] && atlanticReachable[i][j]) ans.push_back({i,j});
      }
    }
    return ans;
  }
};