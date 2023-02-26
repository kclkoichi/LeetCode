#include <vector>
using namespace std;

class Solution {
public:
  // Copying cur was taking time... use & !!!
  // Some ways enable to backtrack faster and create less recursion... (this more efficient than previous submission)
  void dfs(vector<vector<int>>& sol, int start, vector<int>& cur, vector<int>& candidates, int sum, int target) {
    if(sum == target) {
      sol.push_back(cur);
      return;
    } else if(sum > target) {
      return; // backtrack
    } else {
      for(int i = start; i < candidates.size(); i++) {
        if(i > start && candidates[i] == candidates[i-1]) continue; // Don't work with duplicates more than once
        cur.push_back(candidates[i]);
        dfs(sol, i+1, cur, candidates, sum+candidates[i], target);
        cur.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> sol;
    vector<int> cur {};
    dfs(sol, 0, cur, candidates, 0, target);
    return sol;
  }
};