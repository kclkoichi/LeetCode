#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int dfs(int curMin, int index, vector<int>& nums, unordered_map<int, int>& memo) {
    if(index == nums.size()) return 0;
    if(memo.find(index) != memo.end()) return memo[index];

    int longestFuture = 0;
    for(int j = nums.size() - 1; j >= index; j--) {
      int next = nums[j];
      if(next > curMin) longestFuture = max(longestFuture, 1 + dfs(next, j, nums, memo));
    }

    memo[index] = longestFuture;
    return longestFuture;
  }

  int lengthOfLIS(vector<int>& nums) {
    unordered_map<int, int> memo;
    return dfs(INT_MIN, 0, nums, memo);
  }
};
