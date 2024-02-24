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
  int countChain(vector<int>& nums) {
    int maxCount = 0;
    unordered_set<int> have;
    for(int n: nums) have.insert(n);

    for(int i = 0; i < nums.size(); i++) {
      int cur = nums[i]-1;
      // if beginning of chain
      if(have.find(cur) == have.end()) {
        int count = 1;
        cur = nums[i] + 1;
        while(have.find(cur) != have.end()) {
          cur++;
          count++;
        }
        maxCount = max(maxCount, count);
      }
    }

    return maxCount;
  }

  int maxSelectedElements(vector<int>& nums) {
    int tries = 0;
    int maxCount = 0;
    unordered_multiset<int> have;
    for(int i = 0; i < nums.size(); i++) {
      have.insert(nums[i]);
    }
    vector<int> toPush;
    for(int i = 0; i < nums.size(); i++) {
      if(have.count(nums[i]) > 1) {
        toPush.push_back(nums[i]+1);
      }
    }

    while(tries < 500) {
      vector<int> copy = nums;
      for(int i = 0; i < nums.size(); i++) {
        if(have.count(nums[i]) == 1) {
          if(rand() % 2 == 0) copy[i]++;
        }
      }
      for(int t: toPush) copy.push_back(t);
      maxCount = max(maxCount, countChain(copy));
      tries++;
    }

    return maxCount;
  }
};
