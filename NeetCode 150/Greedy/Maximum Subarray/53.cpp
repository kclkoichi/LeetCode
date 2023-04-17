#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int max = nums[0];
    int cur = nums[0];
    for(int i = 1; i < nums.size(); i++) {
      int prev = cur;
      if(prev > 0) {
        cur = prev + nums[i];
      } else {
        cur = nums[i];
      }
      if(cur > max) max = cur;
    }
    return max;
  }
};