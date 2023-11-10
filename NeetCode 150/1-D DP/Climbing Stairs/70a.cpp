#include <vector>
using namespace std;

class Solution {
public:
  int dfs(int target, vector<int>& memo) {
    if(memo[target] != -1) return memo[target];
    int ways = dfs(target-1, memo) + dfs(target-2, memo);
    memo[target] = ways;
    return memo[target];
  }

  int climbStairs(int n) {
    // n+2 to deal with n=1
    vector<int> memo(n+2, -1); // number of ways to get to step n 
    memo[1] = 1; // 1
    memo[2] = 2; // 1+1 or 2
    return dfs(n, memo);
  }
};