#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> sol;
      sol.push_back(vector<int>()); // []

      for(int i = 0; i < nums.size(); i++) {
        int initialSolSize = sol.size();
        for(int j = 0; j < initialSolSize; j++) {
          vector<int> newV = sol[j];
          newV.push_back(nums[i]);
          sol.push_back(newV);
        }
      }

      return sol;
    }
};