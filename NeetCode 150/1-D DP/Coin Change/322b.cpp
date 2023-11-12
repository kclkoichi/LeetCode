#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // return min necessary coin coun
  int dfs(vector<int>& coins, int target, unordered_map<int, int>& targetToMinCoinCount) {
    if(targetToMinCoinCount.find(target) != targetToMinCoinCount.end()) return targetToMinCoinCount[target];
    if(target < 0) return INT_MAX - 1;
    if(target == 0) return 0;

    int minCoinUsage = INT_MAX - 1;
    for(int coin: coins) {
      minCoinUsage = min(minCoinUsage, 1+dfs(coins, target-coin, targetToMinCoinCount));
    }
    targetToMinCoinCount[target] = minCoinUsage;
    return minCoinUsage;
  }

  int coinChange(vector<int>& coins, int amount) {
    unordered_map<int, int> targetToMinCoinCount;
    int minCoinUsage = dfs(coins, amount, targetToMinCoinCount);
    return minCoinUsage == (INT_MAX - 1) ? -1 : minCoinUsage;
  }
};