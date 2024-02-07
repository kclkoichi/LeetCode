#include <vector>
using namespace std;

class Solution {
public:
  int bestOutcome(int i, vector<int>& nums, vector<int>& memo) {
    if(i >= nums.size()) return 0;
    if(memo[i] > -1) return memo[i];
    int outcome = max(nums[i] + bestOutcome(i+2, nums, memo), bestOutcome(i+1, nums, memo));
    memo[i] = outcome;
    return outcome;
  }

  int rob(vector<int>& nums) {
    vector<int> memo(nums.size(), -1);
    return bestOutcome(0, nums, memo);
  }
};
