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

// MLE with 580/582 tests passed :(
class Solution {
public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    vector<pair<int, int>> validArrays;
    unordered_map<int, vector<int>> mapping;
    for(int i = nums.size()-1; i >= 0; i--) {
      int cur = nums[i];

      int sol1 = cur + k;
      if(mapping.find(sol1) != mapping.end()) {
        vector<int> sols = mapping[sol1];
        for(int s: sols) validArrays.push_back(make_pair(i, s));
      }
      int sol2 = cur - k;
      if(mapping.find(sol2) != mapping.end()) {
        vector<int> sols = mapping[sol2];
        for(int s: sols) validArrays.push_back(make_pair(i, s));
      }

      mapping[cur].push_back(i);
    }

    if(validArrays.size() == 0) return 0;

    vector<ll> sumArr = vector<ll>(nums.size());
    ll sum = 0;
    for(int i = 0; i < sumArr.size(); i++) {
      sum += nums[i];
      sumArr[i] = sum;
    }

    ll maxSum = LLONG_MIN;
    for(pair<int, int> p: validArrays) {
      int i = p.first;
      int j = p.second;

      if(i == 0) {
        maxSum = max(maxSum, sumArr[j]);
      } else {
        maxSum = max(maxSum, sumArr[j] - sumArr[i-1]);
      }
    }
    return maxSum;
  }
};

int main() {
  Solution s;
  vector<int> v{-1,-2,-3,-4};
  s.maximumSubarraySum(v, 2);
  return 0;
}
