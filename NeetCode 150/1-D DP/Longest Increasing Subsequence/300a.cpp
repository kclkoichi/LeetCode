#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int dfs(int startAt, vector<int>& nums, int prev, vector<int>& memo) {
    if(memo[startAt] != -10e6) return memo[startAt];
    int longestFuture = 0;
    for(int j = nums.size() - 1; j >= startAt; j--) {
      int cur = nums[j];
      if(cur > prev) longestFuture = max(longestFuture, 1 + dfs(j, nums, cur, memo));
    }
    memo[startAt] = longestFuture;
    return longestFuture;
  }

  int lengthOfLIS(vector<int>& nums) {
    vector<int> memo(nums.size(), -10e6);
    return dfs(0, nums, -10e6, memo);
  }
};
