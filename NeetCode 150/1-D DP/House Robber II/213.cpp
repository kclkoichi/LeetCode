#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return max(nums[0], nums[1]);

    vector<int> potentialA = vector<int>(nums.size() - 1);
    potentialA[0] = nums[1];
    potentialA[1] = nums[2];
    for(int i = 3; i < nums.size(); i++) {
      if(i == 3) potentialA[i-1] = nums[i] + potentialA[0]; 
      else potentialA[i-1] = nums[i] + max(potentialA[i-3], potentialA[i-4]);
    }
    vector<int> potentialB = vector<int>(nums.size() - 1);
    for(int i = 0; i <= 1; i++) potentialB[i] = nums[i]; // [0 to 1]
    for(int i = 2; i < nums.size() - 1; i++) {
      if(i == 2) potentialB[2] = nums[2] + nums[0];
      else potentialB[i] = nums[i] + max(potentialB[i-2], potentialB[i-3]);
    }
    int a = max(potentialA[potentialA.size()-2], potentialA[potentialA.size()-1]);
    int b = max(potentialB[potentialB.size()-2], potentialB[potentialB.size()-1]);
    return max(a,b);
  }
};