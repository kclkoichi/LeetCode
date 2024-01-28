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
  int maxSubarrayLength(vector<int>& nums, int k) {
    int l = 0;
    int r = 0;
    int maxLength = 0;
    unordered_map<int, int> counter;
    int toDel = -1;

    while(r < nums.size()) {
      int cur = nums[r];
      counter[cur]++;
      if(counter[cur] > k) {
        toDel = cur;
        while(true) {
          int curL = nums[l];
          counter[curL]--;
          l++;
          if(curL == toDel) {
            break;
          }
        }
      }
      maxLength = max(maxLength, r - l + 1);
      r++;
    }
    return maxLength;
  }
};
