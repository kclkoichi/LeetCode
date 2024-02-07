#include <vector>
using namespace std;

class Solution {
public:
  int profitFrom(bool canTakeLast, int i, vector<int>& nums, vector<int>& memo) {
    if(i == nums.size() - 1) return canTakeLast ? nums[nums.size() - 1] : 0;
    if(i > nums.size() - 1) return 0;
    if(memo[i] > -1) return memo[i];
    int profit = nums[i] + max(profitFrom(canTakeLast, i+2, nums, memo), profitFrom(canTakeLast, i+3, nums, memo));
    memo[i] = profit;
    return profit;
  }

  int rob(vector<int>& nums) {
    // edge case
    if(nums.size() == 1) return nums[0];
    // size 2 is not edge case

    vector<int> memo1(nums.size(), -1);
    int profit1 = profitFrom(false, 0, nums, memo1);

    vector<int> memo2(nums.size(), -1);
    int profit2 = max(profitFrom(true, 1, nums, memo2), profitFrom(true, 2, nums, memo2));
    return max(profit1, profit2);
  }
};