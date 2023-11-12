#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    // Make vectors split by 0s, isolate 0s
    vector<vector<int>> vectors;
    vector<int> tmp = vector<int>();
    for(int i = 0; i < nums.size(); i++) {
      if(nums[i] == 0) {
        // edge case: first 0, or 0s in a row
        if(tmp.size() > 0) vectors.push_back(tmp);
        tmp = vector<int>();
        vectors.push_back({0});
        continue;
      } 
      tmp.push_back(nums[i]);
    }
    if(tmp.size() > 0) vectors.push_back(tmp);

    int res = INT_MIN;
    // For each splitting
    for(vector<int> vi: vectors) {
      int viRes = vi[0];
      // Traverse from left and from right
      int cur = 1;
      for(int i = 0; i < vi.size(); i++) {
        cur*=vi[i];
        viRes = max(viRes, cur);
      }
      cur = 1;
      for(int i = vi.size()-1; i >= 0; i--) {
        cur*=vi[i];
        viRes = max(viRes, cur);
      }

      res = max(res, viRes);
    }

    return res;
  }
};
