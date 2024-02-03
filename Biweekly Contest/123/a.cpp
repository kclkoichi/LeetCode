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
  pair<int, int> others(int iMax) {
    if(iMax == 0) return make_pair(1,2);
    if(iMax == 1) return make_pair(0,2);
    return make_pair(0,1);
  }

  bool possible(vector<int>& nums) {
    int iMax = longest(nums);
    pair<int, int> p = others(iMax);
    return nums[iMax] <= nums[p.first] + nums[p.second];
  }

  int longest(vector<int>& nums) {
    int iMax = -1;
    int max = -1;
    for(int i = 0; i < nums.size(); i++) {
      if(nums[i] > max) {
        iMax = i;
        max = nums[i];
      }
    }
    return iMax;
  }

  string triangleType(vector<int>& nums) {
    if(nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) {
      if(nums[0] == nums[1] && nums[1] == nums[2]) return "equilateral";
      if(possible(nums)) return "isoceles";
    }
    return possible(nums) ? "scalene" : "none";
  }
};