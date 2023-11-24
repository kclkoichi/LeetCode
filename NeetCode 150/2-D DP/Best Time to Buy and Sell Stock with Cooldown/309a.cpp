#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int dfs(int i, vector<int>& prices, bool bought, unordered_map<int, unordered_map<bool, int>>& memo) {
    if(i >= prices.size()) return 0;
    if(memo[i].find(bought) != memo[i].end()) return memo[i][bought];
    int bestProfit = 0;
    if(bought) {
      bestProfit = max(bestProfit, dfs(i+2, prices, false, memo) + prices[i]); // sell now, skip tomorrow
    } else {
      bestProfit = max(bestProfit, dfs(i+1, prices, true, memo) - prices[i]); // buy now
    }
    bestProfit = max(bestProfit, dfs(i+1, prices, bought, memo)); // skip now
    memo[i][bought] = bestProfit;
    return bestProfit;
  }

  int maxProfit(vector<int>& prices) {
    unordered_map<int, unordered_map<bool, int>> memo;
    return dfs(0, prices, false, memo);
  }
};
