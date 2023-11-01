#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    int prev;

    for(int i = 0; i < nums.size(); i++) {
      int fixed = nums[i];
      if(fixed == prev) {
        continue; // if duplicate number, just go ahead
      }
      int target = 0 - fixed;
      int l = i + 1;
      int r = nums.size() - 1;
      while(l < r) {
        if(target - nums[l] - nums[r] == 0) {
          res.push_back({fixed, nums[l], nums[r]});
          int prev = nums[l];
          while(l < r && prev == nums[l]) {
            l++;
          }
        } else if(target - nums[l] - nums[r] < 0) {
          r--;
        } else {
          l++;
        }
      }
      prev = fixed;
    } 
    return res;
  }
};