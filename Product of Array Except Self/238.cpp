#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> fromL = vector<int>(nums.size());
      int buffer = 1;
      for(int i = 0; i < nums.size(); i++) {
        buffer*=nums[i];
        fromL[i] = buffer;
      }

      vector<int> fromR = vector<int>(nums.size());
      buffer = 1;
      for(int i = nums.size() - 1; i >= 0; i--) {
        buffer*=nums[i];
        fromR[i] = buffer;
      }

      vector<int> sol = vector<int>(nums.size());
      sol[0] = fromR[0 + 1]; // second
      sol[nums.size() - 1] = fromL[nums.size()-1 - 1]; // penultimate
      // Always want multiply everything at its left and everything at its right
      for(int i = 1; i < nums.size() - 1; i++) {
        sol[i] = fromL[i - 1] * fromR[i + 1];
      }
      return sol;
    }
};