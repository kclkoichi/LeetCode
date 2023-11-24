#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int l = 0;
    int r = nums.size()-1;
    int maxSum = 0;
    while(l < r) {
      if(nums[l] + nums[r] > maxSum) maxSum = nums[l] + nums[r];
      l++;
      r--;
    }
    return maxSum;
  }
};
