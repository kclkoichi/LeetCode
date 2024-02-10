#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int dfs(vector<int>& coins, int target, unordered_map<int, int>& memo) {
    if(memo.find(target) != memo.end()) return memo[target];
    if(target == 0) return 0;
    if(target < 0) return -1; // cannot reach
    int coinsNeeded = INT_MAX;
    for(int coin: coins) {
      int tmp = dfs(coins, target - coin, memo);
      if(tmp == -1) continue; // could not reach target
      coinsNeeded = min(coinsNeeded, 1 + tmp);
    }
    coinsNeeded = coinsNeeded == INT_MAX ? -1 : coinsNeeded;
    memo[target] = coinsNeeded;
    return coinsNeeded;
  }


  int coinChange(vector<int>& coins, int amount) {
    unordered_map<int, int> memo;
    return dfs(coins, amount, memo);
  }
};