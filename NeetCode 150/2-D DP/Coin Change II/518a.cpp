#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int target;
  vector<int> availableCoins;
  unordered_map<int, unordered_map<int, int>> memo; // i, cur -> ways

  int dfs(int i, int cur) {
    if(i >= availableCoins.size()) return 0; // There is no way once we are out of bounds
    if(cur == target) return 1; // New way: reached target
    if(cur > target) return 0; // Went over
    if(memo[i].find(cur) != memo[i].end()) return memo[i][cur];

    int ways = 0;
    ways += dfs(i+1, cur); // Skip to next coin
    ways += dfs(i, cur+availableCoins[i]); // Take this coin
    memo[i][cur] = ways;
    return memo[i][cur];
  }

  int change(int amount, vector<int>& coins) {
    target = amount;
    availableCoins = coins;
    return dfs(0, 0);
  }
};
