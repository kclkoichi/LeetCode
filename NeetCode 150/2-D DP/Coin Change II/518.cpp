#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// class Solution {
// public:
//   int dfs(int i, vector<int>& coins, int& target, int sum, unordered_map<int, unordered_map<int, int>>& sumAndIndexToCount) {
//     if(sumAndIndexToCount[sum].find(i) != sumAndIndexToCount[sum].end()) return sumAndIndexToCount[sum][i];
//     if(i == coins.size()) return 0;
//     if(sum > target) return 0;
//     if(sum == target) return 1;

//     int addSameCoinWorld = dfs(i, coins, target, sum+coins[i], sumAndIndexToCount);
//     int skipToNextCoinWorld = dfs(i+1, coins, target, sum, sumAndIndexToCount);
//     sumAndIndexToCount[sum][i] = addSameCoinWorld + skipToNextCoinWorld;
//     return sumAndIndexToCount[sum][i];
//   }

//   int change(int amount, vector<int>& coins) {
//     unordered_map<int, unordered_map<int, int>> sumAndIndexToCount;
//     return dfs(0, coins, amount, 0, sumAndIndexToCount); 
//   }
// };

class Solution {
public:
  // 2d dp
  int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size(), vector<int>(amount+1));
    for(int i = 0; i < coins.size(); i++) dp[i][0] = 1;
    for(int toReach = 1; toReach <= amount; toReach++) {
      for(int j = coins.size() - 1; j >= 0; j--) {
        int curCoin = coins[j];
        int ways = 0;
        if(toReach - curCoin >= 0) {
          ways += dp[j][toReach - curCoin];
        }
        if(j < coins.size() - 1) ways += dp[j + 1][toReach];
        dp[j][toReach] = ways;
      }
    }
    return dp[0][amount];
  }
};