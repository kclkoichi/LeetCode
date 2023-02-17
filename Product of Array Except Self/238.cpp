#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      // multiply everything before with everything after without using more space than the vector to return 
      vector<int> sol = vector<int>(nums.size(), 1); // every value is initialised to 1
      int cur = 1;
      for(int i = 0; i < nums.size(); i++) {
        sol[i] *= cur;
        cur*=nums[i];
      }
      cur = 1;
      for(int i = nums.size() - 1; i >= 0; i--) {
        sol[i] *= cur;
        cur*=nums[i];
      }
      return sol;
    }
};