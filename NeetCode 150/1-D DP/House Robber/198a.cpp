#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return max(nums[0], nums[1]);

    int maxTillTwoPrevious = nums[0];
    int maxTillPrevious = max(nums[0], nums[1]);

    int curMax = 0;
    for(int i = 2; i < nums.size(); i++) {
      curMax = max(maxTillTwoPrevious + nums[i], maxTillPrevious);
      maxTillTwoPrevious = maxTillPrevious;
      maxTillPrevious = curMax;
    }
    return curMax;
  }
};