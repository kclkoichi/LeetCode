#include <vector>
using namespace std;

class Solution {
public:
  long long minimumReplacement(vector<int>& nums) {
    long long res = 0;

    // We won't split the last number, so start from second last
    for(int i = nums.size() - 2; i >= 0; i--) {
      if(nums[i] <= nums[i+1]) continue;

      // nums[i] > nums[i+1]
      if(nums[i] % nums[i+1] == 0) {
        long long splitCount = nums[i] / nums[i+1];
        long long splitValue = nums[i] / splitCount;
        res += splitCount - 1;
        nums[i] = splitValue;
      } else {
        long long splitCount = nums[i] / nums[i+1] + 1;
        long long minSplitValue = nums[i] / splitCount;
        res += splitCount - 1;
        nums[i] = minSplitValue;
      }
    }

    return res;
  }
};
