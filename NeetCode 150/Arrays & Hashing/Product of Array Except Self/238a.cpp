#include <vector>
using namespace std;

class Solution {
public:
  // nums is at least of size 2
  // O(n) space
  vector<int> productExceptSelf2(vector<int>& nums) {
    vector<int> fromLeft = vector<int>(nums.size());
    int cur = 1;
    for(int i = 0; i < nums.size(); i++) {
      cur *= nums[i];
      fromLeft[i] = cur;
    } 

    cur = 1;
    vector<int> fromRight = vector<int>(nums.size());
    for(int i = nums.size() - 1; i >= 0; i--) {
      cur *= nums[i];
      fromRight[i] = cur;
    }

    vector<int> result = vector<int>(nums.size());
    result[0] = fromRight[1];
    result[nums.size() - 1] = fromLeft[nums.size() - 2];
    for(int i = 1; i < nums.size() - 1; i++) {
      result[i] = fromLeft[i-1] * fromRight[i+1];
    }

    return result;
  }

  // O(1) space. DP
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result;
    int cur = 1;
    for(int i = 0; i < nums.size(); i++) {
      cur *= nums[i];
      result.push_back(cur);
    }

    int fromRight = 1;
    for(int i = nums.size() - 1; i >= 0; i--) {
      if(i != nums.size() - 1) fromRight *= nums[i+1];
      if(i == 0) {
        result[i] = fromRight;
      } else {
        result[i] = result[i-1] * fromRight;
      }
    }

    return result;
  }
};