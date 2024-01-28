#include <vector>
#include <unordered_map>
using namespace std;

// time: O(amount * number of coins)
// because of cache
class Solution {
public:
  int dfs(int remainder, unordered_map<int, int>& memo, vector<int>& coins) {
    if(remainder < 0) return -1;
    if(memo.find(remainder) != memo.end()) return memo[remainder];

    int minCoinNeeded = -1;
    for(int coin: coins) {
      int temp = dfs(remainder - coin, memo, coins);
      if(temp != -1){
        if(minCoinNeeded == -1) minCoinNeeded = temp + 1;
        minCoinNeeded = min(minCoinNeeded, temp + 1);
      }
    }
    memo[remainder] = minCoinNeeded;
    return minCoinNeeded;
  }

  int coinChange(vector<int>& coins, int amount) {
    if(amount == 0) return 0;
    unordered_map<int, int> memo;
    for(int coin: coins) memo[coin] = 1;
    return dfs(amount, memo, coins);
  }
};
