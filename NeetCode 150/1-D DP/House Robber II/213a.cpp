#include <vector>
using namespace std;

class Solution {
public:
  int robNotAdjacent(vector<int>& nums) {
    int preprev = nums[0];
    int prev = max(nums[0], nums[1]);
    for(int i = 2; i < nums.size(); i++) {
      int cur = max(preprev + nums[i], prev);
      preprev = prev;
      prev = cur;
    }
    return prev;
  }

  int rob(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    
    // Without first house
    vector<int> nums1 = nums;
    nums1.erase(nums1.begin());

    // Without last house
    nums.pop_back();
    return max(robNotAdjacent(nums1), robNotAdjacent(nums));
  }
};