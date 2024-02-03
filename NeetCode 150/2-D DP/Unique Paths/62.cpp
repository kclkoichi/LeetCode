#include <vector>
using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp = vector<vector<int>>(m+1, vector<int>(n+1));
    dp[m-1][n-1] = 1; // one solution at goal
    for(int i = m - 1; i >= 0; i--) {
      for(int j = n - 1; j >= 0; j--) {
        if(i == m-1 && j == n-1) continue;
        dp[i][j] = dp[i+1][j] + dp[i][j+1]; // right and down
      }
    }
    return dp[0][0];
  }
};