#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    int preprev = nums[0];
    int prev = max(nums[1], nums[0]);
    for(int i = 2; i < nums.size(); i++) {
      int cur = max(prev, preprev + nums[i]);
      preprev = prev;
      prev = cur;
    }
    return prev;
  }
};