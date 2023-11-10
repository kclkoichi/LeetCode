#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int dfs(int remaining, unordered_map<int, int>& memo, vector<int>& coins) {
    if(remaining < 0) return -1; // no solution
    if(remaining == 0) return 0; // a solution
    if(memo.find(remaining) != memo.end()) return memo[remaining]; // memo
    int minCoinCount = INT_MAX; // not found sol yet
    for(int coin: coins) {
      int coinCount = 1 + dfs(remaining - coin, memo, coins);
      if(coinCount == 0) continue; // not a solution
      minCoinCount = min(minCoinCount, coinCount);
    }
    memo[remaining] = minCoinCount == INT_MAX ? -1 : minCoinCount; // -1 if no solution
    return memo[remaining];
  }

  int coinChange(vector<int>& coins, int amount) {
    unordered_map<int, int> memo; // remaining to min number of coins needed
    int numberOfCoins = dfs(amount, memo, coins);
    return numberOfCoins == INT_MAX ? -1 : numberOfCoins;
  }
};
