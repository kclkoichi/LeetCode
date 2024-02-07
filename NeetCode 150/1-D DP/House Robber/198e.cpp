#include <vector>
using namespace std;

class Solution {
public:
  // We can't steal from next
  // If we steal from i+4, it would have been better to take i+2
  // If we steal from i+5, it would have been better to take i+3
  // Therefore we only need to look at best profit from i+2 or i+3
  int profitFrom(int i, vector<int>& nums, vector<int>& memo) {
    if(i > nums.size() - 1) return 0;
    if(memo[i] > -1) return memo[i];
    int profit = nums[i] + max(profitFrom(i+2, nums, memo), profitFrom(i+3, nums, memo));
    memo[i] = profit;
    return profit;
  }

  int rob(vector<int>& nums) {
    vector<int> memo(nums.size(), -1);
    return max(profitFrom(0, nums, memo), profitFrom(1, nums, memo));
  }
};