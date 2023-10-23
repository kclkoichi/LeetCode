#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int rec(vector<int>& nums, int target, int index, int sum, unordered_map<int, unordered_map<int, int>>& memo) {
    if(memo.find(index) != memo.end() && memo[index].find(sum) != memo[index].end()) {
      return memo[index][sum];
    }

    if(index >= nums.size()) {
      return target == sum ? 1 : 0;
    }

    memo[index][sum] = rec(nums, target, index+1, sum-nums[index], memo) + rec(nums, target, index+1, sum+nums[index], memo);
    return memo[index][sum];
  }

  // O(n * t) time complexity with t is range between all - nums and all + nums
  int findTargetSumWays(vector<int>& nums, int target) {
    unordered_map<int, unordered_map<int, int>> memo;
    return rec(nums, target, 0, 0, memo);
  }
};