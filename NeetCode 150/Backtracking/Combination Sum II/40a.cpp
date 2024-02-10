#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    queue<pair<vector<int>, pair<int, int>>> q; // vector, index, sum
    q.push(make_pair(vector<int>(), make_pair(0, 0)));
    while(!q.empty()) {
      vector<int> cur = q.front().first;
      int i = q.front().second.first;
      int sum = q.front().second.second;
      q.pop();
      if(target - sum < 0) continue; // overshoot
      if(target == sum) {
        res.push_back(cur);
        continue;
      }
      // Else, not enough
      int prev = -1; // -1 is impossible val of candidate
      for(; i < candidates.size(); i++) {
        int candidate = candidates[i];
        // we don't want to go in same world as prev.
        // we want world where we have the most of same number
        // which is why it's sorted and we use the first repeated number we have
        if(prev == candidate) continue;
        cur.push_back(candidate);
        q.push(make_pair(cur, make_pair(i+1, sum+candidate)));
        cur.pop_back();
        prev = candidate;
      }
    }
    return res;
  }
};