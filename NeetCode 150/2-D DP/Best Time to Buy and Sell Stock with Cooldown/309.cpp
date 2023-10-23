#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int dfs(int i, bool buying, vector<int>& prices, unordered_map<int, unordered_map<bool, int>>& memo) {
    if(i >= prices.size()) return 0; // max profit we can make out of bounds
    if(memo.find(i) != memo.end() && memo[i].find(buying) != memo[i].end()) {
      return memo[i][buying]; // max profit we can make from this state
    }

    if(buying) {
      int bought = dfs(i+1, false, prices, memo) - prices[i]; // next, bought == selling
      int chilled = dfs(i+1, true, prices, memo); // chilling, so next can still buy
      memo[i][buying] = max(bought, chilled);
    } else {
      // selling
      int sold = dfs(i+2, true, prices, memo) + prices[i]; // next, buying again, must chill next time so i+2
      int chilled = dfs(i+1, false, prices, memo); // chilling, so next can still sell
      memo[i][buying] = max(sold, chilled);
    }
    return memo[i][buying];
  }

  int maxProfit(vector<int>& prices) {
    unordered_map<int, unordered_map<bool, int>> memo; // (index, buying) -> max profit
    return dfs(0, true, prices, memo);
  }
};