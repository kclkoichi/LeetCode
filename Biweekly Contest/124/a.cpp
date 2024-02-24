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
  int maxOperations(vector<int>& nums) {
    int count = 1;
    int score = nums[0] + nums[1];
    for(int i = 2; i < nums.size()-1; i+=2) {
      if(nums[i] + nums[i+1] == score) {
        count++;
      } else {
        break;
      }
    }
    return count;
  }
};