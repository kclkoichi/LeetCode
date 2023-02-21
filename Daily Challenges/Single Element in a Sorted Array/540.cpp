#include <vector>
using namespace std;

class Solution {
public:
  // To get the logic, draw the examples and do like a debugger.
  // To decide to go r or l, it depends on which one is equal, and which side is odd or even.
  int singleNonDuplicate(vector<int>& nums) {
    int l = 0;
    int r = nums.size();
    while(true) {
      int i = (l+r)/2;
      if(i == 0 || i == nums.size() - 1) return nums[i];
      int left = nums[i-1];
      int cur = nums[i];
      int right = nums[i+1];
      if(left == cur) {
        if((i-1)%2==1) {
          r=i-1;
        } else {
          l=i+1;
        }
      } else if(right == cur) {
        if((i+1)%2==1) {
          l=i+1;
        } else {
          r=i-1;
        }
      } else {
        return cur;
      }
    }
    return -1; // There is always a solution so it should never happen
  }
};