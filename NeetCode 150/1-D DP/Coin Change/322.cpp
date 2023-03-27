#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minimum(int a, int b) {
    if (a!=-1 && b!=-1) return min(a,b);
    else return max(a,b);
  }

  // Normal recursion
  int recursion(int count, vector<int>& coins, int curCoin, int remainder) {
    // base case
    if(remainder == 0) return count;
    if(remainder < 0) return -1;
    if(curCoin < 0) return -1;

    int a = recursion(count+1, coins, curCoin, remainder-coins[curCoin]); // - biggest
    int b = recursion(count, coins, curCoin-1, remainder); // forget about biggest coin
    return minimum(a,b);
  }

  // DP
  int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end());
    // index == amount, dp[index] = min coins to reach amount
    vector<int> dp = vector<int>(amount+1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i < dp.size(); i++) {
      for(int c : coins) {
        if(i == c) { dp[i] = 1; break; }
        if(i - c < 0) break;
        if(dp[i-c] != INT_MAX) dp[i] = min(dp[i], dp[i-c]+1);
      }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};