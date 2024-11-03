#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxBefore(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j) {
    int cur = grid[i][j];
    int res = -1;

    if(i-1 >= 0 && cur > grid[i-1][j-1] && dp[i-1][j-1] != -1) res = max(res, dp[i-1][j-1] + 1);
    if(cur > grid[i][j-1] && dp[i][j-1] != -1) res = max(res, dp[i][j-1] + 1); // no check cause start from 2nd col
    if(i+1 < dp.size() && cur > grid[i+1][j-1] && dp[i+1][j-1] != -1) res = max(res, dp[i+1][j-1] + 1);

    return res;
  }

  int maxMoves(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));

    int res = 0;
    // start from second col, go col by col
    for(int j = 1; j < dp[0].size(); j++) {
      for(int i = 0; i < dp.size(); i++) {
        dp[i][j] = maxBefore(grid, dp, i, j);
        res = max(res, dp[i][j]);
      }
    }

    return res;
  }
};
