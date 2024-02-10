#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    queue<pair<vector<int>, int>> q; // vector, current index
    q.push(make_pair(vector<int>(), 0));
    while(!q.empty()) {
      vector<int> cur = q.front().first;
      int i = q.front().second;
      q.pop();
      res.push_back(cur);
      int prev = -1e9; // special num
      for(; i < nums.size(); i++) {
        int num = nums[i];
        if(num == prev) continue; // if same as prev, we don't want duplicate
        cur.push_back(num);
        q.push(make_pair(cur, i+1)); // start from next index next time
        cur.pop_back();
        prev = num;
      }
    }

    return res;
  }
};