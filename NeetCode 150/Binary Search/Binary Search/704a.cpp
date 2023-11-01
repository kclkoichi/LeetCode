#include <vector>
using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int leftIndex = 0;
    int rightIndex = nums.size() - 1;
    int middleIndex = (leftIndex + rightIndex) / 2;

    while(nums[middleIndex] != target) {
      if(nums[middleIndex] > target) {
        rightIndex = middleIndex;
      } else {
        leftIndex = middleIndex;
      }
      middleIndex = (leftIndex + rightIndex) / 2;
      if(middleIndex == leftIndex) {
        if(nums[leftIndex] == target) return leftIndex;
        if(nums[rightIndex] == target) return rightIndex;
        return -1;
      }
    }

    return middleIndex;
  }
};