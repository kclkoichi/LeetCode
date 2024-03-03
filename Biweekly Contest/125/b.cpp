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
  int minOperations(vector<int>& nums, int k) {
    multiset<ll> s;
    for(int n: nums) s.insert(n);
    int count = 0;
    while(*s.begin() < (ll) k) {
      count++;
      ll toAdd = *(s.begin()) * 2 + *(++s.begin());
      s.insert(toAdd);
      s.erase(s.begin());
      s.erase(s.begin());
    }
    return count;
  }
};
