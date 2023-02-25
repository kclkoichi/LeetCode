#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // logic only works if nums is sorted
    vector<vector<int>> sol;
    sol.push_back(vector<int> { });
    unordered_map<int, int> workedTill;
    for(int n : nums) {
      int initialSize = sol.size();
      int i = 0;
      for(i = workedTill[n]; i < initialSize; i++) {
        vector<int> copy = sol[i];
        copy.push_back(n);
        sol.push_back(copy);
      }
      workedTill[n] = i;
    }
    return sol;
  }
};