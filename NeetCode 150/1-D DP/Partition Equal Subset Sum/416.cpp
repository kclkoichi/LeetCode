#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// DFS with memo
class Solution {
public:
  string encode(int index, int sum) {
    return to_string(index) + "#" + to_string(sum);
  }

  bool dfs(int index, vector<int>& nums, int sum, int remainder, unordered_map<string, bool>& memo) {
    if(sum > remainder) return false; // we won't get sum == remainder by keep adding to sum
    if(sum == remainder) return true;
    if(index == nums.size()) return false; // can't keep going

    string state = encode(index, sum);
    if(memo.find(state) != memo.end()) return memo[state];

    bool found = dfs(index+1, nums, sum+nums[index], remainder-nums[index], memo) || dfs(index+1, nums, sum, remainder, memo);
    memo[state] = found;
    return found;
  }

  bool canPartition(vector<int>& nums) {
    int total = 0;
    for(int num: nums) total += num;
    if(total % 2 == 1) return false; // can't reach odd split...
    unordered_map<string, bool> memo; // index#sum to sol
    return dfs(0, nums, 0, total, memo);
  }
};

// DP
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int total = 0;
    for(int num: nums) total += num;
    if(total % 2 == 1) return false; // can't reach odd split...
    int target = total/2;

    unordered_set<int> made;
    made.insert(0);

    for(int num: nums) {
      vector<int> toAdd;
      for(int otherNum: made) {
        int newNum = otherNum + num;
        if(newNum > target) continue;
        if(newNum == target) return true;
        toAdd.push_back(newNum);
      }
      for(int add: toAdd) made.insert(add);
    }
    return false;
  }
};
