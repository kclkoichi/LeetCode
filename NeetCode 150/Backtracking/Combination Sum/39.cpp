#include <vector>
using namespace std;

class Solution {
public:

  // We give the index of the candidate to not go back!!
  // If you notice the state space diagram, for candidate item '2', 
  // we explore 3 possibilities -> Picking one more '2', Picking. a '3' or picking a '5'. 
  // But as we move to '3', there are only 2 more possibilities, picking a 3 or a 5,
  // and finally, for a 5, there is only one possibility -> picking a 5. 
  // This means that as you go toward the right direction, you don't consider 
  // the elements towards the left since they already have been taken into account before.
  void dfs(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& currentCombination, int sum, int index) {
    if(sum > target) return;
    if(sum == target) {
      result.push_back(currentCombination);
      return;
    }

    for(int i = index; i < candidates.size(); i++) {
      currentCombination.push_back(candidates[i]);
      sum+=candidates[i];
      dfs(candidates, target, result, currentCombination, sum, i);
      sum-=candidates[i];
      currentCombination.pop_back();
    }

    return;
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> currentCombination;
    dfs(candidates, target, result, currentCombination, 0, 0);
    return result;
  }
};

// LeetCode
int main() {
  Solution s;
  vector<int> v {2,3,5};
  s.combinationSum(v, 8);
  return 0;
}