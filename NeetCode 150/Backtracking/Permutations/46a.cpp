#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  void makeAllPermutations(unordered_set<int> available, vector<int> cur, vector<vector<int>>& res) {
    if(available.size() == 0) {
      res.push_back(cur);
      return;
    }
    for(int num: available) {
      // use a number
      unordered_set<int> without = available;
      without.erase(num);
      cur.push_back(num);

      makeAllPermutations(without, cur, res);
      cur.pop_back();
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    unordered_set<int> available;
    for(int num: nums) available.insert(num);
    makeAllPermutations(available, {}, res);
    return res;
  }
};