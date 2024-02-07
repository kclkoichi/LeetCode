#include <vector>
using namespace std;

class Solution {
public:
  void dfs(int index, int remaining, vector<int>& candidates, vector<vector<int>>& res, vector<int>& cur) {
    if(index == candidates.size()) return;
    if(remaining < 0) return;
    if(remaining == 0) {
      res.push_back(cur);
      return;
    }
    cur.push_back(candidates[index]);
    dfs(index, remaining - candidates[index], candidates, res, cur); // world where I use this number
    cur.pop_back();
    dfs(index+1, remaining, candidates, res, cur); // world where I don't
    return;
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> cur;
    dfs(0, target, candidates, res, cur);
    return res;
  }
};