#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        int threePrev = nums[0];
        int twoPrev = nums[1];
        int prev = nums[2] + nums[0];
        for(int i = 3; i < nums.size(); i++) {
          int actual = max(threePrev, twoPrev) + nums[i];
          threePrev = twoPrev; twoPrev = prev; prev = actual;
        }

        return max(twoPrev, prev);
    }
};