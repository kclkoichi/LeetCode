#include <vector>
using namespace std;

class Solution {
public:
  void findSolutionsRecursively(int index, int sum, vector<int> cur, vector<int>& candidates, int target, vector<vector<int>>& res) {
    if(index == candidates.size()) return;
    if(sum > target) return;
    if(sum == target) {
      res.push_back(cur);
      return;
    }
    // world where continue adding the same
    cur.push_back(candidates[index]);
    findSolutionsRecursively(index, sum+candidates[index], cur, candidates, target, res);
    // world where we skip
    cur.pop_back();
    findSolutionsRecursively(index+1, sum, cur, candidates, target, res);
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    findSolutionsRecursively(0, 0, {}, candidates, target, res);
    return res;
  }
};