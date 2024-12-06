#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int sumXor = 0;
    for(int i: nums) sumXor ^= i;

    int maxXor = 1;
    for(int i = 2; i <= maximumBit; i++) {
      maxXor <<= 1;
      maxXor |= 1;
    }

    vector<int> res;
    for(int i = nums.size() - 1; i >= 0; i--) {
      res.push_back(sumXor ^ maxXor);
      sumXor ^= nums[i];
    }
    return res;
  }
};
