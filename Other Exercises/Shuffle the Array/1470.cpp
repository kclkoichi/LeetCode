#include <vector>
using namespace std;

class Solution {
public:
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> res;
    int l = 0;
    int r = n;
    while(r < nums.size()) {
      res.push_back(nums[l]);
      res.push_back(nums[r]);
      l++; r++;
    }
    return res;
  }
};