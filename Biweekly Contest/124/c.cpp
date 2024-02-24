#include <iostream>
#include <math.h>
#include <algorithm> // max
#include <string>
#include <algorithm> // sort, stable_sort

#include <vector>
#include <list>
#include <stack>
#include <queue> // and MAX priority queue
#include <deque>

#include <set> // BBST (and multiset)
#include <map> // BBST (and multimap)
#include <unordered_set> // Hash Table, boolean
#include <unordered_map> // Hash Table, map to something
using namespace std;

typedef long long ll;

class Solution {
public:
  int dfs(int l, int r, int aim, vector<int>& nums, unordered_map<int, unordered_map<int, int>>& memo) {
    if(l >= r) return 0;
    if(memo[l][r]) return memo[l][r];

    int maxRes = 0;

    if(aim == nums[l] + nums[l+1]) {
      maxRes = max(maxRes, dfs(l+2, r, aim, nums, memo) + 1);
    }

    if(aim == nums[r] + nums[r-1]) {
      maxRes = max(maxRes, dfs(l, r-2, aim, nums, memo) + 1);
    }

    if(aim == nums[l] + nums[r]) {
      maxRes = max(maxRes, dfs(l+1, r-1, aim, nums, memo) + 1);
    }

    memo[l][r] = maxRes;

    return maxRes;
  }

  int maxOperations(vector<int>& nums) {
    int maxOp = 0;
    unordered_map<int, unordered_map<int, int>> memo;

    int score = nums[0] + nums[1];
    maxOp = max(maxOp, dfs(2, nums.size() - 1, score, nums, memo) + 1);

    score = nums[nums.size() - 1] + nums[nums.size() - 2];
    maxOp = max(maxOp, dfs(0, nums.size() - 3, score, nums, memo) + 1);

    score = nums[0] + nums[nums.size() - 1];
    maxOp = max(maxOp, dfs(1, nums.size() - 2, score, nums, memo) + 1);

    return maxOp;
  }
};
