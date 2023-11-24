#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return max(nums[0], nums[1]);
    int maxLootTwoNext = nums[nums.size() - 1];
    int maxLootNext = max(nums[nums.size() - 2], nums[nums.size() - 1]);
    int maxLoot = -1;
    for(int i = nums.size() - 3; i >= 0; i--) {
      maxLoot = max(nums[i] + maxLootTwoNext, maxLootNext);
      maxLootTwoNext = maxLootNext;
      maxLootNext = maxLoot;
    }
    return maxLoot;
  }
};
