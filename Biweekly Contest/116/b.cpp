#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int dfs(unordered_map<int, unordered_map<int, int>>& memo, int sum, int coins, int i, vector<int>& nums, int target) {
    if(memo[i].find(sum) != memo[i].end()) {
      memo[i][sum] = max(memo[i][sum], coins);
      return memo[i][sum];
    }
    if(sum == target) {
      memo[i][sum] = max(memo[i][sum], coins);
      return memo[i][sum];
    }
    if(i == nums.size() || sum > target) {
      memo[i][sum] = -1;
      return -1;
    }
    int with = dfs(memo, sum + nums[i], coins+1, i+1, nums, target);
    int without = dfs(memo, sum, coins, i+1, nums, target);
    if(with == -1 && without == -1) {
      memo[i][sum] = -1;
      return -1;
    } else if(with == -1) {
      memo[i][sum] = coins + without;
    } else if(without == -1) {
      memo[i][sum] = coins + with;
    } else {
      memo[i][sum] = coins + max(with, without);
    }
    return memo[i][sum];
  }

  int lengthOfLongestSubsequence(vector<int>& nums, int target) {
    unordered_map<int, unordered_map<int, int>> memo; // index, sum map to maxCoins
    return dfs(memo, 0, 0, 0, nums, target);
  }
};