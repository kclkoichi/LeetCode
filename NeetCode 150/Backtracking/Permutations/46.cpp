#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    // Base case
    if(nums.size() == 1) return vector<vector<int>> { nums };

    vector<vector<int>> result;

    int lastIndexNum = nums[nums.size() - 1];
    nums.pop_back();
    vector<vector<int>> smaller = permute(nums);
    for(int i = 0; i < smaller.size(); i++) {
      for(int j = 0; j < smaller[i].size() + 1; j++) {
        smaller[i].insert(smaller[i].begin() + j, lastIndexNum);
        result.push_back(smaller[i]);
        smaller[i].erase(smaller[i].begin() + j);
      }
    }

    return result;
  }
};

// LeetCode
int main() {
  Solution s;
  vector<int> v {1,2,3};
  s.permute(v);
  return 0;
}