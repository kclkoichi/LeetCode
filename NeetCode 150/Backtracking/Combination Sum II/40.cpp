#include <vector>
using namespace std;

class Solution {
public:
  void dfs(vector<vector<int>>& sol, int i, vector<int> cur, vector<int>& candidates, int sum, int target, int lastAdded) {
    if(sum > target) return; // backtrack
    if(i == candidates.size()) {
      if(sum == target) sol.push_back(cur);
      return;
    }
    // Create world in which we add the current number
    cur.push_back(candidates[i]);
    dfs(sol, i+1, cur, candidates, sum+candidates[i], target, candidates[i]);
    cur.pop_back();
    // Create world in which we don't add it IFF the latest added to cur isn't the one we added in the world above
    if(lastAdded != candidates[i]) {
      dfs(sol, i+1, cur, candidates, sum, target, lastAdded);
    }
  }

  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> sol;
    vector<int> cur {};
    dfs(sol, 0, cur, candidates, 0, target, -1);
    return sol;
  }
};