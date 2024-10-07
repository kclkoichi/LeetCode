#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int longestSubarray(vector<int>& nums) {
    int maxValue = *max_element(nums.begin(), nums.end());

    int res = 0;
    int i = 0;
    while(i < nums.size()) {
      if(nums[i] == maxValue) {
        int cur = 1;
        i++;
        while(i < nums.size() && nums[i] == maxValue) {
          cur++;
          i++;
        }
        res = max(cur, res);
        i--;
      }
      i++;
    }

    return res;
  }
};
