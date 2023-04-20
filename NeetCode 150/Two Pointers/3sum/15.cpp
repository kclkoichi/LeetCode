#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for(int i = 0; i < nums.size(); i++) {
      if(i>0 && nums[i-1] == nums[i]) continue;
      // We want a + nums[b] + nums[c] = 0
      int a = nums[i];
      int b = i+1;
      int c = nums.size() - 1;
      while(b < c) {
        int sum = a + nums[b] + nums[c];
        if(sum == 0) {
          vector<int> v {a, nums[b], nums[c]};
          res.push_back(v);
        }
        // >= because if was equal, now try more
        if(sum <= 0) do { b++; } while(b < c && nums[b-1] == nums[b]); // do at least once
        if(sum > 0) do { c--; } while(b < c && nums[c+1] == nums[c]);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> v {-1,0,1,2,-1,-4};
  s.threeSum(v);
  return 0;
}