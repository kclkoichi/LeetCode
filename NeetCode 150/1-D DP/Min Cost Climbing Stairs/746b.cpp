#include <vector>
using namespace std;

class Solution {
public:
  int minCost(int i, vector<int>& cost, vector<int>& dp) {
    if(i >= cost.size()) return 0;
    if(dp[i] != INT_MAX) return dp[i];
    dp[i] = cost[i] + min(minCost(i+1, cost, dp), minCost(i+2, cost, dp));
    return dp[i];
  }

  int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size(), INT_MAX);
    return min(minCost(0, cost, dp), minCost(1, cost, dp));
  }
};